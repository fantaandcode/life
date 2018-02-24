#include <stdio.h>
#include <stdlib.h>

double factorial(double n) {
        if (n == 0 || n == 1) return (1);
        else    return (n * factorial(n - 1));
}

double power(double num, double p) {
        double result = 1;
        double i;
        for (i = 1; i <= p; i++) {
                result *= num;
        }
        return result;
}

double sine(double n) {
        double sum = 0;
        double k;

        for (k = 0; k < 10; k++) {
                double p = power(-1, k);
                double px = power(n, 2*k+1);
                double fac = factorial(2*k + 1);
                sum += (p * px) / fac;
        }
        return sum;
}
double integrate(int f, double a, double b, double deltax) {
        double N = ((b - a)/deltax);
        int k = 0;
        double result = 0;
        if (f == 1) {
        	for (k = 0; k <= N; k++) {
                result += ((sine(a+(k*deltax)) + sine(a+(k+1)*deltax))/2)*deltax;
            }
            return result;
        }
        if (f == 2) {
        	for (k = 0; k <= N; k++) {
                result += ((power(a+(k*deltax), 2) + power(a+(k+1)*deltax, 2))/2)*deltax;
            }
            return result;
        }
        if (f == 3) {
        	for (k = 0; k <= N; k++) {
                result += ((sine(power(a+(k*deltax), 2)) +sine(power(a+(k+1)*deltax, 2)))/2)*deltax;
            }
            return result;
        } else {
                printf("invalid input");
                return result;
        }
}

int main(int args, char **argv) {

        if (args != 5) {
                printf("Not enough arguments.\n");
                return 0;
        }

        double deg, up, low, delta;
        deg = atof(argv[1]);
        up = atof(argv[2]);
        low = atof(argv[3]);
        delta = atof(argv[4]);

        printf("integral value = %f\n", integrate(deg, up, low, delta));

        return 0;
}