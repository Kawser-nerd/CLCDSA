#include<stdio.h>
#include<string.h>>
int main(){
	char S[101];
	char T[101];
	char temp[101];
	gets(S);
	gets(T);
	int i,j;
	int Slen=strlen(S);
	int Llen=strlen(T);
	if(Slen!=Llen){
		printf("NO\n");
	}
	else{
		int flag=0,k=Slen;
		while(k&&flag==0){
			if(strcmp(S,T)==0){
				flag=1;
			}
			else{
				temp[0]=S[Slen-1];
				j=1;
				for(i=0;i<Slen-1;i++){
					temp[j++]=S[i];
				}
				temp[j]='\0';
				strcpy(S,temp);
				k--;
			}
		}
		if(flag==0){
			printf("No\n");
		}
		else{
			printf("Yes\n");
		}
	}
	return 0;
} ./Main.c:2:19: warning: extra tokens at end of #include directive
 #include<string.h>>
                   ^
./Main.c: In function ‘main’:
./Main.c:7:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(S);
  ^
/tmp/ccwyRWdY.o: In function `main':
Main.c:(.text.startup+0x35): warning: the `gets' function is dangerous and should not be used.