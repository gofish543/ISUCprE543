#include "packets.h"

void reserved(const u_char* packet) {
    fprintf(stdout, "Reserved packet encountered... Skipping packet %p\n", packet);
}

void management_association_request(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void management_association_response(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void management_reassociation_request(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void management_reassociation_response(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void management_probe_request(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void management_probe_response(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void management_timing_advertisement(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void management_beacon(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void management_atim(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void management_disassociation(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void management_authentication(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void management_deauthentication(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void management_action(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void management_nack(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void control_trigger(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void control_beamforming(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void control_vht_he_ndp(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void control_frame_extension(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void control_wrapper(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void control_bar(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void control_ba(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void control_ps_poll(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void control_rts(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void control_cts(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void control_ack(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void control_cf_end(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void control_cf_end_cf_ack(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void data_data(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void data_data_cf_ack(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void data_data_cf_poll(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void data_data_cf_ack_cf_poll(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void data_null(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void data_cf_ack(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void data_cf_poll(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void data_cf_ack_cf_poll(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void data_qos_data(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void data_qos_data_cf_ack(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void data_qos_data_cf_poll(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void data_qos_data_cf_ack_cf_oll(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void data_qos_null(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void data_qos_cf_poll(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void data_qos_cf_ack_cf_poll(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

void extension_dmg_beacon(const u_char* packet) {
    fprintf(stdout, "Hello World\n");
}

