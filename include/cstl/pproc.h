#ifndef CSTL_PREPROCESSOR_H
#define CSTL_PREPROCESSOR_H

#define CSTL_WRAP(x) x

#define CSTL__22TH_ELEMENT(\
        a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
        a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, ...) a22

#define CSTL_COUNT(...) \
    CSTL__22TH_ELEMENT(dummy, ## __VA_ARGS__, \
        20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, \
        9, 8, 7, 6, 5, 4, 3, 2, 1, 0 \
    )

#define CSTL__PRIMITIVE_CONCAT2(a1, a2) a1 ## a2

#define CSTL__CONCAT2(a1, a2) CSTL__PRIMITIVE_CONCAT2(a1, a2)
#define CSTL__CONCAT3(a1, ...) CSTL__CONCAT2(a1, CSTL__CONCAT2(__VA_ARGS__))
#define CSTL__CONCAT4(a1, ...) CSTL__CONCAT2(a1, CSTL__CONCAT3(__VA_ARGS__))
#define CSTL__CONCAT5(a1, ...) CSTL__CONCAT2(a1, CSTL__CONCAT4(__VA_ARGS__))
#define CSTL__CONCAT6(a1, ...) CSTL__CONCAT2(a1, CSTL__CONCAT5(__VA_ARGS__))
#define CSTL__CONCAT7(a1, ...) CSTL__CONCAT2(a1, CSTL__CONCAT6(__VA_ARGS__))
#define CSTL__CONCAT8(a1, ...) CSTL__CONCAT2(a1, CSTL__CONCAT7(__VA_ARGS__))
#define CSTL__CONCAT9(a1, ...) CSTL__CONCAT2(a1, CSTL__CONCAT8(__VA_ARGS__))
#define CSTL__CONCAT10(a1, ...) CSTL__CONCAT2(a1, CSTL__CONCAT9(__VA_ARGS__))
#define CSTL__CONCAT11(a1, ...) CSTL__CONCAT2(a1, CSTL__CONCAT10(__VA_ARGS__))
#define CSTL__CONCAT12(a1, ...) CSTL__CONCAT2(a1, CSTL__CONCAT11(__VA_ARGS__))
#define CSTL__CONCAT13(a1, ...) CSTL__CONCAT2(a1, CSTL__CONCAT12(__VA_ARGS__))
#define CSTL__CONCAT14(a1, ...) CSTL__CONCAT2(a1, CSTL__CONCAT13(__VA_ARGS__))
#define CSTL__CONCAT15(a1, ...) CSTL__CONCAT2(a1, CSTL__CONCAT14(__VA_ARGS__))
#define CSTL__CONCAT16(a1, ...) CSTL__CONCAT2(a1, CSTL__CONCAT15(__VA_ARGS__))
#define CSTL__CONCAT17(a1, ...) CSTL__CONCAT2(a1, CSTL__CONCAT16(__VA_ARGS__))
#define CSTL__CONCAT18(a1, ...) CSTL__CONCAT2(a1, CSTL__CONCAT17(__VA_ARGS__))
#define CSTL__CONCAT19(a1, ...) CSTL__CONCAT2(a1, CSTL__CONCAT18(__VA_ARGS__))
#define CSTL__CONCAT20(a1, ...) CSTL__CONCAT2(a1, CSTL__CONCAT19(__VA_ARGS__))

#define CSTL_CONCAT(...) \
    CSTL__CONCAT2(CSTL__CONCAT, CSTL_COUNT(__VA_ARGS__))(__VA_ARGS__)

#define CSTL__STR(x) #x
#define CSTL_STR(x) CSTL__STR(x)


#endif /* CSTL_PREPROCESSOR_H */
