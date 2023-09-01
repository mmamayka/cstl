#ifndef CSTL_ERR_H
#define CSTL_ERR_H

typedef enum {
    CSTL_ERR_OK,
    CSTL_ERR_MEM,
} cstl_err_t;

char const* cstl_errstr(cstl_err_t err);

#define CSTL__CHECK(expression, errc) \
    do { \
        if(!(expression)) { \
            return errc; \
        } \
    } while(0)

#define CSTL__CHECK_ERR(expression) \
    do { \
        cstl_err_t CSTL__CHECK_ERR_errc = (expression); \
        if(CSTL__CHECK_ERR_errc != CSTL_ERR_OK) { \
            return CSTL__CHECK_ERR_errc; \
        } \
    } while(0)


#endif /* CSTL_ERR_H */
