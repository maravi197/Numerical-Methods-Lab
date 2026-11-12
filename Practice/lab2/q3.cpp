#include<bits/stdc++.h>
using namespace std;

double f(double x) {
    return 2*x - 3 - cos(x);
}

double phi(double x) {
    return (3 + cos(x))/2;
}


int main(){
     double x=1.5;
     double tol=1e-6;
     cout<<fixed<<setprecision(10)<<endl;
     cout<<"Fixed Point Iteration\n"<<endl;

     for(int i=0;i<1000;i++){
          
         double xn=phi(x);
         double error=fabs(xn-x);
         cout<< i <<"\t"<<xn<<"\t"<<error<<endl;
         x=xn;
         if(error<tol)break;
  

     }
      cout<<"iterative root is "<<x<<endl;
     cout<<"Ainten method "<<endl;

     double a=1.5;
     double root=a;
     for(int i=0;i<1000;i++){
         double b=phi(a);
         double c=phi(b);
         double deno=c-2*b+a;
         double nume=b-a;
         if(fabs(deno)<1e-15)break;
         double z=a-nume*nume/deno;
         double e=fabs(z-root);
         cout<<i<<"\t"<<z<<"\t"<<e<<endl;
         if(e<tol){
            root=z;
            break;
         }

         root=z;
         a=b;

     }
     cout<<"root is "<<root<<endl;

}