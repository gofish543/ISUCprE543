#include "helpers.h"

pcap_t* pcapHandle = nullptr;
bool stop = false;

int getChar() {
    int userInput = 0;
    int character = 0;

    while ((character = getchar()) != '\n' && character != EOF) {
        userInput += character;
    }

    switch (userInput) {
        case 183: // Up arrow
            userInput = KEY_UP;
            break;
        case 184: // Down arrow
            userInput = KEY_DOWN;
            break;
        case 185: // Right arrow
            userInput = KEY_RIGHT;
            break;
        case 186: // Left arrow
            userInput = KEY_LEFT;
            break;
        case 0: // Enter key
            userInput = KEY_ENTER;
            break;
        default:
            break;
    }

    return userInput;
}

std::string ap_wpa_rsn_flags_to_string(NM80211ApSecurityFlags flags) {
    std::vector<std::string> flagStrings;
    std::string returnString;

    if (flags & NM_802_11_AP_SEC_PAIR_WEP40)
        flagStrings.emplace_back("pair_wpe40");
    if (flags & NM_802_11_AP_SEC_PAIR_WEP104)
        flagStrings.emplace_back("pair_wpe104");
    if (flags & NM_802_11_AP_SEC_PAIR_TKIP)
        flagStrings.emplace_back("pair_tkip");
    if (flags & NM_802_11_AP_SEC_PAIR_CCMP)
        flagStrings.emplace_back("pair_ccmp");
    if (flags & NM_802_11_AP_SEC_GROUP_WEP40)
        flagStrings.emplace_back("group_wpe40");
    if (flags & NM_802_11_AP_SEC_GROUP_WEP104)
        flagStrings.emplace_back("group_wpe104");
    if (flags & NM_802_11_AP_SEC_GROUP_TKIP)
        flagStrings.emplace_back("group_tkip");
    if (flags & NM_802_11_AP_SEC_GROUP_CCMP)
        flagStrings.emplace_back("group_ccmp");
    if (flags & NM_802_11_AP_SEC_KEY_MGMT_PSK)
        flagStrings.emplace_back("psk");
    if (flags & NM_802_11_AP_SEC_KEY_MGMT_802_1X)
        flagStrings.emplace_back("802.1X");

    if (flagStrings.empty()) {
        return "(none)";
    } else {
        for (auto const& str : flagStrings) {
            returnString += " " + str;
        }

        return returnString.substr(1);
    }
}

std::string ap_flags_to_string(NM80211ApFlags flags, NM80211ApSecurityFlags wpaFlags, NM80211ApSecurityFlags rsnFlags) {
    std::vector<std::string> flagStrings;
    std::string flagString;

    if (!(flags & NM_802_11_AP_FLAGS_PRIVACY)
        && (wpaFlags != NM_802_11_AP_SEC_NONE)
        && (rsnFlags != NM_802_11_AP_SEC_NONE))
        flagStrings.emplace_back("Encrypted:");
    if ((flags & NM_802_11_AP_FLAGS_PRIVACY)
        && (wpaFlags == NM_802_11_AP_SEC_NONE)
        && (rsnFlags == NM_802_11_AP_SEC_NONE))
        flagStrings.emplace_back("WEP");
    if (wpaFlags != NM_802_11_AP_SEC_NONE)
        flagStrings.emplace_back("WPA");
    if (rsnFlags != NM_802_11_AP_SEC_NONE)
        flagStrings.emplace_back("WPA2");
    if ((wpaFlags & NM_802_11_AP_SEC_KEY_MGMT_802_1X)
        || (rsnFlags & NM_802_11_AP_SEC_KEY_MGMT_802_1X))
        flagStrings.emplace_back("Enterprise");

    if (flagStrings.empty()) {
        return "";
    } else {
        for (auto const& str : flagStrings) {
            flagString += " " + str;
        }

        return flagString.substr(1);
    }
}

void print_byte_as_bits(unsigned char val) {
    for (int i = 7; 0 <= i; i--) {
        fprintf(stdout, "%c", (val & (1 << i)) ? '1' : '0');
    }
}

void print_bits(char* ty, char* val, unsigned char* bytes, size_t num_bytes) {
    fprintf(stdout, "[ ");
    for (size_t i = 0; i < num_bytes; i++) {
        print_byte_as_bits(bytes[i]);
        fprintf(stdout, " ");
    }
    fprintf(stdout, "]\n");
}