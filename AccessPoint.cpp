#include "AccessPoint.h"

AccessPoint::AccessPoint(char* name, const u_int8_t* macAddress, double signalLevelDb, double signalFrequencyMHz) {
    this->name.assign(name);
    for (int index = 0; index < MAC_LENGTH; index++) {
        this->macAddress[index] = macAddress[index];
    }
    this->signalLevelDb = signalLevelDb;
    this->signalFrequencyMHz = signalFrequencyMHz;
    this->distanceMeters = this->calculateDistance();
}

AccessPoint::~AccessPoint() = default;

double AccessPoint::calculateDistance() {
    double exponent = (27.55 - (20 * std::log10(this->signalFrequencyMHz)) + std::abs(this->signalLevelDb)) / 20.0;

    return std::pow(10.0, exponent);
}

std::string AccessPoint::getName() {
    return this->name;
}

u_int8_t* AccessPoint::getMacAddress() {
    return this->macAddress;
}

std::string AccessPoint::getMacAddressString() {
    std::stringstream stream;

    for (int index = 0; index < MAC_LENGTH; index++) {
        stream << std::hex << this->macAddress[index];

        if (index != MAC_LENGTH - 1) {
            stream << ":";
        }
    }

    return stream.str();
}

double AccessPoint::getSignalLevel() {
    return this->signalLevelDb;
}

double AccessPoint::getSignalFrequency() {
    return this->signalFrequencyMHz;
}

double AccessPoint::getDistance() {
    return this->distanceMeters;
}