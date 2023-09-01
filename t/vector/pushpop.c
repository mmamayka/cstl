#include <stdio.h>

#include <cstl/vec.h>

#define CSTL_TYPE int
#include <cstl/vec-im.h>

int main() {
    cstl_vec_t(int) v;
    cstl_vec_init(int, &v);

    cstl_vec_pub(int, &v, 5);
    cstl_vec_pub(int, &v, 6);
    cstl_vec_pub(int, &v, 7);

    if(cstl_vec_cnt(int, &v) != 3) {
        fprintf(stderr, "Invalid elements count in vector\n");
        return -1;
    }

    if(cstl_vec_at(int, &v, 0) != 5 ||
           cstl_vec_at(int, &v, 1) != 6 ||
           cstl_vec_at(int, &v, 2) != 7) {
        fprintf(stderr, "Invalid pushed values\n");
        return -1;
    }

    cstl_vec_pob(int, &v);
    cstl_vec_pob(int, &v);
    cstl_vec_pob(int, &v);

    if(cstl_vec_cnt(int, &v) != 0) {
        fprintf(stderr, "Invalid elements count in vector\n");
        return -1;
    }

    cstl_vec_free(int, &v);
    return 0;
}
