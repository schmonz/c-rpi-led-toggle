#ifndef HOST_SYSCALLS_H
#define HOST_SYSCALLS_H

#define O_RDWR -77

int open(const char *, int, ...);
void set_mock_open_return_value(int);

int ioctl(int, unsigned long, ...);
void set_mock_ioctl_return_value(int);

int close(int);
void set_mock_close_return_value(int);

#endif
