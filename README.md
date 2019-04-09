### How to Connect to an Access Point 
## Getting Started
1. Open your Arduino Sketch page and write in the following code: 
     ```
     #include <ESP8266WiFi.h>
     #include <WiFiClient.h>
     #include <ESP8266WebServer.h>
     ```
- Begin by adding the necessary libraries using the #include directive at the top of the page.

## Connecting to the Access Point

2. Put the name of the network you want to connect to inplace of “SSID NAME” and do the same with the password of that network on the following line. 
```
const char* ssid = "SSID NAME"
const char* password = "PASSWORD"

ESP8266WebServer server(80);
```

