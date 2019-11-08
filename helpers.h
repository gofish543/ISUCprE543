#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <vector>
#include <ncurses.h>

#include <libnm/NetworkManager.h>
#include <libnm/nm-dbus-interface.h>

#define SHOW(T, V) do { T x = V; print_bits(#T, #V, (unsigned char*) &x, sizeof(x)); } while(0)

int getChar();
std::string ap_wpa_rsn_flags_to_string(NM80211ApSecurityFlags flags);
std::string ap_flags_to_string(NM80211ApFlags flags, NM80211ApSecurityFlags wpaFlags, NM80211ApSecurityFlags rsnFlags);

void print_byte_as_bits(unsigned char val);
void print_bits(char* ty, char* val, unsigned char* bytes, size_t num_bytes);

#endif
