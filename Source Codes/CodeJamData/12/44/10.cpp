#include<cstdio>
#include<set>
#include<vector>
#include<deque>
using namespace std;

set<pair<int,int> > poss;
set<set<pair<int,int> > > found;
deque<set<pair<int,int> > > Q;

char map[100][100];
int r,c;

int dx[]={1,0,0};
int dy[]={0,1,-1};

void dfs(int x,int y){
	if (map[x][y]=='#')
		return;
	if (poss.find(make_pair(x,y))!=poss.end())
		return;
	poss.insert(make_pair(x,y));
	dfs(x-1,y);
	dfs(x,y+1);
	dfs(x,y-1);
}

void solve(){
	scanf("%d%d",&r,&c);
	char s[10];
	gets(s);
	for(int i=0;i<r;++i)
		gets(map[i]);
	for (int ch='0';ch<='9';++ch){
		int x=-1,y=-1;
		for (int i=0;i<r;++i)
			for (int j=0;j<c;++j)
				if (map[i][j]==ch){
					x=i;y=j;
					break;
				}
		if (x==-1) continue;
		printf("%c: ",ch);
		poss.clear();
		dfs(x,y);
		printf("%d ",poss.size());

		found.clear();
		bool ans=false;
		Q.clear();
		Q.push_back(poss);
		found.insert(poss);
		while (!Q.empty()&&!ans){
			set<pair<int,int> > x= Q.front();
			Q.pop_front();
			if (x.size()==1){
				ans=true;
				break;
			}
			for (int dir=0;dir<3;++dir){
				set<pair<int,int> > nx;
				bool check=true;
				for (set<pair<int,int> >::iterator i=x.begin();i!=x.end();i++){
					int a=i->first;
					int b=i->second;
					int na=a+dx[dir];
					int nb=b+dy[dir];
					if (map[na][nb]=='#'){
						na=a;
						nb=b;
					}
					if (poss.find(make_pair(na,nb))==poss.end()){
						check=false;
						break;
					}
					nx.insert(make_pair(na,nb));
				}
				if (!check) continue;
				if (found.find(nx)!=found.end()) continue;
				if (nx.size()==1){
					ans=true;
					break;
				}
				Q.push_back(nx);
				found.insert(nx);
			}
		}
		puts(ans?"Lucky":"Unlucky");
	}

}

int T,I=0;

int main(){
	scanf("%d",&T);
	while (T--){
		printf("Case #%d:\n",++I);
		solve();
	}
}
