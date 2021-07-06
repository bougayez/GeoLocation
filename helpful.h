#include <string>

using namespace std;

string readBuffer;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

string GetResponseHeader()
{
    size_t index = readBuffer.find("\n{");
    return  readBuffer.substr(0, index);
}

string GetResponseBody()
{
    size_t index = readBuffer.find("\n{");
    return  readBuffer.substr(index+1, string::npos);
}
