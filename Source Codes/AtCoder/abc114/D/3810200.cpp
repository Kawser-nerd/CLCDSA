#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(void){
int n,a=0,b=0,c=0,d=0,e=0;
int m[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int p[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
cin>>n;
    for(int i=0;2*m[i]<=n;i++){
        for(int j=m[i];n>j;j=j*m[i]){
            p[i]=p[i]+n/j;
        }
        if(p[i]>=74){
            a++;};
        if(p[i]>=24){
            b++;};
        if(p[i]>=14){
            c++;};
        if(p[i]>=4){
            d++;};
        if(p[i]>=2){
            e++;};
    };
    cout<<a+b*(e-1)+c*(d-1)+d*(d-1)*(e-2)/2;
}