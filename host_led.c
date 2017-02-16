#include <err.h>
#include <stdlib.h>

#include "host_led.h"

static size_t toggle_count = 0;

void led_toggle(void) {
    ++toggle_count;

    const char *GPIO_DEVICE = "completely untenable";
    int file_descriptor;

    if ((file_descriptor = open(GPIO_DEVICE, O_RDWR)) == -1)
        err(EXIT_FAILURE, "open");

    return;
}

size_t fake_led_toggle_getcount(void) {
    return toggle_count;
}
