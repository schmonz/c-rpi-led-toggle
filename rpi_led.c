#include <sys/gpio.h>

#include <err.h>
#include <stdlib.h>
#include <string.h>

#include "rpi_led.h"

void
led_toggle(void)
{
    const size_t LED_PIN = 16;
    const char *GPIO_DEVICE = "/dev/gpio0";
    int file_descriptor;
    struct gpio_req request;

    if ((file_descriptor = open(GPIO_DEVICE, O_RDWR)) == -1)
        err(EXIT_FAILURE, "open");

    memset(&request, 0, sizeof(request));
    request.gp_pin = LED_PIN;

    if (ioctl(file_descriptor, GPIOTOGGLE, &request) == -1)
        err(EXIT_FAILURE, "toggle");

    if (close(file_descriptor) == -1)
        err(EXIT_FAILURE, "close");
}
