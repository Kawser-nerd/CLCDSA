#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

struct E{
	long long int x,y;
	bool operator<(const E& e1)const{
		if(x!=e1.x)return x<e1.x;
		return y<e1.y;
	}
};
int n;
std::map<E,long long int> ms;

long long int f(long long int h,long long int cx,long long int cy,long long int x,long long int y){
	return max(h-abs(cx-x)-abs(cy-y),(long long int)0);
}

long long int f2(long long int l,long long int r,long long int cx,long long int cy){
  long long int m=(l+r)/2;
  int d1=0,u1=0,hit1=0;
  for( auto i = ms.begin(); i != ms.end() ; ++i ) {
      E e1=i->first;
      long long int h2=i->second;
      long long int h3=f(m,cx,cy,e1.x,e1.y);
      if(h2<h3){
      	u1++;
      }else if(h2>h3){
      	d1++;
      }else{
      	hit1++;
      }
  }
  if(d1==0&&u1==0){
  	return m;
  }else if(l==r){
  	return -1;
  }else if(d1>0 && u1>0){
  	return -1;
  }else if(u1>0){
  	return f2(l,m,cx,cy);
  }else{
  	return f2(m+1,r,cx,cy);
  }
}


int main() {
	// your code goes here
	cin>>n;
	for(int i=0;i<n;i++){
		E e1;
		long long int h1;
		cin>>e1.x>>e1.y>>h1;
		ms[e1]=h1;
	}
	long long int ans=-1;
	int ansx,ansy;
	for(int x=0;x<=100;x++){
		for(int y=0;y<=100;y++){
			long long int t=f2(0,2000000000,x,y);
			if(t!=-1){
				ansx=x;
				ansy=y;
				ans=t;
				break;
			}
		}
		if(ans!=-1)break;
	}
	cout<<ansx<<" "<<ansy<<" "<<ans<<"\n";
	return 0;
}