#include<cstdio>
#include<vector>
#define L 600

using namespace std;

bool map[L][L];
bool bt[L];
int lin[L];
int opt[L][L];
vector<int> slj[L],blj[L];
int l,r;

bool dfs(int a){
	if (bt[a]) return false;
	bt[a]=true;
	for (int i=0;i<r;++i)
	    if (map[a][i] && (lin[i]==-1 ||dfs(lin[i]))){
			lin[i]=a;
			return true;
		}
	return false;
}

bool pp(){
	if (l>r) return false;
	for (int i=0;i<r;++i) lin[i]=-1;
	for (int i=0;i<l;++i){
		for (int j=0;j<l;++j) bt[j]=false;
		if (!dfs(i)) return false;
	}
	return true;
}
int sfa[L],bfa[L];

bool dp(int b,int s){
	int &p=opt[b][s];
	if (p!=-1) return p;
	p=0;
	vector<int> sxl;
	vector<int> bxl;
	for (int i=0;i<slj[s].size();++i)
	    if (slj[s][i]!=sfa[s]){
			sxl.push_back(slj[s][i]);
			sfa[slj[s][i]]=s;
		}
	for (int i=0;i<blj[b].size();++i)
	    if (blj[b][i]!=bfa[b]){
			bxl.push_back(blj[b][i]);
			bfa[blj[b][i]]=b;
		}
	for (int i=0;i<sxl.size();++i)
	    for (int j=0;j<bxl.size();++j)
	        dp(bxl[j],sxl[i]);
	for (int i=0;i<sxl.size();++i)
	    for (int j=0;j<bxl.size();++j)
	        map[i][j]=dp(bxl[j],sxl[i]);
	l=sxl.size();
	r=bxl.size();
	p=pp();
//	printf("%d %d %d\n",b,s,p);
	return p;
}

int T;
int n,i,a,b,m,I;

main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (i=1;i<=n;++i) blj[i].clear();
		for (i=0;i<n-1;++i) {
			scanf("%d %d",&a,&b);
			blj[a].push_back(b);
			blj[b].push_back(a);
		}
		scanf("%d",&m);
		for (i=1;i<=m;++i) slj[i].clear();
		for (i=0;i<m-1;++i){
			scanf("%d%d",&a,&b);
			slj[b].push_back(a);
			slj[a].push_back(b);
		}
		bool bt=false;
		for (i=1;i<=n;++i){
			memset(sfa,-1,sizeof sfa);
			memset(bfa,-1,sizeof bfa);
			memset(opt,-1,sizeof opt);
//			printf("%d:\n",i);
			if (dp(i,1)){
				bt=true;
				break;
			}
		}
		printf("Case #%d: ",++I);
		if (bt) printf("YES\n");
		else printf("NO\n");
	}
}
		
