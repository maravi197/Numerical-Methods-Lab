/*
 * Lab 02 - Q2
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
    double x=1, y=1;
    cout<<fixed<<setprecision(10)<<"iter\tx\ty\tdx\tdy\terror\n";
    for(int i=1; i<=100; i++) {
        double F=x*x+y*y-4, G=exp(x)+y-1;
        double a=2*x, b=2*y, c=exp(x), d=1, det=a*d-b*c;
        if(fabs(det)<1e-14) {
            cerr<<"Singular Jacobian\n";
            return 1;
        }
        double dx=(-F*d+b*G)/det, dy=(-a*G+c*F)/det;
        x+=dx;
        y+=dy;
        double e=max(fabs(dx), fabs(dy));
        cout<<i<<"\t"<<x<<"\t"<<y<<"\t"<<dx<<"\t"<<dy<<"\t"<<e<<"\n";
        if(e<1e-6)break;
    }
    cout<<"Solution: "<<x<<" "<<y<<"\n";
}
