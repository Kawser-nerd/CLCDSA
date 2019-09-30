#include <stdio.h>
#include <stdlib.h>
//#include <limits.h>

//long get_w(long a,long b);
long n,rt;
long *d;
long *w;
long *total;

int cmp(const void *a,const void *b){
    return (*(long *)a>*(long *)b)?1:((*(long *)a<*(long *)b)?-1:0);
}

int main(){
    //printf("%d\n",INT_MAX);
	scanf("%ld",&n);
    d=(long*)valloc(sizeof(long)*n);
	w=(long*)valloc(sizeof(long)*n*4);
	total=(long*)valloc(sizeof(long)*n*4);
	long i;
	for(i=0;i<n;i++){
		scanf("%ld",&(d[i]));
		w[i*4+0]=-1;
		w[i*4+1]=-1;
		w[i*4+2]=-1;
		w[i*4+3]=1;
	}
	
	qsort(d,n,sizeof(long),cmp);
	
	
	long k,l,m,st;
	for(k=n-1;k>=0;k--){
		total[k*4+3]=n-k;
	}
	for(l=2;l>=0;l--){
		st=n-1;
		for(k=n-2;k>=0;k--){
			//d[k]*2<=d[p]???????p?????total[p*4+l]?w[k*4+l]???
			//????w[k*4+1]=0
			
			w[k*4+l]=0;
			for(m=st;m>=0;m--){
				if(d[k]*2>d[m]){
					st=m;
					if(m<n-1){
						w[k*4+l]=total[(m+1)*4+(l+1)];
					}else{
						w[k*4+l]=0;
					}
					break;
				}
			}
		}
		//total[()*4+l]????
		total[(n-1)*4+l]=0;
		for(k=n-2;k>=0;k--){
			total[k*4+l]=(total[(k+1)*4+l]+w[k*4+l])%1000000007;
		}
	}
	
	rt=total[0];
	
	/*rt=0;
	for(i=n-2;i>=0;i--){
		rt+=get_w(i,0);
		if(rt>1000000007){
			rt%=1000000007;
		}
	}*/
	
	printf("%ld\n",rt);
	
	/*for(l=0;l<=3;l++){
		for(k=0;k<=n-1;k++){
			printf("%ld,",w[k*4+l]);
		}
		printf("\n");
	}
	printf("\n");
	for(l=0;l<=3;l++){
		for(k=0;k<=n-1;k++){
			printf("%ld,",total[k*4+l]);
		}
		printf("\n");
	}*/
	
	//scanf("%d",&n);
	return 0;
}

/*long get_w(long a,long b){
	if(b==3){
		return 1;
	}else if(w[a*4+b]<0){
		w[a*4+b]=0;
		for(long j=n-1;j>a;j--){
			if(d[a]*2>d[j]){
				break;
			}
			w[a*4+b]+=get_w(j,b+1);
		}
	}
	return w[a*4+b];
}*/ ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&n);
  ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&(d[i]));
   ^