#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int temp[1048577]={};
int x[4]={0,3,5,7};
int tempnum= 0;
void puttotemp(int k){
	temp[tempnum] = k;
	tempnum++;
}
void maketemp(int n){
	int a,b,c,d,e,f,g,h,i,j;
	for(a=0;a<4;a++){
		for(b=0;b<4;b++){
			for(c=0;c<4;c++){
				for(d=0;d<4;d++){
					for(e=0;e<4;e++){
						for(f=0;f<4;f++){
							for(g=0;g<4;g++){
								for(h=0;h<4;h++){
									for(i=0;i<4;i++){
										puttotemp(
												x[a]*(100000000)+
												x[b]*(10000000)+
												x[c]*(1000000)+
												x[d]*(100000)+
												x[e]*(10000)+
												x[f]*(1000)+
												x[g]*(100)+
												x[h]*(10)+
												x[i]*(1)
											);
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

int main(void){
	int N;
	scanf("%d",&N);
	int i,j,x;
	int flag,threeflag,fiveflag,sevenflag;
	char s[11];
	snprintf(s,11,"%d",N);//s??N???
	int n = strlen(s);//n??N??????
	int ans = 0;
	maketemp(n);
	//printf("n = %d\n",n);
	for(i=0;i<1048576;i++){
		if( N >= temp[i]){
		}else{
			continue;
		}
		//s?0????753???????
		snprintf(s,11,"%d",temp[i]);//
		flag = 0;threeflag=0;fiveflag=0;sevenflag=0;
		for(j=0;j<strlen(s);j++){
			if(s[j]=='7'){
				sevenflag=1;
			}else if(s[j]=='5'){
				fiveflag = 1;
			}else if(s[j]=='3'){
				threeflag= 1;
			}else{
				flag = -1;
			}
		}
		if(flag == 0 && sevenflag==1 && fiveflag ==1 && threeflag ==1){
			ans++;
		}
		
	}
	printf("%d",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:47:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^