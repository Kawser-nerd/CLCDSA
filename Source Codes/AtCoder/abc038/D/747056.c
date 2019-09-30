#include<stdio.h>
#include<stdlib.h>

struct data{
	int w;int h;
}d[100000];

int cmp(const void *p, const void *q){
	struct data a = *(struct data *)p;
	struct data b = *(struct data *)q;

	if(a.w > b.w)return 1;
	if(a.w == b.w){
		if(a.h > b.h)return 1;
	}
	return 0;
}

int main(){
	int i,j,n;
	int ans1 = 1,a1=0,a2=0;
	int ans2 = 1;
	int w,h,f;
	int l[200001];
	int max;
	int len;
	int low,hh,mid;
	struct data tmp,ll[100001];
	
	for(i=0;i<200001;i++)l[i]=1;

	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d%d",&d[i].w,&d[i].h);
//if(n>1000)return 0;

/*
puts("");
for(i=0;i<n;i++)
printf("%d %d\n",d[i].w,d[i].h);
*/

	qsort(d,n,sizeof(struct data),cmp);

/*
puts("");
for(i=0;i<n;i++)
printf("%d %d\n",d[i].w,d[i].h);
*/


	for(i=0;i<n;i++){
		for(j=i+1;j<(n<(i+1500)?n:i+1500);j++){
			if(d[j].w>d[i].w&&d[j].h>d[i].h&&l[i]>=l[j])l[j]=l[i]+1;
		}
	}

	max = l[0];
	for(i=1;i<n;i++)if(max<l[i])max=l[i];
	printf("%d\n",max);


/*
tmp.h=-1;tmp.w=-1;
for(i=0;i<100001;i++)ll[i]=tmp;
ll[0]=d[0];
len=1;
for(i=1;i<n;i++){
	if(ll[len-1].w<d[i].w&&ll[len-1].h<d[i].h)
		ll[len++]=d[i];
	else{
		low=0;
		hh=len;
		while (low <= hh) {
			mid = (low + hh) / 2;
			if (cmp(&(d[i]),&(ll[mid-1]))==1&&cmp(&(d[i]),&(ll[mid]))==0) {
				break;
			} else if (cmp(&(d[i]),&(ll[mid]))==1) {
				hh = mid - 1;
			} else {
				low = mid + 1;
			}
		}
	}
}
max=0;
for(i=0;i<len;i++)max++;

	printf("%d\n",max);
*/

/*
tmp.h=-1;tmp.w=-1;
for(i=0;i<100001;i++)ll[i]=tmp;
l[0]=d[0].h;
len=1;
for(i=1;i<n;i++){
	if(l[len-1]<d[i].h)
		l[len++]=d[i].h;
	else{
		low=0;
		hh=len;
		while (low <= hh) {
			mid = (low + hh) / 2;
			if (l[mid]==d[i].h) {
				l[mid] = 
				break;
			} else if (l[mid]<d[i].h) {
				hh = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		
	}
}
max=0;
for(i=0;i<len;i++)max++;

	printf("%d\n",len);
*/

//for(i=0;i<n;i++)printf("%d\n",l[i]);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:32:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:33:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%d%d",&d[i].w,&d[i].h);
                  ^