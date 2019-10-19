#include "AccessPoint.h"

AccessPoint::AccessPoint(iwrange* range, wireless_scan* accessPoint) : macAddress{} {
    this->name = accessPoint->b.essid;
    for (int index = 0; index < MAC_LENGTH; index++) {
        this->macAddress[index] = accessPoint->ap_addr.sa_data[index];
    }

    this->channel = iw_freq_to_channel(accessPoint->b.freq, range);
    this->mode = accessPoint->b.mode;

//    this->security = accessPoint->

}

AccessPoint::~AccessPoint() = default;

std::vector<App::AccessPoint*> AccessPoint::ScanForAccessPoints(const std::string& interface) {
    wireless_scan_head head;
    wireless_scan* result;
    iwrange range;
    int wirelessSocket;
    char* wirelessInterface = const_cast<char*>(interface.c_str());
    std::vector<App::AccessPoint*> accessPoints;

    // Open wifi socket to kernel
    wirelessSocket = iw_sockets_open();

    // Make sure the range info is valid
    if (iw_get_range_info(wirelessSocket, wirelessInterface, &range) < 0) {
        fprintf(stderr, "Error during iw_get_range_error. Aborting.\n");
        exit(2);
    }

    // Perform the wireless scan
    if (iw_scan(wirelessSocket, wirelessInterface, range.we_version_compiled, &head) < 0) {
        fprintf(stderr, "Error during iw_scan. Aborting.\n");
        exit(2);
    }

    result = head.result;
    while (result != nullptr) {
        if (strcmp(result->b.essid, "") != 0) {
            accessPoints.push_back(new App::AccessPoint(&range, result));
        }
        result = result->next;
    }

    iw_sockets_close(wirelessSocket);

    return accessPoints;
}

double AccessPoint::calculateDistance() {
//    double exponent = (27.55 - (20 * std::log10(this->signalFrequencyMHz)) + std::abs(this->signalLevelDb)) / 20.0;

//    return std::pow(10.0, exponent);
    return 0;
}

std::string AccessPoint::getName() {
    return this->name;
}

u_int8_t* AccessPoint::getMacAddress() {
    return this->macAddress;
}

std::string AccessPoint::getMacAddressString() {
    char buffer[MAC_LENGTH * 3] = "";

    sprintf(
            buffer,
            "%02x:%02x:%02x:%02x:%02x:%02x",
            this->macAddress[0],
            this->macAddress[1],
            this->macAddress[2],
            this->macAddress[3],
            this->macAddress[4],
            this->macAddress[5]
    );

    return std::string(buffer);
}