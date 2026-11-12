/*
 * Lab 09 - Q1
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
    return exp(-x*x)/(1+x*x);
}
double trap(int n) {
    double h=1.0/n, s=(f(0)+f(1))/2;
    for(int i=1; i<n; i++)s+=f(i*h);
    return h*s;
}
double simpson(int n) {
    double h=1.0/n, s=f(0)+f(1);
    for(int i=1; i<n; i++)s+=(i%2?4:2)*f(i*h);
    return h*s/3;
}
int main() {
    cout<<setprecision(12);
    vector<int>ns= {
        12, 24, 48, 96
    };
    double R[4][4]= {
    };
    for(int i=0; i<4; i++) {
        R[i][0]=trap(ns[i]);
        cout<<"Trapezoid n="<<ns[i]<<" value="<<R[i][0]<<"\n";
        for(int j=1; j<=i; j++)R[i][j]=R[i][j-1]+(R[i][j-1]-R[i-1][j-1])/(pow(4, j)-1);
    }
    for(int i=0; i<4; i++)cout<<"Romberg level "<<i+1<<" = "<<R[i][i]<<"\n";
    double ref=simpson(200000);
    cout<<"High-accuracy Simpson reference="<<ref<<"\n";
    for(int i=0; i<4; i++)cout<<"n="<<ns[i]<<" trapezoid error="<<fabs(R[i][0]-ref)<<" Romberg error="<<fabs(R[i][i]-ref)<<"\n";
}
