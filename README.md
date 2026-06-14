🌱 Frame A Farm


AI-powered AR soil analysis and crop planning — point any camera at soil and instantly see where to plant.



Built at JAMHacks 2026 by John Varghese and Vikas Sethuramam.


What It Does

Frame A Farm combines computer vision AI with real Arduino soil sensors to give farmers instant, intelligent planting recommendations. Point your iPhone camera at any patch of soil, press scan, and the app tells you:


Soil type (Sandy, Loam, Clay)
Real-time moisture and temperature from the Arduino sensor
The best crop to plant (Rice, Corn, or Apple)
Exactly where to place each seed — shown as AR plant overlays directly on the camera feed


How It Works

Hardware: An Arduino Leonardo mounted on a rod with a moisture sensor and temperature sensor attached at the base makes direct contact with the soil. It sends real-time JSON data over USB serial to the Flask backend.

Backend: A Python Flask server receives camera frames from the browser and sensor data from the Arduino. It passes both to the Claude API for analysis.

AI: Claude Sonnet analyzes the soil image visually alongside the sensor readings to recommend the optimal crop and calculate planting grid coordinates.

Frontend: A single-page HTML app hosted on Netlify uses the device camera and draws AR plant PNG overlays at the Claude-calculated coordinates using the HTML5 Canvas API. No app download required.

Networking: A Cloudflare tunnel bridges the browser (HTTPS) to the local Flask server for real-time communication.

Tech Stack


Python / Flask
Anthropic Claude API (claude-sonnet-4-6)
Arduino C++
HTML5 / JavaScript / Canvas API
Cloudflare Tunnel
Netlify
Continuity Camera (iOS/macOS)


Getting Started

Prerequisites


Python 3.10+
Arduino IDE
Arduino Leonardo with moisture sensor (A0) and temperature sensor (A1)
Anthropic API key
cloudflared CLI


Installation

bashgit clone https://github.com/jvarghesetech/farmvision
cd farmvision
python3 -m venv venv
source venv/bin/activate
pip install flask anthropic pyserial flask-cors

Running

Tab 1 — Flask backend:

bashexport ANTHROPIC_API_KEY="your_api_key_here"
python app.py

Tab 2 — Cloudflare tunnel:

bashcloudflared tunnel --url http://localhost:5000

Copy the tunnel URL, update BACKEND in index.html, and deploy to Netlify.

Arduino

Upload arduino/soil_sensor.ino to your Arduino Leonardo using Arduino IDE. Make sure the Serial Monitor is closed before running Flask.

Project Structure

farmvision/
├── app.py              # Flask backend
├── farm_planner.py     # Claude API integration
├── templates/
│   └── index.html      # Frontend (local version)
├── arduino/
│   └── soil_sensor.ino # Arduino firmware
└── README.md

Demo

Live demo available at JAMHacks 2026 submission page.


Built with the Anthropic Claude API. 🤖
