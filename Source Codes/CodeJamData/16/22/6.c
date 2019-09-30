#include<stdio.h>
#include<string.h>

char s1[32],s2[32];
int d;

int gao(char s1[],char s2[],char t1[],char t2[]) {
	int i,f;
	strcpy(t1,s1);
	strcpy(t2,s2);
	if (t1[d]>t2[d]) {
		for(i=d-1,f=-1;i>=0;i--) {
			if (t1[i]=='?' && t2[i]=='?' && f<0) f=i;
			else if (t1[i]=='?' && t2[i]>'0' && t2[i]!='?') {
				t1[i]=t2[i]-1;
				break;
			} else if (t1[i]!='?' && t1[i]<'9' && t2[i]=='?') {
				if (f<0) t2[i]=t1[i]+1;
				else t1[f]='0',t2[f]='1';
				break;
			}
		}
		if (i<0) {
			for(i=d-1,f=-1;i>=0;i--) {
				if (t1[i]=='?' && t2[i]=='?' && f<0) f=i;
				else if (t1[i]==t2[i]) break;
			}
			if (f<0) return 0;
			else t1[f]='0',t2[f]='1';
		}
	}
	for(i=f=0;t1[i];i++) {
		if (!f) {
			if (t1[i]=='?' && t2[i]=='?') t1[i]=t2[i]='0';
			else if (t1[i]=='?') t1[i]=t2[i];
			else if (t2[i]=='?') t2[i]=t1[i];
			else if (t1[i]!=t2[i]) f=1;
		} else {
			if (t1[i]=='?') t1[i]='9';
			if (t2[i]=='?') t2[i]='0';
		}
	}
	return 1;
}

int main() {
	int N,cs=0,i,f1,f2;
	long long tt1,tt2,tt3,tt4;
	char t1[32],t2[32],t3[32],t4[32];
	for(scanf("%d",&N);N--;) {
		scanf("%s %s",s1,s2);
		for(i=0;s1[i];i++) if (s1[i]!='?' && s2[i]!='?' && s1[i]!=s2[i]) break;
		if (!s1[i]) {
			for(i=0;s1[i];i++) {
				if (s1[i]=='?' && s2[i]=='?') s1[i]=s2[i]='0';
				else if (s1[i]=='?') s1[i]=s2[i];
				else if (s2[i]=='?') s2[i]=s1[i];
			}
		} else {
			d=i;
			f1=gao(s1,s2,t1,t2);
			f2=gao(s2,s1,t4,t3);
			sscanf(t1,"%lld",&tt1);
			sscanf(t2,"%lld",&tt2);
			sscanf(t3,"%lld",&tt3);
			sscanf(t4,"%lld",&tt4);
//			printf("%s %s %s %s %d %d\n",t1,t2,t3,t4,f1,f2);
			if (f1 && f2) {
				if (tt2-tt1<tt3-tt4) {
					strcpy(s1,t1);
					strcpy(s2,t2);
				} else if (tt2-tt1>tt3-tt4) {
					strcpy(s1,t3);
					strcpy(s2,t4);
				} else if (tt1<tt3) {
					strcpy(s1,t1);
					strcpy(s2,t2);
				} else if (tt1>tt3) {
					strcpy(s1,t3);
					strcpy(s2,t4);
				} else if (tt2<tt4) {
					strcpy(s1,t1);
					strcpy(s2,t2);
				} else {
					strcpy(s1,t3);
					strcpy(s2,t4);
				}
			} else if (f1) {
				strcpy(s1,t1);
				strcpy(s2,t2);
			} else if (f2) {
				strcpy(s1,t3);
				strcpy(s2,t4);
			}
		}
		printf("Case #%d: %s %s\n",++cs,s1,s2);
	}
	return 0;
}
