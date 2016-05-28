#ifndef RIVAL_100_H
#define RIVAL_100_H

#include "device.h"
#include "linux_hidraw.h"

#define RIVAL_100_SENSITIVITY_P1  0x01
#define RIVAL_100_SENSITIVITY_P2  0x02

#define RIVAL_100_SENSITIVITY_250  0x08
#define RIVAL_100_SENSITIVITY_500  0x07
#define RIVAL_100_SENSITIVITY_1000 0x06
#define RIVAL_100_SENSITIVITY_1250 0x05
#define RIVAL_100_SENSITIVITY_1500 0x04
#define RIVAL_100_SENSITIVITY_1750 0x03
#define RIVAL_100_SENSITIVITY_2000 0x02
#define RIVAL_100_SENSITIVITY_4000 0x01

#define RIVAL_100_POLLING_125  0x04
#define RIVAL_100_POLLING_250  0x03
#define RIVAL_100_POLLING_500  0x02
#define RIVAL_100_POLLING_1000 0x01

int rival_100_is_device(device_t device);
int rival_100_set_color(device_t device, char red, char green, char blue);

#endif /* RIVAL_100_H */

