#include <string>

using namespace std;

class Response
{
private:
    string sHeader;
    string sBody;
    string sResType;
    int iResCode = 0;
    string sResStatus;
    double iLat = 0;
    double iLng = 0;
    double iRadius = 0;
public:
    Response();
    Response(string, string);
};