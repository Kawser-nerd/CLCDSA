#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <utility>
using namespace std;

pair<int,int> hoge[1010];

int a[2020];

bool ok(){
	int lim=0;
	for(int i=0;i<2010;i++){
		for(int j=0;j<a[i];j++){
			if(i>lim)return false;
			lim++;
		}
	}
	return true;
}

main(){
	int casenum,totcase;
	scanf("%d",&totcase);
	for(int casenum=1;casenum<=totcase;casenum++){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d",&hoge[i].first,&hoge[i].second);
		}
		sort(hoge,hoge+n);
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++){
			a[hoge[i].first]++;
			a[hoge[i].second]++;
		}
		
		//for(int i=0;i<50;i++)printf("%d ",a[i]);puts("");
		
		
		if(!ok()){
			printf("Case #%d: Too Bad\n",casenum);
		}else{
			int ans=2*n;
			for(int i=0;i<n;i++){
				a[hoge[i].first]--;
				a[hoge[i].second]++;
				if(!ok()){
					a[hoge[i].first]++;
					a[hoge[i].second]--;
				}else ans--;
			}
			printf("Case #%d: %d\n",casenum,ans);
		}
	}
}