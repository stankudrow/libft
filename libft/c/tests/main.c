#include "libft.h"
#include <check.h>
#include <stdbool.h>


START_TEST(check_isdigit)
{
    char c = '0';
    char result = ft_isdigit(c);
    ck_assert_int_eq(result, true);

    c = '0' - 1;
    result = ft_isdigit(c);
    ck_assert_int_ne(result, true);

    c = '9';
    result = ft_isdigit(c);
    ck_assert_int_ne(result, false);

    c = '9' + 1;
    result = ft_isdigit(c);
    ck_assert_int_eq(result, false);
}
END_TEST


START_TEST(check_isprint)
{
    char c = 100;
    char result = ft_isprint(c);
    ck_assert_int_eq(result, true);

    c = 31;
    result = ft_isprint(c);
    ck_assert_int_ne(result, true);

    c = 127;
    result = ft_isprint(c);
    ck_assert_int_eq(result, false);
}
END_TEST


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


TCase *is_char_kind_test_case(void)
{
    TCase *tc = tcase_create("ft_is<char_kind> test case");

    tcase_add_test(tc, check_isdigit);
    tcase_add_test(tc, check_isprint);

    return tc;
}


TCase *to_char_case_test_case(void)
{
    TCase *tc = tcase_create("ft_to<case> test case");

    tcase_add_test(tc, check_tolower);
    tcase_add_test(tc, check_toupper);

    return tc;
}


Suite *libft_main_suite(void)
{
    Suite *s = suite_create("Main test suite");

    suite_add_tcase(s, is_char_kind_test_case());
    suite_add_tcase(s, to_char_case_test_case());

    return s;
}


int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = libft_main_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}
