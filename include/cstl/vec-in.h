#if !defined(CSTL_TYPE)
#error "CSTL vector interface instantiation: expectec VEC_TYPE defined"
#endif /* VEC_TYPE */

#include <stddef.h>
#include <assert.h>

#include <cstl/err.h>
#include <cstl/vec.h>

typedef struct {
    CSTL_TYPE* data;

    size_t count;
    size_t capacity;
} cstl_vec_t(CSTL_TYPE);

cstl_err_t cstl_vec_init(CSTL_TYPE, cstl_vec_t(CSTL_TYPE)* v);
void cstl_vec_free(CSTL_TYPE, cstl_vec_t(CSTL_TYPE)* v);


extern inline size_t cstl_vec_cnt(CSTL_TYPE, cstl_vec_t(CSTL_TYPE) const* v) {
    assert(v != NULL);
    return v->count;
}

extern inline size_t cstl_vec_cap(CSTL_TYPE, cstl_vec_t(CSTL_TYPE) const* v) {
    assert(v != NULL);
    return v->capacity;
}

extern inline CSTL_TYPE* cstl_vec_data(CSTL_TYPE, cstl_vec_t(CSTL_TYPE)* v) {
    assert(v != NULL);
    return v->data;
}

extern inline CSTL_TYPE const* 
cstl_vec_cdata(CSTL_TYPE, cstl_vec_t(CSTL_TYPE) const* v) {
    assert(v != NULL);
    return v->data;
}

extern inline CSTL_TYPE 
cstl_vec_at(CSTL_TYPE, cstl_vec_t(CSTL_TYPE) const* v, size_t pos) {
    assert(v != NULL);
    assert(pos < v->count);

    return v->data[pos];
}

extern inline CSTL_TYPE* 
cstl_vec_pat(CSTL_TYPE, cstl_vec_t(CSTL_TYPE)* v, size_t pos) {
    assert(v != NULL);
    assert(pos < v->count);

    return v->data + pos;
}

extern inline CSTL_TYPE const* 
cstl_vec_cpat(CSTL_TYPE, cstl_vec_t(CSTL_TYPE) const* v, size_t pos) {
    assert(v != NULL);
    assert(pos < v->count);

    return v->data + pos;
}

cstl_err_t cstl_vec_pub(CSTL_TYPE, cstl_vec_t(CSTL_TYPE)* v, CSTL_TYPE val);

cstl_err_t
cstl_vec_ins(CSTL_TYPE, cstl_vec_t(CSTL_TYPE)* v, size_t pos, CSTL_TYPE val);

extern inline void 
cstl_vec_set(CSTL_TYPE, cstl_vec_t(CSTL_TYPE)* v, size_t pos, CSTL_TYPE val) {
    assert(v != NULL);
    assert(pos < v->count);

    v->data[pos] = val;
}

extern inline void cstl_vec_pob(CSTL_TYPE, cstl_vec_t(CSTL_TYPE)* v) {
    assert(v != NULL);
    assert(v->count != 0);

    --v->count;
}

void cstl_vec_rem(CSTL_TYPE, cstl_vec_t(CSTL_TYPE)* v, size_t pos);

extern inline void cstl_vec_clr(CSTL_TYPE, cstl_vec_t(CSTL_TYPE)* v) {
    assert(v != NULL);

    v->count = 0;
}
