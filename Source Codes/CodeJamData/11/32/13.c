#include<stdio.h>
int f[1001];

void solve(int N,int L,int t){
	int i,j,k,time=0,ts,ts1,ts2,maxts=0,ttl,ttl1,ttl2;
	int dist[1001];
	
	for(i=0;i<N;i++){
		time += f[i]*2;
		if(i == 0)
		dist[i] = f[i];
		else
		dist[i] = f[i] + dist[i-1];
	}
	
	if(L==1){
		for(i=0;i<N;i++){
			//if the speed booster is built on star i
			if(i != 0)
				ttl = dist[i-1]*2;
			else 
				ttl = 0;
			
			if (t > ttl)
				ts = f[i] - (t - ttl)/2;
			else
				ts = f[i];
				
			if(ts > maxts)
				maxts = ts;
			
		}
		time = time - maxts;
	}
	
	if(L==2){
		for(i=0;i<N-1;i++){
			for(j=i+1;j<N;j++){
				//if the speed booster is built on star i and j
				if(i != 0)
					ttl1 = dist[i-1]*2;
				else 
					ttl1 = 0;
				
				if (t > ttl1)
					ts1 = f[i] - (t - ttl1)/2;
				else
					ts1 = f[i];

				ttl2 = dist[j-1]*2 - ts1;
				
				if (t > ttl2)
					ts2 = f[j] - (t - ttl2)/2;
				else
					ts2 = f[j];
					
				ts = ts1+ts2;
					
				if(ts > maxts)
					maxts = ts;
			}			
		}
		time = time - maxts;
	}	
	
	printf("%d\n",time);
}

int main(){
	int T,L,t,N,C,tmp,i,j,k;

	scanf("%d",&T);

	for(i=1;i<=T;i++){
		scanf("%d",&L);
		scanf("%d",&t);
		scanf("%d",&N);
		scanf("%d",&C);
		for(j=0;j<C;j++){
			scanf("%d",&tmp);
			for(k=0;k<N;k++){
				if((k%C)==j){
					f[k]=tmp;
				}
			}
		}
		printf("Case #%d: ",i);
		solve(N,L,t);
	}
return 0;
}