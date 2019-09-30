c(int*a,int*b){return *b-*a;}i,n,s;R[9999];main(r){for(scanf("%*d");~scanf("%d",&r);)R[n++]=r*r;for(qsort(R,n,4,c);n-i;s+=i++%2?-r:r)r=R[i];printf("%.9f\n",acos(-1)*s);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 c(int*a,int*b){return *b-*a;}i,n,s;R[9999];main(r){for(scanf("%*d");~scanf("%d",&r);)R[n++]=r*r;for(qsort(R,n,4,c);n-i;s+=i++%2?-r:r)r=R[i];printf("%.9f\n",acos(-1)*s);}
 ^
./Main.c:1:30: warning: data definition has no type or storage class
 c(int*a,int*b){return *b-*a;}i,n,s;R[9999];main(r){for(scanf("%*d");~scanf("%d",&r);)R[n++]=r*r;for(qsort(R,n,4,c);n-i;s+=i++%2?-r:r)r=R[i];printf("%.9f\n",acos(-1)*s);}
                              ^
./Main.c:1:30: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:32: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
 c(int*a,int*b){return *b-*a;}i,n,s;R[9999];main(r){for(scanf("%*d");~scanf("%d",&r);)R[n++]=r*r;for(qsort(R,n,4,c);n-i;s+=i++%2?-r:r)r=R[i];printf("%.9f\n",acos(-1)*s);}
                                ^
./Main.c:1:34: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
 c(int*a,int*b){return *b-*a;}i,n,s;R[9999];m...