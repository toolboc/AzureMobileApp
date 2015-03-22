// This #include statement was automatically added by the Spark IDE.
#include "HttpClient.h"

// This #include statement was automatically added by the Spark IDE.
#include "HttpClient.h"

// This #include statement was automatically added by the Spark IDE.
#include "AzureMobileService.h"

#define MYSERVICE "amsspark"
#define MYKEY "ossZtVoHrixTiOugoEsmfcqNKjKBqu22"

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

    char buffer[100];
    snprintf(buffer, sizeof(buffer), "{\"Value1\":\"1\", \"Value2\":\"2\",\"Value\":\"3\"}");
    
    digitalWrite(led, HIGH);
    
    String table = "Data";
    String itemId = "1334FB57-293F-4941-BC12-7704D09B9C82";
    
    Serial.println("**************************************************************");
    Serial.println("Publishing data from buffer to AMS");
    Serial.println("**************************************************************");
    ams.create(table, buffer);
    
    Serial.println("**************************************************************");
    Serial.println("Reading data from " + table);
    Serial.println("**************************************************************");
    String queryPayload = ams.read(table);
    
    Serial.println("**************************************************************");
    Serial.println("Updating itemId " + itemId + " in " + table);
    Serial.println("**************************************************************");
    snprintf(buffer, sizeof(buffer), "{\"Value1\":\"4\", \"Value2\":\"5\",\"Value\":\"6\"}");
    ams.update(table, itemId, buffer);
    
    Serial.println("**************************************************************");
    Serial.println("Deleting itemId " + itemId + " in " + table);
    Serial.println("**************************************************************");
    ams.destroy(table, itemId);

    digitalWrite(led, LOW);
}