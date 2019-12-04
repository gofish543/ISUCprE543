#include <cstdio>
#include <algorithm>

#include <glib.h>

#include "helpers.h"
#include "AccessPoint.h"

int main(int argc, char* argv[]) {
    if(argc < 2 || argc > 2) {
        fprintf(stderr, "Please enter the wireless interface\n");
        fprintf(stderr, "Usage Example: \n./ISUCprE543 wlo1\n");
        return 1;
    }
    int userInput = 0;
    int selection = 0;
    struct sigaction signalAction{};
    std::vector<App::AccessPoint*> accessPoints = AccessPoint::ScanForAccessPoints(argv[1]);
    std::sort(accessPoints.begin(), accessPoints.end(), AccessPoint::Compare);
    signalAction.sa_handler = terminate;
    signalAction.sa_flags = 0;

    sigaction(SIGINT, &signalAction, nullptr);
    sigaction(SIGTERM, &signalAction, nullptr);

    AccessPoint::PrintTable(accessPoints, accessPoints.at(selection));
    while (!stop) {
        userInput = getChar();

        if (!stop) {
            switch (userInput) {
                case KEY_UP: // Up arrow
                    selection = std::max(0, selection - 1);
                    break;
                case KEY_DOWN: // Down arrow
                    selection = std::min(int(accessPoints.size() - 1), selection + 1);
                    break;
                case KEY_ENTER: // Enter key
                    accessPoints.at(selection)->listenForTraffic();
                    break;
                default:
                    break;
            }
            AccessPoint::PrintTable(accessPoints, accessPoints.at(selection));
        }
    }

    for (auto& accessPoint : accessPoints) {
        delete accessPoint;
    }

    return 0;
}