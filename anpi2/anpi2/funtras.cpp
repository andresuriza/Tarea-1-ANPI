#include "funtras.h"
#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
using namespace boost::multiprecision;

// Faltan algunas funciones mias (Andres)

    cpp_dec_float_50 Fun_tras::factorial(int n)
    {
        if (n >= 0) {
            if (n == 0 || n == 1) {
                return 1;
            }
            else {
                return n * factorial(n - 1);
            }
        }

        else {
            return -1;
        }
    }

    cpp_dec_float_50 Fun_tras::divi_t(cpp_dec_float_50 x) {
        cpp_dec_float_50 x_0 = 0;

        if (0 < x <= factorial(20))
        {
            x_0 = pow(eps, 2);
        }

        if (factorial(20) < x <= factorial(40))
        {
            x_0 = pow(eps, 4);
        }

        if (factorial(40) < x <= factorial(60))
        {
            x_0 = pow(eps, 8);
        }

        if (factorial(60) < x <= factorial(80))
        {
            x_0 = pow(eps, 11);
        }

        if (factorial(80) < x <= factorial(100))
        {
            x_0 = pow(eps, 15);
        }

        cpp_dec_float_50 num = x_0;

        for (int n = 0; n <= iterMax; n++)
        {
            cpp_dec_float_50 sk_1 = x_0 * (2 - x * x_0);
            cpp_dec_float_50 stop = abs(sk_1 - x_0);
            x_0 = sk_1;

            if (stop < tol * abs(sk_1)) {
                return sk_1;
                break;
            }
        }
    }

    cpp_dec_float_50 Fun_tras::sin_t(int x) {
        cpp_dec_float_50 sk = 0;

        for (int n = 0; n <= iterMax; n++)
        {
            cpp_dec_float_50 sk_1 = sk + pow(-1, n) * pow(x, (2 * n + 1)) * divi_t((factorial(2 * n + 1)));
            cpp_dec_float_50 stop = abs(sk_1 - sk);
            sk = sk_1;

            if (stop < tol) {
                return sk;
                break;
            }
        }
    }


int main(int argc, char const* argv[])
{
    Fun_tras calc1;
    cpp_dec_float_50 result = calc1.sin_t(3); // Caso de prueba
    cout << setprecision(std::numeric_limits<cpp_dec_float_50>::max_digits10) << result << endl;

    return 0;
}