#include "host_syscalls.h"

static int mock_open_return_value;

void set_mock_open_return_value(int value) {
    mock_open_return_value = value;
}

/* #include <fcntl.h> */
int open(const char *path, int oflag) {
    (void)*path;
    (void)oflag;
    return mock_open_return_value;
}
