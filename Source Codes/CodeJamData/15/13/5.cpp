#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
int x[3100];
int y[3100];
double EPS=1e-9;
double PI=acos(-1.0);
int ret[3100];
vector<double>th;
int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int a;scanf("%d",&a);
		for(int i=0;i<a;i++)scanf("%d%d",x+i,y+i);
		for(int i=0;i<a;i++){
			th.clear();
			for(int j=0;j<a;j++){
				if(i==j)continue;
				th.push_back(atan2(y[j]-y[i],x[j]-x[i]));
				th.push_back(atan2(y[j]-y[i],x[j]-x[i])+PI*2);
			}
			std::sort(th.begin(),th.end());
			int L=0;
			int u=0;
			for(int j=0;j<th.size();j++){
				while(L<th.size()&&th[j]-th[L]>PI+EPS){
					L++;
				}
				u=max(u,j-L+1);
			}
			ret[i]=a-u-1;
		}
		fprintf(stderr,"finish case #%d\n",t);
		printf("Case #%d:\n",t);
		for(int i=0;i<a;i++)printf("%d\n",ret[i]);
	}
}