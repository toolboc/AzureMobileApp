#include "AzureMobileApp.h"
#include "HttpClient.h"

void AzureMobileApp::configure(String serviceURL, String serviceKey){
    _azureserviceURL = serviceURL;
    _azureKeyValue = serviceKey;
    _azureKeyValue.toCharArray(_azureKeyChar, 100);
}

uint8_t AzureMobileApp::create(String table, String values){
    
    HttpClient http;
    
    http_header_t headers[] = {
        { "X-ZUMO-APPLICATION", _azureKeyChar },
        { "Content-Type", "application/json" },
        { NULL, NULL } // NOTE: Always terminate headers with NULL
    };
    
    http_request_t request;
    http_response_t response;
    
    request.hostname = _azureserviceURL;
    request.port = 80;
    request.path = "/tables/" + table;
    request.body = values;

    http.post(request, response, headers);
    Serial.print("Application>\tResponse status: ");
    Serial.println(response.status);

    Serial.print("Application>\tHTTP Response Body: ");
    Serial.println(response.body);

    return response.status;
}

String AzureMobileApp::read(String table) {
    
    HttpClient http;
    
    http_header_t headers[] = {
        { "X-ZUMO-APPLICATION", _azureKeyChar },
        { "Content-Type", "application/json" },
        { NULL, NULL } // NOTE: Always terminate headers with NULL
    };
    
    http_request_t request;
    http_response_t response;
    
    request.hostname = _azureserviceURL;
    request.port = 80;
    request.path = "/tables/" + table;

    http.get(request, response, headers);
    Serial.print("Application>\tResponse status: ");
    Serial.println(response.status);

    Serial.print("Application>\tHTTP Response Body: ");
    Serial.println(response.body);

    return response.body;
}

uint8_t AzureMobileApp::update(String table, String itemId, String values) {

	//The "patch" method has not been completely accepted in the HttpClient
	//This method will not work until that has been updated
	
    HttpClient http;
    
    http_header_t headers[] = {
        { "X-ZUMO-APPLICATION", _azureKeyChar },
        { "Content-Type", "application/json" },
        { NULL, NULL } // NOTE: Always terminate headers with NULL
    };
    
    http_request_t request;
    http_response_t response;
    
    request.hostname = _azureserviceURL;
    request.port = 80;
    request.path = "/tables/" + table + "/" + itemId;
    request.body = values;

    http.patch(request, response, headers);
    Serial.print("Application>\tResponse status: ");
    Serial.println(response.status);

    Serial.print("Application>\tHTTP Response Body: ");
    Serial.println(response.body);

    return response.status;
}

uint8_t AzureMobileApp::destroy(String table, String itemId) {
        
    HttpClient http;
    
    http_header_t headers[] = {
        { "X-ZUMO-APPLICATION", _azureKeyChar },
        { "Content-Type", "application/json" },
        { NULL, NULL } // NOTE: Always terminate headers with NULL
    };
    
    http_request_t request;
    http_response_t response;
    
    request.hostname = _azureserviceURL;
    request.port = 80;
    request.path = "/tables/" + table + "/" + itemId;

    http.del(request, response, headers);
    Serial.print("Application>\tResponse status: ");
    Serial.println(response.status);

    Serial.print("Application>\tHTTP Response Body: ");
    Serial.println(response.body);

    return response.status;
}

