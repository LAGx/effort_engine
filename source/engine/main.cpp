#include <iostream>
#include <cstdlib>
#include "engine/meta.h"

using namespace eff::engine;

int main(){

        std::cout << "version: " << meta::MODULE_NAME << std::endl;

        return EXIT_SUCCESS;
}
