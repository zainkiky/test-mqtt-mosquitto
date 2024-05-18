#include <WiFi.h>
#include <PubSubClient.h>

// WiFi credentials
const char* ssid = "Marnov_plus";
const char* password = "jujurdanamanah";

// MQTT Broker details
const char* MQTT_SERVER = "test.mosquitto.org";
const int MQTT_PORT = 1883;
const char* ROUTING_KEY = "buattestinimah/nodemcu/v1";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  
  setupWiFi();
  client.setServer(MQTT_SERVER, MQTT_PORT);
  
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");
    if (client.connect("NodeMCUClient")) {
      Serial.println("connected");
    } else {
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }

  // Publish a message
  client.publish(ROUTING_KEY, "Hallow Lagi");
}

void loop() {
  client.loop();
}

void setupWiFi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
