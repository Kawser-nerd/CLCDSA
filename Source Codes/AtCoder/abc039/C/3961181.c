#include<stdio.h>

int main(){
		char s[25];
		scanf("%s",s);
		int i,j;
		char dore[7][50]={
				{"WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW"},
				{"WBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW"},
				{"WWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW"},
				{"WBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW"},
				{"WBWBWWBWBWWBWBWBWWBWBWWBWBWBW"},
				{"WBWWBWBWWBWBWBWWBWBWWBWBWBW"},
				{"WWBWBWWBWBWBWWBWBWWBWBWBW"},
					
		};
		for(i=0;i<7;i++){
				int f=0;
				for(j=0;j<20;j++){
						if(dore[i][j]!=s[j])f=1;
				}
				if(f==0){
						if(i==0)puts("Do");
						if(i==1)puts("Re");
						if(i==2)puts("Mi");
						if(i==3)puts("Fa");
						if(i==4)puts("So");
						if(i==5)puts("La");
						if(i==6)puts("Si");
				}
		}
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^