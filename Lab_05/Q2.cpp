
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

bool solve(double alpha, double beta, double x[], int &failPivot) {
    const int n = 4;

    double a[n] = {0, -1, -1, -1};
    double b[n] = {2, alpha, beta, 2};
    double c[n] = {-1, -1, -1, 0};
    double d[n] = {1, 2, 2, 1};

    double B[n], D[n];

    for (int i = 0; i < n; i++) {
        B[i] = b[i];
        D[i] = d[i];
    }

    // Forward elimination
    for (int i = 1; i < n; i++) {

        if (fabs(B[i-1]) < 1e-12) {
            failPivot = i;
            return false;
        }

        double m = a[i] / B[i-1];

        B[i] = B[i] - m * c[i-1];
        D[i] = D[i] - m * D[i-1];
    }

    // Check last pivot
    if (fabs(B[n-1]) < 1e-12) {
        failPivot = n;
        return false;
    }

    // Backward substitution
    x[n-1] = D[n-1] / B[n-1];

    for (int i = n-2; i >= 0; i--) {
        x[i] = (D[i] - c[i] * x[i+1]) / B[i];
    }

    return true;
}

int main() {

    double alpha[7] = {
        0.5, 2, 0.2, 0, 1.5, 2, 1
    };

    double beta[7] = {
        1, 2, 1.0/3, 2, 1, 2.0/3, 1
    };

    for (int k = 0; k < 7; k++) {

        double x[4];
        int failPivot = 0;

        cout << "\nAlpha = " << alpha[k]
             << ", Beta = " << beta[k] << "\n";

        bool success = solve(
            alpha[k], beta[k], x, failPivot
        );

        if (success) {
            cout << "Thomas Algorithm: SUCCESS\n";
            cout << "Solution: ";

            for (int i = 0; i < 4; i++) {
                cout << fixed << setprecision(6)
                     << x[i] << " ";
            }

            cout << "\n";
        }
        else {
            cout << "Thomas Algorithm: FAILED\n";
            cout << "Zero pivot at equation "
                 << failPivot << "\n";
        }
    }

    return 0;
}
