#include <string.h>

#include <cstl/pproc.h>

int main() {
    int status = strcmp(
        "012345678910111213141516171819", 
        CSTL_STR(CSTL_CONCAT(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
            17, 18, 19))
    );

    return status == 0 ? 0 : -1;
}
