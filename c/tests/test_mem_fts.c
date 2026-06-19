#include "test_libft.h"

#include "libft.h"

#include <signal.h>
#include <stdlib.h>
#include <string.h>


START_TEST(check_ft_memcmp)
{
    char *str1, *str2;
    int result;

    str1 = str2 = "Hello, World!";
    result = ft_memcmp(str1, str2, strlen(str1));
    ck_assert_int_eq(result, 0);

    str1 = "A"; str2 = "B";
    ck_assert_int_eq(ft_memcmp(str1, str2, strlen(str1)), -1);
    ck_assert_int_eq(ft_memcmp(str2, str1, strlen(str1)), 1);

    str1 = "Abc"; str2 = "B";
    ck_assert_int_eq(ft_memcmp(str1, str2, strlen(str2)), -1);
    ck_assert_int_eq(ft_memcmp(str2, str1, strlen(str2)), 1);

    str1 = "B"; str2 = "Bbb";
    ck_assert_int_eq(ft_memcmp(str1, str2, strlen(str1)), 0);

    str1 = "Bbc"; str2 = "Bbb";
    ck_assert_int_eq(ft_memcmp(str1, str2, strlen(str1)), 1);
}


START_TEST(check_ft_memset)
{
    char *reg; int c; size_t n;
    void *result;

    reg = "Modern C", c = 'A', n = 0;
    result = ft_memset(reg, c, n);
    ck_assert_mem_eq(result, reg, strlen(reg));

    reg = uft_allocate_str("Modern C"), c = 'A', n = 1;
    result = ft_memset(reg, c, n);
    ck_assert_mem_eq(result, reg, strlen(reg));
    ck_assert_str_eq(reg, "Aodern C");
    free(reg);

    reg = uft_allocate_str("Modern C"), c = 'D', n = 1;
    result = ft_memset(reg + 7, c, n);
    ck_assert_mem_eq(result, reg + 7, strlen(reg));
    ck_assert_str_eq(reg, "Modern D");
    free(reg);
}
END_TEST

START_TEST(check_ft_memset_null) { ft_memset(NULL, 1, 1); } END_TEST

START_TEST(check_ft_memset_literal) { ft_memset("Nope", 'Z', 2); } END_TEST

START_TEST(check_ft_memset_out) {
    char *str = uft_allocate_str("to be violated");
    ft_memset((void *)str, 'Z', strlen(str) + 100);
} END_TEST


TCase *ft_mem_test_case(void)
{
    TCase *tc = tcase_create("ft_<mem> test case");

    tcase_add_test(tc, check_ft_memcmp);

    tcase_add_test(tc, check_ft_memset);
    tcase_add_test_raise_signal(tc, check_ft_memset_null, SIGSEGV);
    tcase_add_test_raise_signal(tc, check_ft_memset_literal, SIGSEGV);
    tcase_add_test_raise_signal(tc, check_ft_memset_out, SIGSEGV);

    return tc;
}
