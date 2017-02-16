#include <stddef.h>

#include "host_led.h"

static size_t toggle_count = 0;

void led_toggle(void) {
    ++toggle_count;
    return;
}

size_t fake_led_toggle_getcount(void) {
    return toggle_count;
}
