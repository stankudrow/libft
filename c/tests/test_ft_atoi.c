#include "test_libft.h"

#include "libft.h"

#include <stdlib.h>  // atoi


START_TEST(check_ft_atoi)
{
    char *str;

    str = "-0";
    ck_assert_int_eq(ft_atoi(str), atoi(str));

    str = "0";
    ck_assert_int_eq(ft_atoi(str), atoi(str));

    str = "+0";
    ck_assert_int_eq(ft_atoi(str), atoi(str));

    str = "-7";
    ck_assert_int_eq(ft_atoi(str), atoi(str));

    str = "8";
    ck_assert_int_eq(ft_atoi(str), atoi(str));

    str = "+9";
    ck_assert_int_eq(ft_atoi(str), atoi(str));

    str = "-12";
    ck_assert_int_eq(ft_atoi(str), atoi(str));

    str = "345";
    ck_assert_int_eq(ft_atoi(str), atoi(str));

    str = "+6789";
    ck_assert_int_eq(ft_atoi(str), atoi(str));

    str = "";
    ck_assert_int_eq(ft_atoi(str), atoi(str));

    str = "a";
    ck_assert_int_eq(ft_atoi(str), atoi(str));
}


TCase *ft_atoi_test_case(void)
{
    TCase *tc = tcase_create("ft_atoi test case");

    tcase_add_test(tc, check_ft_atoi);
    // there is no itoa in standard C library

    return tc;
}
