#include <iostream>
#include "Subject.h"
#include "Wrapper.h"
#include "Engine.h"

int main() {
    Subject subj;

    Wrapper<int> wrapper(&subj, &Subject::f3, {{"arg1", 0}, {"arg2", 0}});
    Engine engine;

    engine.register_command<int>(&wrapper, "command1");

    std::cout << engine.execute<int>("command1", {{"arg1", 4}, {"arg2", 5}}) << std::endl;

    return 0;
};
