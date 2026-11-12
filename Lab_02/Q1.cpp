/*
 * Lab 02 - Q1
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
    return x-cos(x);
}
double df(double x) {
    return 1+sin(x);
}
int main() {
    double x=.5, tol=1e-6;
    cout<<fixed<<setprecision(10)<<"iter\tx\tf(x)\tf'(x)\terror\n";
    for(int i=1; i<=100; i++) {
        double fx=f(x), d=df(x), xn=x-fx/d, e=fabs(xn-x);
        cout<<i<<"\t"<<x<<"\t"<<fx<<"\t"<<d<<"\t"<<e<<"\n";
        x=xn;
        if(e<tol)break;
    }
    cout<<"Root = "<<x<<"\n";
}
