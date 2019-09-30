#include <stdio.h>
#include <string.h>

int len;
char a[100],b[100];
char a2[100],b2[100];
long long bestd,besta,bestb;

long long toll(char *s) {
	long long r=0;
	while(*s) r=r*10+*(s++)-48;
	return r;
}

void btr(int at,int comp) {
	long long aa,bb,dd;
	if(at==len) {
		aa=toll(a);
		bb=toll(b);
		dd=aa<bb?bb-aa:aa-bb;
//		printf("try %I64d %I64d => %I64d\n",aa,bb,dd);
		if(bestd>dd) bestd=dd,besta=aa,bestb=bb;
		else if(bestd==dd) {
			if(besta>aa) bestd=dd,besta=aa,bestb=bb;
			else if(besta==aa) {
				if(bestb>bb) bestd=dd,besta=aa,bestb=bb;
			}
		}
		return;
	}
	if(a[at]=='?' && b[at]=='?') {
		if(!comp) {
			/* make still equal */
			a[at]='0'; b[at]='0'; btr(at+1,comp);
			/* make a<b */
			a[at]='0'; b[at]='1'; btr(at+1,-1);
			/* make a>b */
			a[at]='1'; b[at]='0'; btr(at+1,1);
		} else if(comp<0) { /* a<b */
			a[at]='9'; b[at]='0'; btr(at+1,comp);
		} else { /* comp>0, a>b */
			a[at]='0'; b[at]='9'; btr(at+1,comp);
		}
		a[at]='?'; b[at]='?';
	} else if(a[at]=='?') {
		if(!comp) {
			/* make still equal */
			a[at]=b[at]; btr(at+1,0);
			/* make a<b */
			if(b[at]>'0') { a[at]=b[at]-1; btr(at+1,-1); }
			/* make a>b */
			if(b[at]<'9') { a[at]=b[at]+1; btr(at+1,1); }
		} else if(comp<0) { /* a<b */
			a[at]='9'; btr(at+1,comp);
		} else { /* comp>0, a>b */
			a[at]='0'; btr(at+1,comp);
		}
		a[at]='?';
	} else if(b[at]=='?') {
		if(!comp) {
			/* make still equal */
			b[at]=a[at]; btr(at+1,0);
			/* make a<b */
			if(a[at]<'9') { b[at]=a[at]+1; btr(at+1,-1); }
			/* make a>b */
			if(a[at]>'0') { b[at]=a[at]-1; btr(at+1,1); }
		} else if(comp<0) { /* a<b */
			b[at]='0'; btr(at+1,comp);
		} else { /* comp>0, a>b */
			b[at]='9'; btr(at+1,comp);
		}
		b[at]='?';
	} else {
		if(!comp) {
			if(a[at]<b[at]) btr(at+1,-1);
			else if(a[at]>b[at]) btr(at+1,1);
			else btr(at+1,0);
		} else btr(at+1,comp);
	}
}

void solve() {
	int i;
	scanf("%s %s",a,b);
	len=strlen(a);
	besta=bestb=bestd=1099999999999999999LL;
	for(i=0;i<len;i++) if(a[i]!='?' && b[i]!='?' && a[i]!=b[i]) goto stuff;
	/* trivial */
	for(i=0;i<len;i++) {
		if(a[i]=='?' && b[i]=='?') a[i]=b[i]='0';
		else if(a[i]=='?') a[i]=b[i];
		else if(b[i]=='?') b[i]=a[i];
	}
	printf("%s %s\n",a,b);
	return;
stuff:
	btr(0,0);
	printf("%0*I64d %0*I64d\n",len,besta,len,bestb);
	return;
}

int main() {
	int T,caseno=1;
	scanf("%d",&T);
	while(T--) printf("Case #%d: ",caseno++),solve();
	return 0;
}
