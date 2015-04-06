#include "AzureMobileService/AzureMobileService.h"

#define MYSERVICE "PoweredByAzure"
#define MYKEY "SecretKey"

AzureMobileService ams;

int led = D7;
bool sent = false;


void setup() {
    Serial.begin(9600);
    delay(10000);
    pinMode(led, OUTPUT);
    ams.configure(MYSERVICE, MYKEY);
}

void loop() {
    delay(5000);
    String table = "AzureFirst";

	//send JSON formatted data
	// { "SchoolName":"Microsoft", "TeamName":"DX at First", "TeamNumber":"0", "City": "St. Louis", "State":"MO", "Message":"Hello World!" }
	char* SchoolName = "SchoolName";
	char* TeamName = "TeamName";
	char* TeamNumber = "0000";
	char* City = "CityName";
	char* State = "ST";
	char* Message = "We are Powered By Azure";
	
	char buffer[1000];
    snprintf(buffer, sizeof(buffer), "{ \"SchoolName\":\"%s\", \"TeamName\":\"%s\", \"TeamNumber\":\"%s\", \"City\":\"%s\", \"State\":\"%s\", \"Message\":\"%s\"}", SchoolName, TeamName, TeamNumber, City, State, Message );
    
    digitalWrite(led, HIGH);
    if (sent == false)
    {
        Serial.println("**************************************************************");
        Serial.println("Publishing data from buffer to AMS");
        Serial.println("**************************************************************");
        uint8_t retVal = 0;
        retVal = ams.create(table, buffer);
        if (retVal == 201)
        {
            sent = true;
        }
    }
    digitalWrite(led, LOW);
}