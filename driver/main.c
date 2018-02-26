#include <stdio.h>
#include "driver.h"

int main() {
    uint8_t size = 10;
    uint8_t data[size];
    read(data, size);

    for (int var = 0; var < size; ++var) {
        printf("reading: %d\n", data[var]);
    }
    return 0;
}

