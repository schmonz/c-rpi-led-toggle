#include <stdio.h>

#include "led.h"

int main(void) {
    fprintf(stderr, "about to toggle the LED\n");
    led_toggle();
}
