#include <cstl/vec.h>

#define CSTL_TYPE int
#include <cstl/vec-im.h>

int main() {
    cstl_vec_t(int) v;
    cstl_vec_init(int, &v);
    cstl_vec_free(int, &v);
}

