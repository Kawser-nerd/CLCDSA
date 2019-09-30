#include<stdio.h>
#include<string.h>

int main(){
	char A[101],B[101],C[101],ch,ch1,res;
	int a=0,b=0,c=0,t=0;
	scanf("%s",A);
	getchar();
	scanf("%s",B);
	getchar();
	scanf("%s",C);
	while(1){
		if(t==0){
			ch=A[a];
			ch1=A[a+1];
			res='A';
			if(ch1=='\0'){
				break;
			}
			t++;
			a++;
		}
		else{
			if(ch=='a'){
				ch=A[a];
				
				res='A';
				if(ch=='\0'){
					break;
				}				
				a++;
			}
			else if(ch=='b'){
				ch=B[b];
				
				res='B';
				if(ch=='\0'){
					break;
				}
				b++;
			}
			else if(ch=='c'){
				ch=C[c];
				
				res='C';
				if(ch=='\0'){
					break;
				}
				c++;
			}
		}
	}
	printf("%c",res);
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",A);
  ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",B);
  ^
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",C);
  ^