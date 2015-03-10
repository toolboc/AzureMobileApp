#include "AzureMobileService.h"

void AzureMobileService::configure(String serviceName, String serviceKey){
    _azureServiceName = serviceName;
    _azureKeyValue = serviceKey;
}

uint8_t AzureMobileService::create(String table, String values){
    String mydomain = "azuremobilespark.azure-mobile.net";
    //char mydomain[100];
    //_azureServiceName.toCharArray(mydomain, 100);
    _client.connect("azuremobilespark.azure-mobile.net", 80);
    blinkOnboardLEDonFail();
    _client.println("POST /tables/" + table + " HTTP/1.1"); 
    _client.println("Host: " + mydomain);
    //if (_azureKeyValue != "")
    //{
    //    _client.println("X-ZUMO-APPLICATION: " + _azureKeyValue);
    //}
    _client.println("Content-Type: application/json");
    _client.print("Content-Length: ");
    _client.println(values.length());
    _client.println(); 
    _client.println(values);
    _client.flush();
    delay(1000);
    _client.stop();
    return 0;
}

String AzureMobileService::read(String, String) {
    return "Not implemented";
}

uint8_t AzureMobileService::update(String, String) {
    return 0;
}

uint8_t AzureMobileService::destroy(String, String) {
    return 0;
}

void AzureMobileService::blinkOnboardLEDonFail(){
    if (!_client.connected()){
        for (int i = 0; i < 5; i++){
            digitalWrite(D7, HIGH);
            delay(500);
            digitalWrite(D7, LOW);
            delay(500);
        }
    }
}