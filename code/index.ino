#include <ESP8266WiFi.h>
#include <DHT.h>
#include <ESP8266HTTPClient.h>

#define DHTPIN D4
#define MOISTURE_PIN A0
#define RELAY_PIN D3
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(115200);
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, LOW);
    dht.begin();
    WiFi.begin(ssid, password);
    // connect Wi-Fi
}

void loop() {
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    int rawMoisture = analogRead(MOISTURE_PIN);
    int moisturePct = map(rawMoisture, airValue, waterValue, 0, 100);
    
    if(moisturePct < 25) {
        digitalWrite(RELAY_PIN, HIGH); // Pump ON
        delay(10000);
        digitalWrite(RELAY_PIN, LOW); // Pump OFF
    }
}
