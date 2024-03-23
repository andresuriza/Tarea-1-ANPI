#include "funtras.h"

int main(int argc, char const* argv[])
{
    Fun_tras calc;

    cpp_dec_float_50 test = (calc.root_t((calc.cos_t(3 * calc.divi_t(7)) + calc.ln_t(2)), 3) * calc.divi_t(calc.sinh_t(calc.sqrt_t(2)))) + calc.atan_t(calc.exp_t(-1));
    cout << setprecision(std::numeric_limits<cpp_dec_float_50>::max_digits10) << test << endl;

    return 0;
}
