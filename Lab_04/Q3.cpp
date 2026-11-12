/*
 * Lab 04 - Q3
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
    const int n=5;
    double A[n][n]= {
        {
            4, 1, -1, 1, 0
        },  {
            1, 5, 2, 0, 1
        },  {
            -1, 2, 5, 1, 1
        },  {
            1, 0, 1, 4, 2
        },  {
            0, 1, 1, 2, 5
        }
    }, b[n]= {
        9.5, -4, -.5, 10.5, -4.5
    };
    vector<double> eig= {
        -.7605, .7294, -.2445, -.0824, .3579
    };
    double mn=1e9, mx=-1e9;
    for(double v:eig) {
        mn=min(mn, v);
        mx=max(mx, v);
    }
    double rho=max(abs(mn), abs(mx));
    double w=2/(1+sqrt(1-rho*rho));
    for(int method=0; method<3; method++) {
        double x[n]= {
        };
        int it;
        for(it=1; it<=10000; it++) {
            double old[n];
            copy(x, x+n, old);
            for(int i=0; i<n; i++) {
                double s=b[i];
                for(int j=0; j<n; j++)if(j!=i)s-=A[i][j]*(method==0?old[j]:x[j]);
                double v=s/A[i][i];
                if(method==2)x[i]=(1-w)*old[i]+w*v;
                else x[i]=v;
            }
            double e=0;
            for(int i=0; i<n; i++)e=max(e, fabs(x[i]-old[i]));
            if(e<1e-5)break;
        }
        cout<<(method==0?"Jacobi":method==1?"Gauss-Seidel":"SOR")<<" omega="<<w<<" iterations="<<it<<" x=";
        for(double v:x)cout<<v<<" ";
        cout<<"\n";
    }
}
