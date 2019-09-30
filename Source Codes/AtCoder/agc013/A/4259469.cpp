#include<iostream>
#include<cstdio>
using namespace std;
int a[200000];
int n;
int main(){
	
	scanf("%d",&n);
	for(int i = 0;i < n;i ++){
		scanf("%d",&a[i]);
	}
	int cnt = 1;
	int ju = -1;	//1?? 2?? 
	int i = 1;
	for(i;i < n;i ++){
		if(ju == -1){
			if(a[i] > a[i-1]){
				ju = 1;
			}
			else if(a[i] < a[i-1]){
				ju = 2;
			}
			else{
				continue;
			}
		}
		else if(ju == 1 ){
			if(a[i] < a[i-1]){
				cnt++;
				ju = -1;
			}
		}
		else if(ju == 2){
			if(a[i] > a[i-1]){
				cnt++;
				ju = -1;
			}
		}
	}
	//if(i == n+1){
	//	cnt++;
	//}
	printf("%d",cnt);
	return 0;
} ./Main.cpp:15:6: warning: expression result unused [-Wunused-value]
        for(i;i < n;i ++){
            ^
1 warning generated.