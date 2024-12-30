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
