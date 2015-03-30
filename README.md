# AzureMobileSpark
Library for abstracting Azure Mobile Services REST Api for the Spark.Core.

<a name="resources" />
## Resources ##
https://msdn.microsoft.com/en-us/library/azure/jj710108.aspx

<a name="phase" />
## Phase ##
V1 (Ease of Interaction with Mobile Service Operations)

- Login
- Mobile Service Functionality
- User required to build JSON string

````
	ams.insert("Table", valueString);
````

V2 (Data Enhancement)

- User builds key dictionary, provide simpler posting of data

````
	dictionary.Add("Key", "Value");
	azure.insertdata("table", dictionary);
````

<a name="requirements" />
## Requirements ##
Functionality - Create, Read, Update, Destroy handled using HttpClient

- Create(Table, JSONData)
- Read(Table)
- Update(Table, ID, JSONData)
- Destroy(Table, ID)

Other

- Azure string builder - abstracted away to create connections to service
- Error - receive http codes and act appropriately
- Data - JSON payload builder


Configuration - Mobile Service Name and Mobile Service Key

<a name="implementation" />
## Implementation ##

````C#
#include "HttpClient/HttpClient.h"
#include "AzureMobileService/AzureMobileServices.h"
 
AzureMobileServices ams;
String azureKey = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
String azureUrl = "MyAzureMobileServiceName";
 
int button = D6;
 
void setup() {
	ams.configure(MYSERVICE, MYKEY);
	pinMode(button, INPUT_PULLUP);
}
 
void loop() {
	if (digitalRead(button) == LOW) {
		sendDataToAzure("pushed a button at: " + Time.now());
	}
}
 
void sendDataToAzure(String message) {
	ams.create("TableName", "{\"text\":\"" + message +"\}");
}
````