#include<bits/stdc++.h>
using namespace std;
#define r(i,n) for(int i=0;i<n;i++)
#define s second
#define f first
#define mk make_pair
int main(){
  int ppp,ss=0;
  cin>>ppp;
  while(ppp--){ss++;
    int n,t;
    cin>>n>>t;
    string s[n];
    r(i,n)cin>>s[i];
    for(int i=0;i<n;i++){
      for(int j=0;j<t;j++){
        if(i+1<n)if(s[i+1][j]=='?'&&s[i][j]!='?')s[i+1][j]=s[i][j];
      }
    }
    for(int i=n-1;i>=0;i--){
      for(int j=0;j<t;j++){
        if(i-1>=0)if(s[i-1][j]=='?'&&s[i][j]!='?')s[i-1][j]=s[i][j];
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<t;j++){
        if(j+1<t)if(s[i][j+1]=='?'&&s[i][j]!='?')s[i][j+1]=s[i][j];
      }
    }
    for(int i=0;i<n;i++){
      for(int j=t-1;j>=0;j--){
        if(j-1>=0)if(s[i][j-1]=='?'&&s[i][j]!='?')s[i][j-1]=s[i][j];
      }
    }
    printf("Case #%d:\n",ss);
    r(i,n)cout<<s[i]<<endl;
  }
}