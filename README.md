# AzureMobileSpark
Library for abstracting Azure Mobile Services REST Api for the Spark.Core.

Resources
*********
https://msdn.microsoft.com/en-us/library/azure/jj710108.aspx

Phase
*****
V1 (Ease of Interaction with Mobile Service Operations) - Login, Mobile Service Functionality, user required to build JSON string
	azure.insert("Table", valueString);
V2 (Data Enhancement) - User builds key dictionary, provide simpler posting of data 
	dictionary.Add("Key", "Value");
	azure.insertdata("table", dictionary);


Requirements
************
Functionality - Create, Read, Insert, Delete handled using TCPClient
	input(table, payload)
* Azure string builder - abstracted away to create connections to service
* Error - receive http codes and act appropriately
* Data - JSON payload builder
Configuration - Mobile Server address and Mobile Service


Implementation
**************
#include "Azure/AzureMobileServices.h"
 
AzureMobileServices azure = AzureMobileServices();
String azureKey = "xxxxxxxxxxxx";
String azureUrl = "https://mysparkhack.azure-mobile.net";
 
int button = D6;
 
void setup() {
azure.login(azureKey, azureUrl);
 
pinMode(button, INPUT_PULLUP);
}
 
void loop() {
if (digitalRead(button) == LOW) {
sendDataToAzure("pushed a button at: " + Time.now());
}
}
 
void sendDataToAzure(String message) {
// azure.insert(table, object) - using SparkJson/SparkJson.h
azure.insert("Table1", "{\"text\":\"" + message +"\}");
}

