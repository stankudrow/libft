#include "libft.h"

#include "test_libft.h"

#include <signal.h>
#include <string.h>



START_TEST(check_strlen)
{
    char *str;
    size_t result;

    str = "";
    result = ft_strlen(str);
    ck_assert_int_eq(result, 0);

    str = "-1";
    result = ft_strlen(str);
    ck_assert_int_eq(result, 2);
}
END_TEST


START_TEST(check_strlen_null) { ft_strlen(NULL); } END_TEST


START_TEST(check_strchr)
{
    char *str;
    char c;
    char *result, *answer;

    str = "", c = 0;
    result = ft_strrchr(str, c);
    ck_assert_str_eq(str, result);

    str = "", c = 1;
    result = ft_strrchr(str, c);
    ck_assert_ptr_null(result);

    str = "hello", c = 'l';
    result = ft_strrchr(str, c);
    answer = strchr(str, c);
    ck_assert_str_eq(result, answer);
    ck_assert_str_eq(result, "llo");

    str = "hello", c = 'o';
    result = ft_strrchr(str, c);
    answer = strchr(str, c);
    ck_assert_str_eq(result, answer);
    ck_assert_str_eq(result, "o");

    str = "hello", c = 'H';
    result = ft_strrchr(str, c);
    answer = strchr(str, c);
    ck_assert_ptr_null(result);
    ck_assert_ptr_null(answer);
}
END_TEST


TCase *ft_str_test_case(void)
{
    TCase *tc = tcase_create("ft_<str> test case");

    tcase_add_test(tc, check_strlen);
    tcase_add_test_raise_signal(tc, check_strlen_null, SIGSEGV);

    tcase_add_test(tc, check_strchr);

    return tc;
}
