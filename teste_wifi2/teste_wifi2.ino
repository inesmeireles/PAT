#include <ESP8266wifi.h>

void setup()
{
  Serial.begin(115200);
  Serial.println();

  WiFi.begin("Casa_Santa_Teresinha", "teresinha");

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {}
