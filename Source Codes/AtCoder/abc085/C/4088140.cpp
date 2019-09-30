#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
#define ll long long
using namespace std;

ll n,y;
int main(){
	cin >> n >> y;
	if((y / 1000) > n * 10 || (y / 1000) < n * 1){
		printf("-1 -1 -1");	return 0;
	}
	for(int i = 0; i <= n ; i++){
		for(int j = 0; j <= n - i; j++){
			for(int k = 0; k <= n - i - j; k++){
				if(10000 * i + 5000 * j + 1000 * k == y && i + j + k == n){
					printf("%d %d %d",i,j,k);
					return 0;
				}
			}
		}
	}
	printf("-1 -1 -1");
}