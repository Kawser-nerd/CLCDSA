#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
 
int main(){
  int n; cin >> n;
  vector<long long int> x(n),y(n);
  for(int i=0;i<n;i++) cin >> x[i] >> y[i];
  vector<pair<long long int,int> > xi(n),yi(n);
  vector<int> xid(n),yid(n);
  for(int i=0;i<n;i++){
    xi[i] = make_pair(x[i],i);
    yi[i] = make_pair(y[i],i);
  }
  sort(xi.begin(),xi.end());
  sort(yi.begin(),yi.end());
  for(int i=0;i<n;i++){
    xid[xi[i].second] = i;
    yid[yi[i].second] = i;
  }
 
  vector<bool> c(n);
  for(int i=0;i<n;i++) c[i] = false;
  priority_queue<pair<long long int,int>, vector<pair<long long int,int>>, greater<pair<long long int, int> > > q;
  c[xi[0].second] = true;
  q.push(make_pair(xi[1].first -xi[0].first, xi[1].second));
  if(yid[xi[0].second]>0) q.push(make_pair(yi[yid[xi[0].second]].first -yi[yid[xi[0].second]-1].first, yi[yid[xi[0].second]-1].second));
  if(yid[xi[0].second]<n-1) q.push(make_pair(yi[yid[xi[0].second]+1].first -yi[yid[xi[0].second]].first, yi[yid[xi[0].second]+1].second));
  int count = 1;
  long long int ans = 0;
  while(count!=n&&!q.empty()){
    while(c[q.top().second]) q.pop();
    int id = q.top().second;
    int ix = xid[id], iy = yid[id];
    //cout << q.top().first << ":" << id << endl;
    
    ans = ans + q.top().first;
    c[id] = true;
    count++;
    q.pop();
    
    if(ix>0&&!c[xi[ix-1].second]) 	q.push(make_pair(xi[ix].first-xi[ix-1].first, xi[ix-1].second));
    if(ix<n-1&&!c[xi[ix+1].second]) q.push(make_pair(xi[ix+1].first-xi[ix].first, xi[ix+1].second));
    if(iy>0&&!c[yi[iy-1].second]) 	q.push(make_pair(yi[iy].first-yi[iy-1].first, yi[iy-1].second));
    if(iy<n-1&&!c[yi[iy+1].second]) q.push(make_pair(yi[iy+1].first-yi[iy].first, yi[iy+1].second));
  }
  cout << ans << endl;
  return 0;

}