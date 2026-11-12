/*
 * Lab 10 - Q2
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
double fun(double x, double y) {
    return sqrt(x*y);
}
int main() {
    double h=1;
    vector<double>x= {
        1, 2, 3, 4
    }, y= {
        1
    };
    double e=1, m=1;
    cout<<fixed<<setprecision(8)<<"x\tEuler\tModifiedEuler\tExact\tErrEuler\tErrModified\n";
    for(int i=0; i<4; i++) {
        double xx=1+i;
        double exact=pow((xx*xx+3)/4, 2);
        if(i>0) {
            double f0=(xx-1)*sqrt(max(0.0, e));
            e=e+h*f0;
            // Euler previous slope
            // modified Euler step from previous value
            double xp=xx-1,  yp=m;
            double k1=xp*sqrt(max(0.0, yp));
            double pred=yp+h*k1;
            double k2=xx*sqrt(max(0.0, pred));
            m=yp+h*(k1+k2)/2;
        }
        cout<<xx<<"\t"<<e<<"\t"<<m<<"\t"<<exact<<"\t"<<fabs(e-exact)<<"\t"<<fabs(m-exact)<<"\n";
    }
}
