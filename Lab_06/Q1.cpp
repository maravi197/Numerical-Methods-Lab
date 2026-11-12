/*
 * Lab 06 - Q1
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
    const int n=30;
    vector<double>x(n), y(n);
    double h=3.0/(n-1);
    for(int i=0; i<n; i++) {
        x[i]=i*h;
        y[i]=exp(x[i]);
    }
    vector<vector<double>>D(n, vector<double>(n));
    for(int i=0; i<n; i++)D[i][0]=y[i];
    for(int j=1; j<n; j++)for(int i=0; i<n-j; i++)D[i][j]=D[i+1][j-1]-D[i][j-1];
    double z=1.2, u=(z-x[0])/h, term=1, p=D[0][0];
    for(int k=1; k<n; k++) {
        term*= (u-k+1)/k;
        p+=term*D[0][k];
    }
    double ex=exp(z);
    cout<<setprecision(12)<<"Newton forward P(1.2)="<<p<<"\nExact="<<ex<<"\nAbsolute error="<<fabs(p-ex)<<"\nRelative error="<<fabs(p-ex)/ex<<"\n";
}
