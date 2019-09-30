#include<iostream>

using namespace std;

int main()
{
	int W,H,N;
	
	cin >> W >> H >> N;
	
	int l=0,r=W,b=0,t=H;
	int x,y,a;
	
	for(int i=0;i<N;i++){
		cin >> x >> y >> a;
		switch(a){
		case 1:
			if(l < x)l = x;
			break;
		case 2:
			if(r > x)r = x;
			break;
		case 3:
			if(b < y)b = y;
			break;
		case 4:
			if(t > y)t = y;
			break;
		}
	}
	
	int res = (r-l)*(t-b);
	if (r > l && t > b ){
		cout << res << endl;
	}else{
		cout << 0 << endl;
	}
	
	return 0;

}