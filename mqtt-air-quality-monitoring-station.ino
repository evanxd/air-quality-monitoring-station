#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define WIFI_SSID           "ssid"
#define WIFI_PASSWORD       "password"
#define MQTT_SERVER_ADDRESS "broker.mqtt-dashboard.com"
#define MQTT_SERVER_PORT    1883
#define MQTT_CLIENT_ID      "clientId"
#define MQTT_TOPIC          "topic"
#define MESSAGE_LENGTH      50

WiFiClient wifiClient;
PubSubClient client(wifiClient);
char message[MESSAGE_LENGTH];
unsigned int pm1_0 = 0;
unsigned int pm2_5 = 0;
unsigned int pm10_0 = 0;

void setup() {
  Serial.begin(9600);
  client.setServer(MQTT_SERVER_ADDRESS, MQTT_SERVER_PORT);
}

void loop() {
  connectWifi();
  connectMqttServer();

  char value;
  char previousValue;
  for (int i = 0; Serial.available(); i++) {
    value = Serial.read();
    if ((i == 0 && value != 0x42) || (i == 1 && value != 0x4D)){
      Serial.println("Cannot find the data header.");
      return;
    }
    if (i == 4 || i == 6 || i == 8 || i == 10 || i == 12 || i == 14) {
      previousValue = value;
    } else if (i == 5) {
      pm1_0 = 256 * previousValue + value;
    } else if (i == 7) {
      pm2_5 = 256 * previousValue + value;
    } else if (i == 9) {
      pm10_0 = 256 * previousValue + value;
    } else if (i >= 15) {
      Serial.read();
    }
  }

  snprintf(message, MESSAGE_LENGTH, "{ \"pm1_0\": %ld, \"pm2_5\": %ld, \"pm10_0\": %ld }",
    pm1_0, pm2_5, pm10_0);
  Serial.println(message);
  client.publish(MQTT_TOPIC, message);
  delay(2000);
}

void connectWifi() {
  if (WiFi.status() == WL_CONNECTED) {
    return;
  }
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void connectMqttServer() {
  while (!client.connected()) {
    if (!client.connect(MQTT_CLIENT_ID)) {
      delay(5000);
    }
  }
  client.loop();
}
