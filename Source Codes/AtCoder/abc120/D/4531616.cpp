#include <iostream>
#include <stdio.h>
#include<vector>
#include<climits>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<functional>
#include <numeric>
#include <map>
#define FORi(N) for(int i=0;i<N;++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
ll gcd(ll m,ll n){
  if(n==0)return abs(m);
  return(gcd(n,m%n));
}
void putYN(bool b){
  if(b){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}
int main(){
  ll N,M;
  cin>>N>>M;
  vector<ll> A(M),B(M);
  vector<ll> parent(N+1,-2);
  vector<ll> ans(M,0);
  ans[M-1]=N*(N-1)/2;
  vector<ll> size(M);
  vector<ll> rank(M);
  FORi(M){
    cin>>A[i]>>B[i];
  }
  for(int i = M-1;i>=1;--i){
    if(parent[A[i]]==-2&&parent[B[i]]==-2){
      parent[A[i]]=-1;
      size[A[i]]=2;
      rank[A[i]]=2;
      parent[B[i]]=A[i];
      ans[i-1]=ans[i]-1;
    }else if(parent[A[i]]==-2&&parent[B[i]]!=-2){
      parent[A[i]]=B[i];
      ll curb=B[i];
      while(true){
        if(parent[curb]!=-1){
          curb=parent[curb];
        }else{
          break;
        }
      }
      ans[i-1]=ans[i]-size[curb];
      size[curb]++;
      rank[curb]++;
      
      ll r = curb;
      curb=B[i];
      ll precurb;
      while(true){
        if(parent[curb]!=-1){
          precurb=curb;
          curb=parent[curb];
          parent[precurb]=r;
        }else{
          break;
        }
      }
    }else if(parent[A[i]]!=-2&&parent[B[i]]==-2){
      parent[B[i]]=A[i];
      ll cura=A[i];
      while(true){
        if(parent[cura]!=-1){
          cura=parent[cura];
        }else{
          break;
        }
      }
      ans[i-1]=ans[i]-size[cura];
      size[cura]++;
      rank[cura]++;
      
      
      ll r = cura;
      cura=A[i];
      ll precura;
      while(true){
        if(parent[cura]!=-1){
          precura=cura;
          cura=parent[cura];
          parent[precura]=r;
        }else{
          break;
        }
      }
    }else{
      ll cura=A[i],curb=B[i];
      while(true){
        if(parent[cura]!=-1){
          cura=parent[cura];
        }else{
          break;
        }
      }
      while(true){
        if(parent[curb]!=-1){
         //cout<<"_" <<curb<<endl;
          curb=parent[curb];
        }else{
          break;
        }
      }
      if(cura!=curb){
        ans[i-1]=ans[i]-size[cura]*size[curb];
        if(rank[cura]>rank[curb]){
          parent[curb]=cura;
          size[cura]+=size[curb];
          rank[cura]=max(rank[cura],rank[curb]+1);
        }else{
          parent[cura]=curb;
          size[curb]+=size[cura];
          rank[curb]=max(rank[curb],rank[cura]+1);
        }
        //root.erase(rootcurb));
      }else{
        ans[i-1]=ans[i];
      }
    }
  }
  FORi(M){
   cout<<ans[i]<<endl; 
  }
  return 0;
}