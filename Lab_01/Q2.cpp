/*
 * Lab 01 - Q2
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
    return exp(-x)-x;
}
int main() {
    double a=0, b=1, tol=1e-6;
    if(f(a)*f(b)>0)return 1;
    cout<<fixed<<setprecision(10);
    cout<<"iter\tx\tf(x)\n";
    double c=a;
    int i=0;
    while(i<1000) {
        c=(a*f(b)-b*f(a))/(f(b)-f(a));
        ++i;
        cout<<i<<"\t"<<c<<"\t"<<f(c)<<"\n";
        if(fabs(f(c))<tol)break;
        if(f(a)*f(c)<0)b=c;
        else a=c;
    }
    cout<<"Root = "<<c<<"\nIterations = "<<i<<"\n";
}
