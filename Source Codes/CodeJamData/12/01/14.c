#include<stdio.h>
int main(){
	char map[] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	char txt[109],ch;
	int T,t=1,l,i;
	scanf("%d",&T);
	scanf("%c",&ch);
	while(t<=T){
		gets(txt);
		//printf("txt = %s\n",txt);
		for(i=0;txt[i]!='\0';i++)
			if(txt[i] >= 'a' && txt[i] <= 'z') {
				txt[i] = map[txt[i]-'a'];
			}
		printf("Case #%d: %s\n",t,txt);
		t++;
	}
}