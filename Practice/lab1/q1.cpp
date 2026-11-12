#include<bits/stdc++.h>
using namespace std;

double f(double x){
    return x*x*x-x-2;
}

int main(){
  
    double a=1,b=2,tol=1e-6;
    
    
    if(f(a)*f(b)>0){
        cout<<"Invalid Interval. Try another Interval"<<endl;
        return 0;
    }
    if(f(a)==0){
        cout<<"root is"<<a<<endl;
        return 0;
    }else if(f(b)==0){
        cout<<"root is "<<b<<endl;
        return 0;
    }

    int i=0;
    cout<<setprecision(9)<<"iter\ta\tb\tmid\tf(mid)\n";
    while(b-a>tol and i<1000){
        double c=(a+b)/2;

        cout<<++i<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<f(c)<<endl;
        if(f(a)*f(c)<0)b=c;
        else a=c;       

    }
   double x=(a+b)/2;

   cout<<"root :"<<x<<endl;
   cout<<"Iter :"<<i<<endl;
   cout<<"f(x) :"<<fabs(f(x))<<endl;

}