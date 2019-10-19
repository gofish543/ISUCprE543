#include <vector>
#include <iostream>
#include "AccessPoint.h"

#define WIRELESS_INTERFACE "wlo1"

int main(int argc, char* argv[]) {
    std::vector<App::AccessPoint*> accessPoints = AccessPoint::ScanForAccessPoints(WIRELESS_INTERFACE);

    for (int index = 0; index < accessPoints.size(); index++) {
        delete accessPoints[index];
    }

    return 0;
}