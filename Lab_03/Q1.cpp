
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <stdexcept>
using namespace std;

using Mat = vector<vector<double>>;

// Round a number to 4 significant digits
double round4(double x) {
    if (x == 0)
        return 0;

    int p = 3 - (int)floor(log10(fabs(x)));
    double factor = pow(10.0, p);

    return round(x * factor) / factor;
}

// Arithmetic operations with 4 significant digit rounding
double add4(double a, double b) {
    return round4(a + b);
}

double sub4(double a, double b) {
    return round4(a - b);
}

double mul4(double a, double b) {
    return round4(a * b);
}

double div4(double a, double b) {
    return round4(a / b);
}

// Find eigenvalues of a symmetric 3x3 matrix
// using Jacobi method with 4-digit rounding
vector<double> eigenvalues(Mat B) {
    int n = 3;

    for (int iter = 0; iter < 100; iter++) {
        int p = 0, q = 1;

        if (fabs(B[0][2]) > fabs(B[p][q]))
            p = 0, q = 2;

        if (fabs(B[1][2]) > fabs(B[p][q]))
            p = 1, q = 2;

        if (fabs(B[p][q]) < 1e-12)
            break;

        double tau = div4(
            sub4(B[q][q], B[p][p]),
            mul4(2, B[p][q])
        );

        double t = div4(
            1,
            add4(fabs(tau), sqrt(round4(add4(1, mul4(tau, tau)))))
        );

        if (tau < 0)
            t = -t;

        double c = div4(1, sqrt(round4(add4(1, mul4(t, t)))));
        double s = mul4(t, c);

        double app = B[p][p];
        double aqq = B[q][q];
        double apq = B[p][q];

        for (int k = 0; k < n; k++) {
            if (k != p && k != q) {
                double bkp = B[k][p];
                double bkq = B[k][q];

                B[k][p] = B[p][k] =
                    sub4(mul4(c, bkp), mul4(s, bkq));

                B[k][q] = B[q][k] =
                    add4(mul4(s, bkp), mul4(c, bkq));
            }
        }

        B[p][p] = sub4(app, mul4(t, apq));
        B[q][q] = add4(aqq, mul4(t, apq));

        B[p][q] = B[q][p] = 0;
    }

    vector<double> eig(3);

    for (int i = 0; i < 3; i++)
        eig[i] = B[i][i];

    return eig;
}

// Calculate Euclidean condition number
double conditionNumber(Mat A) {
    Mat B(3, vector<double>(3, 0));

    // B = transpose(A) * A
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            double sum = 0;

            for (int k = 0; k < 3; k++)
                sum = add4(sum, mul4(A[k][i], A[k][j]));

            B[i][j] = sum;
        }
    }

    vector<double> eig = eigenvalues(B);

    double largest = *max_element(eig.begin(), eig.end());
    double smallest = *min_element(eig.begin(), eig.end());

    double normA = round4(sqrt(largest));
    double normInvA = div4(1, sqrt(smallest));

    cout << "\n||A||2       = " << normA;
    cout << "\n||A inverse||2 = " << normInvA;

    return mul4(normA, normInvA);
}

// Gaussian Elimination
// mode 0 = No pivoting
// mode 1 = Partial pivoting
// mode 2 = Complete pivoting

vector<double> solve(Mat A, vector<double> b, int mode) {
    int n = (int)b.size();

    vector<int> col(n);
    iota(col.begin(), col.end(), 0);

    // Forward elimination
    for (int k = 0; k < n; k++) {
        int pr = k, pc = k;

        // Partial pivoting
        if (mode == 1) {
            for (int i = k + 1; i < n; i++) {
                if (fabs(A[i][k]) > fabs(A[pr][k]))
                    pr = i;
            }
        }

        // Complete pivoting
        if (mode == 2) {
            for (int i = k; i < n; i++) {
                for (int j = k; j < n; j++) {
                    if (fabs(A[i][j]) > fabs(A[pr][pc])) {
                        pr = i;
                        pc = j;
                    }
                }
            }
        }

        // Swap rows
        if (mode == 1 || mode == 2) {
            swap(A[k], A[pr]);
            swap(b[k], b[pr]);
        }

        // Swap columns
        if (mode == 2) {
            for (int i = 0; i < n; i++)
                swap(A[i][k], A[i][pc]);

            swap(col[k], col[pc]);
        }

        if (fabs(A[k][k]) < 1e-14)
            throw runtime_error("Singular pivot - method failed");

        // Eliminate elements below pivot
        for (int i = k + 1; i < n; i++) {
            double m = div4(A[i][k], A[k][k]);

            for (int j = k; j < n; j++) {
                A[i][j] = sub4(
                    A[i][j],
                    mul4(m, A[k][j])
                );
            }

            b[i] = sub4(b[i], mul4(m, b[k]));
        }
    }

    // Back substitution
    vector<double> x(n, 0);

    for (int i = n - 1; i >= 0; i--) {
        double sum = b[i];

        for (int j = i + 1; j < n; j++)
            sum = sub4(sum, mul4(A[i][j], x[j]));

        x[i] = div4(sum, A[i][i]);
    }

    // Restore original variable order
    vector<double> ans(n);

    for (int i = 0; i < n; i++)
        ans[col[i]] = x[i];

    return ans;
}

// Calculate residual vector r = b - Ax
vector<double> residual(Mat A, vector<double> b,
                        vector<double> x) {
    int n = (int)b.size();
    vector<double> r(n);

    for (int i = 0; i < n; i++) {
        double sum = 0;

        for (int j = 0; j < n; j++)
            sum = add4(sum, mul4(A[i][j], x[j]));

        r[i] = sub4(b[i], sum);
    }

    return r;
}

int main() {
    Mat A = {
        {0.0001, 1, 1},
        {1, 1, 2},
        {2, 1, 1}
    };

    vector<double> b = {2.0001, 4, 4};

    cout << fixed << setprecision(4);

    // Part (a): Condition number
    cout << "PART (a): CONDITION NUMBER\n";

    double kappa = conditionNumber(A);

    cout << "\nCondition Number = " << kappa << "\n";

    // Parts (b), (c), (d)
    for (int mode = 0; mode < 3; mode++) {
        cout << "\n--------------------------------\n";

        if (mode == 0)
            cout << "NO PIVOTING\n";
        else if (mode == 1)
            cout << "PARTIAL PIVOTING\n";
        else
            cout << "COMPLETE PIVOTING\n";

        try {
            vector<double> x = solve(A, b, mode);

            cout << "Solution:\n";

            for (int i = 0; i < 3; i++)
                cout << "x" << i + 1 << " = " << x[i] << "\n";

            vector<double> r = residual(A, b, x);

            cout << "Residual vector:\n";

            double normR = 0;

            for (int i = 0; i < 3; i++) {
                cout << r[i] << " ";
                normR += r[i] * r[i];
            }

            normR = sqrt(normR);

            cout << "\nResidual norm = " << normR << "\n";
        }
        catch (exception &e) {
            cout << "Failed: " << e.what() << "\n";
        }
    }

    return 0;
}
