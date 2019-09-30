#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;  

int nwords;
char dict[10000][12];
int len[10000];
int lettermask[10000];
int posmask[10000][26];

char order[30];

pair<int,int> calc(const vector<int> &opt,int at) {
	if(SZ(opt)==1) return MP(0,opt[0]);
	int mask=0; REPSZ(i,opt) mask|=lettermask[opt[i]];
	while((mask&(1<<(order[at]-'a')))==0) ++at;
	map<int,vector<int>> groups;
	REPSZ(i,opt) groups[posmask[opt[i]][order[at]-'a']].PB(opt[i]);
	int bestscore=-1,bestword=-1;
	for(map<int,vector<int>>::iterator it=groups.begin();it!=groups.end();++it) {
		pair<int,int> cur=calc(it->second,at+1);
		if(it->first==0) ++cur.first;
		if(cur.first>bestscore||cur.first==bestscore&&cur.second<bestword) bestscore=cur.first,bestword=cur.second;
	}
/*	REPSZ(i,opt) printf("%d ",opt[i]); printf("= %d (%d) [%c] [%x]\n",bestword,bestscore,order[at],mask);
	for(map<int,vector<int>>::iterator it=groups.begin();it!=groups.end();++it) {
		printf("\t"); REPSZ(i,it->second) printf("%d ",it->second[i]); puts("");
	}*/
	return MP(bestscore,bestword);
}

void run(int casenr) {
	int ngames; scanf("%d%d",&nwords,&ngames);
	REP(i,nwords) scanf("%s",dict[i]);
	REP(i,nwords) len[i]=strlen(dict[i]);
	REP(i,nwords) { lettermask[i]=0; REP(j,len[i]) lettermask[i]|=1<<(dict[i][j]-'a'); }
	REP(i,nwords) REP(j,26) posmask[i][j]=0; REP(i,nwords) REP(j,len[i]) posmask[i][dict[i][j]-'a']|=1<<j;

	vector<string> ret;
	REP(i,ngames) {
		scanf("%s",order);
		int bestscore=-1,bestword=-1;
		FORE(curlen,1,10) {
			vector<int> opt;
			REP(j,nwords) if(len[j]==curlen) opt.PB(j);
			if(SZ(opt)==0) continue;
			pair<int,int> cur=calc(opt,0);
			if(cur.first>bestscore||cur.first==bestscore&&cur.second<bestword) bestscore=cur.first,bestword=cur.second;
		}
		ret.PB(dict[bestword]);
//		cout<<ret.back()<<endl;
	}
	printf("Case #%d:",casenr); REPSZ(i,ret) printf(" %s",ret[i].c_str()); puts("");
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}

 
