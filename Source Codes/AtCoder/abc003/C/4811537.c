c(int*a,int*b){return *b-*a;}double d,e=1;R[999];i;main(j){for(;~scanf("%d",R+i++););for(qsort(R+2,*R,4,c);j++-R[1]-1;d+=R[j]*e)e/=2;printf("%.9f\n",d);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 c(int*a,int*b){return *b-*a;}double d,e=1;R[999];i;main(j){for(;~scanf("%d",R+i++););for(qsort(R+2,*R,4,c);j++-R[1]-1;d+=R[j]*e)e/=2;printf("%.9f\n",d);}
 ^
./Main.c:1:43: warning: data definition has no type or storage class
 c(int*a,int*b){return *b-*a;}double d,e=1;R[999];i;main(j){for(;~scanf("%d",R+i++););for(qsort(R+2,*R,4,c);j++-R[1]-1;d+=R[j]*e)e/=2;printf("%.9f\n",d);}
                                           ^
./Main.c:1:43: warning: type defaults to ‘int’ in declaration of ‘R’ [-Wimplicit-int]
./Main.c:1:50: warning: data definition has no type or storage class
 c(int*a,int*b){return *b-*a;}double d,e=1;R[999];i;main(j){for(;~scanf("%d",R+i++););for(qsort(R+2,*R,4,c);j++-R[1]-1;d+=R[j]*e)e/=2;printf("%.9f\n",d);}
                                                  ^
./Main.c:1:50: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:52: warning: return type defaults to ‘int’ [-Wimplicit-int]
 c(int*a...