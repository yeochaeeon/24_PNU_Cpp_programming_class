//
// Created by codjs on 2024-05-09.
//
#include <iostream>
#include <algorithm>

class String {
public:
    String() ;
    explicit String(const char* s) ;
    ~String() noexcept ;
    String(const String& s) noexcept ;

public:
    const char* data() const;
    bool empty() const;
    size_t size() const;
    String& append(const String& str);
    String& append(const char* str);


private:
    static int count_;
    char* data_;
    size_t len_;
};
