/*
Bedside clock using NodeMCU to obtain time from NTP server, and display on multiplexed 7 segment display
*/

#include <ESP8266WiFi.h> //ESP8266 Core WiFi Library (you most likely already have this in your sketch)
#include <ESP8266WebServer.h> //Local WebServer used to serve the configuration portal

#include <WiFiManager.h>


ESP8266WebServer server(80);        // Instantiate server at port 80

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(115200);

  WiFiManager wifiManager;

  wifiManager.setAPCallback(configModeCallback);

  //first parameter is name of access point, second is the password
  wifiManager.autoConnect("CLOCK", "PASSWORD");
  //wifiManager.startConfigPortal ("DK-AP");
}

void configModeCallback(WiFiManager *myWiFiManager)
{
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());

  Serial.println(myWiFiManager->getConfigPortalSSID());
}

void loop()
{
  // put your main code here, to run repeatedly:

}
