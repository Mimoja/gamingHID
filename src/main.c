#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "rival_100.h"

int main(int argc, char** argv) {

    device_t dev;
    dev.fd = device_open("/dev/hidraw0");
    char buffer[256];
    device_get_name(dev.fd, buffer, 256);
    printf("%s\n", buffer);

    device_get_info(dev.fd, &dev);
    printf("%d %x %x\n", dev.bustype, dev.vendor, dev.procuct);
    if (rival_100_is_device(dev)) {
        printf("Found Rival 100\n");
        rival_100_set_color(dev, 255, 42, 255);
    }else
        printf("Not a Rival 100\n");
    device_close(dev.fd);
}

