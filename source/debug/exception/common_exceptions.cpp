#include "debug/exception/common_exceptions.h"


using namespace eff;
using namespace eff::debug;
using namespace std;



Exception::Exception( Log& log_object, std::string reason): reason(move(reason)){
    log_object << reason;
}


Exception::Exception(std::string reason): reason(move(reason))
    {}


std::string Exception::what() const{
    return reason;
}
