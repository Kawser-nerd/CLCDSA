c(int*a,int*b){return *b-*a;}l[99];i;j;s;main(){for(;~scanf("%d",l+i++););qsort(l+2,*l,4,c);for(;j<l[1];)s+=l[2+j++];printf("%d",s);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 c(int*a,int*b){return *b-*a;}l[99];i;j;s;main(){for(;~scanf("%d",l+i++););qsort(l+2,*l,4,c);for(;j<l[1];)s+=l[2+j++];printf("%d",s);}
 ^
./Main.c:1:30: warning: data definition has no type or storage class
 c(int*a,int*b){return *b-*a;}l[99];i;j;s;main(){for(;~scanf("%d",l+i++););qsort(l+2,*l,4,c);for(;j<l[1];)s+=l[2+j++];printf("%d",s);}
                              ^
./Main.c:1:30: warning: type defaults to ‘int’ in declaration of ‘l’ [-Wimplicit-int]
./Main.c:1:36: warning: data definition has no type or storage class
 c(int*a,int*b){return *b-*a;}l[99];i;j;s;main(){for(;~scanf("%d",l+i++););qsort(l+2,*l,4,c);for(;j<l[1];)s+=l[2+j++];printf("%d",s);}
                                    ^
./Main.c:1:36: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:38: warning: data definition has no type or storage class
 c(int*a,int*b){return *b-*a;}l[99];i;j;s;main(){for(;~scanf("%d",l+i++););qsort(l+2,*l,4,c);for(...