// This #include statement was automatically added by the Spark IDE.
#include "AzureMobileService.h"

#include "DHT.h"
#include "inttypes.h"

#define MYSERVICE "AzureMobileSpark"
#define MYKEY "LhKSxzRgNpXsNnFtwFeyYnmnHFbegL89"
#define DHTPIN D5    // Digital pin D2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
AzureMobileService ams;

int led = D7;
double h;    // humidity
double tc;    // temperature c
double tf; // temperature f

void setup() {
    delay(10000);
    pinMode(led, OUTPUT);
    ams.configure(MYSERVICE, MYKEY);
}

void loop() {
    delay(5000);
    h = dht.readHumidity();
    if (h >= 99999) { h = 0; }
    tc = dht.readTemperature(false);
    tf = dht.readTemperature(true);
    char buffer[100];
    snprintf(buffer, sizeof(buffer), "{\"TempC\":\"%f\", \"TempF\":\"%f\",\"Humidity\":\"%f\"}", tc, tf, h);
    
    digitalWrite(led, HIGH);
    ams.create("DHTData", buffer);
    digitalWrite(led, LOW);
}