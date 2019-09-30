#include<iostream>
typedef long long int lli;
using namespace std;

lli R,B;
lli x,y;

bool check(lli key){
  if(R < key) return false;
  lli a = key + (key-B)/(y-1);
  if(key > B && (key-B)%(y-1)!=0) a++;
  lli b = (R - key)/(x-1);
  if(a < 0) a = 0LL;
  if(b > key) b = key;
  return (b>=a);
}

int main(){
  cin>>R>>B>>x>>y;
  lli mi=0;
  lli ma=1LL<<62;
 
  while(mi <= ma){
    lli mid=(ma+mi)/2;
    //  cout<<mi<<" "<<ma<<" "<<mid<<endl;
    if(check(mid)){
      mi = mid+1;
    }else{
      ma = mid-1;
    }
  }
  cout<<(ma+mi)/2<<endl; 
  return 0;
}