#include "test_libft.h"

#include "libft.h"

#include <signal.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>  // fork


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

    reg = strdup("Modern C");

    c = 'A', n = 0;
    result = ft_memset(reg, c, n);
    ck_assert_ptr_eq(result, reg);

    c = 'A', n = 1;
    result = ft_memset(reg, c, n);
    ck_assert_mem_eq(result, reg, strlen(reg) - n);
    ck_assert_str_eq(reg, "Aodern C");

    c = 'D', n = 1;
    result = ft_memset(reg + 7, c, n);
    ck_assert_mem_eq(result, reg + 7, n);
    ck_assert_str_eq(reg, "Aodern D");

    free(reg);
}
END_TEST

START_TEST(check_ft_memset_null) { ft_memset(NULL, 1, 1); } END_TEST

START_TEST(check_ft_memset_literal) { ft_memset("Nope", 'Z', 2); } END_TEST

// https://libcheck.github.io/check/doc/check_html/check_4.html#Advanced-Features
// An attempt to use unchecked fixture...failed and turned out to be inapropriate.

// char *ft_memset_out_of_bounds_string = NULL;
// static void setup(void)
// {
//     ft_memset_out_of_bounds_string = strdup("Hi");
//     if (!ft_memset_out_of_bounds_string)
//     {
//         perror("ft_memset strdup failed");
//         exit(-1);
//     }
//     printf("A string for ft_memset_out_of_bounds: %s\n", ft_memset_out_of_bounds_string);
// }
// START_TEST(test_ft_memset_out_of_bounds)
// {
//     // char *ft_memset_out_of_bounds_string = strdup("Hi");
//     size_t slen = strlen(ft_memset_out_of_bounds_string);
//     printf("The length of %s is %zu", ft_memset_out_of_bounds_string, slen);  // not printed...
//     // maybe the `printf`'s internal buffer is not flushed bacause of the successive failure and process crash.
//     ft_memset(ft_memset_out_of_bounds_string, 'Z', slen + 10000);  // should segfault
//     // free(str);  // won't be reached because of the crash at the previous line
// }
// END_TEST
// static void teardown(void)
// {
//     printf("Freeing the string for ft_memset_out_of_bounds: %s\n", ft_memset_out_of_bounds_string);
//     free(ft_memset_out_of_bounds_string);
// }

/*
 * The test above was referenced in the `ft_mem_test_case` as:
 * `tcase_add_unchecked_fixture(tc, setup, teardown);`
 * `tcase_add_test_raise_signal(tc, test_ft_memset_out_of_bounds, SIGABRT);`
 *
 * When running `make` or `make re`, the tests passed successfully.
 * But `make check_leaks` failed:

 95%: Checks: 20, Failures: 1, Errors: 0
 test_mem_fts.c:79:F:ft_<mem> test case:test_ft_memset_out_of_bounds:0: Early exit with return value 0
 ==37126==
 ==37126== HEAP SUMMARY:
 ==37126==     in use at exit: 0 bytes in 0 blocks
 ==37126==   total heap usage: 528 allocs, 528 frees, 299,054 bytes allocated
 ==37126==
 ==37126== All heap blocks were freed -- no leaks are possible
 ==37126==
 ==37126== For lists of detected and suppressed errors, rerun with: -s
 ==37126== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 make: *** [Makefile:29: check_leaks] Error 1

 * You see, no expected abort, I guess that valgrind intercepted it earlier,
 * so Check had no chance to handle it propperly - this is just my humble guess.
 */

START_TEST(check_ft_memset_out_of_bounds)
{
    pid_t pid = fork();

    if (pid < 0) {
        ck_abort_msg("Fork failed in check_ft_memset_out_of_bounds");
    }
    if (!pid)  // PID 0 -> child process
    {
        char *str = strdup("Hi");
        if (!str) {
            _exit(EXIT_FAILURE);
        }
        // should crash, the size should be big enough to provoke failure
        ft_memset(str, 'Z', strlen(str) + 100000000);
        // if we are here, it is a problem
        // free(str);  // it is commented because this part is problematic already
        _exit(21);
    } else  {
        // otherwise we are in the parent pprocess and pid contains the child's PID
        int status;
        waitpid(pid, &status, 0);

        bool is_signaled = WIFSIGNALED(status);  // true if killed by a signal, false if `exit`ed (it can be just a `return status_code`)
        bool is_exited = WIFEXITED(status);  // true if exited (zero or non-zero code), false if was killed by a signal
        int status_code = is_exited ? WEXITSTATUS(status) : -1;
        // `WEXITSTATUS(status)` returns an exit status if `WIFEXITED(status) == true`

        // Scenario 1: OS crash (SIGSEGV/SIGABRT)
        if (is_signaled) {
            int sig = WTERMSIG(status);  // returns the code of a signal if `WIFSIGNALED(status) == true`
            if (sig != SIGSEGV && sig != SIGABRT) {
                ck_abort_msg("Expected SIGSEGV or SIGABRT, but received signal %d", sig);
            }
            return;  // OK because an expected signal is intercepted
        }

        /*
         * Scenario 2: when run under Valgrind/ASan.
         * In this scenario the process returns with error code, not dies.
         * The standard code from Valgrind is 1 which is considered as success
         */
        if (is_exited) {
            if (status_code == 1) {
                return;  // Expected from the "checker"
            }
            if (status_code == 21) {
                ck_abort_msg(
                    "Expected function to crash, but it returned normally (code %d). ",
                    status_code
                );
            }
            ck_abort_msg(
                "Unexpected result: process exited with code %d. "
                "Expected signal or Valgrind error code 1.",
                status_code
            );
        }
        ck_abort_msg("Child process state is neither signaled nor exited");
    }
}
END_TEST


TCase *ft_mem_test_case(void)
{
    TCase *tc = tcase_create("ft_<mem> test case");

    tcase_add_test(tc, check_ft_memcmp);

    tcase_add_test(tc, check_ft_memset);
    tcase_add_test_raise_signal(tc, check_ft_memset_null, SIGSEGV);
    tcase_add_test_raise_signal(tc, check_ft_memset_literal, SIGSEGV);

    // try `tcase_add_checked_fixture` and see the result
    // tcase_add_unchecked_fixture(tc, setup, teardown);
    // tcase_add_test_raise_signal(tc, test_ft_memset_out_of_bounds, SIGABRT);

    tcase_add_test(tc, check_ft_memset_out_of_bounds);

    return tc;
}
