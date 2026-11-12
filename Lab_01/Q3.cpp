/*
 * Lab 01 - Q3
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
    return x*x*x+4*x*x-10;
}
struct Result {
    double x;
    int n;
    double fx, sec;
};
Result solve(bool bis) {
    double a=1, b=2, c=0, prev=0;
    int i=0;
    auto st=clock();
    while(i<1000) {
        if(bis)c=(a+b)/2;
        else c=(a*f(b)-b*f(a))/(f(b)-f(a));
        ++i;
        if(f(a)*f(c)<0)b=c;
        else a=c;
        if(fabs(f(c))<1e-6)break;
    }
    double tm=double(clock()-st)/CLOCKS_PER_SEC;
    return {
        c, i, fabs(f(c)), tm
    };
}
int main() {
    cout<<fixed<<setprecision(10);
    for(bool b: {
        true, false
    }) {
        auto r=solve(b);
        cout<<(b?"Bisection":"Regula Falsi")<<": root="<<r.x<<" iterations="<<r.n<<" |f|="<<r.fx<<" CPU(s)="<<r.sec<<"\n";
    }
}
