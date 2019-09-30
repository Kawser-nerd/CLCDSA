//YDK saikoune
#include<iostream>
#include<string>
#define rep(i,n) for(int (i)=0; (i)<(n); (i)++)
#define rep2(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define rrep(i,n) for(int (i)=(n-1); (i)>=0; (i)--)
#define rrep2(i,a,b) for(int (i)=(a-1); (i)>=b; (i)--); 
using namespace std;

int main(){
	int i, j, k, l;
	int H;
	int W;
	int can = 1;
	char s[100][100];
	int dx, dy;
	int lx, ly;
	int wassharp=0;


	cin >> H;
	cin >> W;

	rep(i, H) scanf("%s", s[i]);
	
	//??#???????????
	rep(i, H){
		rep(j, W){
			if((s[i][j] == '#') || (s[i][j] == 'b')){
				dx = -1;
				dy = -1;
				lx = 2;
				ly = 2;
				if(i==0) dy = 0; //???
				if(j==0) dx = 0; //???
				if(i==H-1) ly = 1; //H??
				if(j==W-1) lx = 1; //W??
				
				wassharp = 1;

				rep2(k, dy, ly){
					rep2(l, dx, lx){
						if( !((s[i+k][j+l] == '#') || (s[i+k][j+l] == 'a') || (s[i+k][j+l] == 'b')) ) wassharp = 0;
					}
				}

				//#???????a????????b??????
				if(wassharp){
					rep2(k, dy, ly){
						rep2(l, dx, lx){
							if((i+k==i) && (j+l==j)) s[i+k][j+l] = 'a';
							else  if(s[i+k][j+l] != 'a') s[i+k][j+l] = 'b';
						}
					}
				}
			}
		}
	}

	rep(i, H){
		rep(j, W){
			if(s[i][j] == '#') can = 0;
		}
		if(!can) break;
	}

	if(can){
		cout << "possible" << endl;
		rep(i, H){
			rep(j, W){
				if(s[i][j] == 'a') cout << '#';
				else cout << '.';
			}
			cout << endl;
		}
	}else cout << "impossible" << endl;

	return 0;
}