#include "test_libft.h"

#include "libft.h"

#include <stdlib.h>
#include <unistd.h>


// Damn, test helpers should also be tested
START_TEST(check_uft_allocate_formatted_string)
{
    char *result;

    result = uft_allocate_formatted_string("Hi again!");
    ck_assert_str_eq(result, "Hi again!");
    free(result);

    result = uft_allocate_formatted_string("The answer is %d!", 42);
    ck_assert_str_eq(result, "The answer is 42!");
    free(result);

    result = uft_allocate_formatted_string("The %s answer is %.4f!", "extended", 42.21);
    ck_assert_str_eq(result, "The extended answer is 42.2100!");
    free(result);

    result = uft_allocate_formatted_string(NULL, "extended", 42.21);
    ck_assert_ptr_null(result);
}


TCase *test_utils_test_case(void)
{
    TCase *tc = tcase_create("test_utils");

    tcase_add_test(tc, check_uft_allocate_formatted_string);

    return tc;
}
