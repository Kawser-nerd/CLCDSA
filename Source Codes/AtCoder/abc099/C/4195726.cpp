#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<numeric>
#include <algorithm>
#include<math.h>
#include<cstdio>
#include<string.h>
#include<unistd.h>
#include <array>
#include <map> 




using namespace std;
typedef long long ll;
struct point{
  int x;
  int y;

};
int gcd(int m, int n )
{
	// ??????????????
	if ( ( 0 == m ) || ( 0 == n ) )
		return 0;
	
	// ?????????
	while( m != n )
	{
		if ( m > n ) m = m - n;
		else         n = n - m;
	}
	return m;
}//gcd
int lcm( int m, int n )
{
	// ??????????????
	if ( ( 0 == m ) || ( 0 == n ) )
		return 0;
	
	return ((m / gcd(m, n)) * n); // lcm = m * n / gcd(m,n)
}//lcm
int input(){
  int x;
  cin>>x;
  return x;
}

int moji(char in)
{
    int ans = (int)in-(int)'a';
    if((ans < 0) || (ans > 25)){
        ans = 26;
    }
    return ans;
}
const int VV=10;//??????VV????????????
//dijkstra(s)s????????????????????d??????????????
int cost[VV][VV];
int d[VV];
bool used[VV];
void dijkstra(int s){
  fill(d,d+VV,100000);
  fill(used,used+VV,false);
  d[s]=0;
  while(true){
    int v=-1;
    for(int u=0;u<VV;u++){
      if(!used[u]&&(v==-1||d[u]<d[v]))v=u;
    }
    if(v==-1)break;
    used[v]=true;
    for(int u=0;u<VV;u++){
      d[u]=min(d[u],d[v]+cost[v][u]);
    }
  }

}

int compare_int(const void *a, const void *b)//qsort(quick sort??????)
{
    return *(int*)a - *(int*)b;
}

int binary_searchh(long long x,long long k[],int n){
  int l=0;
  int r=n;
  while(r-l>=1){
    int i=(l+r)/2;
    if(k[i]==x)return i;
    else if(k[i]<x)l=i+1;
    else r=i;
  }
  return -1;
}

struct File {
    int aa;
    int bb;

    File(const int& aa, const int& bb)
        : aa(aa), bb(bb) {}
};

bool operator<(const File& a, const File& b)
{
    // ??????????????????????????
    return std::tie(a.aa, a.bb) < std::tie(b.aa, b.bb);
}




int main(){
  int N;
  cin>>N;
  int res=N;
  for(int i=0;i<=N;i++){
    int cc=0;
    int t=i;
    while(t>0){
      cc+=t%6;
      t/=6;

    }
    t=N-i;
    while(t>0){
      cc+=t%9;
      t/=9;
    }
    if(res>cc){
      res=cc;
    }
  }
  cout<<res<<endl;

  


}