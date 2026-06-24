#include <stdarg.h>  // variadic arguments
#include <stdio.h>  // printf functions etc.
#include <stdlib.h>  // malloc etc.


/* see `man 3 vsnprintf` page */
char *uft_get_formatted_string(const char *fmt, ...)
{
    if (!fmt) return NULL;

    va_list args, args_copy;
    va_start(args, fmt);
    va_copy(args_copy, args);

    /* Determine required size. */
    int len = vsnprintf(NULL, 0, fmt, args);
    va_end(args);
    if (len < 0) {
        va_end(args_copy);
        return NULL;
    }

    size_t bufsize = (size_t)len + 1;
    char *buf = malloc(bufsize);
    if (!buf) {
        va_end(args_copy);
        return NULL;
    }

    len = vsnprintf(buf, bufsize, fmt, args_copy);
    va_end(args_copy);
    if (len < 0) {
        free(buf);
        return NULL;
    }

    return buf;
}
