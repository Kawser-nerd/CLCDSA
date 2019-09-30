#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

#define INF 1023456789

#define modp(x) (((x)%P+P)%P)

typedef long long ll;

#define EPS 1e-9

int vl,vr;
bool edg[2011][2011];

bool aug(int pos, vector<int>& to,vector<bool>& chk){
	if(pos<0)return true;
	if(pos<vl){
		int u=pos;
		for(int i=0;i<vr;i++){
			if(edg[u][i] && !chk[i+vl]){
				chk[i+vl]=true;
				if(aug(to[i+vl],to,chk)){
					to[u]=i+vl;to[i+vl]=u;
					return true;
				}
			}
		}
		return false;
	}else{
		int u=pos-vl;
		for(int i=0;i<vl;i++){
			if(edg[i][u] && !chk[i]){
				chk[i]=true;
				if(aug(to[i],to,chk)){
					to[u+vl]=i;to[i]=u+vl;
					return true;
				}
			}
		}
		return false;
	}
}

int matching(void){
	int n=vl+vr;
	vector<int> to(n,-1);
	int ret=0;
	for(int i=0;i<vl;i++){
		vector<bool> chk(n,false);
		if(aug(i,to,chk))ret++;
	}
	return ret;
}

main(){
	int datasuu;
	scanf("%d ",&datasuu);
	for(int casenum=1;casenum<=datasuu;casenum++){
		printf("Case #%d: ",casenum);
		
		int n;
		scanf("%d",&n);
		if(n==0){puts("0");continue;}
		int freq[10101]={};
		for(int i=0;i<n;i++){
			int tmp;
			scanf("%d",&tmp);
			freq[tmp]++;
		}
		
		vector<int> l,r;
		for(int i=0;i<=10000;i++){
			if(freq[i]<freq[i+1])for(int j=0;j<freq[i+1]-freq[i];j++)l.push_back(i);
			if(freq[i]>freq[i+1])for(int j=0;j<freq[i]-freq[i+1];j++)r.push_back(i);
		}
		int ans=1e9;
		for(int i=0;i<l.size();i++){
			ans=min(ans,r[i]-l[i]);
		}
		printf("%d\n",ans);
		
	}
}