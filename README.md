# AzureMobileApp #
Library for abstracting Azure Mobile App Easy Tables REST Api for particle.io devices

## Prerequisites ##
- An active [Microsoft Azure](http://azure.com) subscription 
- [Deploy and configure an Easy Table in an Azure App Service Mobile App](https://dzone.com/articles/setting-up-easy-tables-in-azure-app-service-mobile)

## Walkthrough and Tutorial ##

[![Demo](https://sec.ch9.ms/ch9/7701/8d7917b8-624e-49d7-b286-ebaaa2ce7701/TheMakerShowEpisode12ConnectingParticlePhotontoCl_960.jpg)](https://channel9.msdn.com/Shows/themakershow/The-Maker-Show-Episode-12-Connecting-Particle-Photon-to-Cloud-Services)



## Usage ##

Obtain the value for `AzureAppServiceURL` from:

![](http://i.imgur.com/2zED5qM.png)


## Example ##

    #include "AzureMobileApp.h" 
	#define MYSERVICE "AzureAppServiceURL"
	#define MYKEY "AuthKey(IfEnabled)"

	AzureMobileApp ama;
	
	void setup() {
	    Serial.begin(9600);
	    delay(10000);
	    ama.configure(MYSERVICE, MYKEY);
	}

	void loop() 
	{
	    delay(5000);
	    String table = "Data";

		//send JSON formatted data
		// { "Value1":"1", "Value2":"2", "Value3":"3" }

    	char buffer[100];
    	snprintf(buffer, sizeof(buffer), "{\"Value1\":\"1\", \"Value2\":\"2\",\"Value3\":\"3\"}");

    
	    Serial.println("**************************************************************");
	    Serial.println("Publishing data from buffer to AMA");
	    Serial.println("**************************************************************");
	    ama.create(table, buffer);

	    Serial.println("**************************************************************");
	    Serial.println("Reading data from " + table);
	    Serial.println("**************************************************************");
	    String queryPayload = ama.read(table);
		Serial.println queryPayload;

	}
