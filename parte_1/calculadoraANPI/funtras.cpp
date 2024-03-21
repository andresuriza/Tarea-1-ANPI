﻿#include "funtras.h"
#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
using namespace boost::multiprecision;

// TODO: tan, necesito cos inverso (Andres)

    // Calculo del factorial de un numero n
    // Estructura: factorial(int n)
    // Parametros: n = numero a calcular factorial
    cpp_dec_float_50 Fun_tras::factorial(int  n)
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
    cpp_dec_float_50 Fun_tras::divi_t(cpp_dec_float_50 x) {
        try {
            if (x > 0) {
                cpp_dec_float_50 x_0;   // Valor inicial

                if (x >= factorial(100)) {
                    return 0;
                }
                else {
                    if (factorial(80) < x <= factorial(100))
                    {
                        x_0 = pow(eps, 15);
                    }

                    else if (factorial(60) < x <= factorial(80))
                    {
                        x_0 = pow(eps, 11);
                    }

                    else if (factorial(40) < x <= factorial(60))
                    {
                        x_0 = pow(eps, 8);
                    }


                    else if (factorial(20) < x <= factorial(40))
                    {
                        x_0 = pow(eps, 4);
                    }

                    else if (0 < x <= factorial(20))
                    {
                        x_0 = pow(eps, 2);
                    }

                    cpp_dec_float_50 sk = x_0;

                    for (int n = 0; n <= iterMax; n++)
                    {
                        cpp_dec_float_50 sk_1 = sk * (2 - x * sk); // Valor actual de sumatoria
                        cpp_dec_float_50 stop = sk_1 - sk; // Criterio de parada
                        sk = sk_1;

                        if (abs(stop) < tol * abs(sk_1)) {
                            return sk_1;
                            break;
                        }
                    }
                }
            }

            else {
                throw -1;
            }
        }
        catch (int error) {
            cout << "Error: x menor o igual a 0" << endl;
        }
    }


    // Calculo del seno de un numero x
    // Estructura: sin_t(int x)
    // Parametros: x = numero entero a calcular seno
    cpp_dec_float_50 Fun_tras::sin_t(cpp_dec_float_50 x) {
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
    // TODO: revisar el dominio
    cpp_dec_float_50 Fun_tras::sinh_t(cpp_dec_float_50 x) {
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

    // TODO: revisar el dominio
    cpp_dec_float_50 Fun_tras::asin_t(cpp_dec_float_50 x) {
        try {
            if ((-1 <= x) && (x <= 1)) {
                cpp_dec_float_50 sk = 0; // Valor anterior de sumatoria

                for (int n = 0; n <= iterMax; n++)
                {
                    cpp_dec_float_50 sk_1 = sk + (factorial(2 * n) * pow(x, (2 * n + 1))) * divi_t((pow(4, n) * pow(factorial(n), 2) * (2 * n + 1))); // Valor actual de sumatoria
                    cpp_dec_float_50 stop = sk_1 - sk;  // Criterio de parada
                    sk = sk_1;

                    if (abs(stop) < tol) {
                        return sk;
                        break;
                    }
                }
            }

            else {
                throw -1;
            }
        }

        catch (int error) {
            cout << "Numero no esta en el dominio" << endl;
            return -1;
        }

    }

    cpp_dec_float_50 Fun_tras::cos_t(cpp_dec_float_50 x) {
        cpp_dec_float_50 prev_sum = 0; // Variable para almacenar la suma anterior y comprobar la convergencia.

        // Iterar hasta que la serie converja o se alcance el número máximo de iteraciones.
        for (int n = 0; n <= iterMax; n++) {
            cpp_dec_float_50 sum = prev_sum + ((pow(-1, n) * pow(x, (2 * n))) * (divi_t(factorial(2 * n))));
            cpp_dec_float_50 stop = sum - prev_sum;
            prev_sum = sum; // Guardar la suma anterior antes de añadir el nuevo término.

            if (abs(stop) < tol) {
                return prev_sum;
                break;
            }
        }
    }
    
    // Calculo del coseno hiperbolico de un numero x
    // Estructura: cosh_t(cpp_dec_float_50 x)
    // Parametros: x = numero a calcular coseno hiperbolico
    cpp_dec_float_50 Fun_tras::cosh_t(cpp_dec_float_50 x) {
        cpp_dec_float_50 sk = 0; // Valor anterior de sumatoria

        for (int n = 0; n <= iterMax; n++)
        {
            cpp_dec_float_50 sk_1 = sk + pow(x, (2 * n)) * divi_t(factorial(2 * n)); // Valor actual de sumatoria
            cpp_dec_float_50 stop = sk_1 - sk;  // Criterio de parada
            sk = sk_1;

            if (abs(stop) < tol) {
                return sk;
                break;
            }
        }
    }

    // TODO: verificar dominio 
    cpp_dec_float_50 Fun_tras::acos_t(cpp_dec_float_50 x) {
        try {
            if ((-1 <= x) && (x <= 1)) {
                cpp_dec_float_50 temp_asin_t = asin_t(x);
                return (pi_t * divi_t(2)) - temp_asin_t;
            }

            else {
                throw -1;
            }
        }

        catch (int error) {
            cout << "Numero no esta en el dominio" << endl;
            return -1;
        }
    }

    cpp_dec_float_50 Fun_tras::ln_t(cpp_dec_float_50  x) {
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
    cpp_dec_float_50 Fun_tras::log_t(cpp_dec_float_50  x, cpp_dec_float_50 y) {
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
            //cout << "Error: numero menor o igual a 0" << endl;
            return -1;
        }
    }

    cpp_dec_float_50 Fun_tras::root_t(cpp_dec_float_50  x, cpp_dec_float_50  y) {
        try {
            if ((x && y) > 0) {
                cpp_dec_float_50 sk = x * divi_t(2);

                for (int n = 0; n <= iterMax; n++)
                {
                    cpp_dec_float_50 sk_1 = sk - (pow(sk, y) - x) * divi_t((y * pow(sk, (y - 1))));
                    cpp_dec_float_50 stop = sk_1 - sk;
                    sk = sk_1;

                    if (abs(stop) < tol * abs(sk_1)) {
                        return sk;
                        break;
                    }
                }
            }

            else {
                throw -1;
            }
        }

        catch (int error) {
            cout << "Error: Índice o radicando menores a 0";
            return -1;
        }
    }

    cpp_dec_float_50 Fun_tras::sqrt_t(cpp_dec_float_50  x) {
        return root_t(x, 2);
    }

    cpp_dec_float_50 Fun_tras::tanh_t(cpp_dec_float_50 x) {
        return (sinh_t(x) * divi_t(cosh_t(x)));
    }

     /*
     Calculo de arctan(x)
     Estructura: atan_t(x)
     Parametros: x = numero entero a calcular logaritmo
     TODO: ver si esta funcion puede admitir floats
     */

     cpp_dec_float_50 Fun_tras::atan_t(cpp_dec_float_50 x){
            cpp_dec_float_50 prev_sum = 0;

            for (int n = 0; n <= iterMax; n++)
            {
                cpp_dec_float_50 sum = prev_sum + pow(-1, n) * pow(x, (2 * n + 1)) * divi_t((2 * n + 1));
                cout << sum << endl;
                cpp_dec_float_50 stop = sum - prev_sum;
                cout << stop << endl;
               

                if (abs(stop) < tol) {
                    return prev_sum;
                    break;
                }
                else {
                    prev_sum = sum; // Guardar la suma anterior antes de añadir el nuevo término.
                }
            }

        if (x > 1)
        {
            cpp_dec_float_50 prev_sum = 0;
            for (int i = 0; i < iterMax; i++)
            {
                cpp_dec_float_50 sum = prev_sum + pow(-1,i)  * divi_t((2 * i + 1) * pow(x, (2 * i - 1)));

                cpp_dec_float_50 s_k = pi_t * divi_t(2) - prev_sum;
                cpp_dec_float_50 s_k_1 = pi_t * divi_t(2) - sum;

                cpp_dec_float_50 stop = s_k_1 - s_k;

                if (abs(stop) < tol) {
                    return pi_t * divi_t(2) - prev_sum;
                    break;
                }
                else {
                    prev_sum = sum; // Guardar la suma anterior antes de añadir el nuevo término.
                }
                
            }
        }
        if (x < -1)
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

     cpp_dec_float_50 Fun_tras::tan_t(cpp_dec_float_50 x) {
         return (sin_t(x) * divi_t(cos_t(x)));
     }


     /*
     * TODO: Verificar el dominio de la funcion
     */
     cpp_dec_float_50 Fun_tras::sec_t(cpp_dec_float_50 x) {
         cpp_dec_float_50 temp_cos_t = cos_t(x);
         if (temp_cos_t == 0) {
             cout << "Error sec_t" << endl;
         }
         else {
             return 1 * divi_t(temp_cos_t);
         }
         
     }

     /*
        * TODO: Verificar el dominio de la funcion
        */
     cpp_dec_float_50 Fun_tras::csc_t(cpp_dec_float_50 x) {
         cpp_dec_float_50 temp_sin_t = sin_t(x);
         if (temp_sin_t == 0) {
             cout << "Error sec_t" << endl;
         }
         else {
             return 1 * divi_t(temp_sin_t);
         }

     }

     // TODO: verificar dominio
     cpp_dec_float_50 Fun_tras::cot_t(cpp_dec_float_50 x) {
         try
         {
             cpp_dec_float_50 temp_tan_t = tan_t(x);

             return divi_t(temp_tan_t);
         }
         catch (const std::exception&)
         {
             cout << "Error: cotangente" << endl;
         }
         
     }

     // TODO: comprobar el dominio de la funcion
     cpp_dec_float_50 Fun_tras::exp_t(cpp_dec_float_50 x) {
         cpp_dec_float_50 sk = 0;    // Valor anterior de sumatoria

         for (int n = 0; n <= iterMax; n++)
         {
             cpp_dec_float_50 sk_1 = sk + pow(x, n) * divi_t(factorial(n)); // Valor actual de sumatoria
             cpp_dec_float_50 stop = sk_1 - sk;  // Criterio de parada
             sk = sk_1;

             if (abs(stop) < tol) {
                 return sk;
                 break;
             }
         }
     }

     cpp_dec_float_50 Fun_tras::power_t(cpp_dec_float_50 x, int y) {
         try
         {
            if (y <= 0) {
                throw -1;
            }
            else {
                cpp_dec_float_50 result = x;

                for (int i = 1; i < y; ++i) {
                   result = result * x;
                }

                return result;
            }
         }

         catch (int error)
         {
            cout << "Error: numero menor o igual a 0" << endl;
            return -1;
         }
     }

/*
int main(int argc, char const* argv[])
{
    Fun_tras calc1;

    cpp_dec_float_50 root = calc1.root_t(-2, 0.5);
    cout << setprecision(std::numeric_limits<cpp_dec_float_50>::max_digits10) << root << endl;


    return 0;
}
*/