/*
 * Lab 12 - Q2
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

// Differential equation: y' = f(x, y)
double differentialEquation(double x, double y) {
    return 1.0 / (1.0 + x * x) - 2.0 * y * y;
}

// Exact solution for checking the answer
double exactSolution(double x) {
    return x / (1.0 + x * x);
}

// One RK4 step with step size h
double rk4Step(double x, double y, double h) {
    double k1 = differentialEquation(x, y);
    double k2 = differentialEquation(x + h / 2.0, y + h * k1 / 2.0);
    double k3 = differentialEquation(x + h / 2.0, y + h * k2 / 2.0);
    double k4 = differentialEquation(x + h, y + h * k3);

    return y + h * (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
}

int main() {
    const double h = 0.1;
    vector<double> x(6), y(6);

    x[0] = 0.0;
    y[0] = 0.0;

    // Use RK4 to create the first 4 points
    for (int i = 0; i < 3; ++i) {
        double currentX = x[i];
        double currentY = y[i];

        x[i + 1] = currentX + h;
        y[i + 1] = rk4Step(currentX, currentY, h);
    }

    cout << fixed << setprecision(8);
    cout << "x\tABM value\texact\terror\n";
   


    
    for (int n = 3; n <= 4; ++n) {
        // Predictor formula (Adams-Bashforth)
        double predictedValue = y[n] + h / 24.0 * (
            55.0 * differentialEquation(x[n], y[n]) -
            59.0 * differentialEquation(x[n - 1], y[n - 1]) +
            37.0 * differentialEquation(x[n - 2], y[n - 2]) -
            9.0 * differentialEquation(x[n - 3], y[n - 3]));

        double correctedValue = predictedValue;

        // Corrector loop (Adams-Moulton)
        for (int iteration = 0; iteration < 100; ++iteration) {
            double nextValue = y[n] + h / 24.0 * (
                9.0 * differentialEquation(x[n] + h, correctedValue) +
                19.0 * differentialEquation(x[n], y[n]) -
                5.0 * differentialEquation(x[n - 1], y[n - 1]) +
                differentialEquation(x[n - 2], y[n - 2]));

            if (fabs(nextValue - correctedValue) < 0.0005) {
                correctedValue = nextValue;
                break;
            }

            correctedValue = nextValue;
        }

        x[n + 1] = x[n] + h;
        y[n + 1] = correctedValue;

        double currentX = x[n + 1];
        double actualValue = exactSolution(currentX);
        double error = fabs(correctedValue - actualValue);

        cout << currentX << "\t" << correctedValue << "\t" << actualValue << "\t" << error << "\n";
    }

    return 0;
}
