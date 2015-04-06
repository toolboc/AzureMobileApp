#include "AzureMobileService/AzureMobileService.h"

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
    
    //The itemId comes from the ID column in your data table
    String itemId = "1334FB57-293F-4941-BC12-7704D09B9C82";
    
    Serial.println("**************************************************************");
    Serial.println("Deleting itemId " + itemId + " in " + table);
    Serial.println("**************************************************************");
    ams.destroy(table, itemId);

    digitalWrite(led, LOW);
}