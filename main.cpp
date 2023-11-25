#include <iostream>
#include "Subject.h"
#include "Wrapper.h"
#include "Engine.h"

int main() {
    Subject subj;

    //work with int elements
    Wrapper<int> wrapper(&subj, &Subject::f3, {{"arg1", 0}, {"arg2", 0}});
    Engine engine;
    engine.register_command<int>(&wrapper, "command1");
    std::cout << engine.execute<int>("command1", {{"arg1", 4}, {"arg2", 5}}) << std::endl;
    //result: 1024
    //work with double elements
    Wrapper<double> wrapperD(&subj, &Subject::f3d, {{"arg1", 0}, {"arg2", 0},{"arg3",0}});
    Engine engineD;
    engineD.register_command<double>(&wrapperD, "command1");
    std::cout << engineD.execute<double>("command1", {{"arg1", 4}, {"arg2", 5}}) << std::endl;
    //result: 0.8
    return 0;
};
