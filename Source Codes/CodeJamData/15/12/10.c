#include <stdio.h>
int main(){
	FILE* in=fopen("b.in","r");
	FILE* out=fopen("b.out","w");
	int t,i;
	fscanf(in,"%d",&t);
	for (i=1;i<=t;++i){
		int b,n,j,m[1010],max=0;
		fscanf(in,"%d %d",&b,&n);
		for (j=0;j<b;++j){
			fscanf(in,"%d",&m[j]);
			if (max<m[j])max=m[j];
		}
		long long high,low,mid,sum,avail;
		low=0;high=(long long)max*(n-1)/b;
		while (1){
			mid=(low+high)/2;
			sum=0;avail=0;
			for (j=0;j<b;++j){
				sum+=(mid-1)/m[j]+1;
				if (mid%m[j]==0)avail+=1;
			}
			if (sum<n&&sum+avail>=n)break;
			else {
				if (sum+avail<n)low=mid+1;
				else high=mid;
			}
		}
		if (mid==0)sum=0;
		for (j=0;j<b;++j){
			if (mid%m[j]==0){
				sum+=1;
				if (sum==n)break;
			}
		}
		fprintf(out,"Case #%d: %d\n",i,j+1);
	}
}