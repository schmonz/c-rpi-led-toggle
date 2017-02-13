#include <check.h>

#include "led.h"

START_TEST(test_nothing) {
    ck_assert_msg(2 == 2, "unit nothing");
} END_TEST

TCase* tcase_unit(void) {
    TCase *tc = tcase_create("Unit Tests");

    tcase_add_test(tc, test_nothing);

    return tc;
}
