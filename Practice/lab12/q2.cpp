#include<bits/stdc++.h>
using namespace std;

double diff(double x,double y){
    return 1/(1+x*x)-2.0*y*y;
}

double Asli(double x,double y){
    return x/(1+x*x);
}

double rk4(double x,double y,double h){
     
    double k1=diff(x,y);
    double k2=diff(x+h/2.0,y+h*k1/2.0);
    double k3=diff(x+h/2.0,y+h*k2/2.0);
    double k4=diff(x+h,y+h*k3);
    return y+h*(k1+2.0*k2+2.0*k3+k4)/6.0;

}

int main(){
      int init=.1;
      double h=.1;
      vector<double>x(6),y(6);
      x[0]=0.0;
      y[0]=0.0;
      for(int i=0;i<3;i++){
         double cx=x[i];
         double cy=y[i];
         double nx=x[i]+h;
         double ny=rk4(x[i],y[i],h);
         y[i+1]=ny;
         x[i+1]=nx;
      }
      cout<<fixed<<setprecision(9)<<endl;
      cout<<"x\tabmvalue\texactvalue\terror"<<endl;
      for(int i=3;i<=4;i++){
           double pre=y[i]+h/24*(55*diff(x[i],y[i])-59*diff(x[i-1],y[i-1])+37);
      }
}

