#include "response.h"

#include <jsoncons/json.hpp>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace jsoncons;

Response::Response(string ResHeader, string ResBody)
{
    sHeader = ResHeader;
    istringstream issHeader(sHeader.substr(0, sHeader.find('\n', 0)));
    issHeader >> sResType >> iResCode >> sResStatus;
    if(iResCode != 200)
    {
        cout << "Response not as expected." << endl;
        cout << "Google API returned error code : " << iResCode << endl;
        cout << "Aborting." << endl;
        exit(2);
    }   
    sBody = ResBody;
    json jResBody = json::parse(sBody.begin(), sBody.end());
    iRadius = jResBody["accuracy"].as<double>() / 1000; // Google API responds in meters
    iLng = jResBody["location"]["lng"].as<double>();
    iLat = jResBody["location"]["lat"].as<double>();
    cout << setprecision(7) << fixed;
    cout << "Latitude: " << iLat << endl;
    cout << "Longitude: " << iLng << endl;
    cout << setprecision(2) << fixed;
    cout << "Radius: " << iRadius << " Kms"<< endl;
    cout << "Check your location on Google MAPS, copy this to your browser : " << endl;
    cout << setprecision(7) << fixed;
    cout << "google.com/maps/@" << iLat << ',' << iLng << ",13z" << endl;
}