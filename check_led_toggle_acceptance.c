#include <check.h>

#include "led.h"

START_TEST(test_nothing) {
    ck_assert_msg(1 == 1, "acceptance nothing");
} END_TEST

TCase* tcase_acceptance(void) {
    TCase *tc = tcase_create("Acceptance Tests");

    tcase_add_test(tc, test_nothing);

    return tc;
}
