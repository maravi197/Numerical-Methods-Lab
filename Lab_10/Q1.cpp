/*
 * Lab 10 - Q1
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
double f(double x, double y) {
    return exp(-(x*x+y*y))/(1+x+y);
}
double trap2(int nx, int ny) {
    double hx=1.0/nx, hy=1.0/ny, s=0;
    for(int i=0; i<=nx; i++)for(int j=0; j<=ny; j++) {
        double w=(i==0||i==nx?.5:1)*(j==0||j==ny?.5:1);
        s+=w*f(i*hx, j*hy);
    }
    return s*hx*hy;
}
double simp2(int nx, int ny) {
    double hx=1.0/nx, hy=1.0/ny, s=0;
    for(int i=0; i<=nx; i++)for(int j=0; j<=ny; j++) {
        int wx=(i==0||i==nx)?1:(i%2?4:2), wy=(j==0||j==ny)?1:(j%2?4:2);
        s+=wx*wy*f(i*hx, j*hy);
    }
    return s*hx*hy/9;
}
double mixed(int nx, int ny) {
    double hx=1.0/nx, hy=1.0/ny, s=0;
    for(int i=0; i<=nx; i++) {
        double wx=(i==0||i==nx)?.5:1;
        double sy=f(i*hx, 0)+f(i*hx, 1);
        for(int j=1; j<ny; j++)sy+=(j%2?4:2)*f(i*hx, j*hy);
        s+=wx*sy*hy/3;
    }
    return s*hx;
}
int main() {
    cout<<setprecision(12)<<"2D trapezoid h=k=.25: "<<trap2(4, 4)<<"\n2D Simpson .25,.25: "<<simp2(4, 4)<<"\n2D Simpson .25,.125: "<<simp2(4, 8)<<"\nMixed trapezoid-x/Simpson-y: "<<mixed(4, 8)<<"\n";
}
