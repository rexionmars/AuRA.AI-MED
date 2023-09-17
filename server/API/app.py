import os
import sys
import cv2
import threading
import json

from optic import core
from model import Model

from flask import Flask, render_template, Response, request, jsonify
from flask_socketio import SocketIO, emit


app = Flask(__name__)
app.config["SECRET_KEY"] = os.getenv("SECRET_KEY")
socketio = SocketIO(app)

# Variáveis globais para o OCR e streaming
video_stream = None
ocr = None
# Variável global para armazenar as palavras detectadas
detected_words = []


def generate_frames():
    global video_stream, ocr, detected_words

    while True:
        if video_stream is not None and ocr is not None:
            frame = video_stream.frame

            # Faz a detecção OCR no frame
            _, text = core.put_ocr_boxes(
                ocr.boxes,
                frame,
                frame.shape[0],
                crop_width=ocr.crop_width,
                crop_height=ocr.crop_height,
                view_mode=ocr.view_mode,
            )

            # Adicione as palavras detectadas à lista detected_words
            detected_words = text.split()

            # Emitir as palavras detectadas para os clientes conectados através do WebSocket
            socketio.emit("detected_words", {"words": detected_words})

            ret, buffer = cv2.imencode(".jpg", frame)
            frame = buffer.tobytes()
            yield (b"--frame\r\n" b"Content-Type: image/jpeg\r\n\r\n" + frame + b"\r\n")


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/start_ocr", methods=["POST"])
def start_ocr():
    global video_stream, ocr

    data = request.form
    source = data["source"]
    crop = [int(data["crop_width"]), int(data["crop_height"])]
    view_mode = int(data["view_mode"])
    language = data["language"]

    video_stream = core.VideoStream(source).start()
    img_wi, img_hi = video_stream.get_video_dimensions()

    ocr = core.OCR().start()

    ocr.set_exchange(video_stream)
    ocr.set_language(language)
    ocr.set_dimensions(img_wi, img_hi, crop[0], crop[1])
    ocr.view_mode = view_mode  # Adiciona o atributo view_mode à classe OCR

    return jsonify({"ok": 200})


@app.route("/tests")
def test():
    return jsonify(Model.vital_signs_monitor())


@app.route("/video_feed")
def video_feed():
    return Response(
        generate_frames(), mimetype="multipart/x-mixed-replace; boundary=frame"
    )


@app.route("/get-detected-words")
def get_detected_words():
    global detected_words
    words = detected_words

    data_info = {
        "detection": words,
    }

    return jsonify(data_info), 200


@app.route("/detected_words")
def show_detected_words():
    return render_template("detected_words.html")


if __name__ == "__main__":
    socketio.run(app, debug=True, host="0.0.0.0", port=5000)