#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
int main(){
  int n,k;
  cin>>n>>k;
  vector<ll> xary,yary;
  for(int i=0;i<n;++i){
    ll x,y;
    cin>>x>>y;
    xary.push_back(x);
    yary.push_back(y);
  }

  unsigned long long ret = 0;
  for(int xi=0;xi<n;++xi){
    for(int xj=xi+1;xj<n;++xj){
      for(int yi=0;yi<n;++yi){
        for(int yj=yi+1;yj<n;++yj){
          int cnt = 0;
          ll maxx = max(xary[xi],xary[xj]);
          ll minx = min(xary[xi],xary[xj]);
          ll maxy = max(yary[yi],yary[yj]);
          ll miny = min(yary[yi],yary[yj]);
          for(int p=0;p<n;++p){
            if(maxx>=xary[p] && xary[p]>=minx && maxy>=yary[p] && yary[p]>=miny){
              cnt += 1;
            }
            if(cnt>=k){
              break;
            }
          }

          if(cnt>=k){
            unsigned long long s = (maxx-minx) * (maxy-miny);
            if(ret==0 || s<ret){
              ret = s;
            }
          }
        }
      }
    }
  }
  cout<<ret<<endl;
}