/*
 * Lab 08 - Q2
 * Goal: Solve the given numerical problem using a clear step-by-step method.
 *
 * Beginner-friendly notes:
 * - Read the code from main() downward.
 * - Set up the input values and constants first.
 * - Apply the numerical method one step at a time.
 * - Print the final values clearly so the result is easy to read.
 */



#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int main() {
    vector<double>t= {
        0, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200
    }, s= {
        0, 4.6, 18.9, 43.7, 80.8, 132.4, 199.7, 284.9, 389.6, 515.8, 665.1, 839.7, 1041.4
    };
    double h=100;
    auto deriv=[&](double z, int order) {
        int i=clamp((int)round(z/h), 0, 12);
        double step=1e-3;
        auto interp=[&](double q) {
            // local 5-point Lagrange polynomial
            int start=clamp(i-2, 0, 8);
            double ans=0;
            for(int a=start; a<start+5; a++) {
                double L=1;
                for(int b=start; b<start+5; b++)if(a!=b)L*=(q-t[b])/(t[a]-t[b]);
                ans+=s[a]*L;
            }
            return ans;
        };
        if(order==1)return (interp(z+step)-interp(z-step))/(2*step);
        return (interp(z+step)-2*interp(z)+interp(z-step))/(step*step);
    };
    for(double z: {
        430., 670., 860., 910.
    })cout<<"Velocity at "<<z<<" s = "<<deriv(z, 1)<<" km/s\n";
    for(double z: {
        525., 720.
    })cout<<"Acceleration at "<<z<<" s = "<<deriv(z, 2)<<" km/s^2\n";
}
