#include "test_libft.h"

#include "libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const char *test_case_name = "ft_<put-in-fd> test case";

// https://libcheck.github.io/check/doc/check_html/check_4.html#Test-Fixtures
// https://libcheck.github.io/check/doc/check_html/check_4.html#Test-Fixture-Examples
//https://libcheck.github.io/check/doc/check_html/check_4.html#Checked-vs-Unchecked-Fixtures

// I need a pipe (channel) to intercept data from a file descriptor (fd)
int pipefd[2];  // global...dangerous

// I need an unchecked test fixtures for this test module:
// - they are run in the same address space as the test program;
// - setup(), if defined, is run before the test case started;
// - teardown(), if defined, is run after the test case is done;
// - an unchecked teardown() fixture will run even if a unit test fails.

// This function is a helper and should be internal.
// Imagine if you have another `setup` in another test module...
// one definition rule is violated and tests won't be compiled.
static void setup()
{
    if (pipe(pipefd) == -1) {
        char *str = uft_allocate_formatted_string("pipe failed for %s", test_case_name);
        if (!str) {
            perror("internal error occured when creating error message after pipe initialisation failure");
            exit(EXIT_FAILURE);
        }
        perror(str);
        free(str);
        exit(EXIT_FAILURE);
    }
    // printf("A pipe for ft_put_fts.c module is opened.\n");
}

static void teardown()
{
    close(pipefd[0]);
    close(pipefd[1]);
    // printf("The pipe for ft_put_fts.c module is closed.\n");
}


START_TEST(check_ft_putchar_fd)
{
    char ch, result;
    ssize_t bytes_read;

    ch = 'T';
    // routing the char to the pippe in lieu of stdout
    // pipefd[1] is the end where data are written to
    ft_putchar_fd(ch, pipefd[1]);
    // pipefd[0] is the end where data are read from
    bytes_read = read(pipefd[0], &result, 1);
    if (bytes_read < 0) ck_abort_msg("check_ft_putchar failed");
    ck_assert_int_eq(result, ch);
}


START_TEST(check_ft_putstr_fd)
{
    char *str, *result;
    ssize_t bytes_read;

    str = "Hello, C!";

    if (!(result = malloc(strlen(str) + 1))) ck_abort_msg("check_ft_putstr_fd failed");
    ft_putstr_fd(str, pipefd[1]);
    bytes_read = read(pipefd[0], result, strlen(str));
    if (bytes_read < 0) ck_abort_msg("check_ft_putstr_fd failed");
    result[bytes_read] = '\0';
    ck_assert_str_eq(result, str);
    free(result);
}


TCase *ft_put_in_fd_test_case(void)
{
    TCase *tc = tcase_create(test_case_name);

    // An unchecked fixture is enough for this dummy implementation,
    // but it can go off when tests are run concurrently (shared global state may suck).
    // Also, you can try `tcase_add_checked_fixture` with some `printf`s in setup/teardown functions.
    tcase_add_unchecked_fixture(tc, setup, teardown);
    tcase_add_test(tc, check_ft_putchar_fd);
    tcase_add_test(tc, check_ft_putstr_fd);

    return tc;
}
