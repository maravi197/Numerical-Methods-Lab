/*
 * Lab 08 - Q3
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
    vector<double>y= {
        1.000000, 1.040811, 1.168731, 1.411993, 1.810656, 2.718282, 4.060156, 6.550203, 11.023176
    };
    double h=.2;
    auto d1=[&](int k) {
        return (y[k+2]-y[k-2])/(4*h);
    };
    auto d2=[&](int k) {
        return (y[k+2]-2*y[k]+y[k-2])/(4*h*h);
    };
    double D1h4=d1(5), D2h4=d2(5);
    double D1h2=(y[6]-y[4])/(2*h), D2h2=(y[6]-2*y[5]+y[4])/(h*h);
    double rich=(4*D1h2-D1h4)/3;
    cout<<setprecision(10)<<"h=0.4: f'="<<D1h4<<" f''="<<D2h4<<"\nh=0.2: f'="<<D1h2<<" f''="<<D2h2<<"\nRichardson f'="<<rich<<"\n";
}
