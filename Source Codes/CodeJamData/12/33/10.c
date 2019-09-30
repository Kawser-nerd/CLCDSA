#include <stdint.h>
uint64_t a[4],b[101];
int ta[4],tb[101];
uint64_t best;
int search(int nn, int mm, int n, int m, uint64_t offset, uint64_t res){
	int i;
	uint64_t tres=res,toff=0;
	if(nn>=n || mm>=m){
		if(res>best)
			best=res;
		return;
	}
	uint64_t aa=a[nn];
	search(nn+1,mm,n,m,offset,res);
	//B start from mm
	b[mm]-=offset;
	for(i=mm;i<m;i++){
		if(tb[i]==ta[nn]){
			if(aa>=b[i]){
				aa-=b[i];
				tres+=b[i];
				search(nn+1,i+1,n,m,0,tres);
			}else{
				tres+=aa;
				toff=aa;
				search(nn+1,i,n,m,toff,tres);
				break;
			}
		}
		if(aa==0)break;
	}
	b[mm]+=offset;
}
int main(){
	int t,p;
	scanf("%d", &t);
	for(p=1;p<=t;p++){
		int n,m;
		scanf("%d %d", &n, &m);
		int i;
		for(i=0;i<n;i++)
			scanf("%llu %d", a+i, ta+i);
		for(i=0;i<m;i++)
			scanf("%llu %d", b+i, tb+i);
		best=0;
		search(0,0,n,m,0,0);
		printf("Case #%d: %llu\n", p, best);
	}
	return 0;
}
