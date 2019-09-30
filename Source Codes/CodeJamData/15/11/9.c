#include <stdio.h>

int main(int argc, char const *argv[])
{
	FILE* in=fopen("a.in","r");
	FILE* out=fopen("a.out","w");
	int t,i;
	fscanf(in,"%d",&t);
	for (i=1;i<=t;++i){
		int n,m[1010],j,sum,max,ans;
		sum=0;max=0;ans=0;
		fscanf(in,"%d",&n);
		fscanf(in,"%d",&m[0]);
		for (j=1;j<n;++j){
			fscanf(in,"%d",&m[j]);
			if (m[j-1]>m[j]){
				sum+=m[j-1]-m[j];
				if (m[j-1]-m[j]>max)max=m[j-1]-m[j];
			}
		}
		for (j=1;j<n;++j){
			if (m[j-1]<max)
				ans+=m[j-1];
			else ans+=max;
		}
		fprintf(out,"Case #%d: %d %d\n",i,sum,ans);
	}
	return 0;
}