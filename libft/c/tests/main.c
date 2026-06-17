#include <check.h>
#include "libft.h"


START_TEST(check_tolower)
{
    char c = 'A';
    char result = ft_tolower(c);
    ck_assert_int_eq(result, 'a');

    c = 'a';
    result = ft_tolower(c);
    ck_assert_int_eq(result, 'a');

    c = 15;
    result = ft_tolower(c);
    ck_assert_int_eq(result, 15);
}
END_TEST


START_TEST(check_toupper)
{
    char c = 'a';
    char result = ft_toupper(c);
    ck_assert_int_eq(result, 'A');

    c = 'A';
    result = ft_toupper(c);
    ck_assert_int_eq(result, 'A');

    c = 15;
    result = ft_toupper(c);
    ck_assert_int_eq(result, 15);
}
END_TEST


Suite *libft_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("libft tests");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, check_tolower);
    tcase_add_test(tc_core, check_toupper);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = libft_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}
