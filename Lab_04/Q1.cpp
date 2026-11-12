/*
 * Lab 04 - Q1
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
    double A[5][5]= {
        {
            3, 2, -2, -1, 1
        },  {
            0, 4, 1, -2, 1
        },  {
            2, -2, 3, -2, 2
        },  {
            2, -2, 2, 4, -2
        },  {
            -2, -1, 0, 0, 3
        }
    }, b[5]= {
        4, -1, -15, 12, -10
    };
    for(int method=0; method<2; method++) {
        double x[5]= {
        }, old[5];
        int it;
        bool conv=false;
        for(it=1; it<=10000; it++) {
            copy(x, x+5, old);
            for(int i=0; i<5; i++) {
                double s=b[i];
                for(int j=0; j<5; j++)if(i!=j)s-=A[i][j]*(method==0?old[j]:x[j]);
                x[i]=s/A[i][i];
            }
            double e=0;
            for(int i=0; i<5; i++)e=max(e, fabs(x[i]-old[i]));
            if(e<1e-5) {
                conv=true;
                break;
            }
            if(!isfinite(e))break;
        }
        cout<<(method==0?"Jacobi":"Gauss-Seidel")<<" "<<(conv?"converged":"diverged/limit")<<" iterations="<<it<<" x=";
        for(double v:x)cout<<v<<" ";
        cout<<"\n";
    }
}
