#include<bits/stdc++.h>
using namespace std;
double f(double x){
    return exp(-x)-x;
}
int main(){
      double a=0,b=1,tol=1e-6;
      
      if(f(a)*f(b)>0){
        cout<<"Invalid Interval"<<endl;
        return 1;
      }

      cout<<fixed<<setprecision(10)<<endl;
      cout<<"Iter\t x \t f(x) "<<endl;
      double c=a;
      int i=0;
      while(i<1000){
        c=(a*f(b)-b*f(a))/(f(b)-f(a));
        ++i;
         cout<<i<<"\t"<<c<<"\t"<<f(c)<<endl;
         if(fabs(f(c))<tol)break;
         if(f(a)*f(c)<0)b=c;
         else a=c;

      }
      cout<<"root "<<c<<endl;
      cout<<"iter "<<i<<endl;

}