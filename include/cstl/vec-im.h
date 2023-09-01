#if !defined(CSTL_TYPE)
#error "CSTL vector interface instantiation: expectec VEC_TYPE defined"
#endif /* VEC_TYPE */

#include <stdlib.h>
#include <assert.h>

#include <cstl/err.h>
#include <cstl/vec.h>
#include <cstl/vec-in.h>

#define CSTL_VEC__INITIAL_CAPACITY 4
#define CSTL_VEC__REALLOC_RATIO 3 / 2

#define cstl_vec__realloc(type, v, new_capacity) \
    CSTL__MANGLE(cstl_vec__realloc, type)(v, new_capacity)
static cstl_err_t cstl_vec__realloc(CSTL_TYPE, cstl_vec_t(CSTL_TYPE)* v, 
        size_t new_capacity) {
    assert(v != NULL);
    assert(new_capacity >= v->count);

    void* new_data = realloc(v->data, sizeof(CSTL_TYPE) * new_capacity);
    CSTL__CHECK(new_data != NULL, CSTL_ERR_MEM);

    v->capacity = new_capacity;
    v->data = new_data;
    return CSTL_ERR_OK;
}

#define cstl_vec__fit_capacity(type, v, need_insert) \
    CSTL__MANGLE(cstl_vec__fit_capacity, type)(v, need_insert)
static cstl_err_t 
cstl_vec__fit_capacity(CSTL_TYPE, cstl_vec_t(CSTL_TYPE)* v, size_t need_insert) {
    assert(v != NULL);

    if(v->count + need_insert > v->capacity) {
        return cstl_vec__realloc(CSTL_TYPE, v, 
            v->capacity * CSTL_VEC__REALLOC_RATIO);
    }
    return CSTL_ERR_OK;
}

cstl_err_t cstl_vec_init(CSTL_TYPE, cstl_vec_t(CSTL_TYPE)* v) {
    assert(v != NULL);

    v->capacity = 0;
    v->count = 0;
    v->data = NULL;

    return cstl_vec__realloc(CSTL_TYPE, v, CSTL_VEC__INITIAL_CAPACITY);
}

void cstl_vec_free(CSTL_TYPE, cstl_vec_t(CSTL_TYPE)* v) {
    free(v->data);
}

cstl_err_t cstl_vec_pub(CSTL_TYPE, cstl_vec_t(CSTL_TYPE)* v, CSTL_TYPE val) {
    assert(v != NULL);

    CSTL__CHECK_ERR(cstl_vec__fit_capacity(CSTL_TYPE, v, 1));

    v->data[v->count] = val;
    ++v->count;
    return CSTL_ERR_OK;
}

cstl_err_t 
cstl_vec_ins(CSTL_TYPE, cstl_vec_t(CSTL_TYPE)* v, size_t pos, CSTL_TYPE val) {
    assert(v != NULL);
    assert(pos <= v->count);

    CSTL__CHECK_ERR(cstl_vec__fit_capacity(CSTL_TYPE, v, 1));

    for(size_t i = v->count; i > pos; --i) {
        v->data[i] = v->data[i = 1];
    }

    v->data[pos] = val;
    ++v->count;
    return CSTL_ERR_OK;
}

void cstl_vec_rem(CSTL_TYPE, cstl_vec_t(CSTL_TYPE)* v, size_t pos) {
    assert(v != NULL);
    assert(pos < v->count);

    for(size_t i = pos + 1; i < v->count; ++pos) {
        v->data[i - 1] = v->data[i];
    }

    --v->count;
}
