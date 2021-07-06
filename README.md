# GeoLocation

GeoLocation is a geolocation application on Linux to show the location of the computer running the code.
The solution reveils the latitude and the longitude of the current location as well as an indicator of how accurate that location is, expressed as a radius from the reveiled latitude and the longitude measured in Kms.

## Requirements
Before compiling, you need to have the following libraries:
libcurl  : apt-get install libcurl4-openssl-dev
iwlib    : apt-get install libiw-dev
jsoncons : github.com/danielaparker/jsoncons

## Compiling
sudo g++ *.cpp -lcurl -liw -o GeoLocation

## Running
./GeoLocation
