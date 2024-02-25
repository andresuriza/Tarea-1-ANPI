#pragma once

#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
using namespace boost::multiprecision;

class Fun_tras {
private:
    cpp_dec_float_50 tol = pow(10, -8);
    int iterMax = 2500;
    cpp_dec_float_50 pi_t = 3.14159265358979323846;
    cpp_dec_float_50 eps = 2.2204 * pow(10, -16);

public:

    cpp_dec_float_50 factorial(int n);
    cpp_dec_float_50 divi_t(cpp_dec_float_50 x);
    cpp_dec_float_50 sin_t(int x);
    cpp_dec_float_50 sinh_t(int x);
};

