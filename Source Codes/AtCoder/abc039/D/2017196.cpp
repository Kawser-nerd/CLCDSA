#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
 
#define MOD (long long int)(1e9+7)
#define ll long long int

int powa(int a,int b){
	if(b==1){
		return a;
	}else if(b%2==0){
		return powa(a,b/2)*powa(a,b/2);
	}else{
		return powa(a,b/2)*powa(a,b/2)*a;
	}
}


int main(void){
	
	int h,w;
	cin>>h>>w;
	int gazo[102][102];
	int ans[102][102];
	for(int i=0;i<102;i++){
		for(int j=0;j<102;j++){
			gazo[i][j]=1;
			ans[i][j]=1;
		}
	}
	string s;
	for(int i=1;i<=h;i++){
		cin>>s;
		for(int j=0;j<w;j++){
			if(s[j]=='#'){
				gazo[i][j+1]=1;
			}else{
				gazo[i][j+1]=0;
			}
		}
	}

	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(gazo[i-1][j-1]*gazo[i-1][j]*gazo[i-1][j+1]*
				gazo[i][j-1]*gazo[i][j]*gazo[i][j+1]*
				gazo[i+1][j-1]*gazo[i+1][j]*gazo[i+1][j+1]>0){
				ans[i][j]=2;
				for(int p=-1;p<=1;p++){
					for(int q=-1;q<=1;q++){
						gazo[i+p][j+q]=2;
					}
				}
			}else{
				ans[i][j]=0;
			}
		}
	}

	bool b=true;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(gazo[i][j]==1){
				b=false;
			}
		}
	}
	if(b){
		cout<<"possible"<<endl;
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				if(ans[i][j]==2){
					cout<<'#';
				}else{
					cout<<'.';
				}
			}
			cout<<endl;
		}
	}else{
		cout<<"impossible"<<endl;
	}
	
	return 0;
}