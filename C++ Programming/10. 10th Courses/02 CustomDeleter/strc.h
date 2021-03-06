#ifndef __STRC_H_
#define __STRC_H_

#include <cstddef>

static const char * __strc_class = "strc";
static const char * __strc_version = "1.0";

class strc {
    static const size_t _maxlen = 10240;
    char * data = nullptr;
    void msg(const char *);
public:
    strc();
    strc(const char * s);
    strc(const strc &);
    strc(strc &&);
    ~strc();
    strc & operator = (strc);
    const char * value() const;
    operator const char * () const;
    void swap(strc &);
};

#endif // __STRC_H_
