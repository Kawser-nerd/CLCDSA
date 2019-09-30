B,Z,W,J,I,X,Y,N,M,A['   '];main(){scanf("%d%d",&N,&M);for(;~scanf("%d%d",&X,&Y);){B=Y+1;for(J=1;J*J<=M;J++){Z=(X+J-1)/J,W=Y/J;A[Z]++;A[W+1<B?W+1:B]--;B=Z;}for(I=1;I<B;I++){if((X-1)/I<Y/I){A[I]++;A[I+1]--;}}}for(I=1;I<=M;I++){A[I]+=A[I-1];printf("%d\n",A[I]);}} ./Main.c:1:1: warning: data definition has no type or storage class
 B,Z,W,J,I,X,Y,N,M,A['   '];main(){scanf("%d%d",&N,&M);for(;~scanf("%d%d",&X,&Y);){B=Y+1;for(J=1;J*J<=M;J++){Z=(X+J-1)/J,W=Y/J;A[Z]++;A[W+1<B?W+1:B]--;B=Z;}for(I=1;I<B;I++){if((X-1)/I<Y/I){A[I]++;A[I+1]--;}}}for(I=1;I<=M;I++){A[I]+=A[I-1];printf("%d\n",A[I]);}}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘B’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘Z’ [-Wimplicit-int]
 B,Z,W,J,I,X,Y,N,M,A['   '];main(){scanf("%d%d",&N,&M);for(;~scanf("%d%d",&X,&Y);){B=Y+1;for(J=1;J*J<=M;J++){Z=(X+J-1)/J,W=Y/J;A[Z]++;A[W+1<B?W+1:B]--;B=Z;}for(I=1;I<B;I++){if((X-1)/I<Y/I){A[I]++;A[I+1]--;}}}for(I=1;I<=M;I++){A[I]+=A[I-1];printf("%d\n",A[I]);}}
   ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘W’ [-Wimplicit-int]
 B,Z,W,J,I,X,Y,N,M,A['   '];main(){scanf("%d%d",&N,&M);for(;~scanf("%d%d",&X,&Y);){B=Y+1;for(J=1;J*J<=M;J++){Z=(X+J-1)/J,W=Y/J;A[Z]++;A[W+1<B?W+1:B]--;B=Z;}for(I=1;I<B;I...