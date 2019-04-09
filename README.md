# How to Connect to an Access Point 
## Getting Started
1. Open your Arduino Sketch page and paste in the following code: 
     ```ino
     #include <ESP8266WiFi.h>
     #include <ESP8266WebServer.h>
     ```
- Begin by adding the necessary libraries using the #include directive at the top of the page.

## Connecting to the Access Point

2. Put the name of the network you want to connect to inplace of “SSID NAME” and do the same with the password of that network on the following line. 
```ino
const char* ssid = "SSID NAME"
const char* password = "PASSWORD"

ESP8266WebServer server(80);
```

## Coding Your Web Server

3. Next create a void setup function and paste in the below code to start the connection to your network

```ino
void setup()
{
  pinMode(pin_led, OUTPUT);
  WiFi.begin(ssid,password);
  Serial.begin(115200);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  ```
## Coding Your Web Server 
###### (cont.)

4. On the lines that follow paste in the serial print methods so you can call for your device’s IP Address. 
5. Then you can begin writing the code for your web server. For now we’ll just display the message “Hello World!” 
```ino
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/",[](){server.send(200,"text/plain","Hello World!");});
  server.begin();
}

void loop()
{
  server.handleClient();
}
```
## The Ending Code 
6. Once you’ve pasted in all the code from the previous slides your end result should mirror the code below. If it does you can go ahead and upload your code to the board. 
```ino
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server;
uint8_t pin_led = 16;
char* ssid = "sophia-shield-office-qa";
char* password = "belkin123";

void setup()
{
  pinMode(pin_led, OUTPUT);
  WiFi.begin(ssid,password);
  Serial.begin(115200);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/",[](){server.send(200,"text/plain","Hello World!");});
  server.begin();
}

void loop()
{
  server.handleClient();
}
```
## Getting to Your Web Server!

![Screen Shot 2019-04-09 at 1 48 15 PM](https://user-images.githubusercontent.com/25018497/55834597-28c15600-5acf-11e9-9a7b-dd0e021bec8e.png)
