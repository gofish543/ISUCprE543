#include "packets.h"

void reserved(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    fprintf(stdout, "Reserved packet encountered... Skipping packet %p\n", packet);
}

void management_association_request(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void management_association_response(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void management_reassociation_request(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void management_reassociation_response(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void management_probe_request(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    auto* wifi_frame = (wifi_management_frame*) frame;
    u_int32_t dataSize = packetSize;
    const u_char* start = nullptr;

    dataSize -= header[2]; // Subtract radio header size
    dataSize -= sizeof(wifi_management_frame); // Subtract size of wifi management frame struct
    dataSize -= 4; // Subtract checksum at end

    start = packet + header[2] + sizeof(wifi_management_frame);
    
    fprintf(stdout, "---------- PROBE REQUEST ----------\n");
    fprintf(stdout, "Packet Size: %d\n", packetSize);
    fprintf(stdout, "Version: %u\n", wifi_frame->frameControl & 0b00000011);
    fprintf(stdout, "Type: %s\n", "Management Frame");
    fprintf(stdout, "SubType: %s\n", "Probe Request");
    fprintf(stdout, "Duration: %u\n", ntohs(wifi_frame->duration));
    fprintf(stdout, "Receiver Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
            wifi_frame->da[0], wifi_frame->da[1], wifi_frame->da[2],
            wifi_frame->da[3], wifi_frame->da[4], wifi_frame->da[5]
    );
    fprintf(stdout, "Destination Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
            wifi_frame->da[0], wifi_frame->da[1], wifi_frame->da[2],
            wifi_frame->da[3], wifi_frame->da[4], wifi_frame->da[5]
    );
    fprintf(stdout, "Transmitter Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
            wifi_frame->sa[0], wifi_frame->sa[1], wifi_frame->sa[2],
            wifi_frame->sa[3], wifi_frame->sa[4], wifi_frame->sa[5]
    );
    fprintf(stdout, "Source Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
            wifi_frame->sa[0], wifi_frame->sa[1], wifi_frame->sa[2],
            wifi_frame->sa[3], wifi_frame->sa[4], wifi_frame->sa[5]
    );
    fprintf(stdout, "BSS ID: %02X:%02X:%02X:%02X:%02X:%02X\n",
            wifi_frame->bssid[0], wifi_frame->bssid[1], wifi_frame->bssid[2],
            wifi_frame->bssid[3], wifi_frame->bssid[4], wifi_frame->bssid[5]
    );
    fprintf(stdout, "Fragment Number: %u\n", ntohs(wifi_frame->sequence) & 0x000F);
    fprintf(stdout, "Sequence Number: %u\n", (ntohs(wifi_frame->sequence) & 0xFFF0) >> 4);

    fprintf(stdout, "Data:");
    for (u_int32_t index = 0; index < dataSize; index++) {
        if (index % 8 == 0) {
            fprintf(stdout, "\n\t");
        }
        if (isprint(start[index])) {
            fprintf(stdout, "%2c", start[index]);
        } else {
            fprintf(stdout, "%02X", start[index]);
        }

        if (index % 8 != 7) {
            fprintf(stdout, " ");
        }
    }
    fprintf(stdout, "\n");
    fprintf(stdout, "---------- PROBE REQUEST ----------\n");
}

void management_probe_response(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void management_timing_advertisement(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void management_beacon(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void management_atim(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void management_disassociation(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void management_authentication(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void management_deauthentication(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void management_action(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void management_nack(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void control_trigger(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void control_beamforming(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void control_vht_he_ndp(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void control_frame_extension(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void control_wrapper(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void control_bar(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void control_ba(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void control_ps_poll(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void control_rts(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void control_cts(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void control_ack(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void control_cf_end(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void control_cf_end_cf_ack(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void data_data(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void data_data_cf_ack(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void data_data_cf_poll(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void data_data_cf_ack_cf_poll(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void data_null(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void data_cf_ack(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void data_cf_poll(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void data_cf_ack_cf_poll(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void data_qos_data(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void data_qos_data_cf_ack(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void data_qos_data_cf_poll(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void data_qos_data_cf_ack_cf_oll(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void data_qos_null(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void data_qos_cf_poll(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void data_qos_cf_ack_cf_poll(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

void extension_dmg_beacon(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {

}

