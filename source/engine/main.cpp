#include <iostream>
#include <cstdlib>
#include "engine/meta.h"
#include "common_types/local_time/date_time.h"
#include "debug/logging/log.h"


using namespace eff::engine;
using namespace eff::common_types;
using namespace eff::debug;


int main(){

    Log log(Log::Settings({"log.log", false}), true);

    log << "hello";
    log.setSettings(Log::Settings({"log.log", true}));
    log << "world";

    return EXIT_SUCCESS;
}
