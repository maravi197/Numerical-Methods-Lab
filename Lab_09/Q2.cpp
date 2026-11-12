/*
 * Lab 09 - Q2
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
double f(double x) {
    return x*sin(x)*exp(-x);
}
double sim13(int n) {
    double h=M_PI/n, s=f(0)+f(M_PI);
    for(int i=1; i<n; i++)s+=(i%2?4:2)*f(i*h);
    return h*s/3;
}
double sim38(int n) {
    double h=M_PI/n, s=f(0)+f(M_PI);
    for(int i=1; i<n; i++)s+=(i%3?3:2)*f(i*h);
    return 3*h*s/8;
}
int main() {
    cout<<setprecision(12);
    complex<double>a(-1, 1);
    complex<double>I=exp(a*M_PI)*(M_PI/a-1.0/(a*a))-(0.0-1.0/(a*a));
    double exact=I.imag();
    for(int n: {
        4, 8, 16, 32, 64
    }) {
        double v13=sim13(n);
        cout<<"n="<<n<<" Simpson1/3="<<v13<<" error="<<fabs(v13-exact)<<"\n";
        if(n%3==0) {
            double v=sim38(n);
            cout<<"Simpson3/8="<<v<<" error="<<fabs(v-exact)<<"\n";
        }
    }
    cout<<"Exact integral="<<exact<<"\nFor the requested n values, composite 3/8 alone is not applicable because none is divisible by 3.\n";
}
