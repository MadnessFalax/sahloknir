#include <string>

class Exception{
    std::string msg;

public:
    Exception(std::string message = "") {
        msg = message;
    }

    std::string get_message() {
        return msg;
    }
};