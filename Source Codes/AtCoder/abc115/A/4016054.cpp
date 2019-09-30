#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<numeric>
#include <algorithm>
#include<math.h>
#include<cstdio>
#include<string.h>




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




int main(){
  string s;
  cin>>s;
  if(s=="25"){
    cout<<"Christmas"<<endl;
  }else if(s=="24"){
    cout<<"Christmas Eve"<<endl;
  }else if(s=="23"){
    cout<<"Christmas Eve Eve"<<endl;
  }else{
    cout<<"Christmas Eve Eve Eve"<<endl;
  }





  

  



}