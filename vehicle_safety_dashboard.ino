#include <ESP8266WiFi.h>

#include <WiFiClient.h>

#include <ThingSpeak.h>

 

const char* ssid = "__________";

const char* password = "_____________";

 

WiFiClient client;

unsigned long myChannelNumber = 2498598;

const char * myWriteAPIKey = "YDFUBG8HVJYGXWR4";

 

void setup() {

Serial.begin(9600);

pinMode(1, OUTPUT);                             // Sets the trigPin as an OUTPUT

pinMode(2, INPUT);                              // Sets the echoPin as an INPUT                            

pinMode(3, INPUT);

 

// Connect to WiFi network

Serial.println();

Serial.println();

Serial.print("Connecting to ");

Serial.println(ssid);

WiFi.begin(ssid, password);

 

while (WiFi.status() != WL_CONNECTED)

{

delay(500);

Serial.print(".");

}

 

  Serial.println("");

  Serial.println("WiFi connected");

// Print the IP address

  Serial.println(WiFi.localIP());

  ThingSpeak.begin(client);

}

 

void loop() {

int accident_state =0;

Serial.println("~~~~~~~~~~~~~~~ Vehicle Safety System ~~~~~~~~~~~~~~~~~~~~~~");

int dist = 1;

digitalWrite(1, LOW);                     // Clear the trigPin condition

delayMicroseconds(5);                     // Set the trigPin HIGH (ACTIVE)

digitalWrite(1, HIGH);

delayMicroseconds(5);

digitalWrite(1, LOW);                     // Reads the echoPin, returns the sound wave travel time in microseconds

float dur = pulseIn(2, HIGH);             // Calculating the distance

dist = dur * 0.0343 / 2;

Serial.print(dist);

Serial.println(" cm");

int impact = digitalRead(3);

if (impact == 0) { 

  Serial.println("2-wheeler crashed !!!");

  int accident_state = 1;

  delay(5000);

  }

  else {

  int accident_state = 0;

  }

delay(2000);

ThingSpeak.setField(2, impact);

ThingSpeak.setField(1, dist);

ThingSpeak.setField(3, accident_state);

ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

}
