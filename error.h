#ifndef ERROR_H
#define ERROR_H

#include <iostream>

class Error : public std::exception{
private:
    std::string msg;
public:
    explicit Error(const char* message) : msg(message){ }
    explicit Error(const std::string& message) : msg(message){ }
    virtual ~Error() throw() { }
    virtual const char* what() const throw () {
        return msg.c_str();
    }
};

#endif // ERROR_H
