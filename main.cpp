#include "request.h"
#include "response.h"
#include "helpful.h"

#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
  CURL *curl;
  CURLcode res;
  curl = curl_easy_init();
  if(!curl)
  {
    cout << "Error initializing curl. Aborting." << endl;
    exit(2);
  }
  RequestHeader ReqHeader(curl);
  RequestBody ReqBody(curl);
  ReqBody.GetAPs();
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
  res = curl_easy_perform(curl);
  curl_easy_cleanup(curl);
  if(res != CURLE_OK)
  {
    cout << "Error performing request. Aborting.\n";
    exit(2);
  }
  string sResHeader = GetResponseHeader();
  string sResBody = GetResponseBody();
  Response Res(sResHeader, sResBody);
  cout << "HTTP Response code: " << Res.iResCode << endl;
  cout << setprecision(7) << fixed;
  cout << "Latitude: " << Res.iLat << endl;
  cout << "Longitude: " << Res.iLng << endl;
  cout << setprecision(2) << fixed;
  cout << "Radius: " << Res.iRadius << " Kms"<< endl;
  cout << "Check your location on Google MAPS, copy this to your browser: " << endl;
  cout << setprecision(7) << fixed;
  cout << "google.com/maps/@" << Res.iLat << ',' << Res.iLng << ",13z" << endl;
  return 0;
}
