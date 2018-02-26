/**
 *            ### EMBEDDED SYSTEMS ####
 *
 * In this exercise a driver must be implemented with
 * the functions below:
 *  - open()
 *  - close()
 *  - read()
 *  - write()
 *  - ioctl()
 *
 * @author: Geymerson Ramos
 * @e-mail: geymerson@ic.ufal.br
 * last modified: february 2018
**/

#ifndef DRIVER_H
#define DRIVER_H

#include "accelerometer.h"

status_t open(uint8_t address);
status_t close(uint8_t address);
status_t read(uint8_t *data, uint8_t size);
status_t write(uint8_t *data, uint8_t size);
status_t ioctl(mode_t mode);

uint8_t ChannelIsOpen();

#endif // DRIVER_H
