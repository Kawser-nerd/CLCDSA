n,m;
i,j;
s;
k,l;
f;

char a[50][55],b[50][55];

main(){
  scanf("%d%d\n",&n,&m); // N, M???
  
  for(i=0;i<n;i++)
    gets(a[i]); // ??A?????
  
  for(i=0;i<m;i++)
    gets(b[i]); // ??B?????
  
  for(i=0;i<=n-m;i++)    // ????? ???A?????
    for(j=0;j<=n-m;j++){ // ????? ???A?????
    f=1;
    
    for(k=0;k<m;k++)     // ????????B?????
      for(l=0;l<m;l++)   // ????????B?????
        f&=a[i+k][j+l]==b[k][l];  // f = f & (a[i+k][j+l]==b[k][l]); ???
                                  // a[i+k][j+l]==b[k][l]? a[i+k][j+l]?b[k][l]???????? ????1(true)?0(false)
                                  // f & a[i+k][j+l]==b[k][l]?f?a[i+k][j+l]==b[k][l]?AND???
                                  // f?a[i+k][j+l]==b[k][l]?true????f & a[i+k][j+l]==b[k][l]???true???
                                  // f = f & (a[i+k][j+l]==b[k][l]); ?f?????
                                  // ????a[i+k][j+l]==b[k][l]????true????f?????true???
        s+=f;                     // s?f??????
    }
    
    puts(s?"Yes":"No");           // s?1(true)??Yes, 0(false)??No???
} ./Main.c:1:1: warning: data definition has no type or storage class
 n,m;
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘m’ [-Wimplicit-int]
 n,m;
   ^
./Main.c:2:1: warning: data definition has no type or storage class
 i,j;
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:2:3: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 i,j;
   ^
./Main.c:3:1: warning: data definition has no type or storage class
 s;
 ^
./Main.c:3:1: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
./Main.c:4:1: warning: data definition has no type or storage class
 k,l;
 ^
./Main.c:4:1: warning: type defaults to ‘int’ in declaration of ‘k’ [-Wimplicit-int]
./Main.c:4:3: warning: type defaults to ‘int’ in declaration of ‘l’ [-Wimplicit-int]
 k,l;
   ^
./Main.c:5:1: warning: data definition has no type or storage class
 f;
 ^
./Main....