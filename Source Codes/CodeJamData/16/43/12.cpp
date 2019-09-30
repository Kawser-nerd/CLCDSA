#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;


vector<int> trace(vector<vector<int> > hoge){
	int r=hoge.size(),c=hoge[0].size();
	vector<int> ret(2*(r+c));
	
	for(int i=0;i<2*(r+c);i++){
		
		int p,q,d;
		if(i<c){p=0;q=2*i+1;d=0;}
		else if(i<c+r){p=2*(i-c)+1;q=2*c;d=3;}
		else if(i<c+r+c){p=2*r;q=2*c-1-2*(i-c-r);d=2;}
		else {p=2*r-1-2*(i-c-r-c);q=0;d=1;}
		
		for(;;){
			if(d==0){
				if(hoge[p/2][(q-1)/2]==0){p++;q--;d=3;}
				else {p++;q++;d=1;}
			}
			else if(d==1){
				if(hoge[(p-1)/2][q/2]==0){p--;q++;d=2;}
				else {p++;q++;d=0;}
			}
			else if(d==2){
				if(hoge[(p-2)/2][(q-1)/2]==0){p--;q++;d=1;}
				else {p--;q--;d=3;}
			}
			else if(d==3){
				if(hoge[(p-1)/2][(q-2)/2]==0){p++;q--;d=0;}
				else {p--;q--;d=2;}
			}
			
			if(p==0 || p==2*r || q==0 || q==2*c){
				if(p==0)ret[i]=(q-1)/2;
				if(q==2*c)ret[i]=(p-1)/2+c;
				if(p==2*r)ret[i]=(2*c-1-q)/2+c+r;
				if(q==0)ret[i]=(2*r-1-p)/2+c+r+c;
				break;
			}
		}
	}
	return ret;
}

main(){
	int testcases;
	scanf("%d",&testcases);
	for(int casenum=1;casenum<=testcases;casenum++){
		printf("Case #%d:\n",casenum);
		int r,c;
		scanf("%d%d",&r,&c);
		int n=2*(r+c);
		vector<int> a(n);
		for(int i=0;i<r+c;i++){
			int p,q;
			scanf("%d%d",&p,&q);
			p--;q--;
			a[p]=q;a[q]=p;
		}
		
		bool found=false;
		for(int b=0;b<(1<<(c*r));b++){
			vector<vector<int> > hoge(r,vector<int>(c));
			int bb=b;
			for(int i=0;i<r;i++)for(int j=0;j<c;j++){
				hoge[i][j]=bb%2;bb/=2;
			}
			if(trace(hoge)==a){
				for(int i=0;i<r;i++){
					for(int j=0;j<c;j++)printf("%c","/\\"[hoge[i][j]]);
					puts("");
				}
				found=true;
				break;
			}
		}
		if(!found)puts("IMPOSSIBLE");
	}
}