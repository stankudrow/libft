#include "test_libft.h"

#include <stdio.h>
#include <getopt.h>


// https://github.com/libcheck/check/tree/master/doc/example/tests


Suite *libft_main_suite(void)
{
    Suite *s = suite_create("Main test suite");

    suite_add_tcase(s, is_char_kind_test_case());
    suite_add_tcase(s, to_char_case_test_case());

    suite_add_tcase(s, ft_mem_test_case());

    suite_add_tcase(s, ft_str_test_case());

    return s;
}


int main(int argc, char **argv)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    int output_mode = CK_NORMAL;
    int opt;
    while ((opt = getopt(argc, argv, "vh")) != -1) {
        switch (opt) {
            case 'v':
                output_mode = CK_VERBOSE;
                fprintf(stdout, "Verbose CK_VERBOSE mode enabled\n");
                break;
            case 'h':
                fprintf(stdout,"Usage: %s [-v] [-h]\n", argv[0]);
                return 0;
            case '?':
                fprintf(stderr, "Unknown option: -%c\n", optopt);
                fprintf(stderr, "Use -h for help\n");
                return 1;
            default:
                fprintf(stderr, "Unexpected error\n");
                return 1;
        }
    }

    s = libft_main_suite();
    sr = srunner_create(s);
    // srunner_set_log (sr, "test_report.log");
    srunner_set_tap (sr, "test_report.tap");

    srunner_run_all(sr, output_mode);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}
