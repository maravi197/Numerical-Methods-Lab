
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    const int n = 15;

    // Sub-diagonal
    double a[n] = {
        0, -1.0, -1.1, -1.3, -1.0,
        -1.2, -1.5, -1.1, -1.0, -1.4,
        -1.2, -1.0, -1.3, -1.1, -1.2
    };

    // Main diagonal
    double b[n] = {
        4.5, 4.8, 5.0, 4.6, 5.2,
        4.9, 5.5, 4.7, 5.0, 4.8,
        5.1, 4.6, 5.3, 4.9, 4.5
    };

    // Super-diagonal
    double c[n] = {
        -1.2, -1.5, -1.2, -1.0, -1.4,
        -1.1, -1.3, -1.2, -1.5, -1.1,
        -1.3, -1.2, -1.0, -1.4, 0
    };

    // RHS
    double d[n] = {
        10.5, 12.0, -8.5, 15.2, 6.8,
        -4.0, 22.1, 11.5, -9.3, 14.0,
        7.4, -2.5, 18.6, 5.0, 13.2
    };

    double B[n], D[n], x[n];

    // Copy main diagonal and RHS
    for (int i = 0; i < n; i++) {
        B[i] = b[i];
        D[i] = d[i];
    }

    // Forward elimination
    for (int i = 1; i < n; i++) {
        double m = a[i] / B[i-1];

        B[i] = B[i] - m * c[i-1];
        D[i] = D[i] - m * D[i-1];
    }

    // Backward substitution
    x[n-1] = D[n-1] / B[n-1];

    for (int i = n-2; i >= 0; i--) {
        x[i] = (D[i] - c[i] * x[i+1]) / B[i];
    }

    // Print solution
    cout << fixed << setprecision(6);

    cout << "Solution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i+1 << "] = " << x[i] << "\n";
    }

    // Calculate infinity norm of residual
    double error = 0;

    for (int i = 0; i < n; i++) {
        double sum = b[i] * x[i];

        if (i > 0)
            sum += a[i] * x[i-1];

        if (i < n-1)
            sum += c[i] * x[i+1];

        double r = fabs(d[i] - sum);

        error = max(error, r);
    }

    cout << setprecision(12);
    cout << "\nResidual infinity norm = " << error << "\n";

    return 0;
}
