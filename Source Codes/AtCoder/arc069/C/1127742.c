#include <stdio.h>

struct stone{
	long id;
	long long num;
};

void quick(struct stone a[],long left,long right);

int main(){
	long n;
	long i,j;
	long long buf,sum,max;
	
	scanf("%ld",&n);
	struct stone a[n];
	long long s[n];
	
	for(i=0;i<n;i++){
		scanf("%lld",&buf);
		a[i].num = buf;
		a[i].id = i;
		s[i] = 0;
	}
	
	for(i=0,sum=0;i<n;i++){
		sum += a[i].num;
	}
	
	quick(a,0,n-1);
	
	long min = a[n-1].id;
	
	for(i=n-1;i>=0;i--){
		long long d;
		long tmp = a[i].id;
		
		if(i>0)	d = a[i].num - a[i-1].num;
		else d = a[i].num;
		
		if(min > tmp) min = tmp;
		
		a[i].num -= d;
		s[min] += (n-i)*d;
	}
		
	for(i=0;i<n;i++){
		printf("%lld\n",s[i]);
	}
	
	return 0;
}

void quick(struct stone a[],long left,long right){
	long i,j,p;
	long long pivot;
	
	i = left;
	j = right;
	
	pivot = a[(left+right)/2].num;
	p = a[(left+right)/2].id;
	
	while(1){
		while(a[i].num < pivot || (a[i].num==pivot && a[i].id < p)) i++;
		while(pivot < a[j].num || (a[j].num==pivot && p < a[j].id)) j--;
		if(i>=j) break;
		
		struct stone tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
		
		i++;
		j--;
	}
	
	if(left < i-1) quick(a,left,i-1);
	if(j+1 < right) quick(a,j+1,right);
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&n);
  ^
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&buf);
   ^