
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SORT(a,n) qsort(a,n,sizeof(int),intcmp)
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%I64d",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)
#define fill(a,v)                   memset(a, v, sizeof(a))
int intcmp(const void *f,const void *s)
{
   return (*(int *)f -*(int *)s);
}
int gcd(int a,int b){ return ((b==0)?a:gcd(b,a%b));}

#define MAX 1123456
#define MODBY 1000000007

typedef long long int lld;
typedef long double Lf;
int preprocess()
{
   return 0;
}

int main()
{
   int cases;
   int i,j,n;
   char a[MAX];
   preprocess();
   int casectr=1;
   for(scanf("%d",&cases);casectr<=cases;++casectr){
      scanf("%s",a);
      scanf("%d",&n);
      printf("Case #%d: ",casectr);
      int ans=0;
      for(i=0;a[i];++i){
         int cnt=0,sign=0;
         int go=0;
//         printf("i %d\n",i);
         for(j=i;a[j];++j){
         //printf("j %d\n",j);
            if(sign==0){//last was a vowel
               if(strchr("aeiou",a[j])){
               }
               else{
                  sign=1;
                  cnt++;
               }
            }
            else{
               if(strchr("aeiou",a[j])){
                  sign=0;cnt=0;
               }
               else{
                  cnt++;
               }
            }
       //     printf("\t\t\tcnt: %d \n",cnt);
            go|=((cnt>=n));
            ans+=go;
         }
      }
      printf("%d\n",ans);
   }
   return 0;
}
