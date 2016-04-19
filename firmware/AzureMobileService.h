#include "application.h"
class AzureMobileService {
    private:
        String _azureServiceURL;
        String _azureKeyValue;
        char _azureKeyChar [100];
        TCPClient _client;
    
    public:
        void configure(String, String);
        uint8_t create(String, String);
        String read(String);
        uint8_t update(String, String, String);
        uint8_t destroy(String, String);
};
