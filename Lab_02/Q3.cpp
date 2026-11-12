
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return 2*x - 3 - cos(x);
}

double phi(double x) {
    return (3 + cos(x))/2;
}

int main() {
    double x = 1.5;
    double tol = 1e-6;

    // Fixed Point Iteration
    cout << fixed << setprecision(10);
    cout << "Fixed Point Iteration\n";

    for(int i = 1; i <= 100; i++) {
        double xn = phi(x);
        double error = fabs(xn - x);

        cout << i << "\t" << xn << "\t"
             << error << "\n";

        x = xn;

        if(error < tol)
            break;
    }

    cout << "Fixed Point Root = " << x << "\n";

    // Aitken's Delta Square Method
    cout << "\nAitken Method\n";

    double a = 1.5;
    double root = a;

    for(int i = 1; i <= 100; i++) {
        double b = phi(a);
        double c = phi(b);

        double den = c - 2*b + a;

        if(fabs(den) < 1e-15)
            break;

        double z = a - (b-a)*(b-a)/den;

        double error = fabs(z - root);

        cout << i << "\t" << z << "\t"
             << error << "\n";

        if(i > 1 && error < tol) {
            root = z;
            break;
        }

        root = z;
        a = b;
    }

    cout << "Aitken Root = " << root << "\n";

    return 0;
}
