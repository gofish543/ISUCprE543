#include "packets.h"

void reserved(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    fprintf(stdout, "Reserved packet encountered... Skipping packet %p\n\n", packet);
}

void management_association_request(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    fprintf(stdout, "Association Request Not Implemented\n\n");
}

void management_association_response(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    fprintf(stdout, "Association Response Not Implemented\n\n");
}

void management_reassociation_request(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    fprintf(stdout, "Reassociation Request Not Implemented\n\n");
}

void management_reassociation_response(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    fprintf(stdout, "Reassociation Response Not Implemented\n\n");
}

void management_probe_request(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    auto* wifi_frame = (wifi_management_frame*) frame;
    u_int32_t dataSize = packetSize;
    const u_char* start = nullptr;
    char subtype[] = "Probe Request";

    dataSize -= header[2]; // Subtract radio header size
    dataSize -= sizeof(wifi_management_frame); // Subtract size of wifi management frame struct
    dataSize -= 4; // Subtract checksum at end

    start = packet + header[2] + sizeof(wifi_management_frame);

    print_management_frame(wifi_frame, subtype, start, dataSize);
}

void management_probe_response(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    auto* wifi_frame = (wifi_management_frame*) frame;
    u_int32_t dataSize = packetSize;
    const u_char* start = nullptr;
    char subtype[] = "Probe Response";

    dataSize -= header[2]; // Subtract radio header size
    dataSize -= sizeof(wifi_management_frame); // Subtract size of wifi management frame struct
    dataSize -= 4; // Subtract checksum at end

    start = packet + header[2] + sizeof(wifi_management_frame);

    print_management_frame(wifi_frame, subtype, start, dataSize);
}

void management_timing_advertisement(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    fprintf(stdout, "Timing Advertisement Not Implemented\n\n");
}

void management_beacon(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    auto* wifi_frame = (wifi_management_frame*) frame;
    u_int32_t dataSize = packetSize;
    const u_char* start = nullptr;
    char subtype[] = "Beacon";

    dataSize -= header[2]; // Subtract radio header size
    dataSize -= sizeof(wifi_management_frame); // Subtract size of wifi management frame struct
    dataSize -= 4; // Subtract checksum at end

    start = packet + header[2] + sizeof(wifi_management_frame);

    print_management_frame(wifi_frame, subtype, start, dataSize);
}

void management_atim(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    fprintf(stdout, "ATIM not implemented\n\n");
}

void management_disassociation(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    fprintf(stdout, "Disassociation Not Implemented\n\n");
}

void management_authentication(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    auto* wifi_frame = (wifi_management_frame*) frame;
    u_int32_t dataSize = packetSize;
    const u_char* start = nullptr;
    char subtype[] = "Authentication";

    dataSize -= header[2]; // Subtract radio header size
    dataSize -= sizeof(wifi_management_frame); // Subtract size of wifi management frame struct
    dataSize -= 4; // Subtract checksum at end

    start = packet + header[2] + sizeof(wifi_management_frame);

    print_management_frame(wifi_frame, subtype, start, dataSize);
}

void management_deauthentication(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    fprintf(stdout, "De-authentication Not Implemented\n\n");
}

void management_action(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    auto* wifi_frame = (wifi_management_frame*) frame;
    u_int32_t dataSize = packetSize;
    const u_char* start = nullptr;
    char subtype[] = "Action";

    dataSize -= header[2]; // Subtract radio header size
    dataSize -= sizeof(wifi_management_frame); // Subtract size of wifi management frame struct
    dataSize -= 4; // Subtract checksum at end

    start = packet + header[2] + sizeof(wifi_management_frame);

    print_management_frame(wifi_frame, subtype, start, dataSize);
}

void management_nack(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    fprintf(stdout, "NACK Not Implemented\n\n");
}

void control_trigger(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    fprintf(stdout, "Control Trigger Not Implemented\n\n");
}

void control_beamforming(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    fprintf(stdout, "Control Beam Forming Implemented\n\n");
}

void control_vht_he_ndp(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    fprintf(stdout, "Control VHT HE NDP Not Implemented\n\n");
}

void control_frame_extension(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    fprintf(stdout, "Control Frame Extension Not Implemented\n\n");
}

void control_wrapper(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    fprintf(stdout, "Control Wrapper Not Implemented\n\n");
}

void control_bar(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    auto* wifi_frame = (wifi_control_block_ack_request*) frame;
    char subtype[] = "Block Action Request";

    fprintf(stdout, "---------- %s ----------\n", subtype);
    fprintf(stdout, "Version: %u\n", wifi_frame->frameControl & 0b00000011);
    fprintf(stdout, "Type: %s\n", "Control Frame");
    fprintf(stdout, "SubType: %s\n", subtype);
    fprintf(stdout, "Flags: %02X\n", wifi_frame->flags);
    fprintf(stdout, "Duration: %hu\n", wifi_frame->duration);
    fprintf(stdout, "Receiver Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
            wifi_frame->ra[0], wifi_frame->ra[1], wifi_frame->ra[2],
            wifi_frame->ra[3], wifi_frame->ra[4], wifi_frame->ra[5]
    );
    fprintf(stdout, "Transmitter Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
            wifi_frame->ta[0], wifi_frame->ta[1], wifi_frame->ta[2],
            wifi_frame->ta[3], wifi_frame->ta[4], wifi_frame->ta[5]
    );
    fprintf(stdout, "Block Ack Control: 0x%04X\n", wifi_frame->blockAckRequest[0]);
    fprintf(stdout, "Block Ack Starting: 0x%04X\n", wifi_frame->blockAckRequest[1]);
    fprintf(stdout, "\n");
}

void control_ba(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    auto* wifi_frame = (wifi_control_block_ack*) frame;
    char subtype[] = "Block Action";

    fprintf(stdout, "---------- %s ----------\n", subtype);
    fprintf(stdout, "Version: %u\n", wifi_frame->frameControl & 0b00000011);
    fprintf(stdout, "Type: %s\n", "Control Frame");
    fprintf(stdout, "SubType: %s\n", subtype);
    fprintf(stdout, "Flags: %02X\n", wifi_frame->flags);
    fprintf(stdout, "Duration: %hu\n", wifi_frame->duration);
    fprintf(stdout, "Receiver Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
            wifi_frame->ra[0], wifi_frame->ra[1], wifi_frame->ra[2],
            wifi_frame->ra[3], wifi_frame->ra[4], wifi_frame->ra[5]
    );
    fprintf(stdout, "Transmitter Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
            wifi_frame->ta[0], wifi_frame->ta[1], wifi_frame->ta[2],
            wifi_frame->ta[3], wifi_frame->ta[4], wifi_frame->ta[5]
    );
    fprintf(stdout, "Block Ack Control: 0x%04X\n", wifi_frame->blockAckResponse[0]);
    fprintf(stdout, "Block Ack Starting: 0x%04X\n", wifi_frame->blockAckResponse[1]);
    fprintf(stdout, "Block Ack BitMap: ");
    SHOW(u_int64_t, wifi_frame->blockAckBitMap);
    fprintf(stdout, "\n");
}

void control_ps_poll(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    fprintf(stdout, "Control Power Saving Poll Not Implemented\n\n");
}

void control_rts(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    auto* wifi_frame = (wifi_control_rts*) frame;
    char subtype[] = "Request To Send";

    fprintf(stdout, "---------- %s ----------\n", subtype);
    fprintf(stdout, "Version: %u\n", wifi_frame->frameControl & 0b00000011);
    fprintf(stdout, "Type: %s\n", "Control Frame");
    fprintf(stdout, "SubType: %s\n", subtype);
    fprintf(stdout, "Flags: %02X\n", wifi_frame->flags);
    fprintf(stdout, "Duration: %hu\n", wifi_frame->duration);
    fprintf(stdout, "Receiver Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
            wifi_frame->ra[0], wifi_frame->ra[1], wifi_frame->ra[2],
            wifi_frame->ra[3], wifi_frame->ra[4], wifi_frame->ra[5]
    );
    fprintf(stdout, "Transmitter Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
            wifi_frame->ta[0], wifi_frame->ta[1], wifi_frame->ta[2],
            wifi_frame->ta[3], wifi_frame->ta[4], wifi_frame->ta[5]
    );
    fprintf(stdout, "\n");
}

void control_cts(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    auto* wifi_frame = (wifi_control_cts*) frame;
    char subtype[] = "Clear To Send";

    fprintf(stdout, "---------- %s ----------\n", subtype);
    fprintf(stdout, "Version: %u\n", wifi_frame->frameControl & 0b00000011);
    fprintf(stdout, "Type: %s\n", "Control Frame");
    fprintf(stdout, "SubType: %s\n", subtype);
    fprintf(stdout, "Flags: %02X\n", wifi_frame->flags);
    fprintf(stdout, "Duration: %hu\n", wifi_frame->duration);
    fprintf(stdout, "Receiver Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
            wifi_frame->ra[0], wifi_frame->ra[1], wifi_frame->ra[2],
            wifi_frame->ra[3], wifi_frame->ra[4], wifi_frame->ra[5]
    );
    fprintf(stdout, "\n");
}

void control_ack(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    auto* wifi_frame = (wifi_control_ack*) frame;
    char subtype[] = "Request To Send";

    fprintf(stdout, "---------- %s ----------\n", subtype);
    fprintf(stdout, "Version: %u\n", wifi_frame->frameControl & 0b00000011);
    fprintf(stdout, "Type: %s\n", "Control Frame");
    fprintf(stdout, "SubType: %s\n", subtype);
    fprintf(stdout, "Flags: %02X\n", wifi_frame->flags);
    fprintf(stdout, "Duration: %hu\n", wifi_frame->duration);
    fprintf(stdout, "Receiver Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
            wifi_frame->ra[0], wifi_frame->ra[1], wifi_frame->ra[2],
            wifi_frame->ra[3], wifi_frame->ra[4], wifi_frame->ra[5]
    );
    fprintf(stdout, "\n");
}

void control_cf_end(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    fprintf(stdout, "Control Contention Free Not Implemented\n\n");
}

void control_cf_end_cf_ack(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    fprintf(stdout, "Control Contention Free End and Ack Not Implemented\n\n");
}

void data_data(const u_char* header, const u_char* frame, const u_char* packet, bpf_u_int32 packetSize) {
    auto* wifi_frame = (wifi_data_data*) frame;
    char subtype[] = "Data";

    fprintf(stdout, "---------- %s ----------\n", subtype);
    fprintf(stdout, "Version: %u\n", wifi_frame->frameControl >> 6);
    fprintf(stdout, "Type: %s\n", "Data Frame");
    fprintf(stdout, "SubType: %s\n", subtype);
    fprintf(stdout, "Flags: %02X\n", wifi_frame->flags);
    u_int8_t ds = wifi_frame->flags >> 6;
    fprintf(stdout, "To Ds/From Ds: %02b\n", ds);
    fprintf(stdout, "Duration: %hu\n", wifi_frame->duration);
    fprintf(stdout, "Receiver Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
            wifi_frame->addr1[0], wifi_frame->addr1[1], wifi_frame->addr1[2],
            wifi_frame->addr1[3], wif_frame->addr1[4], wifi_frame->addr1[5]
    );
    fprintf(stdout, "Transmitter Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
            wifi_frame->addr2[0], wifi_frame->addr2[1], wifi_frame->addr2[2],
            wifi_frame->addr2[3], wifi_frame->addr2[4], wifi_frame->addr2[5]
    );
    if(ds == 0){
        fprintf(stdout, "Destination Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
                wifi_frame->addr1[0], wifi_frame->addr1[1], wifi_frame->addr1[2],
                wifi_frame->addr1[3], wif_frame->addr1[4], wifi_frame->addr1[5]
        );

        fprintf(stdout, "Source Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
                wifi_frame->addr2[0], wifi_frame->addr2[1], wifi_frame->addr2[2],
                wifi_frame->addr2[3], wifi_frame->addr2[4], wifi_frame->addr2[5]
        );

        fprintf(stdout, "BSSID: %02X:%02X:%02X:%02X:%02X:%02X\n",
                wifi_frame->addr3[0], wifi_frame->addr3[1], wifi_frame->addr3[2],
                wifi_frame->addr3[3], wif_frame->addr3[4], wifi_frame->addr3[5]
        );
    }
    else if(ds == 1){
        fprintf(stdout, "Destination Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
                wifi_frame->addr1[0], wifi_frame->addr1[1], wifi_frame->addr1[2],
                wifi_frame->addr1[3], wif_frame->addr1[4], wifi_frame->addr1[5]
        );

        fprintf(stdout, "Source Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
                wifi_frame->addr3[0], wifi_frame->addr3[1], wifi_frame->addr3[2],
                wifi_frame->addr3[3], wif_frame->addr3[4], wifi_frame->addr3[5]
        );

        fprintf(stdout, "BSSID: %02X:%02X:%02X:%02X:%02X:%02X\n",
                wifi_frame->addr2[0], wifi_frame->addr2[1], wifi_frame->addr2[2],
                wifi_frame->addr2[3], wifi_frame->addr2[4], wifi_frame->addr2[5]
        );
    }
    else if(ds == 2){
        fprintf(stdout, "Destination Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
                wifi_frame->addr3[0], wifi_frame->addr3[1], wifi_frame->addr3[2],
                wifi_frame->addr3[3], wif_frame->addr3[4], wifi_frame->addr3[5]
        );

        fprintf(stdout, "Source Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
                wifi_frame->addr2[0], wifi_frame->addr2[1], wifi_frame->addr2[2],
                wifi_frame->addr2[3], wifi_frame->addr2[4], wifi_frame->addr2[5]
        );

        fprintf(stdout, "BSSID: %02X:%02X:%02X:%02X:%02X:%02X\n",
                wifi_frame->addr1[0], wifi_frame->addr1[1], wifi_frame->addr1[2],
                wifi_frame->addr1[3], wif_frame->addr1[4], wifi_frame->addr1[5]
        );
    }
    else if(ds == 3){
        fprintf(stdout, "Destination Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
                wifi_frame->addr3[0], wifi_frame->addr3[1], wifi_frame->addr3[2],
                wifi_frame->addr3[3], wif_frame->addr3[4], wifi_frame->addr3[5]
        );

        fprintf(stdout, "Source Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
                wifi_frame->addr4[0], wifi_frame->addr4[1], wifi_frame->addr4[2],
                wifi_frame->addr4[3], wifi_frame->addr4[4], wifi_frame->addr4[5]
        );
    }

    fprintf(stdout, "\n");

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
    fprintf(stdout, "DMG Beacon Not Implemented\n\n");
}

void print_management_frame(wifi_management_frame* frame, char* subtype, const u_char* data, u_int32_t size) {
    fprintf(stdout, "---------- %s ----------\n", subtype);
    fprintf(stdout, "Version: %u\n", frame->frameControl & 0b00000011);
    fprintf(stdout, "Type: %s\n", "Management Frame");
    fprintf(stdout, "SubType: %s\n", subtype);
    fprintf(stdout, "Flags: %02X\n", frame->flags);
    fprintf(stdout, "Duration: %u\n", ntohs(frame->duration));
    fprintf(stdout, "Receiver Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
            frame->da[0], frame->da[1], frame->da[2],
            frame->da[3], frame->da[4], frame->da[5]
    );
    fprintf(stdout, "Destination Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
            frame->da[0], frame->da[1], frame->da[2],
            frame->da[3], frame->da[4], frame->da[5]
    );
    fprintf(stdout, "Transmitter Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
            frame->sa[0], frame->sa[1], frame->sa[2],
            frame->sa[3], frame->sa[4], frame->sa[5]
    );
    fprintf(stdout, "Source Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
            frame->sa[0], frame->sa[1], frame->sa[2],
            frame->sa[3], frame->sa[4], frame->sa[5]
    );
    fprintf(stdout, "BSS ID: %02X:%02X:%02X:%02X:%02X:%02X\n",
            frame->bssid[0], frame->bssid[1], frame->bssid[2],
            frame->bssid[3], frame->bssid[4], frame->bssid[5]
    );
    fprintf(stdout, "Fragment Number: %u\n", ntohs(frame->sequence) & 0x000F);
    fprintf(stdout, "Sequence Number: %u\n", (ntohs(frame->sequence) & 0xFFF0) >> 4);

    fprintf(stdout, "Data:");
    for (u_int32_t index = 0; index < size; index++) {
        if (index % 8 == 0) {
            fprintf(stdout, "\n\t");
        }
        if (isprint(data[index])) {
            fprintf(stdout, "%2c", data[index]);
        } else {
            fprintf(stdout, "%02X", data[index]);
        }

        if (index % 8 != 7) {
            fprintf(stdout, " ");
        }
    }
    fprintf(stdout, "\n\n");
}

