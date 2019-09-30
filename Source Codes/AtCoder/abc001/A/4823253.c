#include <stdio.h>

int main(){
    int a[2];
	for(int i = 0;i < 2;i++){
		a[i] = 0;
		}
    while(scanf("%d",&a[0]) == 0){
	}
	while(scanf("%d",&a[1]) == 0){
	}
	printf("%d\n",a[0]-a[1]); 


    return 0;

 }