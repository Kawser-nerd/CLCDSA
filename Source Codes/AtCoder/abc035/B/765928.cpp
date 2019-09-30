//Aho
#include<iostream>
#include<string>
#define rep(i,n) for(int (i)=0; (i)<(n); (i)++)
#define rep2(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define rrep(i,n) for(int (i)=(n-1); (i)>=0; (i)--)
#define rrep2(i,a,b) for(int (i)=(a-1); (i)>=b; (i)--); 
using namespace std;

int main(){
	int i, j;
	char S[100000];
	int T;
	int x=0, y=0;;
	int dxy = 0;

	cin >> S;
	cin >> T;


	rep(i, strlen(S)){
		if(S[i] == 'L') x--;
		else if(S[i] == 'R') x++;
		else if(S[i] == 'U') y++;
		else if(S[i] == 'D') y--;
		else if(S[i] == '?') dxy++;
	}
	
	if(T == 1){
		if(x>0) x += dxy;
		else x -= dxy;
	}else if(T == 2){
		while((x>0) && (dxy>0)){
			x--;
			dxy--;
		}
		while((x<0) && (dxy>0)){
			x++;
			dxy--;
		}
		while((y>0) && (dxy>0)){
			y--;
			dxy--;
		}
		while((y<0) && (dxy>0)){
			y++;
			dxy--;
		}
		if((x==0) && (y==0)){
			if(dxy%2){
				x=1;
				y=0;
			}else{
				x=0;
				y=0;
			}
		}
	}

	if(x<0) x *= -1;
	if(y<0) y *= -1;

	cout << x + y << endl;

	return 0;
}