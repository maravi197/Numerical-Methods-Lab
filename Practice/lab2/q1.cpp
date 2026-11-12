#include<bits/stdc++.h>
using namespace std;

double f(double x){
    return x-cos(x);
}

double df(double x){
    return 1+sin(x);
}

int main(){
    double xi=0.5;
    double tol=1e-6;
    cout<<fixed<<setprecision(10)<<endl;
    cout<<"Iter\txn\tf(x)\tf'(x)\tError"<<endl;
    int i=0;
    int count=0;
    while(i<1000){
           double fx=f(xi);
           double dx=df(xi);
           double xn=xi-fx/dx;
           double e=fabs(xn-xi);
           cout<<i<<"\t"<<xn<<"\t"<<fx<<"\t"<<df<<"\t"<<e<<endl;
           i++;
              count=i;     
              xi=xn;
          if(e<tol)break;
 
    }
    cout<<"root"<<xi<<endl;
    cout<<"iter"<<count<<endl;
}