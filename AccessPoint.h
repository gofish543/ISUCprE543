#ifndef ACCESSPOINT_H
#define ACCESSPOINT_H

#define MAC_LENGTH 6

#include <string>
#include <cmath>
#include <sstream>

namespace App {
    class AccessPoint {
    public:
        AccessPoint(char* name, const u_int8_t* macAddress, double signalLevelDb, double signalFrequencyMHz);
        ~AccessPoint();

        /** GETTERS **/
        std::string getName();
        u_int8_t* getMacAddress();
        std::string getMacAddressString();
        double getSignalLevel();
        double getSignalFrequency();
        double getDistance();
        /** GETTERS **/

    protected:

        double calculateDistance();

    private:
        std::string name;
        u_int8_t macAddress[MAC_LENGTH];

        double signalLevelDb;
        double signalFrequencyMHz;
        double distanceMeters;
    };
}

using App::AccessPoint;

#endif
