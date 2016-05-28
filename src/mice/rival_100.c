#include <string.h>

#include "rival_100.h"


#define VENDOR  0x1038
#define PRODUCT 0x1702
#define NAME SteelSeries SteelSeries Rival 100 Gaming Mouse

#define CMD_SENSITIVITY   0x03
#define CMD_POLLING       0x04
#define CMD_COLOR         0x05
#define CMD_LIGHT_EFFECT  0x07
#define CMD_SAVE          0x09
#define CMD_BUTTON        0x0B

int rival_100_is_device(device_t device) {
    if (device.vendor == VENDOR && device.procuct == PRODUCT) {
        return 1;
    }
    return 0;
}

int rival_100_set_senitivity(device_t device, int preset, int value) {
    char cmd[3];
    cmd[0] = CMD_SENSITIVITY;
    cmd[1] = preset;
    if (value > RIVAL_100_SENSITIVITY_4000 || value < RIVAL_100_SENSITIVITY_250) {
        if (preset == RIVAL_100_SENSITIVITY_P1)
            cmd[2] = RIVAL_100_SENSITIVITY_1000;
        else
            cmd[2] = RIVAL_100_SENSITIVITY_2000;
    }
    return device_write(device.fd, cmd, 3);
}

int rival_100_set_pollingrate(device_t device, int value) {
    char cmd[2];
    cmd[0] = CMD_POLLING;
    cmd[1] = value;
    if (value > RIVAL_100_POLLING_125 || value < RIVAL_100_POLLING_1000) {
        cmd[1] = RIVAL_100_POLLING_1000;
    }
    return device_write(device.fd, cmd, 2);
}

int rival_100_set_color(device_t device, char red, char green, char blue) {
    char cmd[5];
    cmd[0] = CMD_COLOR;
    cmd[1] = 0x00;
    cmd[2] = red;
    cmd[3] = green;
    cmd[4] = blue;

    return device_write(device.fd, cmd, 5);
}
