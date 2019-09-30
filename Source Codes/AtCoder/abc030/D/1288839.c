#include<stdio.h>
#include<string.h>
int strnum(char* a,char* b){
  int la=strlen(a),lb=strlen(b);
  return la-lb?la-lb:strcmp(a,b);
}
int main(){
	int n,m,i,a,b,c=0,d[100010],f[100010]={};
	char s[100010],w[100];
	scanf("%d %d %s",&n,&m,s);
	for(i=0;i<n;i++)scanf("%d",&d[i]);
	b=m;
	for(i=1;f[b]==0;i++){//printf("%d",m);
		f[b]=i;
		b=d[b-1];
	}//printf("%d ",i);
	a=f[b]-1;
	b=i-f[b];//printf("%d %d ",a,b);
	sprintf(w,"%d",a);//printf("%d\n",strnum(w,s));
	if(strnum(s,w)<0){
		for(i=0;s[i];i++)c=c*10+s[i]-'0';
		goto END;
	}
	for(i=0;s[i];i++)c=(c*10+s[i]-'0')%b;
	while(c<a)c+=b;
	END:;//printf("%d %d\n",c,m);
	while(c--)m=d[m-1];
	printf("%d\n",m);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %s",&n,&m,s);
  ^
./Main.c:11:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%d",&d[i]);
                  ^