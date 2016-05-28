#include "linux_hidraw.h"

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <linux/types.h>
#include <linux/input.h>
#include <linux/hidraw.h>
#include <sys/ioctl.h>
#include <sys/param.h>

int device_open(const char* path) {

    int fd = open(path, O_RDWR);
    if (fd < 0) {
        perror("open");
    }
    return fd;
}

int device_close(int fd) {
    int ret = close(fd);
    if (ret) {
        perror("close");
    }
    return ret;
}

int device_get_name(int fd, char* buffer, int size) {
    int ret = ioctl(fd, HIDIOCGRAWNAME(size), buffer);
    if (ret < 0) {
        perror("ioctl");
    }
    return ret;
}

int device_get_info(int fd, device_t* device) {
    struct hidraw_devinfo devinfo;

    int ret = ioctl(fd, HIDIOCGRAWINFO, &devinfo);
    if (ret < 0) {
        perror("ioctl");
    }

    device->bustype = devinfo.bustype;
    device->vendor = devinfo.vendor;
    device->procuct = devinfo.product;
    return ret;
}

int device_write(int fd, char* buffer, int size) {
    int ret = write(fd, buffer, size);
    if (ret < 0) {
         perror("write");
    }
    return ret;
}

int device_read(int fd, char *buffer, int size) {
    int ret = read(fd, buffer, size);
    if (ret < 0) {
         perror("read");
    }
    return ret;
}