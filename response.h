#include <string>
#include <jsoncons/json.hpp>
#include <sstream>
#include <iostream>

using namespace std;

class Response
{
public:
    string sHeader;
    string sBody;
    string sResType;
    int iResCode = 0;
    string sResStatus;
    double iLat = 0;
    double iLng = 0;
    double iRadius = 0;
    Response();
    Response(string, string);
};
