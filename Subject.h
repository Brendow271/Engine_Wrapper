#pragma once
#include <cmath>

class Subject {
    public:
    int f1(int a) {
        return a + 4;
    };

    int f2(int a) {
        return a - 4;
    };

    int f3(int a, int b) {
        return  (int) pow(a,b);
    };
};

