#ifndef TEST_LIBFT_H
#define TEST_LIBFT_H

#include <check.h>

// test utils (internal) (uft_ prefix)

// it is my prefernce not to use parameter names:
// - types are enough
// - reduced risk of name mismatches in .h and .c files
char *uft_allocate_str(const char *);

// end of utils section

TCase *is_char_kind_test_case(void);
TCase *to_char_case_test_case(void);

TCase *ft_mem_test_case(void);

TCase *ft_str_test_case(void);

#endif /* TEST_LIBFT_H */
