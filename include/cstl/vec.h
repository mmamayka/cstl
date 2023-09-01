#ifndef CSTL_VEC_H
#define CSTL_VEC_H

#include <cstl/err.h>
#include <cstl/templ.h>

#define cstl_vec_t(type) CSTL__MANGLE(vec, type)

#define cstl_vec_init(type, v) CSTL__MANGLE(cstl_vec_init, type)(v)
#define cstl_vec_free(type, v) CSTL__MANGLE(cstl_vec_free, type)(v)

#define cstl_vec_cnt(type, v) CSTL__MANGLE(cstl_vec_cnt, type)(v)
#define cstl_vec_cap(type, v) CSTL__MANGLE(cstl_vec_cap, type)(v)
#define cstl_vec_data(type, v) CSTL__MANGLE(cstl_vec_data, type)(v)
#define cstl_vec_cdata(type, v) CSTL__MANGLE(cstl_vec_cdata, type)(v)

#define cstl_vec_at(type, v, pos) CSTL__MANGLE(cstl_vec_at, type)(v, pos)
#define cstl_vec_pat(type, v, pos) CSTL__MANGLE(cstl_vec_pat, type)(v, pos)
#define cstl_vec_cpat(type, v, pos) CSTL__MANGLE(cstl_vec_cpat, type)(v, pos)

#define cstl_vec_pub(type, v, val) CSTL__MANGLE(cstl_vec_pub, type)(v, val)
#define cstl_vec_ins(type, v, pos, val) \
    CSTL__MANGLE(cstl_vec_ins, type)(v, pos, val)

#define cstl_vec_set(type, v, pos, val) \
    CSTL__MANGLE(cstl_vec_set, type)(v, pos, val)

#define cstl_vec_pob(type, v) CSTL__MANGLE(cstl_vec_pob, type)(v)
#define cstl_vec_rem(type, v, pos) CSTL__MANGLE(cstl_vec_rem, type)(v, pos)
#define cstl_vec_clr(type, v) CSTL__MANGLE(cstl_vec_clr, type)(v)

#endif /* CSTD_VEC_H */
