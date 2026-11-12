/*
 * Lab 09 - Q3
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
    vector<double>y= {
        1, 1.6487, 2.7183, 4.4817, 7.3891, 12.1825, 20.0855
    };
    double h=.5;
    int n=6;
    double tr=h*((y[0]+y[n])/2+accumulate(y.begin()+1, y.end()-1, 0.0));
    double s13=h/3*(y[0]+y[n]+4*(y[1]+y[3]+y[5])+2*(y[2]+y[4]));
    double s38=3*h/8*(y[0]+3*y[1]+3*y[2]+2*y[3]+3*y[4]+3*y[5]+y[6]);
    double exact=exp(3)-1;
    cout<<setprecision(12)<<"Trapezoid="<<tr<<" error="<<fabs(tr-exact)<<"\nSimpson 1/3="<<s13<<" error="<<fabs(s13-exact)<<"\nSimpson 3/8="<<s38<<" error="<<fabs(s38-exact)<<"\nExact="<<exact<<"\n";
}
