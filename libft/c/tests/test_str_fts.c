#include "test_libft.h"

#include "libft.h"

#include <signal.h>
#include <string.h>


START_TEST(check_ft_strlen)
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

START_TEST(check_ft_strlen_null) { ft_strlen(NULL); } END_TEST

// strlen is marked nonnull, so passing NULL is obstructed
// START_TEST(check_std_strlen_null) { strlen(NULL); } END_TEST


// this test states the functionality according to a white box approach
START_TEST(check_ft_strnstr)
{
    char *big, *lil;
    size_t n;
    char *result;

    big = NULL, lil = "ttle", n = 0;
    result = ft_strnstr(big, lil, n);
    ck_assert_ptr_null(result);

    big = "ger", lil = "ill", n = 0;
    result = ft_strnstr(big, lil, n);
    ck_assert_ptr_null(result);

    big = "ger", lil = "", n = 5;
    result = ft_strnstr(big, lil, n);
    ck_assert_str_eq(result, big);

    // big = NULL, lil = "tre", n = 5;
    // result = ft_strnstr(big, lil, n);
    // ck_assert_ptr_null(result);

    big = "A", lil = "tre", n = 5;
    result = ft_strnstr(big, lil, n);
    ck_assert_ptr_null(result);

    big = "ABC", lil = "tre", n = 2;
    result = ft_strnstr(big, lil, n);
    ck_assert_ptr_null(result);

    big = "allo, salut", lil = ",", n = 3;
    result = ft_strnstr(big, lil, n);
    ck_assert_ptr_null(result);

    big = "allo, salut", lil = ",", n = 4;
    result = ft_strnstr(big, lil, n);
    ck_assert_ptr_null(result);

    big = "allo, salut", lil = ",", n = 5;
    result = ft_strnstr(big, lil, n);
    ck_assert_str_eq(result, big + 4);
}
END_TEST


START_TEST(check_ft_strrchr)
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
    answer = strrchr(str, c);
    ck_assert_str_eq(result, answer);
    ck_assert_str_eq(result, "lo");

    str = "hello", c = 'o';
    result = ft_strrchr(str, c);
    answer = strrchr(str, c);
    ck_assert_str_eq(result, answer);
    ck_assert_str_eq(result, "o");

    str = "hello", c = 'H';
    result = ft_strrchr(str, c);
    answer = strrchr(str, c);
    ck_assert_ptr_null(result);
    ck_assert_ptr_null(answer);
}
END_TEST


TCase *ft_str_test_case(void)
{
    TCase *tc = tcase_create("ft_<str> test case");

    tcase_add_test(tc, check_ft_strlen);
    tcase_add_test_raise_signal(tc, check_ft_strlen_null, SIGSEGV);
    // tcase_add_test_raise_signal(tc, check_std_strlen_null, SIGSEGV);

    tcase_add_test(tc, check_ft_strnstr);

    tcase_add_test(tc, check_ft_strrchr);

    return tc;
}
