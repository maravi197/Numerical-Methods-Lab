/*
 * Lab 06 - Q2
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
vector<double> coeff(vector<double> y) {
    int n=y.size();
    vector<double>d=y;
    for(int j=1; j<n; j++)for(int i=n-1; i>=j; i--)d[i]-=d[i-1];
    return d;
}
double backward(vector<double>x, vector<double>y, double z) {
    int n=x.size();
    double h=x[1]-x[0], v=(z-x.back())/h;
    auto d=coeff(y);
    double ans=d[n-1], term=1;
    for(int k=1; k<n; k++) {
        term*= (v+k-1)/k;
        ans+=term*d[n-1-k];
    }
    return ans;
}
int main() {
    vector<double>x= {
        0, .2, .4, .6, .8, 1, 1.2, 1.4, 1.6, 1.8, 2
    }, y= {
        8, 6.48, 4.7203, 2.7301, .6142, -1, .4398, 12.981, 57.8395, 184.0393, 494
    };
    cout<<setprecision(10)<<"All 11 points: "<<backward(x, y, 1.7)<<"\n";
    vector<double>xx(x.end()-5, x.end()), yy(y.end()-5, y.end());
    cout<<"Last five points: "<<backward(xx, yy, 1.7)<<"\n";
}
