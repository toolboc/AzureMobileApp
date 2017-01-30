#include "AzureMobileApp.h"

#define MYSERVICE "AzureAppServiceURL"
#define MYKEY "AuthKey(IfEnabled)"

AzureMobileApp ama;

int led = D7;

void setup() {
    Serial.begin(9600);
    delay(10000);
    pinMode(led, OUTPUT);
    ama.configure(MYSERVICE, MYKEY);
}

void loop() {
    delay(5000);
    String table = "Data";

	//send JSON formatted data
	// { "Value1":"1", "Value2":"2", "Value3":"3" }
    char buffer[100];
    snprintf(buffer, sizeof(buffer), "{\"Value1\":\"1\", \"Value2\":\"2\",\"Value3\":\"3\"}");
    
    digitalWrite(led, HIGH);
    
    Serial.println("**************************************************************");
    Serial.println("Publishing data from buffer to AMA");
    Serial.println("**************************************************************");
    ama.create(table, buffer);
    
    digitalWrite(led, LOW);
}
