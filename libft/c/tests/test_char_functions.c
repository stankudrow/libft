#include "libft.h"

#include "test_libft.h"

#include <stdbool.h>


START_TEST(check_isalnum)
{
    char c, result;

    c = 'A' - 1;
    result = ft_isalnum(c);
    ck_assert_int_eq(result, false);

    c = 'A';
    result = ft_isalnum(c);
    ck_assert_int_eq(result, true);

    c = 'Z';
    result = ft_isalnum(c);
    ck_assert_int_eq(result, true);

    c = 'a';
    result = ft_isalnum(c);
    ck_assert_int_eq(result, true);

    c = 'z';
    result = ft_isalnum(c);
    ck_assert_int_eq(result, true);

    c = 'z' + 1;
    result = ft_isalnum(c);
    ck_assert_int_eq(result, false);

    c = '0' - 1;
    result = ft_isalnum(c);
    ck_assert_int_eq(result, false);

    c = '0';
    result = ft_isalnum(c);
    ck_assert_int_eq(result, true);

    c = '9';
    result = ft_isalnum(c);
    ck_assert_int_ne(result, false);

    c = '9' + 1;
    result = ft_isalnum(c);
    ck_assert_int_eq(result, false);

    c = '?';
    result = ft_isalnum(c);
    ck_assert_int_eq(result, false);
}
END_TEST


START_TEST(check_isalpha)
{
    char c, result;

    c = 'A' - 1;
    result = ft_isalnum(c);
    ck_assert_int_eq(result, false);

    c = 'A';
    result = ft_isalnum(c);
    ck_assert_int_eq(result, true);

    c = 'Z';
    result = ft_isalnum(c);
    ck_assert_int_eq(result, true);

    c = 'a';
    result = ft_isalnum(c);
    ck_assert_int_eq(result, true);

    c = 'z';
    result = ft_isalnum(c);
    ck_assert_int_eq(result, true);

    c = 'z' + 1;
    result = ft_isalnum(c);
    ck_assert_int_eq(result, false);
}
END_TEST


START_TEST(check_isascii)
{
    int c, result;

    c = -1;
    result = ft_isascii(c);
    ck_assert_int_eq(result, false);

    c = 0;
    result = ft_isascii(c);
    ck_assert_int_eq(result, true);

    c = 100;
    result = ft_isascii(c);
    ck_assert_int_eq(result, true);

    c = 127;
    result = ft_isascii(c);
    ck_assert_int_eq(result, true);

    c = 128;
    result = ft_isascii(c);
    ck_assert_int_eq(result, false);
}
END_TEST


START_TEST(check_isdigit)
{
    char c, result;

    c = '0' - 1;
    result = ft_isdigit(c);
    ck_assert_int_eq(result, false);

    c = '0';
    result = ft_isdigit(c);
    ck_assert_int_eq(result, true);

    c = '9';
    result = ft_isdigit(c);
    ck_assert_int_ne(result, false);

    c = '9' + 1;
    result = ft_isdigit(c);
    ck_assert_int_eq(result, false);

    c = '!';
    result = ft_isdigit(c);
    ck_assert_int_eq(result, false);
}
END_TEST


START_TEST(check_isprint)
{
    int c, result;

    c = 30;
    result = ft_isprint(c);
    ck_assert_int_eq(result, false);

    c = 31;
    result = ft_isprint(c);
    ck_assert_int_ne(result, true);

    c = 100;
    result = ft_isprint(c);
    ck_assert_int_eq(result, true);

    c = 127;
    result = ft_isprint(c);
    ck_assert_int_eq(result, false);

    c = 128;
    result = ft_isprint(c);
    ck_assert_int_eq(result, false);
}
END_TEST


TCase *is_char_kind_test_case(void)
{
    TCase *tc = tcase_create("ft_is<char_kind> test case");

    tcase_add_test(tc, check_isalnum);
    tcase_add_test(tc, check_isalpha);
    tcase_add_test(tc, check_isascii);
    tcase_add_test(tc, check_isdigit);
    tcase_add_test(tc, check_isprint);

    return tc;
}


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

    c = 26;
    result = ft_toupper(c);
    ck_assert_int_eq(result, 26);
}
END_TEST


TCase *to_char_case_test_case(void)
{
    TCase *tc = tcase_create("ft_to<case> test case");

    tcase_add_test(tc, check_tolower);
    tcase_add_test(tc, check_toupper);

    return tc;
}
