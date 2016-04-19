#include "AzureMobileApp/AzureMobileApp.h"

#define MYSERVICE "myservicename"
#define MYKEY "myservicekey"

AzureMobileApp ams;

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

	//send JSON formatted data
	// { "Value1":"1", "Value2":"2", "Value3":"3" }
    char buffer[100];
    snprintf(buffer, sizeof(buffer), "{\"Value1\":\"1\", \"Value2\":\"2\",\"Value\":\"3\"}");
    
    digitalWrite(led, HIGH);
    
    Serial.println("**************************************************************");
    Serial.println("Publishing data from buffer to AMS");
    Serial.println("**************************************************************");
    ams.create(table, buffer);
    
    digitalWrite(led, LOW);
}
