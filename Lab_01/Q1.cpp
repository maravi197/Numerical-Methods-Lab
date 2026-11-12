/*
 * Lab 01 - Q1
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
    return x*x*x-x-2;
}
int main() {
    double a=1, b=2, tol=1e-6;
    if(f(a)*f(b)>0) {
        cerr<<"Invalid bracket\n";
        return 1;
    }
    cout<<fixed<<setprecision(9)<<"iter\ta\tb\tmid\tf(mid)\n";
    int i=0;
    while(b-a>tol && i<1000) {
        double c=(a+b)/2;
        cout<<++i<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<f(c)<<"\n";
        if(f(a)*f(c)<0)b=c;
        else a=c;
    }
    double x=(a+b)/2;
    cout<<"Root = "<<x<<"\nIterations = "<<i<<"\n|f(root)| = "<<fabs(f(x))<<"\n";
}
