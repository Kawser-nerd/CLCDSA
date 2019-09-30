#include <stdio.h>
#include <string.h>

char tall[2000000][101];
int lens[2000000];
int tn;

char s[211],t[211];

void btr(int at,int L,int len,int mid,int ones,int twos) {
	int i,j;
	if(twos>1 || ones>5) return;
	if(at==(len+1)/2) {
		for(i=0;i<len+len-1;i++) t[i]=0; t[i]=0;
		for(i=0;i<len;i++) for(j=0;j<len;j++) t[i+j]+=s[i]*s[j];
		for(i=0;i<len+len-1;i++) t[i]+=48;
		for(i=0;i<len+len-1;i++) if(t[i]>57) goto fail;
		lens[tn]=len+len-1;
		strcpy(tall[tn++],t);
	fail:
		return;
	}
	if(!at) {
		for(i=0;i<L+L+mid;i++) s[i]='0'; s[i]=0;
		s[0]=s[len-1]=1;
		btr(at+1,L,len,mid,1,0);
		s[0]=s[len-1]=2;
		btr(at+1,L,len,mid,0,1);
	} else if(at==L && mid) {
		s[at]=s[len-at-1]=0;
		btr(at+1,L,len,mid,ones,twos);
		s[at]=s[len-at-1]=1;
		btr(at+1,L,len,mid,ones+1,twos);
		s[at]=s[len-at-1]=2;
		btr(at+1,L,len,mid,ones,twos+1);
	} else {
		s[at]=s[len-at-1]=0;
		btr(at+1,L,len,mid,ones,twos);
		s[at]=s[len-at-1]=1;
		btr(at+1,L,len,mid,ones+1,twos);
		s[at]=s[len-at-1]=2;
		btr(at+1,L,len,mid,ones,twos+1);
	}
}

void pre() {
	int l;
	tn=0;
	lens[tn]=1; strcpy(tall[tn++],"1");
	lens[tn]=1; strcpy(tall[tn++],"4");
	lens[tn]=1; strcpy(tall[tn++],"9");
	for(l=1;l<=25;l++) {
		btr(0,l,l+l,0,0,0);
		if(l>49) break;
		btr(0,l,l+l+1,1,0,0);
	}
}

void minusone(char *s) {
	int i=strlen(s)-1;
	while(i>=0) {
		s[i]-=1;
		if(s[i]==47) {
			s[i]=57;
			i--;
		} else break;
	}
}

int larger(char *tall,int la,char *b,int lb) {
	int i;
	if(la>lb) return 1;
	if(la<lb) return 0;
	for(i=0;i<lb;i++) {
		if(tall[i]>b[i]) return 1;
		if(tall[i]<b[i]) return 0;
	}
	return 0;
}

int solve(char *s) {
	int i,lb=strlen(s);
	for(i=0;i<tn;i++) if(larger(tall[i],lens[i],s,lb)) break;
	return i;
}

int main() {
	int T,no=1;
	char s[120],t[120];
	pre();
	scanf("%d",&T);
	while(T--) {
		scanf("%s %s",s,t);
		minusone(s);
		printf("Case #%d: %d\n",no++,solve(t)-solve(s));
	}
	return 0;
}
