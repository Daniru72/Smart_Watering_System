# IoT Smart Watering System

An innovative smart watering system that leverages IoT technology to monitor and control the watering of plants. This system integrates a mobile application, backend services, and hardware components to provide an efficient and user-friendly solution for plant care.

---

## Features

### Mobile Application (React Native - Expo)
- **Water Level Monitoring:** Displays real-time water levels in the tank and soil moisture levels.
- **Control Watering:** Allows users to control water flow from the tank to the plants with a simple button press.
- **User-Friendly Interface:** Intuitive design for seamless interaction.

### Backend (Java with Hibernate ORM)
- **Data Management:** Stores and retrieves data about water levels and device configurations.
- **API Integration:** Facilitates communication between the mobile app and hardware components.
- **Robust Architecture:** Ensures reliable and secure operations.

### Hardware Components (Arduino - C++)
- **Sensors:** Measure water tank levels and soil moisture.
- **Actuators:** Control water flow based on user input from the app.
- **Microcontroller Integration:** Efficiently connects all components for smooth operation.

---
### Design

<img src="https://github.com/user-attachments/assets/93ed9bbf-9f00-4d5e-9009-e9c077a7b45f" alt="WhatsApp Image 2024-12-30 at 23 19 04_ef8b8af8" width="300">
<img src="https://github.com/user-attachments/assets/b4db9532-d67d-4fb1-bf36-2587e7f4da47" alt="WhatsApp Image 2024-12-30 at 23 19 05_b80096ca" width="300">
<img src="https://github.com/user-attachments/assets/8713d9fe-e768-4f55-a3e0-b031b38ceffb" alt="WhatsApp Image 2024-12-30 at 23 19 05_7448694c" width="300">

<img src="https://github.com/user-attachments/assets/39eeec6a-e736-4bab-b564-36bab9a45a59" alt="WhatsApp Image 2024-12-30 at 20 44 58_3fcbeb1e" width="300">
<img src="https://github.com/user-attachments/assets/44db3233-23aa-41fe-9c1e-218ca254a92a" alt="WhatsApp Image 2024-12-30 at 20 44 59_c2bd285a" width="300">
<img src="https://github.com/user-attachments/assets/ac8410ea-480e-4950-ab03-3b56b07b0e07" alt="WhatsApp Image 2024-12-30 at 20 45 00_c6ea77dd" width="300">



## System Architecture

1. **Mobile App:** Developed using React Native (Expo) for cross-platform compatibility.
2. **Backend Server:** Java backend with Hibernate ORM for database management and API endpoints.
3. **Arduino Hardware:** Implements C++ code to handle sensor data and control actuators.

---

## How It Works

1. **Monitoring:** Sensors in the system measure the water level in the tank and soil moisture.
2. **Data Transmission:** Sensor data is sent to the backend server, where it is processed and stored.
3. **Mobile App Interaction:** Users can view real-time data on the app and send commands to control watering.
4. **Action Execution:** The Arduino processes commands from the server to regulate water flow.

---

## Prerequisites

### Software Requirements
- Node.js (for running React Native - Expo)
- Java 8+ (for the backend application)
- Arduino IDE (for programming hardware)

### Hardware Requirements
- ESP32 board 
- Soil moisture sensor
- Ultrasonic water level sensor
- Motor controll (to control water pump & moters)
- Water pump and tank setup
- Two Motors

---

## Setup and Installation

### Backend Setup
1. Clone the repository: 
   ```bash
   git clone https://github.com/yourusername/iot-smart-watering.git
   ```
2. Navigate to the backend folder and set up the project:
   ```bash
   cd backend
   ./mvnw spring-boot:run
   ```
3. Configure your database connection in `application.properties`.

### Mobile App Setup
1. Navigate to the mobile app folder:
   ```bash
   cd mobile-app
   ```
2. Install dependencies:
   ```bash
   npm install
   ```
3. Start the application:
   ```bash
   expo start
   ```

### Arduino Setup
1. Open the Arduino folder in the Arduino IDE.
2. Upload the code to your ESP32 board.
3. Connect sensors and actuators as per the wiring diagram.

---


## Acknowledgments

- Thanks to the open-source community for tools and libraries.
- Special thanks to all contributors.
