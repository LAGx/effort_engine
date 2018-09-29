#include <iostream>
#include <cstdlib>
#include "engine/meta.h"
#include "common_types/local_time/date_time.h"
#include "debug/logging/log.h"


using namespace eff::engine;
using namespace eff::common_types;
using namespace eff::debug;


int main(){

    Log log(Log::Settings({"log/test.log", true}), true);

    log << "hello world";

    log << "hello world1" << "kek";
    log << "hello world2";

    return EXIT_SUCCESS;
}
