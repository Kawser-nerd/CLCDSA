#include<stdio.h>
int ans;
char c;
int main(){
	ans = 1;
	c=getchar();
	while(c!='\n'){//10
		if(c=='o' || c=='k' || c=='u'){
		}else if(c=='c'){
			if((c=getchar())!='h'){
				ans = 0;
				break;
			}
		}else{
			ans = 0;
			break;
		}
		c=getchar();
	}
	if(ans){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
}