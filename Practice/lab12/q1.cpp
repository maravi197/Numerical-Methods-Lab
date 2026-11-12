#include<bits/stdc++.h>
using namespace std;

 double diff(double x,double y){
    return (y*y-2.0*x)/(y*y+x);
 }

  double rk4(double x,double y,double h){
     double k1=diff(x,y);
     double k2=diff(x+h/2.0,y+h*k1/2.0);
     double k3=diff(x+h/2.0,y+h*k2/2.0);
     double k4=diff(x+h,y+h*k3);
     return y+h*(k1+2.0*k2+2.0*k3+k4)/6;
  }
double modi(double x,double y,double h){
     double start=diff(x,y);
     double pri=y+h*start;
     double end=diff(x+h,pri);
     return y+h*(start+end)/2.0;
}

int main(){
    
    double h=.1;
    int stepsize=5;
    int n=15;
    double irk=1.0;
    double im=1.0;
    cout<<fixed<<setprecision(10)<<endl;


    cout<<"x\trk4\teuler"<<endl;
    double x=0.0;
    for(int i=1;i<=n;i++){
      
       irk=rk4(x,irk,h);
        im=modi(x,im,h);
              
  
        x+=h;
    
            cout<<x<<"\t"<<irk<<"\t"<<im<<endl;
        

    }

}