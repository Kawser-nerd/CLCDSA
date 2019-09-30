#include<stdio.h>

char*encry="ejp mysljylc kd kxveddknmc re jsicpdrysi\
 rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd\
 de kr kd eoya kw aej tysr re ujdr lkgc jv";
char*decry="our language is impossible to understand\
 there are twenty six factorial possibilities\
 so it is okay if you want to just give up";

int main(int argc,char*argv[]){
	int m[128],a,b,c;
	char s[128];

	for(a=0;a<128;a++)m[a]=0;

	for(a=0;encry[a]!='\0';a++)m[(int)encry[a]]=decry[a];
	m['q']='z';
	m['z']='q';

	gets(s);
	sscanf(s,"%d",&c);
	for(a=1;a<=c;a++){
		gets(s);
		for(b=0;s[b]!='\0';b++)s[b]=m[(int)s[b]];
		printf("Case #%d: %s\n",a,s);
	}
	return 0;
}
