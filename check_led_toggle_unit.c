#include <check.h>

#include "led.h"
#include "syscalls.h"

START_TEST(test_led_does_not_toggle_or_close_when_open_fails) {
    set_mock_open_return_value(-1);

    led_toggle();

    ck_assert_int_eq(get_mock_open_calls(), 1);
    ck_assert_int_eq(get_mock_ioctl_calls(), 0);
    ck_assert_int_eq(get_mock_close_calls(), 0);
} END_TEST

START_TEST(test_led_does_not_close_when_toggle_fails) {
    set_mock_open_return_value(5);
    set_mock_ioctl_return_value(-1);

    led_toggle();

    ck_assert_int_eq(get_mock_open_calls(), 1);
    ck_assert_int_eq(get_mock_ioctl_calls(), 1);
    ck_assert_int_eq(get_mock_close_calls(), 0);
} END_TEST

START_TEST(test_led_toggle_happy_path) {
    set_mock_open_return_value(5);
    set_mock_ioctl_return_value(5);
    set_mock_close_return_value(5);

    led_toggle();

    ck_assert_int_eq(get_mock_open_calls(), 1);
    ck_assert_int_eq(get_mock_ioctl_calls(), 1);
    ck_assert_int_eq(get_mock_close_calls(), 1);
} END_TEST

void setup(void) {
    reset_mocks();
}

void teardown(void) {
}

TCase* tcase_unit(void) {
    TCase *tc = tcase_create("Unit Tests");

    tcase_add_checked_fixture(tc, setup, teardown);

    tcase_add_test(tc, test_led_does_not_toggle_or_close_when_open_fails);
    tcase_add_test(tc, test_led_does_not_close_when_toggle_fails);
    tcase_add_test(tc, test_led_toggle_happy_path);

    return tc;
}
