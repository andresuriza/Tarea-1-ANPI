#include "funtras.h"
#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
using namespace boost::multiprecision;

// TODO: tan, necesito cos inverso (Andres)

    // Calculo del factorial de un numero n
    // Estructura: factorial(int n)
    // Parametros: n = numero a calcular factorial
    // TODO: quitar recursion y poner un for. Esta durand mucho tiempo 
    cpp_dec_float_50 Fun_tras::factorial(int n)
    {
        n = abs(n); // Se obliga a numero a ser positivo

        if (n == 0 || n == 1) {
            return 1;
        }
        else {
            return n * factorial(n - 1);
        }
    }

    // Calculo del inverso de un numero x
    // Estructura: divi_t(cpp_dec_float_50 x)
    // Parametros: x = numero de punto flotante de precision de 50 decimales a calcular su inverso
    // TODO: Revisar esta porque no esta funcionando
    cpp_dec_float_50 Fun_tras::divi_t(cpp_dec_float_50 x) {
        try {
            if (x <= 0) {
                throw -1;
            }
            else {
                cpp_dec_float_50 x_0 = 0;   // Valor inicial

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
                    cpp_dec_float_50 sk_1 = x_0 * (2 - x * x_0); // Valor actual de sumatoria
                    cpp_dec_float_50 stop = sk_1 - x_0; // Criterio de parada
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
            cout << "Error: x menor o igual a 0" << endl;
            return -1;
        }
    }

    // Calculo del seno de un numero x
    // Estructura: sin_t(int x)
    // Parametros: x = numero entero a calcular seno
    cpp_dec_float_50 Fun_tras::sin_t(int x) {
        cpp_dec_float_50 sk = 0;    // Valor anterior de sumatoria

        for (int n = 0; n <= iterMax; n++)
        {
            cpp_dec_float_50 sk_1 = sk + pow(-1, n) * pow(x, (2 * n + 1)) * divi_t((factorial(2 * n + 1))); // Valor actual de sumatoria
            cpp_dec_float_50 stop = sk_1 - sk;  // Criterio de parada
            sk = sk_1;

            if (abs(stop) < tol) {
                return sk;
                break;
            }
        }
    }

    // Calculo del seno hiperbolico de un numero x
    // Estructura: sinh_t(int x)
    // Parametros: x = numero entero a calcular seno hiperbolico
    cpp_dec_float_50 Fun_tras::sinh_t(int x) {
        cpp_dec_float_50 sk = 0; // Valor anterior de sumatoria

        for (int n = 0; n <= iterMax; n++)
        {
            cpp_dec_float_50 sk_1 = sk + pow(x, (2 * n + 1)) * divi_t(factorial(2 * n + 1)); // Valor actual de sumatoria
            cpp_dec_float_50 stop = sk_1 - sk;  // Criterio de parada
            sk = sk_1;

            if (abs(stop) < tol) {
                return sk;
                break;
            }
        }
    }

    cpp_dec_float_50 Fun_tras::cos_t(int x) {
        cpp_dec_float_50 prev_sum = 0; // Variable para almacenar la suma anterior y comprobar la convergencia.

        // Iterar hasta que la serie converja o se alcance el número máximo de iteraciones.
        for (int n = 0; n <= iterMax; n++) {
            cpp_dec_float_50 sum = prev_sum + (pow(-1, n) * pow(x, 2 * n) * divi_t(factorial(2 * n)));
            cpp_dec_float_50 stop = sum - prev_sum;
            prev_sum = sum; // Guardar la suma anterior antes de añadir el nuevo término.

            if (abs(stop) < tol) {
                return prev_sum;
                break;
            }
        }
    }

    cpp_dec_float_50 Fun_tras::ln_t(int x) {
        try {
            if (x <= 0) {
                throw - 1;
            }

            else {

                cpp_dec_float_50 sk = 0;

                for (int n = 0; n <= iterMax; n++)
                {
                    cpp_dec_float_50 sk_1 = sk + divi_t(2 * n + 1) * pow((x - 1) * divi_t(x + 1), 2 * n);
                    cpp_dec_float_50 stop = sk_1 - sk;
                    sk = sk_1;

                    if (abs(stop) < tol) {
                        return 2 * (x - 1) * divi_t(x + 1) * sk;
                        break;
                    }
                }
            }
        }
        catch (int error)
        {
            cout << "Error: numero menor o igual a 0" << endl;
            return -1;
        }
    }

    // Calculo del logaritmo de un numero x, base y
    // Estructura: log_t(int x, int y)
    // Parametros: x = numero entero a calcular logaritmo
    // y = base entera del logaritmo
    cpp_dec_float_50 Fun_tras::log_t(int x, int y) {
        try {
            if (x <= 0) {
                throw - 1;
            }
            else {
                return ln_t(x) * divi_t(ln_t(y));
            }
        }
        catch (int error)
        {
            cout << "Error: numero menor o igual a 0" << endl;
            return -1;
        }
    }

    /*
    Calculo de tangente h
    Estructura: tanh_t(int x) VER SI NECESITA FLOATS
    Parametros: x = numero entero a calcular logaritmo
    sinh(x)/cosh(x)
   
    cpp_dec_float_50 Fun_tras::tanh_t(int x){

    }

    TODO: ocupo la funcion cosh(x)
     */

     /*
     Calculo de arctan(x)
     Estructura: atan_t(x)
     Parametros: x = numero entero a calcular logaritmo
     TODO: ver si esta funcion puede admitir floats
     */

     cpp_dec_float_50 Fun_tras::atan_t(int x){
        if (-1 <= x <= 1)
        {
            cpp_dec_float_50 prev_sum = 0;
            for (int i = 0; i < iterMax; i++)
            {
                cpp_dec_float_50 sum = prev_sum + (pow(-1, i) + pow(x, 2*i+1) * divi_t(2*i+1));
                
                cpp_dec_float_50 stop = sum - prev_sum;
                prev_sum = sum; // Guardar la suma anterior antes de añadir el nuevo término.

                if (abs(stop) < tol) {
                    return prev_sum;
                    break;
                }
                
            }
            
        } else if (x > 1)
        {
            cpp_dec_float_50 prev_sum = 0;
            for (int i = 0; i < iterMax; i++)
            {
                cpp_dec_float_50 sum = prev_sum + (1 * divi_t((2 * i + 1) * pow(x, 2 * i - 1)));
                
                cpp_dec_float_50 stop = sum - prev_sum;
                prev_sum = sum; // Guardar la suma anterior antes de añadir el nuevo término.

                if (abs(stop) < tol) {
                    return pi_t * divi_t(2) - prev_sum;
                    break;
                }
                
            }
        } else if (x < -1)
        {
            cpp_dec_float_50 prev_sum = 0;
            for (int i = 0; i < iterMax; i++)
            {
                cpp_dec_float_50 sum = prev_sum + (1 * divi_t((2 * i + 1) * pow(x, 2 * i - 1)));
                
                cpp_dec_float_50 stop = sum - prev_sum;
                prev_sum = sum; // Guardar la suma anterior antes de añadir el nuevo término.

                if (abs(stop) < tol) {
                    return -1 * pi_t * divi_t(2) - prev_sum;
                    break;
                }
                
            }
        }
        
        
        
     }

int main(int argc, char const* argv[])
{
    Fun_tras calc1;

    cpp_dec_float_50 cos_result = calc1.factorial(9);
    cout << setprecision(std::numeric_limits<cpp_dec_float_50>::max_digits10) << cos_result << endl;
    
    return 0;
}