#include<stdio.h>
#include<string.h>

int a[128];
char str[1024];

void bn_mul(char a[],int k) {
	int t[1024],i,l=strlen(a);
	memset(t,0,sizeof(t));
	for(i=0;i<l;i++) t[i]=(a[l-1-i]-'0')*k;
	for(i=0;i<l;i++) if (t[i]>9) t[i+1]+=t[i]/10,t[i]%=10;
	while(t[l]) t[l+1]=t[l]/10,t[l]%=10,l++;
	for(i=0;i<l;i++) a[i]=t[l-1-i]+'0';
	a[l]='\0';
}

void bn_add(char a[],char b[]) {
	int t[1024],l1=strlen(a),l2=strlen(b),i;
	memset(t,0,sizeof(t));
	for(i=0;i<l1;i++) t[i]=a[l1-1-i]-'0';
	for(i=0;i<l2;i++) t[i]+=b[l2-1-i]-'0';
	if (l1<l2) l1=l2;
	for(i=0;i<l1;i++) if (t[i]>9) t[i]-=10,t[i+1]++;
	if (t[l1]) l1++;
	for(i=0;i<l1;i++) a[l1-1-i]=t[i]+'0';
	a[l1]='\0';
}

int main() {
	int N,cs=0;
	char tmp[64],tmp1[8];
	int base,i;
	for(scanf("%d",&N);N--;) {
		memset(a,0xff,sizeof(a));
		scanf("%s",tmp);
		str[0]='\0';
		base=0;
		for(i=0;tmp[i];i++) if (a[tmp[i]]<0) {
			a[tmp[i]]=base;
			base++;
		}
		if (base<2) base=2;
		for(i=0;tmp[i];i++) {
			bn_mul(str,base);
			if (a[tmp[i]]==1) sprintf(tmp1,"%d",0);
			else if (a[tmp[i]]==0) sprintf(tmp1,"%d",1);
			else sprintf(tmp1,"%d",a[tmp[i]]);
			bn_add(str,tmp1);
		}
		printf("Case #%d: %s\n",++cs,str);
	}
	return 0;
}
