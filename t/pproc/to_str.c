#include <string.h>

#include <cstl/pproc.h>

int main() {
    if(strcmp(CSTL_STR(hello_world), "hello_world") == 0) {
        return 0;
    } else {
        return -1;
    }
}
