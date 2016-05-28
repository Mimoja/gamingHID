#ifndef LINUX_HIDRAW_H
#define LINUX_HIDRAW_H

#include <stdint.h>
#include "device.h"

int device_open(const char* path);
int device_close(int fd);
int device_get_name(int fd, char* buffer, int size);
int device_get_info(int fd, device_t* device);
int device_write(int fd, char* buffer, int size);
int device_read(int fd, char *buffer, int size);

#endif /* LINUX_HIDRAW_H */

