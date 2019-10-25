#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <vector>
#include <ncurses.h>

#include <libnm/NetworkManager.h>
#include <libnm/nm-dbus-interface.h>

int getChar();
std::string ap_wpa_rsn_flags_to_string(NM80211ApSecurityFlags flags);
std::string ap_flags_to_string(NM80211ApFlags flags, NM80211ApSecurityFlags wpaFlags, NM80211ApSecurityFlags rsnFlags);

#endif
