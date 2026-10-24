#include <iostream>
#include <cmath>
using namespace std;


double integrate(double(*f)(double), double a, double b, int precision = 100) {
    double temp = 0;
    if (a > b) { //To flip if b is less than a, turning it negative
        temp = b;
        b = a;
        a = temp;
        temp = 1;
    }
    double changeX = (b - a) / (2 * precision);//change of X
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < (2 * precision);i++) {
        sum += f(a + (i * changeX));
    }
    sum = sum * changeX;
    if (temp == 1) {
        sum = sum * -1;
    }
    return sum;
}

double power4(double x) {
    return x * x * x * x;
}
double power3(double x) {
    return x * x * x;
}
double power2(double x) {
    return x * x;
}

int main()
{
    double x = integrate(sin, 0, 3, 100); //~ 1.99
    cout << x << endl;
    double y = integrate(power4, 0, 2, 100); // ~6.4
    cout << y << endl;
    double z = integrate(power3, 4, -3, 100); // ~-43.75
    cout << z << endl;
}