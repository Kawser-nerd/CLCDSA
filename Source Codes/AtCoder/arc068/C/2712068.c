A['   '];B,X,Y;W,J,I;main(M){scanf("%*d%d",&M);for(;~scanf("%d%d",&X,&Y);){for(B=Y+1,J=1;J*J<=M;J++)I=(X+J-1)/J,W=Y/J+1,A[I]++,A[W<B?W:B]--,B=I;for(I=1;I<B;I++)(X-1)/I<Y/I?A[I]++,A[I+1]--:0;}for(I=1;I<=M;I++)printf("%d\n",A[I]+=A[I-1]);} ./Main.c:1:3: warning: multi-character character constant [-Wmultichar]
 A['   '];B,X,Y;W,J,I;main(M){scanf("%*d%d",&M);for(;~scanf("%d%d",&X,&Y);){for(B=Y+1,J=1;J*J<=M;J++)I=(X+J-1)/J,W=Y/J+1,A[I]++,A[W<B?W:B]--,B=I;for(I=1;I<B;I++)(X-1)/I<Y/I?A[I]++,A[I+1]--:0;}for(I=1;I<=M;I++)printf("%d\n",A[I]+=A[I-1]);}
   ^
./Main.c:1:1: warning: data definition has no type or storage class
 A['   '];B,X,Y;W,J,I;main(M){scanf("%*d%d",&M);for(;~scanf("%d%d",&X,&Y);){for(B=Y+1,J=1;J*J<=M;J++)I=(X+J-1)/J,W=Y/J+1,A[I]++,A[W<B?W:B]--,B=I;for(I=1;I<B;I++)(X-1)/I<Y/I?A[I]++,A[I+1]--:0;}for(I=1;I<=M;I++)printf("%d\n",A[I]+=A[I-1]);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘A’ [-Wimplicit-int]
./Main.c:1:10: warning: data definition has no type or storage class
 A['   '];B,X,Y;W,J,I;main(M){scanf("%*d%d",&M);for(;~scanf("%d%d",&X,&Y);){for(B=Y+1,J=1;J*J<=M;J++)I=(X+J-1)/J,W=Y/J+1,A[I]++,A[W<B?W:B]--,B=I;for(I=1;I<B;I++)(X-1)/I<Y/I?A[I]++,A[I+1]--:0;}for(I=1;I<=M;I++)printf("%d\n",A[I]+=A[I-1]);}
     ...