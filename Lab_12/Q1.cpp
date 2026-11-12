/*
 * Lab 12 - Q1
 * Goal: Solve the given numerical problem using a clear step-by-step method.
 *
 * Beginner-friendly notes:
 * - Read the code from main() downward.
 * - Set up the input values and constants first.
 * - Apply the numerical method one step at a time.
 * - Print the final values clearly so the result is easy to read.
 */



#include <iomanip>
#include <iostream>
using namespace std;

// Differential equation: y' = f(x, y)
double differentialEquation(double x, double y) {
    return (y * y - 2.0 * x) / (y * y + x);
}

// One RK4 step with step size h
double rk4Step(double x, double y, double h) {
    double k1 = differentialEquation(x, y);
    double k2 = differentialEquation(x + h / 2.0, y + h * k1 / 2.0);
    double k3 = differentialEquation(x + h / 2.0, y + h * k2 / 2.0);
    double k4 = differentialEquation(x + h, y + h * k3);

    return y + h * (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
}

// One Modified Euler step with step size h
double modifiedEulerStep(double x, double y, double h) {
    double slopeAtStart = differentialEquation(x, y);
    double predictedY = y + h * slopeAtStart;
    double slopeAtPredictedPoint = differentialEquation(x + h, predictedY);

    return y + h * (slopeAtStart + slopeAtPredictedPoint) / 2.0;
}

int main() {
    const double h = 0.1;
    const int totalSteps = 15;
    const int printEvery = 5;

    double yRk4 = 1.0;          // initial value y(0)
    double yModifiedEuler = 1.0; // initial value y(0)

    cout << fixed << setprecision(10);
    cout << "x\t\tRK4\t\tModified Euler\n";

    for (int step = 1; step <= totalSteps; ++step) {
        double x = (step - 1) * h;

        // Update both methods using the previous value of y
        yRk4 = rk4Step(x, yRk4, h);
        yModifiedEuler = modifiedEulerStep(x, yModifiedEuler, h);

        if (step % printEvery == 0) {
            double currentX = step * h;
            cout << currentX << "\t" << yRk4 << "\t" << yModifiedEuler << "\n";
        }
    }

    return 0;
}
