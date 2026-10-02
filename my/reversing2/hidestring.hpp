#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>
#include <boost/preprocessor/seq/enum.hpp>
#include <boost/preprocessor/seq/size.hpp>

#define CRYPT_MACRO(r, d, i, elem) ( elem ^ ( d - i ) )

#define DEFINE_HIDDEN_STRING(NAME, SEED, SEQ) \
struct BOOST_PP_CAT(Get, NAME) {\
    static constexpr size_t length = BOOST_PP_SEQ_SIZE(SEQ); \
    static char get(size_t idx) {
        static const char data[] = { BOOST_PP_SEQ_ENUM(SEQ) }; \
        if (idx >= length) return '\0'; \
        return data[idx] ^ (SEED - idx); \
    } \
};