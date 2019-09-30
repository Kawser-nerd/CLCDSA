#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

char ss[200][200];
int pos[200][30],len[200];
int n;

int ok(char *s,int id) {
	int c=0,i,j,L=strlen(s);
	for(i=0;i<L;i++) {
		s[c++]=s[i];
		for(j=i+1;j<L&&s[j]==s[i];j++) ;
		i=j-1;
	}
	s[c]=0;
	memset(pos[id],0,sizeof(pos[id]));
	for(i=0;i<c;i++) {
		if(pos[id][s[i]-'a']) return 0;
		pos[id][s[i]-'a']=i+1;
	}
	len[id]=c;
	return 1;
}

int jud(int id) {
	int i,j;
	char ch=ss[id][0];
	for(i=1;i<=n;i++) if(i!=id) {
		int p=pos[i][ch-'a'];
		if(p==0) continue;
		if(p!=1&&p!=len[i]) return 0;
	}
	ch=ss[id][len[id]-1];
	for(i=1;i<=n;i++) if(i!=id) {
		int p=pos[i][ch-'a'];
		if(p==0) continue;
		if(p!=1&&p!=len[i]) return 0;
	}
	return 1;
}

const int mod=1000000007;
int f[30][30],to[30],from[30],ext[30],num[30],vis[30];
long long fac[105];

int main() {
	freopen("1.in","r",stdin);
	freopen("ans.txt","w",stdout);
	
	int T,tc,i,j,k;
	fac[0]=1;
	for(i=1;i<=100;i++) fac[i]=fac[i-1]*i%mod;
	scanf("%d",&T);
	for(tc=1;tc<=T;tc++) {
		scanf("%d",&n);
		for(i=1;i<=n;i++) {
			scanf("%s",ss[i]);
		}
		for(i=1;i<=n;i++) {
			if(!ok(ss[i],i)) break;
		}
		if(i<=n) {
			printf("Case #%d: 0\n",tc);
			continue;
		}
		for(i=1;i<=n;i++) {
			if(!jud(i)) break;
		}
		if(i<=n) {
			printf("Case #%d: 0\n",tc);
			continue;
		}
		memset(f,0,sizeof(f));
		memset(to,0,sizeof(to));
		memset(from,0,sizeof(from));
		memset(ext,0,sizeof(ext));
		memset(num,0,sizeof(num));
		for(i=1;i<=n;i++) {
			if(len[i]==1) {
				ext[ss[i][0]-'a']=1;
				num[ss[i][0]-'a']++;
			} else {
				int a=ss[i][0]-'a',b=ss[i][len[i]-1]-'a';
				ext[a]=ext[b]=1;
				f[a][b]=1;
				from[a]++;
				to[b]++;
			}
		}
		for(k=0;k<26;k++)
			for(i=0;i<26;i++)
				for(j=0;j<26;j++) f[i][j]|=(f[i][k]&f[k][j]);
		for(i=0;i<26;i++) if(from[i]>1||to[i]>1||f[i][i]) break;
		if(i<26) {
			printf("Case #%d: 0\n",tc);
			continue;
		}
		int cnt=0;
		for(i=0;i<26;i++) if(ext[i]&&to[i]==0) cnt++;
		long long ans=fac[cnt];
		for(i=0;i<26;i++) ans=ans*fac[num[i]]%mod;
		printf("Case #%d: %lld\n",tc,ans);
	}
}

		
		


			



		

	
