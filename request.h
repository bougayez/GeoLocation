#include <string>
#include <jsoncons/json.hpp>
#include <curl/curl.h>
#include <iwlib.h>
#include <vector>

using namespace std;
using namespace jsoncons;

class RequestHeader
{
private:
    string url = "https://www.googleapis.com/geolocation/v1/geolocate?key=";
    string key = "GOOGLE GEOLOCATION API";
    struct curl_slist *list = NULL;
public:
    RequestHeader(CURL *);
};

class RequestBody
{
private:
    json jPostData;
    string sPostData;
    uint32_t homeMobileCountryCode = -1; // HOME MOBILE COUNTRY CODE
    uint32_t homeMobileNetworkCode = -1; // HOME MOBILE NETWORK CODE
    string radioType = "gsm"; // COMMONLY IT IS gsm
    string carrier = "CARRIER NAME";
    bool considerIp = true; // COMMONLY IT IS true
    vector<json> APs;
    char * interface_name = "WIFI INTERFACE NAME";
public:
    RequestBody();
    RequestBody(CURL *);
    void GetAPs();
};
