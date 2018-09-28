#include <iostream>
#include <cstdlib>
#include "engine/meta.h"
#include "common_types/local_time/date_time.h"

using namespace eff::engine;
using namespace eff::common_types;

int main(){

    DateTime time;

    std::cout << time(DateTime::TimeType::Day) << std::endl;

    return EXIT_SUCCESS;
}
