#include<bits/stdc++.h>
using namespace std;

int main(){
    int x=1,y=1;
    cout<<fixed<<setprecision(10)<<endl;
    cout<<"itr\tx\ty\tdeltax\tdeltay\terror"<<endl;
    for(int i=0;i<100;i++){
       double F=x*x+y*y-4, G=exp(x)+y-1;
       double a=2*x,b=2*y,c=exp(x),d=1,det=a*d-b*c;
       if(fabs(det)<1e-14)return;
        double dx=(-F*d+b*G)/det, dy=(-a*G+c*F)/det;
        x+=dx;
        y+=dy;

        double e=max(fabs(dx),fabs(dy));
        cout<<i<<"\t"<<x<<"\t"<<y<<"\t"<<dx<<"\t"<<dy<<"\t"<<e<<endl;
        if(e<1e-6)break;

    }
    cout<<"solutions are "<<x<<" "<<y<<endl;
}