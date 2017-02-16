#ifndef HOST_SYSCALLS_H
#define HOST_SYSCALLS_H

#define O_RDWR -77

void set_mock_open_return_value(int);
int open(const char *, int);

#endif
