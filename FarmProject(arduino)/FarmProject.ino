#include <L298N.h>

#include <Ultrasonic.h>
#include <WiFi.h>



// Replace with your Wi-Fi credentials
const char* ssid = "Dialog 4G 108";
const char* password = "FIGHT2KILL";

WiFiServer server(80); // Use WiFiServer instead of NetworkServer

//UltraSonic pins
Ultrasonic u1 = Ultrasonic(5,18); //triger,echo

//MotorControl pins 2moters&waterpump
L298N m1 = L298N(2,4);

//MotorControl pins waterpump
L298N m2 = L298N(19,21);

//SOIL_MOISTURE_PIN 
#define SOIL_MOISTURE_PIN 34  // Replace with your chosen ADC pin





void setup() {
  // put your setup code here, to run once:
   Serial.begin(115200);
  pinMode(SOIL_MOISTURE_PIN, INPUT);



  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("Connecting...");
  }

  Serial.println("\nWiFi Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Start the server
  server.begin();
  Serial.println("Server started");


  

}




void loop() {
  // put your main code here, to run repeatedly:
    WiFiClient client = server.available(); // Use WiFiClient instead of NetworkClient

  if (client) {
    Serial.println("Client connected");
    String request = "";

    // Read the request
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        request += c;

       
        // Check if the request is complete (ends with a blank line)
        if (request.endsWith("\r\n\r\n")) {
          Serial.println("Request: " + request);


       

          if (request.indexOf("GET /?Motor=1") != -1) {

               m1.forward();
          
            
          }else if(request.indexOf("GET /?Motor=2") != -1){

              m1.stop();



          }else if(request.indexOf("GET /?WaterPump=1") != -1){
                //starting fill the tank

                // Check tank water level and stop motor if it exceeds 70%
            int distance = u1.read();
            int tankPercentage = map(distance, 2, 8, 100, 0);
            tankPercentage = constrain(tankPercentage, 0, 100);

          if (tankPercentage >= 70) {
              m2.stop();
              Serial.println("Water level 70% or above. Stopping motor.");
            }else{

               m2.forward();
            }

             

          }else if(request.indexOf("GET /?WaterPump=2") != -1){
                //stop fill the tank
               m2.stop();



          }else if(request.indexOf("GET /?WaterLevel=1") != -1){

                int sensorValue = analogRead(SOIL_MOISTURE_PIN);
  
                // Map the value to a percentage (optional)
                int moisturePercentage = map(sensorValue, 4095, 0, 0, 100);
                
                Serial.print("Raw ADC Value: ");
                Serial.print(sensorValue);
                Serial.print(" | Soil Moisture (%): ");
                Serial.println(moisturePercentage);
                
                
           // Send HTTP response to the client

          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/plain");
          client.println("Connection: close");
          client.println();
           client.println(moisturePercentage);




          }else if(request.indexOf("GET /?TankWaterLevel=1") != -1){

             int distance = u1.read();
            int percentage = map(distance, 2, 8, 100, 0); // Map 2-400cm to 100%-0%
            percentage = constrain(percentage, 0, 100); // Ensure percentage is within range

             if (percentage >= 70) {
                m2.stop();
                Serial.println("Water level 70% or above. Stopping motor.");
              }

            Serial.print("Distance (cm): ");
            Serial.print(distance);
            Serial.print(" | Tank Water Level (%): ");
            Serial.println(percentage);

            // Send HTTP response to the client
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: text/plain");
            client.println("Connection: close");
            client.println();
            client.println(percentage);


          }


     

          break;
        }
      }
    }

    // Close the connection
    client.stop();
    Serial.println("Client disconnected");
  }
}
