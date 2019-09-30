#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int A[110][210][110][110];

struct state {
  int x,y,z,w;
  bool alive(){ return x > 0; }
};

void do_case(){
  int Hd, Ad, Hk, Ak, B, D;
  cin >> Hd >> Ad >> Hk >> Ak >> B >> D;
  
  for(int i=0;i<=100;i++)
    for(int j=0;j<=200;j++)
      for(int k=0;k<=100;k++)
	for(int l=0;l<=100;l++)
	  A[i][j][k][l] = -1;

  state start = {Hd,Ad,Hk,Ak};
  A[Hd][Ad][Hk][Ak] = 0;
  queue<state> q;
  q.push(start);
  while(!q.empty()){
    state curr = q.front(); q.pop();
    int hd,ad,hk,ak;
    hd = curr.x, ad = curr.y;
    hk = curr.z, ak = curr.w;

    int d = A[hd][ad][hk][ak];
    
    if(ad >= hk){ cout << d+1 << endl; return; }
    
    { // Attack
      state next = {hd-ak,ad,hk-ad,ak};
      if(next.alive()){
	int& x = A[hd-ak][ad][hk-ad][ak];
	if(x == -1){
	  x = d+1;
	  q.push(next);
	}
      }
    }
    { // Buff
      state next = {hd-ak,ad+B,hk,ak};
      if(next.alive()){
	int& x = A[hd-ak][ad+B][hk][ak];
	if(x == -1){
	  x = d+1;
	  q.push(next);
	}
      }
    }
    { // Cure
      state next = {Hd-ak,ad,hk,ak};
      if(next.alive()){
	int& x = A[Hd-ak][ad][hk][ak];
	if(x == -1){
	  x = d+1;
	  q.push(next);
	}
      }
    }
    { // Debuff
      int new_ak = max(0,ak-D);
      state next = {hd-new_ak,ad,hk,new_ak};
      if(next.alive()){
	int& x = A[hd-new_ak][ad][hk][new_ak];
	if(x == -1){
	  x = d+1;
	  q.push(next);
	}
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
}

int main(){
  int T,C=1; cin >> T;
  while(T--){
    cout << "Case #" << C++ << ": ";
    do_case();
  }
}
