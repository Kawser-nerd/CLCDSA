#include<stdio.h>
#include<math.h>
#include<algorithm>
int tcn,tc;
int n,m;
int a[1010][6];
struct edge{
	int a,b,cost;
	bool operator<(const edge&r)const{
		return cost<r.cost;
	}
};
edge el[1100000];
int en;
int uft[1010];
int uftf(int x){
	if(x==uft[x])return x;
	return uft[x]=uftf(uft[x]);
}
int main(){
	int i,j,k,tryn;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++){
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++){
			for(j=0;j<6;j++){
				scanf("%d",&a[i][j]);
			}
		}
		en=0;
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				el[en].a=i;
				el[en].b=j;
				el[en].cost=(a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1])+(a[i][2]-a[j][2])*(a[i][2]-a[j][2]);
				en++;
			}
		}
		std::sort(el,el+en);
		for(i=0;i<n;i++){
			uft[i]=i;
		}
		for(i=0;i<en;i++){
			if(uftf(el[i].a)!=uftf(el[i].b)){
				uft[uftf(el[i].b)]=uftf(el[i].a);
			}
			if(uftf(0)==uftf(1))break;
		}
		printf("Case #%d: %.8lf\n",tc,sqrt((double)el[i].cost));
	}
	return 0;
}