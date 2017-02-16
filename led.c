#include <string.h>

#include "led.h"
#include "syscalls.h"

void
led_toggle(void)
{
    const size_t LED_PIN = 16;
    const char *GPIO_DEVICE = "/dev/gpio0";
    int file_descriptor;
    struct gpio_req request;

    if ((file_descriptor = open(GPIO_DEVICE, O_RDWR)) == -1)
        return;

    memset(&request, 0, sizeof(request));
    request.gp_pin = LED_PIN;

    if (ioctl(file_descriptor, GPIOTOGGLE, &request) == -1)
        return;

    if (close(file_descriptor) == -1)
        return;
}
