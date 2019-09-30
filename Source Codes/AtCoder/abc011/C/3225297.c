#include<stdio.h>

int main(){
	int N,NG1,NG2,NG3,i;
	scanf("%d %d %d %d",&N,&NG1,&NG2,&NG3);
	
	if(N==NG1||N==NG2||N==NG3){
		puts("NO");
		return 0;
	}
	
	for(i=1;i<=100;i++){
		
		if(N-3!=NG1&&N-3!=NG2&&N-3!=NG3){
			N-=3;
		}
		else{
			if(N-2!=NG1&&N-2!=NG2&&N-2!=NG3){
				N-=2;
			}
			else{
				if(N-1!=NG1&&N-1!=NG2&&N-1!=NG3){
					N-=1;
				}
				else{
					puts("NO");
					return 0;
				}
			}
		}
	}
	if(N>0){
		puts("NO");
	}
	else{
		puts("YES");
	}
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d",&N,&NG1,&NG2,&NG3);
  ^