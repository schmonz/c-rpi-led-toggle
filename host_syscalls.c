#include "host_syscalls.h"

static int mock_open_return_value;
/* #include <fcntl.h> */
int open(const char *path, int oflag, ...) {
    (void)*path;
    (void)oflag;
    return mock_open_return_value;
}
void set_mock_open_return_value(int value) {
    mock_open_return_value = value;
}

static int mock_ioctl_return_value;
/* #include <sys/ioctl.h> */
int ioctl(int fildes, unsigned long request, ...) {
    (void)fildes;
    (void)request;
    return mock_ioctl_return_value;
}
void set_mock_ioctl_return_value(int value) {
    mock_ioctl_return_value = value;
}

static int mock_close_return_value;
/* #include <unistd.h> */
int close(int fildes) {
    (void)fildes;
    return mock_close_return_value;
}
void set_mock_close_return_value(int value) {
    mock_close_return_value = value;
}
