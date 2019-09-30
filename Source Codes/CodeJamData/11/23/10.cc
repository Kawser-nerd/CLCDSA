#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<int> a[2010];
map<int, int> pred[2010];

int n, m;
int c;
int ans[2010];

vector<int> walk(int cur, int nxt)
{
	int s=cur;
	int tmp;
	vector<int> ret;
	while(true)
	{
		ret.push_back(cur);
		if(nxt!=s){tmp=pred[nxt][cur]; cur=nxt; nxt=tmp;}
		else break;
	}
	return ret;
}

int walklen(int cur, int nxt)
{
	int s=cur;
	int tmp;
	int ret=0;
	while(true)
	{
		ret++;
		if(nxt!=s){tmp=pred[nxt][cur]; cur=nxt; nxt=tmp;}
		else break;
	}
	return ret;
}

void color(int v1, int v2)
{
	int i, j;
	vector<int> v=walk(v1, v2);
	set<int> s;
	vector<int> cs;
	for(i=1;i<=c;i++) s.insert(i);
	for(i=0;i<v.size();i++)
	{
		if(s.find(ans[v[i]])!=s.end()) s.erase(ans[v[i]]);
	}
	if(!s.size()) return;
	for(set<int>::iterator it=s.begin();it!=s.end();++it) cs.push_back(*it);
	for(i=0, j=0;i<v.size() && j<cs.size();i++)
	{
		if(!ans[v[i]]){ans[v[i]]=cs[j]; j++;}
	}
	for(;i<v.size();i++)
	{
		if(ans[v[i]]) continue;
		int c1=ans[v[(i+1)%v.size()]];
		int c2=ans[v[(i+v.size()-1)%v.size()]];
		for(j=1;j<=c && (j==c1 || j==c2);j++);
		ans[v[i]]=j;
	}
	for(i=0;i<v.size();i++)
	{
		int t1=v[(i+1)%v.size()], t2=v[i];
		if((t1+n-1)%n!=t2) color(t1, t2);
	}
}

bool vis[2010][2010];
void verify()
{
	memset(vis, false, sizeof(vis));
	int i, j, k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<a[i].size();j++)
		{
			if(vis[i][a[i][j]]) continue;
			vector<int> v=walk(i, a[i][j]);
			for(k=0;k<v.size();k++) vis[v[k]][v[(k+1)%v.size()]]=true;
			set<int> t;
			for(k=0;k<v.size();k++) t.insert(ans[v[k]]);
			if(t.size()!=c)
			{
				for(k=0;k<n;k++) printf("%d ", ans[k]);
				printf("\n");
				printf("bad!\n"); exit(0);
			}
		}
	}
}

int main()
{
	char filename[32];
	char infile[32], outfile[32];
	scanf("%s", filename);
	strcpy(infile, filename); strcpy(outfile, filename);
	strcat(infile, ".in"); strcat(outfile, ".out");
	FILE *fp=fopen(infile, "r"), *ofp=fopen(outfile, "w");
	
	int i, j;
	int t, tc;
	fscanf(fp, "%d", &tc);
	for(t=1;t<=tc;t++)
	{
		fscanf(fp, "%d%d", &n, &m);
		for(i=0;i<n;i++)
		{
			a[i].clear();
			a[i].push_back((i+1)%n); a[i].push_back((i+n-1)%n);
		}
		vector<int> t1, t2;
		for(i=1;i<=m;i++)
		{
			int buf;
			fscanf(fp, "%d", &buf); t1.push_back(buf-1);
		}
		for(i=1;i<=m;i++)
		{
			int buf;
			fscanf(fp, "%d", &buf); t2.push_back(buf-1);
		}
		for(i=0;i<m;i++){a[t1[i]].push_back(t2[i]); a[t2[i]].push_back(t1[i]);}
		for(i=0;i<n;i++)
		{
			for(j=0;j<a[i].size();j++)
			{
				if(a[i][j]<i) a[i][j]+=n;
			}
			sort(a[i].begin(), a[i].end());
			for(j=0;j<a[i].size();j++)
			{
				if(a[i][j]>=n) a[i][j]-=n;
			}
			pred[i].clear();
			for(j=0;j<a[i].size();j++) pred[i][a[i][(j+1)%a[i].size()]]=a[i][j];
		}
		c=n;
		for(i=0;i<n;i++)
		{
			for(j=0;j<a[i].size();j++)
			{
				int len=walklen(i, a[i][j]);
				c=min(c, len);
			}
		}
		memset(ans, 0, sizeof(ans));
		ans[0]=1; ans[1]=2;
		color(0, 1);
		//verify();
		fprintf(ofp, "Case #%d: %d\n", t, c);
		for(i=0;i<n;i++) fprintf(ofp, "%d%c", ans[i], (i==n-1)?'\n':' ');
	}

	fclose(fp);
	fclose(ofp);
	char cmd[128];
	strcpy(cmd, "cat ");
	strcat(cmd, outfile);
	system(cmd);
	return 0;
}
