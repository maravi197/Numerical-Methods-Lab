/*
 * Lab 07 - Q1
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
    vector<double>x= {
        0, .3, .9, 2, 2.4, 3.1, 3.8, 4.2, 4.7, 4.8
    }, y;
    for(double v:x)y.push_back(sin(v));
    int n=x.size();
    vector<vector<double>>D(n, vector<double>(n));
    for(int i=0; i<n; i++)D[i][0]=y[i];
    for(int j=1; j<n; j++)for(int i=0; i<n-j; i++)D[i][j]=(D[i+1][j-1]-D[i][j-1])/(x[i+j]-x[i]);
    cout<<setprecision(10)<<"Divided difference table\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i; j++)cout<<setw(14)<<D[i][j];
        cout<<"\n";
    }
    double z=1.8, p=D[0][0], prod=1;
    for(int j=1; j<n; j++) {
        prod*=z-x[j-1];
        p+=D[0][j]*prod;
    }
    cout<<"P(1.8)="<<p<<"\nExact="<<sin(z)<<"\nAbsolute error="<<fabs(p-sin(z))<<"\n";
    double M=1;
    for(double v:x)M=max(M, fabs(sin(v+(M_PI/2))));
    double w=1;
    for(double v:x)w*=fabs(z-v);
    cout<<"Conservative error bound (using |f^(n+1)|<=1): "<<w/tgamma(n+1)<<"\n";
}
