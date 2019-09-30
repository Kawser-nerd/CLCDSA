int comp_int(const void *A,const void *B){
	const int *a = (const int*)A;
	const int *b = (const int*)B;
	return *a - *b;
}

int main(){
	int T,N,s[202],t,i,A[202],ts;
	double f[202],ans,base,S,avg;
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d",&N);
		S=0;
		for(i=0;i<N;i++){
			scanf("%d",&s[i]);
			A[i] = s[i];
			S += s[i];
		}
		
		qsort(A,N,sizeof(int),comp_int);
		ts = 0;
		for(i=0;i<N;i++){
			ts += A[i];
			avg = (double)(ts + S)/(double)(i+1);
			
			if(avg < A[i]) break;
		}
		
		if(i != N){
			ts -= A[i];
			avg = (double)(ts + S)/(double)(i);
		}
		//printf("avg = %f\n",avg);
		base = 200.0/N;
		printf("Case #%d:",t);
		for(i=0;i<N;i++){
			ans = (avg - s[i])*100/S;
			if(ans < 0) ans = 0;
			printf(" %.5f",ans);
		}
		printf("\n");
	}
	return 0;
}