#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

string sol(int r,int s,int p,string nr,string ns,string np){
	if(r+s+p==1){
		if(r==1)return nr;
		if(s==1)return ns;
		if(p==1)return np;
	}else{
		if(r>s+p || s>p+r || p>r+s)return string("IMPOSSIBLE");
		int sp=(s+p-r)/2;
		int pr=(p+r-s)/2;
		int rs=(r+s-p)/2;
		return sol(rs,sp,pr,min(nr,ns)+max(nr,ns),min(ns,np)+max(ns,np),min(np,nr)+max(np,nr));
	}
}

main(){
	int testcases;
	scanf("%d",&testcases);
	for(int casenum=1;casenum<=testcases;casenum++){
		printf("Case #%d: ",casenum);
		int n;
		int r,p,s;
		scanf("%d%d%d%d",&n,&r,&p,&s);
		printf("%s\n",sol(r,s,p,string("R"),string("S"),string("P")).c_str());
	}
}