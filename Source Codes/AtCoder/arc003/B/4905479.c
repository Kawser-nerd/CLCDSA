strcmp();n;i;r(char*s){for(n=strlen(s),i=0;i<n/2;)s[i++]^=s[n-i-1]^=s[i]^=s[n-i-1];}char w[999][99];j;main(k){for(;~scanf("%s",w[j]);)r(w[j++]);for(qsort(w[1],j-1,99,strcmp);k<j;puts(w[k++]))r(w[k]);} ./Main.c:1:1: warning: data definition has no type or storage class
 strcmp();n;i;r(char*s){for(n=strlen(s),i=0;i<n/2;)s[i++]^=s[n-i-1]^=s[i]^=s[n-i-1];}char w[999][99];j;main(k){for(;~scanf("%s",w[j]);)r(w[j++]);for(qsort(w[1],j-1,99,strcmp);k<j;puts(w[k++]))r(w[k]);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘strcmp’ [-Wimplicit-int]
./Main.c:1:10: warning: data definition has no type or storage class
 strcmp();n;i;r(char*s){for(n=strlen(s),i=0;i<n/2;)s[i++]^=s[n-i-1]^=s[i]^=s[n-i-1];}char w[999][99];j;main(k){for(;~scanf("%s",w[j]);)r(w[j++]);for(qsort(w[1],j-1,99,strcmp);k<j;puts(w[k++]))r(w[k]);}
          ^
./Main.c:1:10: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:1:12: warning: data definition has no type or storage class
 strcmp();n;i;r(char*s){for(n=strlen(s),i=0;i<n/2;)s[i++]^=s[n-i-1]^=s[i]^=s[n-i-1];}char w[999][99];j;main(k){for(;~scanf("%s",w[j]);)r(w[j++]);for(qsort(w[1],j-1,99,strcmp);k<j;puts(w[k++]))r(w[k]);}
            ^
./Main....