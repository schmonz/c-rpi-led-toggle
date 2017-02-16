#include <check.h>

#include "host_led.h"

START_TEST(test_led_toggle_gets_called) {
    set_mock_open_return_value(5);
    led_toggle();
    ck_assert_int_eq(fake_led_toggle_getcount(), 1);
    led_toggle();
    ck_assert_int_eq(fake_led_toggle_getcount(), 2);
} END_TEST

TCase* tcase_unit(void) {
    TCase *tc = tcase_create("Unit Tests");

    tcase_add_test(tc, test_led_toggle_gets_called);

    return tc;
}
