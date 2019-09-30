#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;

int main() {
	int a,b,c,x,y,z,w;
	cin>>a>>b>>c;
	cin>>x>>y>>z>>w;
	bool red=true,blue=true;
	if(b-c>=y&&b+c<=w&&a-c>=x&&a+c<=z)red=false;
	x-=a;
	y-=b;
	z-=a;
	w-=b;
	c=c*c;
	//cout<<x<<" "<<y<<" "<<z<<" "<<w<<" "<<c<<endl;
	if(x*x+y*y<=c&&x*x+w*w<=c&&z*z+y*y<=c&&z*z+w*w<=c)blue=false;
	if(red)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
	if(blue)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
}