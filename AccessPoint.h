#ifndef ACCESSPOINT_H
#define ACCESSPOINT_H

#define MAC_LENGTH 6

#include <string>
#include <cmath>
#include <sstream>
#include <vector>
#include <iwlib.h>

namespace App {
    class AccessPoint {
    public:
        explicit AccessPoint(iwrange* range, wireless_scan* accessPoint);
        ~AccessPoint();

        static std::vector<App::AccessPoint*> ScanForAccessPoints(const std::string& interface);

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
        int channel;
        int mode;
        int security;
        int privacy;
        int cipher;
        double frequency;
        int quality;
        double signal;
        int bandwidth;
        double minSignal;
        double maxSignal;
        long int firstSeen;
        long int lastSeen;
        int vendor;
        int protocol;

        double distance;
    };
}

using App::AccessPoint;

#endif
