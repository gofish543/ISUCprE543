#include <cstdio>
#include <string>
#include <map>
#include <cmath>
#include <iterator>
#include "wifi_scan.h"
#include "AccessPoint.h";

double distance(double signalLevelDb, double frequencyInMHz);

int main(int argc, char* argv[]) {
    std::map<std::string, App::AccessPoint*> accessPoints;

    int status;
    struct bss_info bss[100];
    struct wifi_scan* wifi = wifi_scan_init("wlo1");

    status = wifi_scan_all(wifi, bss, 100);

    for (int index = 0; index < status && index < 20; ++index) {
        auto accessPoint = new AccessPoint(bss[index].ssid, bss[index].bssid, bss[index].signal_mbm / 100.0, bss[index].frequency);
        accessPoints.insert(std::pair<std::string, App::AccessPoint*>(accessPoint->getMacAddressString(), accessPoint));
    }

    wifi_scan_close(wifi);
}

double distance(double signalLevelDb, double frequencyInMHz) {
    double exponent = (27.55 - (20 * std::log10(frequencyInMHz)) + std::abs(signalLevelDb)) / 20.0;

    return std::pow(10.0, exponent);
}