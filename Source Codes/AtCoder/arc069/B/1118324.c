#include<stdio.h>

char s[100001],l[100001];

int check(long n,int i){
	l[0]=(i%2==0)?'S':'W';
	l[1]=(i/2==0)?'S':'W';
	long j;
	for(j=1;j<n-1;j++){
		if(l[j]=='S'){
			if(s[j]=='o') l[j+1]=l[j-1];
			else l[j+1]=(l[j-1]=='W')?'S':'W';
		}else{
			if(s[j]=='x') l[j+1]=l[j-1];
			else l[j+1]=(l[j-1]=='W')?'S':'W';
		}
	}
	if(l[n-1]=='S'){
		if(s[n-1]=='o'){
			if(l[0]!=l[n-2]) return 0;
		}else{
			if(l[0]==l[n-2]) return 0;
		}
	}else{
		if(s[n-1]=='x'){
			if(l[0]!=l[n-2]) return 0;
		}else{
			if(l[0]==l[n-2]) return 0;
		}
	}
	if(l[0]=='S'){
		if(s[0]=='o'){
			if(l[1]!=l[n-1]) return 0;
		}else{
			if(l[1]==l[n-1]) return 0;
		}
	}else{
		if(s[0]=='x'){
			if(l[1]!=l[n-1]) return 0;
		}else{
			if(l[1]==l[n-1]) return 0;
		}
	}
	l[n]='\0';
	return 1;
}

int main(int argc, char const *argv[]) {
	long n;
	int i;
	scanf("%ld",&n);
	scanf("%s",s);
	for(i=0;i<4;i++){
		if(check(n,i)) i=4;
	}
	if(i==4) printf("-1\n");
	else printf("%s\n",l);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:51:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&n);
  ^
./Main.c:52:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^