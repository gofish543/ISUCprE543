#include "AccessPoint.h"

AccessPoint::AccessPoint(NMAccessPoint* accessPoint) {
    /* Get AP properties */
    this->ssid = (const GByteArray*) nm_access_point_get_ssid(accessPoint);
    this->bssid = nm_access_point_get_bssid(accessPoint);

    this->flags = nm_access_point_get_flags(accessPoint);
    this->wpaFlags = nm_access_point_get_wpa_flags(accessPoint);
    this->rsnFlags = nm_access_point_get_rsn_flags(accessPoint);

    this->frequency = nm_access_point_get_frequency(accessPoint);
    this->mode = nm_access_point_get_mode(accessPoint);
    this->bitrate = nm_access_point_get_max_bitrate(accessPoint);
    this->strength = nm_access_point_get_strength(accessPoint);
    this->channel = nm_utils_wifi_freq_to_channel(this->frequency);
    this->distance = 0;

    this->path = nm_object_get_path(NM_OBJECT (accessPoint));

    // SSID STRING
    if (this->ssid != nullptr) {
        char* ssidTmp = nm_utils_ssid_to_utf8(this->ssid->data, this->ssid->len);
        this->ssidString = ssidTmp;
        free(ssidTmp);
    } else {
        this->ssidString = "---";
    }

    // BSSID STRING
    if (this->bssid != nullptr) {
        this->bssidString = bssid;
    } else {
        this->bssidString = "---";
    }

    // FLAGS STRING
    this->flagString = ap_flags_to_string(this->flags, this->wpaFlags, this->rsnFlags);
    this->wpaFlagsString = ap_wpa_rsn_flags_to_string(this->wpaFlags);
    this->rsnFlagsString = ap_wpa_rsn_flags_to_string(this->rsnFlags);

    // MODE STRING
    if (mode == NM_802_11_MODE_ADHOC) {
        this->modeString = "Ad-Hoc";
    } else if (mode == NM_802_11_MODE_INFRA) {
        this->modeString = "Infrastructure";
    } else {
        this->modeString = "Unknown";
    }

    // NUMERIC STRINGS
    this->frequencyString = std::to_string(this->frequency) + " MHz";
    this->bitrateString = std::to_string(this->bitrate / 1000) + " MB/s";
    this->strengthString = std::to_string(this->strength);
    this->channelString = std::to_string(this->channel);
    this->distanceString = std::to_string(this->distance) + " m";
}

AccessPoint::~AccessPoint() = default;

void AccessPoint::PrintTable(const std::vector<App::AccessPoint*>& accessPoints, App::AccessPoint* selected = nullptr) {
    fprintf(stdout, "+---+------------+------+---------+------------+----------+----------+\n");
    fprintf(stdout, "|   |    SSID    | MODE | CHANNEL |    RATE    |  SIGNAL  | SECURITY |\n");
    fprintf(stdout, "+---+------------+------+---------+------------+----------+----------+\n");
    for (auto& accessPoint : accessPoints) {
        fprintf(stdout, "| %1s | %10s | %4s | %7s | %10s | %8s | %8s |\n",
                accessPoint == selected ? "*" : " ",
                accessPoint->ssidString.substr(0, 10).c_str(),
                accessPoint->modeString.substr(0, 4).c_str(),
                accessPoint->channelString.substr(0, 7).c_str(),
                accessPoint->bitrateString.substr(0, 10).c_str(),
                accessPoint->strengthString.substr(0, 8).c_str(),
                accessPoint->flagString.substr(0, 8).c_str()
        );
    }
    fprintf(stdout, "+---+------------+------+---------+------------+----------+----------+\n");
}

std::vector<App::AccessPoint*> AccessPoint::ScanForAccessPoints(const char* interface = "wlo1") {
    int index;
    NMClient* nm_client;
    NMDevice* device;
    const GPtrArray* aps;
    NMAccessPoint* accessPoint;
    std::vector<App::AccessPoint*> accessPoints;

    /* Initialize GType system */
    g_type_init();

    /* Get NMClient object */
    nm_client = nm_client_new(nullptr, nullptr);
    if (!nm_client) {
        std::cerr << "Could not create NMClient" << std::endl;
        exit(1);
    }

    device = nm_client_get_device_by_iface(nm_client, interface);
    if (!device || NM_IS_DEVICE_WIFI (device) == FALSE) {
        std::cerr << "The wifi device " << interface << " could not be found" << std::endl;
        exit(1);
    }

    nm_device_wifi_request_scan(NM_DEVICE_WIFI (device), nullptr, nullptr);

    // Wait for the devices to populate, with a max weight of 30 seconds
    index = 0;
    do {
        aps = nm_device_wifi_get_access_points(NM_DEVICE_WIFI(device));
        sleep(1);
        index++;
    } while (aps->len < 2 && index < 30);

    for (index = 0; index < aps->len; index++) {
        if (NM_IS_ACCESS_POINT(g_ptr_array_index(aps, index))) {
            accessPoint = NM_ACCESS_POINT(g_ptr_array_index(aps, index));

            accessPoints.push_back(new App::AccessPoint(accessPoint));
        }
    }

    g_object_unref(nm_client);

    return accessPoints;
}

void AccessPoint::listenForTraffic() {
    int userInput;

    fprintf(stdout, "Access Point: \n");
    fprintf(stdout, "\tSSID:\t\t%s\n", this->ssidString.c_str());
    fprintf(stdout, "\tBSSID:\t\t%s\n", this->bssidString.c_str());
    fprintf(stdout, "\tFlags:\t\t%s\n", this->rsnFlagsString.c_str());
    fprintf(stdout, "\tRSN Flags:\t%s\n", this->rsnFlagsString.c_str());
    fprintf(stdout, "\tWPA Flags:\t%s\n", this->wpaFlagsString.c_str());
    fprintf(stdout, "\tSecurity:\t%s\n", this->securityString.c_str());
    fprintf(stdout, "\tMode:\t\t%s\n", this->modeString.c_str());
    fprintf(stdout, "\tFrequency:\t%s\n", this->frequencyString.c_str());
    fprintf(stdout, "\tChannel:\t%s\n", this->channelString.c_str());
    fprintf(stdout, "\tStrength:\t%s\n", this->strengthString.c_str());
    fprintf(stdout, "\tBit Rate:\t%s\n", this->bitrateString.c_str());
    fprintf(stdout, "\tDistance:\t%s\n", this->distanceString.c_str());

    fprintf(stdout, "\nPress [ Y / N ] to begin packet capture...\n");
    userInput = getChar();

    switch (userInput) {
        case 'y':
        case 'Y':
            fprintf(stdout, "Scanning...\n");
            break;
    }
}

bool AccessPoint::Compare(const App::AccessPoint* a, const App::AccessPoint* b) {
    return a->strength > b->strength;
}

//double AccessPoint::CalculateDistance() {}() {
//    double exponent = (27.55 - (20 * std::log10(this->signalFrequencyMHz)) + std::abs(this->signalLevelDb)) / 20.0;

//    return std::pow(10.0, exponent);
//    return 0;
//}