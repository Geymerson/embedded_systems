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

#include "driver.h"

//__isOpen = 1 indicates that a communication channel is open
//__isOpen = 0 indicates that there is no communication channels open
static uint8_t __isOpen = 0;

//Return a value indicating
//if the channel is open
uint8_t ChannelIsOpen() {
    return __isOpen;
}

//address = 0xE3 to open
status_t open(uint8_t address) {
    if(accelerometerWrite(address) == fail) {
        return fail;
    }
    __isOpen = 1;
    return ok;
}

//address = 0xE3 to close
status_t close(uint8_t address) {
    if(accelerometerWrite(address) == fail) {
        return fail;
    }
    __isOpen = 0;
    return ok;
}

//Sample accelerometer data
status_t read(uint8_t *data, uint8_t size) {
    //Check if the communication channel is already open
    uint8_t channelState = ChannelIsOpen();
    if(channelState) { close(0xE3); }
    status_t status = ok;

    for(int i = 0; i < size; i++) {
        //open communication
        open(0xE3);
        //enter reading mode
        accelerometerWrite(0x21);
        //request readings from accelerometer
        accelerometerWrite(0xC3);
        if(accelerometerRead(&data[i]) == fail) {
            status = fail;
        }
        //close communication
        close(0xE3);
    }

    //If the channel was open
    //restore it to the previous state
    if(channelState) { open(0xE3); }
    return status;
}

//Write something to the accelerometer
status_t write(uint8_t *data, uint8_t size) {
    //Check if the communication channel is already open
    uint8_t channelState = ChannelIsOpen();
    if(channelState) { close(0xE3); }
    status_t status = ok;

    for(int i = 0; i < size; i++) {
        //open communication
        open(0xE3);
        //enter reading mode
        accelerometerWrite(0x31);
        //request acceleration readings
        accelerometerWrite(0xC3);
        if(accelerometerWrite(data[i]) == fail) {
            status = fail;
        }
        //close communication
        close(0xE3);
    }

    //If the channel was open
    //restore it to the previous state
    if(channelState) { open(0xE3); }
    return status;
}

// 0x00 = low power | 0x01 = run
status_t ioctl(mode_t mode) {
    //User must open the channel
    //before set operation mode
    if(!ChannelIsOpen()) {
        return fail;
    }
    //enter writing mode
    accelerometerWrite(0x31);
    //enter operation selection mode
    accelerometerWrite(0xB3);
    //set the desired mode
    return accelerometerWrite(mode);
}

