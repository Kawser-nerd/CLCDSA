//
//  aaaaa.c
//  
//
//  Created by Fourier Shuzaei on 2018/05/26.
//
b;x;
main(a){
    scanf("%d",&a);
    char n[a+1];
    int c[a],d[a],e[a];
    scanf("%s",&n);
    for(b=0;b<a;++b){
        c[b]=(n[b]=='W'?1:-1);
    }

    d[0]=(c[0]==1?1:0);
    for(b=1;b<a;++b){
        if(c[b]==1)d[b]=d[b-1]+1;
        else d[b]=d[b-1];
    }

    e[a-1]=(c[a-1]==1?0:1);
    for(b=a-2;b>-1;--b){
        if(c[b]==1)e[b]=e[b+1];
        else e[b]=e[b+1]+1;
    }

    int p,q;
    if(e[1]<d[a-2]){p=e[1];q=0;}
    else{p=d[a-2];q=a-1;}

    for(b=1;b<a-1;++b){
        int t = e[b+1]+d[b-1];
        if (t<p){p=t;q=b;}
    }
    printf("%d",p);

} ./Main.c:7:1: warning: data definition has no type or storage class
 b;x;
 ^
./Main.c:7:1: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
./Main.c:7:3: warning: data definition has no type or storage class
 b;x;
   ^
./Main.c:7:3: warning: type defaults to ‘int’ in declaration of ‘x’ [-Wimplicit-int]
./Main.c:8:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a){
 ^
./Main.c: In function ‘main’:
./Main.c:8:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:9:5: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
     scanf("%d",&a);
     ^
./Main.c:9:5: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:9:5: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:12:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[(sizetype)(a + 1)]’ [-Wformat=]
     scanf("%s",&n);
           ^
./Main.c:37:5: warning: implicit declaration of fu...