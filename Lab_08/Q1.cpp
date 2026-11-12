/*
 * Lab 08 - Q1
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
vector<double> dd(vector<double>x, vector<double>y) {
    int n=x.size();
    vector<vector<double>>D(n, vector<double>(n));
    for(int i=0; i<n; i++)D[i][0]=y[i];
    for(int j=1; j<n; j++)for(int i=0; i<n-j; i++)D[i][j]=(D[i+1][j-1]-D[i][j-1])/(x[i+j]-x[i]);
    vector<double>c(n);
    for(int i=0; i<n; i++)c[i]=D[0][i];
    return c;
}
double P(vector<double>x, vector<double>c, double z) {
    double p=c.back();
    for(int i=(int)c.size()-2; i>=0; i--)p=p*(z-x[i])+c[i];
    return p;
}
int main() {
    vector<double>x= {
        0, .08, .19, .33, .50, .72, .99, 1.31, 1.68, 2.10
    }, y= {
        1, 1.084, 1.218, 1.406, 1.686, 2.099, 2.687, 3.540, 4.747, 6.404
    };
    auto c=dd(x, y);
    for(double z: {
        .33, .50, .72
    }) {
        double h=1e-4, fp=P(x, c, z+h), fm=P(x, c, z-h), f0=P(x, c, z);
        double d1=(fp-fm)/(2*h), d2=(fp-2*f0+fm)/(h*h);
        cout<<setprecision(10)<<"x="<<z<<" f'="<<d1<<" f''="<<d2<<"\n";
    }
    auto mm=minmax_element(y.begin(), y.end());
    cout<<"Observed minimum "<<*mm.first<<" at x="<<x[mm.first-y.begin()]<<"\nObserved maximum "<<*mm.second<<" at x="<<x[mm.second-y.begin()]<<"\n";
}
