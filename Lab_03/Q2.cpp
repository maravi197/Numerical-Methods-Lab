/*
 * Lab 03 - Q2
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
    double A[3][3]= {
        {
            10, -1, 2
        },  {
            -1, 11, -1
        },  {
            2, -1, 10
        }
    }, b[3]= {
        27, -19, 35
    }, x[3]= {
        0, 0, 0
    };
    int it=0;
    cout<<fixed<<setprecision(10)<<"iter\tx1\tx2\tx3\trelErr1\trelErr2\trelErr3\n";
    for(it=1; it<=10000; it++) {
        double old[3]= {
            x[0], x[1], x[2]
        };
        x[0]=(b[0]+x[1]-2*x[2])/10;
        x[1]=(b[1]+x[0]+x[2])/11;
        x[2]=(b[2]-2*x[0]+x[1])/10;
        double e=0;
        for(int j=0; j<3; j++)e=max(e, fabs(x[j]-old[j])/max(1e-30, fabs(x[j])));
        cout<<it<<"\t"<<x[0]<<"\t"<<x[1]<<"\t"<<x[2]<<"\t";
        for(int j=0; j<3; j++)cout<<fabs(x[j]-old[j])/max(1e-30, fabs(x[j]))<<"\t";
        cout<<"\n";
        if(e<1e-10)break;
    }
    cout<<"Iterations = "<<it<<"\nResidual: ";
    for(int i=0; i<3; i++) {
        double r=b[i];
        for(int j=0; j<3; j++)r-=A[i][j]*x[j];
        cout<<r<<" ";
    }
    cout<<"\n";
}
