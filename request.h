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
    string key = "AIzaSyBgEbITQW6FzTLU18YLr4uyPRDZv--Cu0g";
    struct curl_slist *list = NULL;
public:
    RequestHeader(CURL *);
};

class RequestBody
{
private:
    json jPostData;
    string sPostData;
    uint32_t homeMobileCountryCode = 212;
    uint32_t homeMobileNetworkCode = 6;
    string radioType = "gsm";
    string carrier = "IAM";
    bool considerIp = true;
    vector<json> APs;
    char * interface_name = "wlx983f9f22b1bf";
public:
    RequestBody();
    RequestBody(CURL *);
    void GetAPs();
};