#pragma once

#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
using namespace boost::multiprecision;

class Fun_tras {
private:
    cpp_dec_float_50 tol = pow(10, -8); // Valor de tolerancia a utilizar en la condición de parada
    int iterMax = 2500; // Número de iteraciones máximas a utilizar en las series
    cpp_dec_float_50 pi_t = 3.14159265358979323846; // Valor constante de pi
    cpp_dec_float_50 eps = 2.2204 * pow(10, -16);   // Constante utilizada en la función divi_t

public:
    // Función getter del valor de pi
    cpp_dec_float_50 Get_pi() {
        return (this->pi_t);
    }

    // Calculo del factorial de un numero n
    // Estructura: factorial(int n)
    // Parametros: n = numero a calcular factorial
    cpp_dec_float_50 factorial(int  n)
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
    cpp_dec_float_50 divi_t(cpp_dec_float_50 x) {
        cpp_dec_float_50 temp_x;
        try {
            if (x != 0) {
                if (x < 0) {
                    temp_x = -1 * x;
                }

                else {
                    temp_x = x;
                }

                cpp_dec_float_50 x_0;   // Valor inicial

                if (temp_x >= factorial(100)) {
                    return 0;
                }
                else {
                    if (factorial(80) < temp_x <= factorial(100))
                    {
                        x_0 = pow(eps, 15);
                    }

                    else if (factorial(60) < temp_x <= factorial(80))
                    {
                        x_0 = pow(eps, 11);
                    }

                    else if (factorial(40) < temp_x <= factorial(60))
                    {
                        x_0 = pow(eps, 8);
                    }


                    else if (factorial(20) < temp_x <= factorial(40))
                    {
                        x_0 = pow(eps, 4);
                    }

                    else if (0 < temp_x <= factorial(20))
                    {
                        x_0 = pow(eps, 2);
                    }

                    cpp_dec_float_50 sk = x_0;

                    for (int n = 0; n <= iterMax; n++)
                    {
                        cpp_dec_float_50 sk_1 = sk * (2 - temp_x * sk); // Valor actual de sumatoria
                        cpp_dec_float_50 stop = sk_1 - sk; // Criterio de parada
                        sk = sk_1;

                        if (abs(stop) < tol * abs(sk_1)) {
                            if (x < 0) {
                                return (-1 * sk_1);
                            }
                            else {
                                return sk_1;
                            }
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
    cpp_dec_float_50 sin_t(cpp_dec_float_50 x) {
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
    cpp_dec_float_50 sinh_t(cpp_dec_float_50 x) {
        cpp_dec_float_50 sk = 0; // Valor anterior de sumatoria

        // Iterar hasta que la serie converja o se alcance el número máximo de iteraciones.
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

    // Caldulo de seno inverso de un numero x
    // Estructura: asin_t(float x)
    // Parametros: x = numero a calcular
    cpp_dec_float_50 asin_t(cpp_dec_float_50 x) {
        try {
            if ((-1 <= x) && (x <= 1)) {
                cpp_dec_float_50 sk = 0; // Valor anterior de sumatoria

                // Iterar hasta que la serie converja o se alcance el número máximo de iteraciones.
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

    // Caldulo de coseno de un numero x
    // Estructura: cos_t(float x)
    // Parametros: x = numero a calcular
    cpp_dec_float_50 cos_t(cpp_dec_float_50 x) {
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
    cpp_dec_float_50 cosh_t(cpp_dec_float_50 x) {
        cpp_dec_float_50 sk = 0; // Valor anterior de sumatoria

        // Iterar hasta que la serie converja o se alcance el número máximo de iteraciones.
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

    // Calculo del coseno inverso de un numero x
    // Estuctura: acos_t(float x)
    // Parametros: x = numero a calcular
    cpp_dec_float_50 acos_t(cpp_dec_float_50 x) {
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

    // Calculo de logaritmo natural de un numero x
    // Estructura: ln_t(float x)
    // Parametros: x = numero a calcular
    cpp_dec_float_50 ln_t(cpp_dec_float_50  x) {
        try {
            if (x <= 0) {
                throw - 1;
            }

            else {

                cpp_dec_float_50 sk = 0;

                // Iterar hasta que la serie converja o se alcance el número máximo de iteraciones.
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
    cpp_dec_float_50 log_t(cpp_dec_float_50  x, cpp_dec_float_50 y) {
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

    // Calculo del raiz de un numero x, base y
    // Estructura: root_t(float x, float y)
    // Parametros: x = numero float, y = numero float
    cpp_dec_float_50 root_t(cpp_dec_float_50  x, cpp_dec_float_50  y) {
        if (ceilf(float(y)) == float(y)) { // Si y es entero
            int yInt = static_cast<int>(y);
            try {
                if (yInt >= 2) {
                    if ((yInt % 2) == 0) {
                        try {
                            if (x > 0) {
                                cpp_dec_float_50 sk = x * divi_t(2);

                                for (int n = 0; n <= iterMax; n++)
                                {
                                    cpp_dec_float_50 sk_1 = sk - (pow(sk, yInt) - x) * divi_t((yInt * pow(sk, (yInt - 1))));
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
                            return -1;
                        }
                    }
                    else {
                        cpp_dec_float_50 sk = x * divi_t(2);

                        for (int n = 0; n <= iterMax; n++)
                        {
                            cpp_dec_float_50 sk_1 = sk - (pow(sk, yInt) - x) * divi_t((yInt * pow(sk, (yInt - 1))));
                            cpp_dec_float_50 stop = sk_1 - sk;
                            sk = sk_1;

                            if (abs(stop) < tol * abs(sk_1)) {
                                return sk;
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
                return -1;
            }
        }
        else {
            return power_t(x, 1/y); // Cambiar con divi_t
        }
    }

    // Calculo del raiz cuadrada de un numero x, base y
    // Estructura: sqrt_t(float x)
    // Parametros: x = numero a calcular
    cpp_dec_float_50 sqrt_t(cpp_dec_float_50  x) {
        return root_t(x, 2);
    }

    // Calculo del tangente hiperbolica de un numero
    // Estructura: tanh_t(float x)
    // Parametros: x = numero a calcular
    cpp_dec_float_50 tanh_t(cpp_dec_float_50 x) {
        // se calcula a partir de identidades trigonometricas
        return (sinh_t(x) * divi_t(cosh_t(x)));
    }

    /*
     Calculo de arctan(x)
     Estructura: atan_t(x)
     Parametros: x = numero entero a calcular logaritmo
     */
    cpp_dec_float_50 atan_t(cpp_dec_float_50 x){
        cpp_dec_float_50 sk = 0;    // Valor anterior de sumatoria
        if ((-1 <= x) && (x <= 1)) {
            for (int n = 0; n <= iterMax; n++)
            {
                cpp_dec_float_50 sk_1 = sk + (((pow(-1, n) * pow(x, (2 * n + 1)))) * divi_t(2 * n + 1)); // Valor actual de sumatoria
                cpp_dec_float_50 stop = sk_1 - sk;  // Criterio de parada
                sk = sk_1;

                if (abs(stop) < tol) {
                    break;
                }
            }
        }

        else if (x >= 1) {
            for (int n = 0; n <= iterMax; n++)
            {
                cpp_dec_float_50 sk_1 = sk + (pow(-1, n) * divi_t((2 * n + 1) * pow(x, (2 * n + 1)))); // Valor actual de sumatoria
                cpp_dec_float_50 stop = sk_1 - sk;  // Criterio de parada
                sk = sk_1;

                if (abs(stop) < tol) {
                    //return (pi_t * divi_t(2)) - sk;
                    sk = (pi_t * divi_t(2)) - sk;
                    break;
                }
            }
        }

        else if (x <= -1) {
            for (int n = 0; n <= iterMax; n++)
            {
                cpp_dec_float_50 sk_1 = sk + (pow(-1, n) * divi_t((2 * n + 1) * pow(x, (2 * n + 1)))); // Valor actual de sumatoria
                cpp_dec_float_50 stop = sk_1 - sk;  // Criterio de parada
                sk = sk_1;

                if (abs(stop) < tol) {
                    sk = ((-1 * pi_t) * divi_t(2)) - sk;
                    break;
                }
            }
        }

        return sk;
    }

    // Calculo del tangente de un numero
    // Estructura: tanh_t(float x)
    // Parametros: x = numero a calcular
    cpp_dec_float_50 tan_t(cpp_dec_float_50 x) {
        try {
            // se calcula con base a identidades trigonometricas
            return (sin_t(x) * divi_t(cos_t(x)));
        } catch (const std::exception&) {
            cout << "Error: tangente" << endl;
            return -1;
        }

    }

    /*
     * Calculo de secante de un numero
     * Estructura: sec_t(float x)
     * Parametro: x = numero a calcular
    */
    cpp_dec_float_50 sec_t(cpp_dec_float_50 x) {
        try {
            // calculo de coseno
            cpp_dec_float_50 temp_cos_t = cos_t(x);
            // verifica que sea diferente de cero para evitar division por cero
            if (temp_cos_t == 0) {
                cout << "Error sec_t" << endl;
                return -1;
            }
            else {
                // calculo por identidades trigonometricas
                return 1 * divi_t(temp_cos_t);
            }
        } catch (const std::exception&) {
            cout << "Error: secante" << endl;
            return -1;
        }


    }

    /*
     * Calcula de cosecante de un numero
     * Estructura: csc_t(float x)
     * Parametros: x = numero a calcular
     */
    cpp_dec_float_50 csc_t(cpp_dec_float_50 x) {
        try {
            // calculo de seno
            cpp_dec_float_50 temp_sin_t = sin_t(x);

            if (temp_sin_t == 0) {
                cout << "Error sec_t" << endl;
                return -1;
            }
            else {
                // calculo de csc a partir de identidaes trigonometrica
                return 1 * divi_t(temp_sin_t);
            }
        } catch (const std::exception&) {
            cout << "Error: cosecante" << endl;
            return -1;
        }



        // verifica que sea diferente de cero


    }

    // Calculo de cotangente de un numero
    // Estructura: cot_t(float x)
    // Parametros: x = numero a calcular
    cpp_dec_float_50 cot_t(cpp_dec_float_50 x) {
        // calculo de tangente en caso de dar resultado calcula por identidad trigonometrica la cot
        try
        {
            cpp_dec_float_50 temp_tan_t = tan_t(x);

            return divi_t(temp_tan_t);
        }
        catch (const std::exception&)
        {
            cout << "Error: cotangente" << endl;
            return -1;
        }

    }

    // Calculo de euler a la exponente
    // Parametros: x = numero a calcular
    // Estructura: exp_t(float x)
    cpp_dec_float_50 exp_t(cpp_dec_float_50 x) {
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

    // Calculo de un numero a la potencia
    // Estructura: power_t(float x)
    // Parametros : x = numero a calcular
    cpp_dec_float_50 power_t(cpp_dec_float_50 x, cpp_dec_float_50 y) {
        return exp_t(y * ln_t(x));
    }
};
