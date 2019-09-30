#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

void tos(){
  int N;
  int minh,minw,maxh,maxw;
  minh=minw=1000000000;
  maxh=maxw=0;
  cin>>N;
  vector<int> H(N),W(N),X(N);
  for(int i=0; i<N; i++){
    cin>>H[i]>>W[i];
    string str;
    cin>>str;
    if(str[0]=='B'){
      X[i]=1;
      minh=min(minh,H[i]);
      maxh=max(maxh,H[i]);
      minw=min(minw,W[i]);
      maxw=max(maxw,W[i]);
    }else{
      cin>>str;
      X[i]=0;
    }
  }
  cout<<endl;
  int M;
  cin>>M;
  if(minh>maxh){
    for(int i=0; i<M; i++){
      int h,w;
      cin>>h>>w;
      bool f=false;
      for(int j=0; j<N; j++){
	if(h==H[j]&&w==W[j]){
	  f=true;
	  break;
	}
      }
      if(f) cout<<"NOT BIRD"<<endl;
      else cout<<"UNKNOWN"<<endl;
    }
    return;
  }
  for(int i=0; i<M; i++){
    int h,w;
    cin>>h>>w;
    if(minh<=h&&h<=maxh&&minw<=w&&w<=maxw){
      cout<<"BIRD"<<endl;
    }else{
      int mh=min(h,minh);
      int Mh=max(h,maxh);
      int mw=min(w,minw);
      int Mw=max(w,maxw);
      //cerr<<mh<<Mh<<mw<<Mw<<endl;
      //int hh[4]={minh,minh,maxh,maxh};
      //int ww[4]={minw,maxw,minw,maxw};
      bool f=false;
      for(int j=0; j<N; j++){
	if(X[j]) continue;
	if(mh<=H[j]&&H[j]<=Mh && mw<=W[j]&&W[j]<=Mw){
	  f=true;
	  break;
	}
      }
      if(f) cout<<"NOT BIRD"<<endl;
      else cout<<"UNKNOWN"<<endl;
    }
  }
}

int main(){
  int N;
  cin>>N;
  for(int i=1; i<=N; i++){
    //printf("Case #%d: ", i);
    cout<<"Case #"<<i<<": ";
    tos();
  }
  return 0;
}

