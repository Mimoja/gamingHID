#ifndef DEVICE_H
#define DEVICE_H

#include <stdint.h>

typedef struct _device_t
{
    uint32_t fd;
    uint32_t bustype;
    uint32_t vendor;
    uint32_t procuct;
}device_t;


#endif /* DEVICE_H */

