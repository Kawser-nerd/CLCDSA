#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  int a,b,c,time,aa;
  cin>>time;
  a=time/3600;
  aa=time%3600;
  b=aa/60;
  c=aa%60;
  if(a<10 and b<10 and c<10)
    cout<<'0'<<a<<':'<<'0'<<b<<':'<<'0'<<c<<endl;
  if(a<10 and b<10 and c>=10)
    cout<<'0'<<a<<':'<<'0'<<b<<':'<<c<<endl;
  if(a<10 and c<10 and b>=10)
    cout<<'0'<<a<<':'<<b<<':'<<'0'<<c<<endl;
  if(b<10 and c<10 and a>=10)
    cout<<a<<':'<<'0'<<b<<':'<<'0'<<c<<endl;
  if(a<10 and b>=10 and c>=10)
    cout<<'0'<<a<<':'<<b<<':'<<c<<endl;
  if(b<10 and a>=10 and c>=10)
    cout<<a<<':'<<'0'<<b<<':'<<c<<endl;
  if(c<10 and a>=10 and b>=10)
    cout<<a<<':'<<b<<':'<<'0'<<c<<endl;
  if(a>=10 and b>=10 and c>=10)
    cout<<a<<':'<<b<<':'<<c<<endl;
}