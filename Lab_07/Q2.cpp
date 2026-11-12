/*
 * Lab 07 - Q2
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
        -1, -.85, -.7, -.55, -.4, -.25, -.1, .05, .2, .35, .5, .65, .8, 1
    };
    vector<double>y;
    for(double v:x)y.push_back(1/(1+25*v*v));
    int n=x.size();
    vector<vector<double>>D(n, vector<double>(n));
    for(int i=0; i<n; i++)D[i][0]=y[i];
    for(int j=1; j<n; j++)for(int i=0; i<n-j; i++)D[i][j]=(D[i+1][j-1]-D[i][j-1])/(x[i+j]-x[i]);
    for(double z: {
        -.9, -.6, -.3, 0., .3, .6, .9
    }) {
        double p=D[0][0], prod=1;
        for(int j=1; j<n; j++) {
            prod*=z-x[j-1];
            p+=D[0][j]*prod;
        }
        double ex=1/(1+25*z*z);
        cout<<setprecision(10)<<"x="<<z<<" P="<<p<<" exact="<<ex<<" error="<<fabs(p-ex)<<"\n";
    }
}
