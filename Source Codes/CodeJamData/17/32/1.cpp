#include <iostream>
#include <algorithm>
using namespace std;
int t[24*60];
int tt[24*60];
int dyn[24*60][2][24*60+1];
const int inf = 24*60+1;
int main(){
  int tnum;cin>>tnum;
  for (int ti=0;ti<tnum;++ti){
    int n[2];cin>>n[0]>>n[1];
    for (int i=0;i<24*60;++i)
      tt[i]=-1;
    for (int i=0;i<2;++i)
      for (int j=0;j<n[i];++j){
        int a, b;cin>>a>>b;
        for (int k=a;k<b;++k)
          tt[k] = i;
      }
    int ans=inf;
    if (n[0]+n[1]==0){
      ans = 2;
      goto print;
    }
    for (int i=0;i<24*60;++i)
      if (tt[i]!=-1){
        for (int j=0;j<24*60;++j)
          t[j]=tt[(j+i)%(24*60)];
        break;
      }
    for (int i=0;i<24*60;++i)
      for (int j=0;j<2;++j)
        for (int k=0;k<=24*60;++k){
          dyn[i][j][k]=inf;
          if (t[i]!=-1 && t[i]!=j)
            continue;
          if (j==0 && k==0)
            continue;
          if (i==0){
            if ((j==0 && k==1) || (j==1 && k==0))
              dyn[i][j][k]=0;
            continue;
          }
          int nk=k;
          if (j==0)
            nk -= 1;
          dyn[i][j][k] = min(dyn[i][j][k], dyn[i-1][j][nk]);
          dyn[i][j][k] = min(dyn[i][j][k], dyn[i-1][1-j][nk]+1);
        }
    ans = min(ans, dyn[24*60-1][0][24*60/2]+(t[0]==1?1:0));
    ans = min(ans, dyn[24*60-1][1][24*60/2]+(t[0]==0?1:0));
print:
    cout<<"Case #"<<ti+1<<": "<<ans<<endl;
  }
  return 0;
}
