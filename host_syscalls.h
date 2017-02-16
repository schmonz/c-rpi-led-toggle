#ifndef HOST_SYSCALLS_H
#define HOST_SYSCALLS_H

#include <stddef.h>

#define GPIOTOGGLE 66
#define O_RDWR -77

struct gpio_req {
    int gp_pin;
};

void reset_mocks(void);

int open(const char *, int, ...);
void set_mock_open_return_value(int);
size_t get_mock_open_calls(void);

int ioctl(int, unsigned long, ...);
void set_mock_ioctl_return_value(int);
size_t get_mock_ioctl_calls(void);

int close(int);
void set_mock_close_return_value(int);
size_t get_mock_close_calls(void);

#endif
