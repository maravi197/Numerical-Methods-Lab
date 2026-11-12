/*
 * Lab 04 - Q2
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
    const int n=8;
    double A[n][n]= {
        {
            13, 0, 1, 3, -1, 1, 1, 3
        },  {
            -2, -11, 3, -1, -1, 1, 0, -1
        },  {
            2, 1, -12, 0, 2, 2, -2, 0
        },  {
            1, -3, 0, -15, 2, 1, 0, -3
        },  {
            -3, -1, -1, 3, -16, 0, 0, 3
        },  {
            2, 2, 3, 2, -1, 16, 3, 0
        },  {
            -3, -1, 1, -1, 3, 1, -18, 3
        },  {
            -2, 0, -3, 0, 2, -2, -2, -15
        }
    };
    double b[n]= {
        31, 21.5, -2, -35.5, 20.5, 47.5, -7, -4
    };
    double rho=.3343, wopt=2/(1+sqrt(1-rho*rho));
    for(double w: {
        .5, 1.5, wopt
    }) {
        double x[n]= {
        };
        int it;
        for(it=1; it<=10000; it++) {
            double old[n];
            copy(x, x+n, old);
            for(int i=0; i<n; i++) {
                double s=b[i];
                for(int j=0; j<n; j++)if(j!=i)s-=A[i][j]*x[j];
                double gs=s/A[i][i];
                x[i]=(1-w)*old[i]+w*gs;
            }
            double e=0;
            for(int i=0; i<n; i++)e=max(e, fabs(x[i]-old[i]));
            if(e<1e-5)break;
        }
        cout<<"omega="<<w<<" iterations="<<it<<" x=";
        for(double v:x)cout<<v<<" ";
        cout<<"\n";
    }
}
