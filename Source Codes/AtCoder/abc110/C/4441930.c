char *S[]={"No","Yes"};
char f;

char a[26], b[26];
char *A=a-'a'+1, *B=b-'a'+1;
char s[200000], t[200000], c;
int n, i, j;
int main(){
  while((c=getchar())!=10){s[i++]=c;}
  while((c=getchar())!=10){t[j++]=c;}
  n=i;
  f=1;
  for(i=0; i<n; i++){
    if(A[s[i]]==0){
      A[s[i]]=t[i];
    }else if(A[s[i]]!=t[i]){
      f=0; break;
    }
    if(B[t[i]]==0){
      B[t[i]]=s[i];
    }else if(B[t[i]]!=s[i]){
      f=0; break;
    }
  }
  puts(S[f]);
} ./Main.c: In function ‘main’:
./Main.c:9:12: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
   while((c=getchar())!=10){s[i++]=c;}
            ^
./Main.c:25:3: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
   puts(S[f]);
   ^