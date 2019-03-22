#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "SSID";
const char* password = "PASSWORD";
 
void setup () {
 
Serial.begin(115200);
WiFi.begin(ssid, password);
 
while (WiFi.status() != WL_CONNECTED) {
 
delay(1000);
Serial.println("Connecting..");
 
}
 
}

void loop() {
 
fireevent();
 
delay(30000);    //Send a request every 30 seconds
 
}

void fireevent()
{
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 
HTTPClient http;  //Declare an object of class HTTPClient
 
http.begin("http://maker.ifttt.com/trigger/dustbin_full/with/key/n74aO1FHoMTsF2Dq-r-S9b2kUWH75VuC90-miOt5rKa");  //Specify request destination
int httpCode = http.GET();                                                                  //Send the request
 Serial.println(httpCode);  
if (httpCode > 0) { //Check the returning code
 
String payload = http.getString();   //Get the request response payload
Serial.println(payload);                     //Print the response payload
 
}
 
http.end();   //Close connection
 
}
}
