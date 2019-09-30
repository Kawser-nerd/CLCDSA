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
#include <cassert>
#include <cstring>
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

char mapping[26];
char buff[1000];

void run(int casenr) {
	gets(buff);
	for(int i=0;buff[i]!='\0';++i) if(isalpha(buff[i])) buff[i]+=mapping[tolower(buff[i])-'a']-tolower(buff[i]);
	printf("Case #%d: %s\n",casenr,buff);
}

char from[3][100]={"ejp mysljylc kd kxveddknmc re jsicpdrysi","rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","de kr kd eoya kw aej tysr re ujdr lkgc jv"};
char too[3][100]={"our language is impossible to understand","there are twenty six factorial possibilities","so it is okay if you want to just give up"};

int main() {
	memset(mapping,'?',sizeof(mapping)); //mapping['a'-'a']='y'; mapping['o'-'a']='e'; mapping['z'-'a']='q';
	mapping['q'-'a']='z'; mapping['z'-'a']='q';
	REP(i,3) for(int j=0;from[i][j]!='\0';++j) if(isalpha(from[i][j])) {
		int ind=tolower(from[i][j])-'a';
		char val=tolower(too[i][j]);
		if(mapping[ind]=='?') mapping[ind]=val; else if(mapping[ind]!=val) printf("error for %c: %c vs %c\n",'a'+ind,mapping[ind],val);
	}
	REP(i,26) printf("%c",mapping[i]); puts("");
	gets(buff); int n; sscanf(buff,"%d",&n); FORE(i,1,n) run(i);
	return 0;
}
