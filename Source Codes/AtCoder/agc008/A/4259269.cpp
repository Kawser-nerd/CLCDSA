#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int x,y;
	scanf("%d%d",&x,&y);
	if(x == y){
		printf("0");
		return 0;
	}
	if( x == 0 ){
		if(y > 0){
			printf("%d",y - x);
		}
		if(y < 0){
			printf("%d",x - y + 1);
		}
	}
	if(y == 0){
		if(x < 0){
			printf("%d",y - x);
		}
		else{
			printf("%d",x + 1);
		}
	}
	if(x > 0 && y > 0){
		if(x < y){
			printf("%d",y - x);
		}
		else{
			printf("%d",x - y + 2);
		}
	}
	else if(x > 0 && y < 0){
		if(x >= -y){
			printf("%d", abs(x)-abs(y) + 1);
		}
		else{
			printf("%d", abs(y) - abs(x) + 1);
		}
	}
	else if(x < 0 && y > 0){
		if(abs(x) >= abs(y)){
			printf("%d", abs(x) - abs(y) + 1);
		}
		else{
			printf("%d", abs(y) - abs(x) + 1);
		}
	}
	else if( x < 0 && y < 0){
		if(x < y){
			printf("%d", abs(x) - abs(y) );
		}
		else{
			printf("%d",abs(y) - abs(x) + 2);
		}
	}
	return 0;
}