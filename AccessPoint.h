#ifndef ACCESSPOINT_H
#define ACCESSPOINT_H

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

#include <pcap.h>

#include <glib.h>
#include <gmodule.h>

#include <libnm/NetworkManager.h>
#include <libnm/nm-client.h>
#include <libnm/nm-device-wifi.h>
#include <libnm/nm-utils.h>

#include "helpers.h"
#include "packets.h"

namespace App {
    class AccessPoint {
    public:
        explicit AccessPoint(const char* interface, NMAccessPoint* accessPoint);
        ~AccessPoint();

        static std::vector<App::AccessPoint*> ScanForAccessPoints(const char* interface);
        static void PrintTable(const std::vector<App::AccessPoint*>& accessPoints, App::AccessPoint* selected);
        static bool Compare(const App::AccessPoint* a, const App::AccessPoint* b);
        static void ProcessPacket(u_char* args, const struct pcap_pkthdr* header, const u_char* packet);

        void listenForTraffic();

        std::string ssidString;
        std::string bssidString;
        std::string flagString;
        std::string rsnFlagsString;
        std::string wpaFlagsString;
        std::string securityString;
        std::string modeString;
        std::string frequencyString;
        std::string channelString;
        std::string strengthString;
        std::string bitrateString;
        std::string distanceString;

    protected:

    private:
        const char* interface;

        const GByteArray* ssid;
        const char* bssid;

        NM80211ApFlags flags;
        NM80211ApSecurityFlags rsnFlags;
        NM80211ApSecurityFlags wpaFlags;
        NM80211Mode mode;

        guint32 frequency;
        guint32 channel;
        gint8 strength;
        guint32 bitrate;
        gdouble distance;

        const char* path;
    };
}

using App::AccessPoint;

#endif
