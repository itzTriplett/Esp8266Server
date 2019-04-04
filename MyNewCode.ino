#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
 
// Replace with your network credentials
const char* ssid = "sophia-shield-office-qa";
const char* password = "belkin123";
 
ESP8266WebServer server(80);   //instantiate server at port 80 (http port)
 
String page = ""; //Creates the HTML Page
int LEDPin = 2;
void setup(void){
  //the HTML of the web page
  page = "<h1>Joke Server</h1><p><a href=\"joke\"><button>Joke</button></a>&nbsp;<a href=\"punch\"><button>Punchline</button></a></p>";
  //make the LED pin output and initially turned off
  pinMode(LEDPin, OUTPUT);
  digitalWrite(LEDPin, LOW);
   
  delay(1000);
  Serial.begin(115200);
  WiFi.begin(ssid, password); //begin WiFi access point
  Serial.println("");
 
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); 
   
  server.on("/", [](){
    server.send(200, "text/html", page);
  });
  server.on("/joke", [](){
    server.send(200, "text/html","<center> <h1>What do you call an alligator in a vest?</h1></center>");
    
  });
  server.on("/punch", [](){
    server.send(200, "text/html","<center><h1><b>An Investigator!</b></h1> <img src='https://media.giphy.com/media/29HRejgahYenVsohB5/giphy.gif' alt='Trulli' width='500' height='333'></center>");
    
  });
  server.begin();
  Serial.println("Web server started!");
}
 
void loop(void){
  server.handleClient();
}
