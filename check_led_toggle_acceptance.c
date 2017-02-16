#include <check.h>

#include "led.h"

START_TEST(test_led_toggle_interface) {
    led_toggle();
} END_TEST

TCase* tcase_acceptance(void) {
    TCase *tc = tcase_create("Acceptance Tests");

    tcase_add_test(tc, test_led_toggle_interface);

    return tc;
}
