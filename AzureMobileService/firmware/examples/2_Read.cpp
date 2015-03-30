// This #include statement was automatically added by the Spark IDE.
#include "HttpClient/HttpClient.h"

// This #include statement was automatically added by the Spark IDE.
#include "AzureMobileService.h"

#define MYSERVICE "myservicename"
#define MYKEY "myservicekey"

AzureMobileService ams;

int led = D7;

void setup() {
    Serial.begin(9600);
    delay(10000);
    pinMode(led, OUTPUT);
    ams.configure(MYSERVICE, MYKEY);
}

void loop() {
    delay(5000);
    String table = "Data";

    digitalWrite(led, HIGH);
    
    Serial.println("**************************************************************");
    Serial.println("Reading data from " + table);
    Serial.println("**************************************************************");
    String queryPayload = ams.read(table);
    
    digitalWrite(led, LOW);
}