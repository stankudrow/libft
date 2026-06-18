#include <stdlib.h>  // exit()
#include <string.h>


char *uft_allocate_str(const char *str)
{
    char *copy = strdup(str);
    if (!copy)
        exit(-1);
    return copy;
}
