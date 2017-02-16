#include "host_syscalls.h"

static int mock_open_return_value;
static size_t mock_open_num_calls;
/* #include <fcntl.h> */
int open(const char *path, int oflag, ...) {
    (void)*path;
    (void)oflag;
    ++mock_open_num_calls;
    return mock_open_return_value;
}
void set_mock_open_return_value(int value) {
    mock_open_return_value = value;
}
size_t get_mock_open_calls(void) {
    return mock_open_num_calls;
}

static int mock_ioctl_return_value;
static size_t mock_ioctl_num_calls;
/* #include <sys/ioctl.h> */
int ioctl(int fildes, unsigned long request, ...) {
    (void)fildes;
    (void)request;
    ++mock_ioctl_num_calls;
    return mock_ioctl_return_value;
}
void set_mock_ioctl_return_value(int value) {
    mock_ioctl_return_value = value;
}
size_t get_mock_ioctl_calls(void) {
    return mock_ioctl_num_calls;
}

static int mock_close_return_value;
static size_t mock_close_num_calls;
/* #include <unistd.h> */
int close(int fildes) {
    (void)fildes;
    ++mock_close_num_calls;
    return mock_close_return_value;
}
void set_mock_close_return_value(int value) {
    mock_close_return_value = value;
}
size_t get_mock_close_calls(void) {
    return mock_close_num_calls;
}

void reset_mocks() {
    mock_open_return_value = -1;
    mock_open_num_calls = 0;
    mock_ioctl_return_value = -1;
    mock_ioctl_num_calls = 0;
    mock_close_return_value = -1;
    mock_close_num_calls = 0;
}
