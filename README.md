# GeoLocation

GeoLocation is a geolocation application on Linux terminal to show the location of the computer running the code.
The solution reveils the latitude and the longitude of the current location as well as an indicator of how accurate that location is, expressed as a radius from the reveiled latitude and the longitude measured in Kms.

## Requirements
After cloning the repository, you need to have the following libraries:
* Google Geolocation API key : [Google Geolocation API](https://developers.google.com/maps/documentation/geolocation/overview).
* libcurl  : ` apt-get install libcurl4-openssl-dev `
* iwlib    : ` apt-get install libiw-dev `
* jsoncons :   [JSONCONS](https://github.com/danielaparker/jsoncons)

## Changes
Before compiling, you have to make the following changes in the code :
In file ` request.h ` :
* ` string key = "GOOGLE GEOLOCATION API" `
Change the value of ` key ` to your Google API key, you can get it from [HERE](https://developers.google.com/maps/documentation/geolocation/overview).
* ` uint32_t homeMobileCountryCode = 0 `
Change the value of ` homeMobileCountryCode ` to your home mobile country code, you can get it from [HERE](https://www.mcc-mnc.com).
* ` uint32_t homeMobileNetworkCode = 0 `
Change the value of ` homeMobileNetworkCode ` to your home mobile network code (mnc), you can get it from [HERE](https://www.mcc-mnc.com).
* ` string radioType = "gsm" `
Change ` radioType ` to the appropriate radio type, but it is commonly ` gsm `.
* ` string carrier = "CARRIER NAME" `
Change ` carrier ` to your carrier name.
* ` bool considerIp = true `
Change ` considerIp ` depending on your conditions, but it is commonly ` true `.
* ` char * interface_name = "WIFI INTERFACE NAME" `
Change ` interface_name ` to your WIFI interface name, open Terminal and run ` ifconfig ` to check.

## Compiling
` g++ *.cpp -lcurl -liw -o GeoLocation `

## Running
` ./GeoLocation `
