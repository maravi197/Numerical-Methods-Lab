/*
 * Lab 12 - Q3
 * Goal: Solve the given numerical problem using a clear step-by-step method.
 *
 * Beginner-friendly notes:
 * - Read the code from main() downward.
 * - Set up the input values and constants first.
 * - Apply the numerical method one step at a time.
 * - Print the final values clearly so the result is easy to read.
 */



#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int numberOfSteps = 10;
    const double h = 0.2;

    vector<double> x(numberOfSteps + 1), y(numberOfSteps + 1);

    // Create x-values from 0 to 2
    for (int i = 0; i <= numberOfSteps; ++i) {
        x[i] = i * h;
    }

    // Boundary conditions
    y[0] = 1.0;
    y[numberOfSteps] = 2.0;

    // We guess the interior values and improve them repeatedly
    for (int iteration = 0; iteration < 10000; ++iteration) {
        double maxDifference = 0.0;
        vector<double> newY = y;

        for (int i = 1; i < numberOfSteps; ++i) {
            newY[i] = (y[i - 1] + y[i + 1] - h * h * 0.5 * x[i]) /
                      (2.0 + h * h * 0.5);

            maxDifference = max(maxDifference, fabs(newY[i] - y[i]));
        }

        y = newY;

        if (maxDifference < 1e-12) {
            break;
        }
    }

    cout << fixed << setprecision(8);
    cout << "x\ty\n";

    for (int i = 0; i <= numberOfSteps; ++i) {
        cout << x[i] << "\t" << y[i] << "\n";
    }

    return 0;
}
