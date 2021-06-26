#include <iostream>
#include <string>
#include <curl/curl.h>
#include <jsoncons/json.hpp>
#include "wlanapi/wlanapi.h"

using namespace std;
using namespace jsoncons;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main(void)
{
  CURL *curl;
  CURLcode res;
  string readBuffer;
  string url = "https://www.googleapis.com/geolocation/v1/geolocate?key=";
  string key = "AIzaSyBgEbITQW6FzTLU18YLr4uyPRDZv--Cu0g";
  url += key;
  struct curl_slist *list = NULL;
  list = curl_slist_append(list, "Content-Type: application/json");
  uint32_t homeMobileCountryCode = 212;
  uint32_t homeMobileNetworkCode = 6;
  string radioType = "gsm";
  string carrier = "IAM";
  bool considerIp = true;
  json post_data;
  post_data.insert_or_assign("homeMobileCountryCode", homeMobileCountryCode);
  post_data.insert_or_assign("homeMobileNetworkCode", homeMobileNetworkCode);
  post_data.insert_or_assign("radioType", radioType);
  post_data.insert_or_assign("carrier", carrier);
  post_data.insert_or_assign("considerIp", considerIp);

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, post_data.size());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    std::cout << readBuffer << std::endl;
  }
  return 0;
}