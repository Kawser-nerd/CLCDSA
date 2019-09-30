//YDK saikoune
#include<iostream>
#include<string>
#define rep(i,n) for(int (i)=0; (i)<(n); (i)++)
#define rep2(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define rrep(i,n) for(int (i)=(n-1); (i)>=0; (i)--)
#define rrep2(i,a,b) for(int (i)=(a-1); (i)>=b; (i)--); 
using namespace std;

int main(){
	int i, j;
	int s=1;
	int h, w;
	int n;
	int min;
	int tmin;

	cin >> n;

	while(s*s <= n) s++;

	s--;
	min = n - s*s;

	rep(i, s){
		rep(j, s){
			tmin = n -(s-i)*(s+j);
			if(tmin < 0) break;
			if(min > tmin + (i+j)) min = tmin + (i+j);
		}
	}
		
	cout << min << endl;


	return 0;
}