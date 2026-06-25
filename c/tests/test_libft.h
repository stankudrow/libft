#ifndef TEST_LIBFT_H
#define TEST_LIBFT_H

#include <check.h>

// test utils (internal) (uft_ prefix)
char *uft_allocate_formatted_string(const char *fmt, ...);

TCase *test_utils_test_case(void);

// end of utils section

TCase *ft_atoi_test_case(void);

TCase *ft_is_char_kind_test_case(void);
TCase *ft_to_char_case_test_case(void);

TCase *ft_mem_test_case(void);

TCase *ft_put_in_fd_test_case(void);

TCase *ft_str_test_case(void);

#endif /* TEST_LIBFT_H */
