A['   '];M;B,X,Y;W,J,I;main(){scanf("%d%d",&I,&M);for(;~scanf("%d%d",&X,&Y);){for(B=Y+1,J=1;J*J<=M;J++)I=(X+J-1)/J,W=Y/J+1,A[I]++,A[W<B?W:B]--,B=I;for(I=1;I<B;I++)if((X-1)/I<Y/I)A[I]++,A[I+1]--;}for(I=1;I<=M;I++){A[I]+=A[I-1];printf("%d\n",A[I]);}} ./Main.c:1:3: warning: multi-character character constant [-Wmultichar]
 A['   '];M;B,X,Y;W,J,I;main(){scanf("%d%d",&I,&M);for(;~scanf("%d%d",&X,&Y);){for(B=Y+1,J=1;J*J<=M;J++)I=(X+J-1)/J,W=Y/J+1,A[I]++,A[W<B?W:B]--,B=I;for(I=1;I<B;I++)if((X-1)/I<Y/I)A[I]++,A[I+1]--;}for(I=1;I<=M;I++){A[I]+=A[I-1];printf("%d\n",A[I]);}}
   ^
./Main.c:1:1: warning: data definition has no type or storage class
 A['   '];M;B,X,Y;W,J,I;main(){scanf("%d%d",&I,&M);for(;~scanf("%d%d",&X,&Y);){for(B=Y+1,J=1;J*J<=M;J++)I=(X+J-1)/J,W=Y/J+1,A[I]++,A[W<B?W:B]--,B=I;for(I=1;I<B;I++)if((X-1)/I<Y/I)A[I]++,A[I+1]--;}for(I=1;I<=M;I++){A[I]+=A[I-1];printf("%d\n",A[I]);}}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘A’ [-Wimplicit-int]
./Main.c:1:10: warning: data definition has no type or storage class
 A['   '];M;B,X,Y;W,J,I;main(){scanf("%d%d",&I,&M);for(;~scanf("%d%d",&X,&Y);){for(B=Y+1,J=1;J*J<=M;J++)I=(X+J-1)/J,W=Y/J+1,A[I]++,A[W<B?W:B]--,B=I;for(I=1;I<B;I++)if((X-1)/I<Y/I)A[I]++,A[I+1]--;}for(I=1;I<=M;I++){A[I]+=A[...