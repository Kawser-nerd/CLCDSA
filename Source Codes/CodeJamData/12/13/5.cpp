#include <stdio.h>
#include <math.h>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int par[600000];
int colinfo[600000];
#define L 555551
#define R 555552
#define enc(p,t) ((p)+(t)*50)
#define EPS 1e-9
void init(){
	for(int i=0;i<600000;i++){par[i]=i;colinfo[i]=1;}
}

pair<int,int> fnd(int p){
	if(par[p]==p)return make_pair(p,1);
	pair<int,int> ret=fnd(par[p]);
	par[p]=ret.first;
	colinfo[p]=ret.second*colinfo[p];
	return make_pair(par[p],colinfo[p]);
}

bool uni(int p,int q,int s){
	pair<int,int> retp=fnd(p);
	pair<int,int> retq=fnd(q);
	if(retp.first==retq.first){
		return retp.second*retq.second*s==1;
	}else{
		par[retp.first]=retq.first;
		colinfo[retp.first]=retp.second*retq.second*s;
		return true;
	}
}

int initlane[60];
double v[60],p[60];

main(){
	int casenum,totcase;
	scanf("%d",&totcase);
	for(int casenum=1;casenum<=totcase;casenum++){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			char buf[10];
			scanf("%s %lf %lf",buf,&v[i],&p[i]);
			initlane[i]=(buf[0]=='L'?1:-1);
		}
		
		vector<double> ev;
		ev.push_back(0);
		ev.push_back(1e6);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(v[i]>=v[j])continue;
				if(p[i]-p[j]>0)ev.push_back((p[i]-p[j])/(v[j]-v[i]));
				if(p[i]-p[j]-5>0)ev.push_back((p[i]-p[j]-5)/(v[j]-v[i]));
				if(p[i]-p[j]+5>0)ev.push_back((p[i]-p[j]+5)/(v[j]-v[i]));
			}
		}
		sort(ev.begin(),ev.end());
		
		vector<double> tmp;
		for(int i=0;i<ev.size();i++){
			if(i==0 || fabs(ev[i]-ev[i-1])>EPS)tmp.push_back(ev[i]);
		}
		ev=tmp;
		
		init();
		uni(L,R,-1);
		
		bool omedetou=true;
		
		for(int k=0;k<ev.size()-1;k++){
			//printf("t=%f\n",ev[k]);
			//if(k>=1 && fabs(ev[k]-ev[k-1])<EPS)continue;
			double q[60];
			for(int i=0;i<60;i++){
				q[i]=p[i]+v[i]*ev[k];
			}
			for(int i=0;i<n;i++){
				bool ok=true;
				for(int j=0;j<n;j++){
					if(i!=j && fabs(q[i]-q[j])<5-EPS)ok=false;
				}
				if(!ok){
					if(k==0){
						//printf("union (lane %d, [%d,%d]) 1\n",initlane[i],i,k);
						omedetou&=uni(initlane[i]==1?L:R,enc(i,k),1);
					}else{
						//printf("union ([%d,%d], [%d,%d]) 1\n",i,k-1,i,k);
						omedetou&=uni(enc(i,k-1),enc(i,k),1);
					}
				}
			}
			for(int i=0;i<60;i++){
				q[i]=p[i]+v[i]*((ev[k]+ev[k+1])/2);
			}
			for(int i=0;i<n;i++){
				for(int j=0;j<i;j++){
					if(fabs(q[i]-q[j])<5-EPS){
						//printf("union ([%d,%d], [%d,%d]) -1\n",i,k,j,k);
						omedetou&=uni(enc(i,k),enc(j,k),-1);
					}
				}
			}
			if(!omedetou){
				printf("Case #%d: %.12f\n",casenum,ev[k]);
				break;
			}
		}
		
		if(omedetou){
				printf("Case #%d: Possible\n",casenum);
		}
	}
}