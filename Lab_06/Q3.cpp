/*
 * Lab 06 - Q3
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
    return 1/(1+x);
}
int main() {
    vector<double>x= {
        0, .35, .55, .65, .88, 1, 1.37, 1.5, 1.91, 2
    };
    double z=1.25;
    // choose four nodes nearest to z
    sort(x.begin(), x.end(), [&](double a, double b) {
        return fabs(a-z)<fabs(b-z);
    });
    x.resize(5);
    sort(x.begin(), x.end());
    double p=0, prod=1;
    for(int i=0; i<5; i++) {
        double L=1;
        for(int j=0; j<5; j++)if(i!=j)L*=(z-x[j])/(x[i]-x[j]);
        p+=f(x[i])*L;
        prod*= (i==0?1:1);
    }
    double bound=1;
    for(double v:x)bound*=fabs(z-v);
    // f^(5) max = 5!/(1+x)^6, interval x>=0
    bound*=1/pow(1+*min_element(x.begin(), x.end()), 6);
    cout<<setprecision(12)<<"Nodes: ";
    for(double v:x)cout<<v<<" ";
    cout<<"\nP4(1.25)="<<p<<"\nExact="<<f(z)<<"\nAbsolute error="<<fabs(p-f(z))<<"\nError bound <= "<<bound<<"\n";
}
