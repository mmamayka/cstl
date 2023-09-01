#include <cstl/pproc.h>

int main() {
    if(CSTL_COUNT(a) == 1 &&
       CSTL_COUNT(a, a, a) == 3) {
        return 0;
    } else {
        return -1;
    }
}
