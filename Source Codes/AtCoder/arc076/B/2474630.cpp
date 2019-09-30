#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,i,j,k,cc[500000],a,b,c,s ;
struct p{
	long long x,y,z;
	bool operator < (const p& gg) const{
		return x<gg.x;
	}
}s1[500000],s2[500000];
struct pp{
	long long x,y,z;
	bool operator < (const pp& tt) const{
		return z<tt.z;
	}
}wow[1000000];
long long find(long long x){
	if (cc[x]==x) return x;
	else {
		cc[x]= find(cc[x]);
		return cc[x];
	}
}

int main(){
	scanf("%lld",&n);
	for (int i=0;i<n;i++){
		scanf("%lld %lld",&s1[i].x,&s1[i].y);
		s2[i].x=s1[i].y;
		s2[i].y=s1[i].x;
		s1[i].z=i+1;
		s2[i].z=i+1;
	}
	sort(s1,s1+n);
	sort(s2,s2+n);
	a=-1;
	for (int i=1;i<n;i++){
		a++;
		wow[a].x=s1[i].z;
		wow[a].y=s1[i-1].z;
		wow[a].z=(s1[i].x-s1[i-1].x);
	}
	for (int i=1;i<n;i++){
		a++;
		wow[a].x=s2[i].z;
		wow[a].y=s2[i-1].z;
		wow[a].z=(s2[i].x-s2[i-1].x);
	}	
//	for (int i=0;i<=a;i++) printf("%d %d %d\n",wow[i].x,wow[i].y,wow[i].z);		
	sort(wow,wow+a+1);
//	for (int i=0;i<=a;i++) printf("%d %d %d\n",wow[i].x,wow[i].y,wow[i].z);	
	for (int i=0;i<=300000;i++) cc[i]=i;
	for (int i=0;i<=a;i++){
		if (find(cc[wow[i].x])!=find(cc[wow[i].y])){
			cc[find(cc[wow[i].x])]=find(cc[wow[i].y]);
			s+=wow[i].z;
		}
	}
	printf("%lld\n",s);
	return 0;
}