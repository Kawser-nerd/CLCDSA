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

main(){
	int datasuu;
	scanf("%d ",&datasuu);
	for(int casenum=1;casenum<=datasuu;casenum++){
		printf("Case #%d: ",casenum);
		
		int w,l,u,g;
		scanf("%d%d%d%d",&w,&l,&u,&g);
		double y0[1010],y1[1010];
		int px,py;
		for(int i=0;i<l;i++){
			int qx,qy;
			scanf("%d%d",&qx,&qy);
			if(i>0){
				for(int i=px;i<=qx;i++){
					y0[i]=(double)py+(double)(qy-py)/(qx-px)*(i-px);
				}
			}
			px=qx;
			py=qy;
		}
		for(int i=0;i<u;i++){
			int qx,qy;
			scanf("%d%d",&qx,&qy);
			if(i>0){
				for(int i=px;i<=qx;i++){
					y1[i]=(double)py+(double)(qy-py)/(qx-px)*(i-px);
				}
			}
			px=qx;
			py=qy;
		}
		
		//for(int i=0;i<=w;i++)printf("%f %f\n",y0[i],y1[i]);
		double rui[1010];
		rui[0]=0;
		for(int i=0;i<w;i++)rui[i+1]=rui[i]+(y1[i]+y1[i+1]-y0[i]-y0[i+1])/2;
		double tot=rui[w];

		puts("");
		for(int k=1;k<g;k++){
			double targ=tot/g*k;
			double ub=w,lb=0;
			for(int t=0;t<100;t++){
				double mid=(ub+lb)/2;
				double s=0;
				int i;
				for(i=0;i<mid;i++);
				i--;
				s=rui[i];
				double y0m=y0[i]+(y0[i+1]-y0[i])*(mid-i);
				double y1m=y1[i]+(y1[i+1]-y1[i])*(mid-i);
				s+=(y1[i]+y1m-y0[i]-y0m)*(mid-i)/2;
				if(s>targ)ub=mid;
				else lb=mid;
				//printf("%f: i=%d %f\n",mid,i,s);
			}
			printf("%.10f\n",(ub+lb)/2);
		}
	}
}