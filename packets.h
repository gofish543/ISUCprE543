#ifndef PACKETS_H
#define PACKETS_H

#include <cstdio>
#include <cctype>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <pcap/bpf.h>

#include "helpers.h"

typedef void (* print_packet)(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);

void reserved(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);

/* 0000 */ void management_association_request(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 0001 */ void management_association_response(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 0010 */ void management_reassociation_request(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 0011 */ void management_reassociation_response(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 0100 */ void management_probe_request(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 0101 */ void management_probe_response(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 0110 */ void management_timing_advertisement(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 0111 */ // reserved
/* 1000 */ void management_beacon(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 1001 */ void management_atim(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 1010 */ void management_disassociation(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 1011 */ void management_authentication(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 1100 */ void management_deauthentication(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 1101 */ void management_action(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 1110 */ void management_nack(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 1111 */ // reserved

/* 0000 */ // reserved
/* 0001 */ // reserved
/* 0010 */ void control_trigger(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 0011 */ // reserved
/* 0100 */ void control_beamforming(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 0101 */ void control_vht_he_ndp(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 0110 */ void control_frame_extension(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 0111 */ void control_wrapper(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 1000 */ void control_bar(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 1001 */ void control_ba(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 1010 */ void control_ps_poll(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 1011 */ void control_rts(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 1100 */ void control_cts(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 1101 */ void control_ack(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 1110 */ void control_cf_end(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 1111 */ void control_cf_end_cf_ack(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);

/* 0000 */ void data_data(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 0001 */ void data_data_cf_ack(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 0010 */ void data_data_cf_poll(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 0011 */ void data_data_cf_ack_cf_poll(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 0100 */ void data_null(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 0101 */ void data_cf_ack(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 0110 */ void data_cf_poll(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 0111 */ void data_cf_ack_cf_poll(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 1000 */ void data_qos_data(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 1001 */ void data_qos_data_cf_ack(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 1010 */ void data_qos_data_cf_poll(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 1011 */ void data_qos_data_cf_ack_cf_oll(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 1100 */ void data_qos_null(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 1101 */ // reserved
/* 1110 */ void data_qos_cf_poll(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 1111 */ void data_qos_cf_ack_cf_poll(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);

/* 0000 */ void extension_dmg_beacon(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize);
/* 0001 - 1111 */ // reserved

static print_packet management_frames[16] = {
        management_association_request, // 0
        management_association_response, // 1
        management_reassociation_request, // 2
        management_reassociation_response, // 3
        management_probe_request, // 4
        management_probe_response, // 5
        management_timing_advertisement, // 6
        reserved, // 7
        management_beacon, // 8
        management_atim, // 9
        management_disassociation, // 10
        management_authentication, // 11
        management_deauthentication, // 12
        management_action, // 13
        management_nack, // 14
        reserved, // 15
};

static print_packet control_frames[16] = {
        reserved, // 0
        reserved, // 1
        control_trigger, // 2
        reserved, // 3
        control_beamforming, // 4
        control_vht_he_ndp, // 5
        control_frame_extension, // 6
        control_wrapper, // 7
        control_bar, // 8
        control_ba, // 9
        control_ps_poll, // 10
        control_rts, // 11
        control_cts, // 12
        control_ack, // 13
        control_cf_end, // 14
        control_cf_end_cf_ack, // 15
};

static print_packet data_frames[16] = {
        data_data, // 0
        data_data_cf_ack, // 1
        data_data_cf_poll, // 2
        data_data_cf_ack_cf_poll, // 3
        data_null, // 4
        data_cf_ack, // 5
        data_cf_poll, // 6
        data_cf_ack_cf_poll, // 7
        data_qos_data, // 8
        data_qos_data_cf_ack, // 9
        data_qos_data_cf_poll,// 10
        data_qos_data_cf_ack_cf_oll,// 11
        data_qos_null,// 12
        reserved,// 13
        data_qos_cf_poll,// 14
        data_qos_cf_ack_cf_poll,// 15
};

static print_packet extension_frames[16] = {
        extension_dmg_beacon, // 0
        reserved, // 1
        reserved, // 2
        reserved, // 3
        reserved, // 4
        reserved, // 5
        reserved, // 6
        reserved, // 7
        reserved, // 8
        reserved, // 9
        reserved, // 10
        reserved, // 11
        reserved, // 12
        reserved, // 13
        reserved, // 14
        reserved, // 15
};

typedef struct wifi_management_frame {
    u_int8_t frameControl;
    u_int8_t flags;
    u_int16_t duration;
//    u_int8_t ra[6]; DA == RA
    u_int8_t da[6];
    // u_int8_t ta[6]; SA == TA
    u_int8_t sa[6];
    u_int8_t bssid[6];
    u_int16_t sequence;
} wifi_management_frame;

typedef struct wifi_control_block_ack_request {
    u_int8_t frameControl;
    u_int8_t flags;
    u_int16_t duration;
    u_int8_t ra[6];
    u_int8_t ta[6];
    u_int16_t blockAckRequest[2];
} wifi_control_block_ack_request;

typedef struct wifi_control_block_ack {
    u_int8_t frameControl;
    u_int8_t flags;
    u_int16_t duration;
    u_int8_t ra[6];
    u_int8_t ta[6];
    u_int16_t blockAckResponse[2];
    u_int64_t blockAckBitMap;
} wifi_control_block_ack;

typedef struct wifi_control_rts {
    u_int8_t frameControl;
    u_int8_t flags;
    u_int16_t duration;
    u_int8_t ra[6];
    u_int8_t ta[6];
} wifi_control_rts;

typedef struct wifi_control_cts {
    u_int8_t frameControl;
    u_int8_t flags;
    u_int16_t duration;
    u_int8_t ra[6];
} wifi_control_cts;

typedef struct wifi_control_ack {
    u_int8_t frameControl;
    u_int8_t flags;
    u_int16_t duration;
    u_int8_t ra[6];
} wifi_control_ack;

typedef struct wifi_data_data {
    u_int8_t frameControl;
    u_int8_t flags;
    u_int16_t duration;
    u_int8_t ra[6];
    u_int8_t ta[6];
    u_int8_t da[6];
    u_int8_t sa[6];
    u_int8_t bssid[6];
    u_int8_t sta[6];
    u_int16_t sequenceNumber;
    u_int64_t ccmp;
} wifi_data_data;

void print_management_frame(wifi_management_frame* frame, char* subtype, const u_char* data, u_int32_t size);
void print_contents(const u_char* data, u_int32_t size);

#endif
