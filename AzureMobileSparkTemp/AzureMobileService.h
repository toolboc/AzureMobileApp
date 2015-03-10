#include "application.h"
#include "inttypes.h"

#define NAN 999999
class AzureMobileService {
    private:
        String _azureServiceName;
        String _azureKeyValue;
        TCPClient _client;
        void blinkOnboardLEDonFail();
    
    public:
        void configure(String, String);
        uint8_t create(String, String);
        String read(String, String);
        uint8_t update(String, String);
        uint8_t destroy(String, String);
};