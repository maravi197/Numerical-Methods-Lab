/*
 * Lab 03 - Q3
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
            15.2, -2.1, .5, 1.1, -.3, 2, 0, -1.5
        },  {
            -1, 18.5, -3.2, 0, 2.5, -1.1, .8, .5
        },  {
            .5, -2, 14.8, -4.1, 1.2, 0, -.9, 2.1
        },  {
            1.1, 0, -3, 16.4, -2.2, 1.5, -.5, .8
        },  {
            -.4, 2.2, 1, -2.5, 19.1, -3, 1.1, 0
        },  {
            2.1, -1, 0, 1.2, -2.8, 17.5, -3.5, 1
        },  {
            0, .9, -1.1, -.5, 1.5, -3.2, 16.8, -2.2
        },  {
            -1.2, .5, 2, .7, 0, 1.1, -2.5, 15.6
        }
    };
    double b[n]= {
        14.9, -22.3, 35.6, -11.2, 42.8, -5.4, 19.1, -28.4
    }, x[n]= {
    }, old[n];
    bool sdd=true;
    for(int i=0; i<n; i++) {
        double sum=0;
        for(int j=0; j<n; j++)if(i!=j)sum+=abs(A[i][j]);
        if(A[i][i]<=sum)sdd=false;
    }
    int it;
    for(it=1; it<=10000; it++) {
        copy(x, x+n, old);
        for(int i=0; i<n; i++) {
            double s=b[i];
            for(int j=0; j<n; j++)if(i!=j)s-=A[i][j]*x[j];
            x[i]=s/A[i][i];
        }
        double e=0;
        for(int i=0; i<n; i++)e=max(e, fabs(x[i]-old[i])/max(1e-30, fabs(x[i])));
        if(e<1e-8)break;
    }
    double nr=0;
    cout<<fixed<<setprecision(6)<<"Strict diagonal dominance: "<<(sdd?"yes":"no")<<"\nIterations: "<<it<<"\nSolution: ";
    for(double v:x)cout<<v<<" ";
    cout<<"\nResidual: ";
    for(int i=0; i<n; i++) {
        double r=b[i];
        for(int j=0; j<n; j++)r-=A[i][j]*x[j];
        cout<<r<<" ";
        nr+=r*r;
    }
    cout<<"\nResidual norm = "<<sqrt(nr)<<"\n";
}
