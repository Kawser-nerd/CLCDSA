double X[1010],Y[1010],R[1010],D[1010][1010],d;
j,k,N;main(i){
	scanf("%lf%lf%lf%lf%d",X,Y,X+1,Y+1,&N);N+=2;
	for(;++i<N;)scanf("%lf%lf%lf",X+i,Y+i,R+i);
	for(i=0;i<N;i++)for(j=i;j<N;j++)D[i][j]=D[j][i]=(d=hypot(X[i]-X[j],Y[i]-Y[j])-R[i]-R[j])>0?d:0;
	for(k=0;k<N;k++)for(i=0;i<N;i++)for(j=0;j<N;j++)if(D[i][j]>(d=D[i][k]+D[k][j]))D[i][j]=d;
	printf("%.9f\n",D[0][1]);
} ./Main.c:2:1: warning: data definition has no type or storage class
 j,k,N;main(i){
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
./Main.c:2:3: warning: type defaults to ‘int’ in declaration of ‘k’ [-Wimplicit-int]
 j,k,N;main(i){
   ^
./Main.c:2:5: warning: type defaults to ‘int’ in declaration of ‘N’ [-Wimplicit-int]
 j,k,N;main(i){
     ^
./Main.c:2:7: warning: return type defaults to ‘int’ [-Wimplicit-int]
 j,k,N;main(i){
       ^
./Main.c: In function ‘main’:
./Main.c:2:7: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:3:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%lf%lf%lf%lf%d",X,Y,X+1,Y+1,&N);N+=2;
  ^
./Main.c:3:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:5:53: warning: implicit declaration of function ‘hypot’ [-Wimplicit-function-declaration]
  for(i=0;i<N;i++)for(j=i;j<...