// ConsoleApplication28.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <array>
#include <algorithm>
#include <cmath>

constexpr std::array<double, 3> lambda = { 656.21 , 486.07 ,434.01 };

double rd(double arg, double scal=10.0) {
    return std::round(arg * scal) / scal;
}

const size_t nmax = 10000;

int main()
{
    bool conditionForBreak = false;
    std::array<double, 3> k;
    size_t m = 0;
    size_t n = 1;

    do {
        n = m;
        ++m;
        do {
            ++n;
            for (size_t i = 0; i < 3; ++i) {
                k[i] = lambda[i] * ((n + i + 1.0) * (n + i + 1.0) - m * m) / ((n + i + 1.0) * (n + i + 1.0));
                k[i] = rd(k[i]);
            }
            conditionForBreak = rd(k[1] - k[0]) != 0.0 || rd(k[2] - k[0]) != 0.0;
        }
        while (conditionForBreak && n < 10);
    }
    while (conditionForBreak && m < 6);
    std::cout << "m: " << m << std::endl;
    std::cout << "n: " << n << std::endl;
    for (size_t i = 0; i < 3; ++i) {
        std::cout << "k[" << i << "]: " << k[i] << std::endl;
    }
    
    std::cout << "Rydberg-Konstante: " << m * m/k[2] << std::endl;
}

