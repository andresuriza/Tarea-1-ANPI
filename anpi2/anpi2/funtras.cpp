#include "funtras.h"
#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
using namespace boost::multiprecision;

// TODO: tan, log, necesito las otras funciones, cos y ln (Andres)

    cpp_dec_float_50 Fun_tras::factorial(int n)
    {
        n = abs(n);

        if (n == 0 || n == 1) {
            return 1;
        }
        else {
            return n * factorial(n - 1);
        }
    }

    cpp_dec_float_50 Fun_tras::divi_t(cpp_dec_float_50 x) {
        try {
            if (x == 0) {
                throw -1;
            }
            else {
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
                    cpp_dec_float_50 stop = sk_1 - x_0;
                    x_0 = sk_1;

                    if (abs(stop) < tol * abs(sk_1)) {
                        return sk_1;
                        break;
                    }
                }
            }
        }

        catch (int error)
        {
            cout << "Error: division por 0" << endl;
            return -1;
        }
    }

    cpp_dec_float_50 Fun_tras::sin_t(int x) {
        cpp_dec_float_50 sk = 0;

        for (int n = 0; n <= iterMax; n++)
        {
            cpp_dec_float_50 sk_1 = sk + pow(-1, n) * pow(x, (2 * n + 1)) * divi_t((factorial(2 * n + 1)));
            cpp_dec_float_50 stop = sk_1 - sk;
            sk = sk_1;

            if (abs(stop) < tol) {
                return sk;
                break;
            }
        }
    }

    cpp_dec_float_50 Fun_tras::sinh_t(int x) {
        cpp_dec_float_50 sk = 0;

        for (int n = 0; n <= iterMax; n++)
        {
            cpp_dec_float_50 sk_1 = sk + pow(x, (2 * n + 1)) * divi_t(factorial(2 * n + 1));
            cpp_dec_float_50 stop = sk_1 - sk;
            sk = sk_1;

            if (abs(stop) < tol) {
                return sk;
                break;
            }
        }
    }




    //cos


    cpp_dec_float_50 Fun_tras::cos_t(cpp_dec_float_50 a) {
        // Convertir a radianes
        a = a * pi_t / 3;

        cpp_dec_float_50 sum = 1; // El primer término de la serie de Taylor para cos(a) es 1.
        cpp_dec_float_50 term = 1; // Inicializamos el término actual de la serie.
        cpp_dec_float_50 prev_sum = 0; // Variable para almacenar la suma anterior y comprobar la convergencia.

        // Iterar hasta que la serie converja o se alcance el número máximo de iteraciones.
        for (int n = 1; n <= iterMax && abs(term) >= tol; ++n) {
            term *= -a * a / ((2 * n - 1) * (2 * n)); // Actualizar el término actual de la serie.
            prev_sum = sum; // Guardar la suma anterior antes de añadir el nuevo término.
            sum += term; // Añadir el nuevo término a la suma acumulativa.

            if (abs(sum - prev_sum) < tol) {
                break;
            }
        }

        return sum;
    }





    cpp_dec_float_50 Fun_tras::ln_t(cpp_dec_float_50 a) {
        if (a <= 0) {
            cout << "Error: 'a' debe ser mayor que 0" << endl;
            return cpp_dec_float_50(0); // Retornar 0 para indicar un error.
        }

        cpp_dec_float_50 factor = 2 * (a - 1) / (a + 1);

        cpp_dec_float_50 x = (a - 1) / (a + 1);
        cpp_dec_float_50 x_pow_2n = x; // Inicia con x^1 ya que n=0.

        cpp_dec_float_50 sum = x; // Inicializar con el primer término de la serie.

        cpp_dec_float_50 prev_sum = 0;

        for (int n = 1; n <= iterMax; ++n) {
            x_pow_2n *= x * x;

         
            cpp_dec_float_50 current_term = x_pow_2n / (2 * n + 1);

            prev_sum = sum;
            sum += current_term;

            if (abs(current_term) < tol) {
                break;
            }
        }

        return factor * sum;
    }




int main(int argc, char const* argv[])
{
    Fun_tras calc1;
    cpp_dec_float_50 result = calc1.sinh_t(3); // Caso de prueba

    cout << setprecision(std::numeric_limits<cpp_dec_float_50>::max_digits10) << result << endl;


    // Prueba para la función cos_t con π/3 como argumento
    cpp_dec_float_50 cos_result = calc1.cos_t(0); // cos(4)
    cout  << setprecision(std::numeric_limits<cpp_dec_float_50>::max_digits10) << cos_result << endl;

    // Prueba para la función ln_t con e (base de los logaritmos naturales) como argumento
    cpp_dec_float_50 ln_result = calc1.ln_t(1); // ln(e)
    cout << setprecision(std::numeric_limits<cpp_dec_float_50>::max_digits10) << ln_result << endl;



    return 0;
}