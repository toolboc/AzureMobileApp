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

	//send JSON formatted data
	// { "Value1":"1", "Value2":"2", "Value3":"3" }
	char buffer[100];
	snprintf(buffer, sizeof(buffer), "{\"Value1\":\"1\", \"Value2\":\"2\",\"Value\":\"3\"}");

	digitalWrite(led, HIGH);

	//The itemId comes from the ID column in your data table
	String itemId = "1334FB57-293F-4941-BC12-7704D09B9C82";

	Serial.println("**************************************************************");
	Serial.println("Updating itemId " + itemId + " in " + table);
	Serial.println("**************************************************************");
	snprintf(buffer, sizeof(buffer), "{\"Value1\":\"4\", \"Value2\":\"5\",\"Value\":\"6\"}");
	ams.update(table, itemId, buffer);

	digitalWrite(led, LOW);
}