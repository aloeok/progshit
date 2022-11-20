#ifndef biginthpp
#define biginthpp 20221118

#include <cstddef>

class bigint {
    char*   data;
    size_t  size;
    bool    neg ;
    
    public:
    
    bigint();
    bigint(const bigint&);
    ~bigint();
    
    explicit bigint(long);
    explicit bigint(unsigned long);
    explicit bigint(const char*);
    
    void print() const;
    
    static bigint add(const bigint& left, const bigint& right);
    static bigint sub(const bigint& left, const bigint& right);
    static bigint mul(const bigint& left, const bigint& right);
    static bigint div(const bigint& left, const bigint& right);
    static bigint div(const bigint& left, const bigint& right, bigint& reminder);
};

#endif
