int cmp(const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}
int main(){
	int N, NA, NB, T, i, j, k, pa, pb, h1, m1,h2,m2, na, nb,ra,rb;
	int A[1000];
	int B[1000];
	scanf("%d",&N);
	for(i = 1; i<=N; i++){
		pa = pb = na = nb = ra = rb = 0;
		scanf("%d%d%d",&T,&NA,&NB);
		for(j = 0; j < NA; j++){
			scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
			A[pa++] = (h1*60+m1)*2+1;
			B[pb++] = (h2*60+m2+T)*2;
		}
		for(j = 0; j < NB; j++){
			scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
			B[pb++] = (h1*60+m1)*2+1;
			A[pa++] = (h2*60+m2+T)*2;
		}
		qsort(A,pa,sizeof(int),cmp);
		qsort(B,pb,sizeof(int),cmp);
		for(j = 0; j<pa; j++){
			if(A[j]%2 == 0)na++;
			else na--;
			if(-na > ra)ra = -na;
		}
		for(j = 0; j<pb; j++){
			if(B[j]%2 == 0)nb++;
			else nb--;
			if(-nb > rb)rb = -nb;
		}
		printf("Case #%d: %d %d\n",i,ra,rb);

	}
}
