#define DEBUG 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int comp(const void *a, const void *b) {
  return (*(long long *)a - *(long long *)b);
}

template <typename Iterator>
bool next_combination(const Iterator first, Iterator k, const Iterator last)
{
   /* Credits: Mark Nelson http://marknelson.us */
   if ((first == last) || (first == k) || (last == k))
      return false;
   Iterator i1 = first;
   Iterator i2 = last;
   ++i1;
   if (last == i1)
      return false;
   i1 = last;
   --i1;
   i1 = k;
   --i2;
   while (first != i1)
   {
      if (*--i1 < *i2)
      {
         Iterator j = k;
         while (!(*i1 < *j)) ++j;
         std::iter_swap(i1,j);
         ++i1;
         ++j;
         i2 = k;
         std::rotate(i1,j,last);
         while (last != j)
         {
            ++j;
            ++i2;
         }
         std::rotate(k,i2,last);
         return true;
      }
   }
   std::rotate(first,k,last);
   return false;
}

int main(void) {
  int tc, cn;
  scanf("%d", &tc);
  for(cn=1;cn<=tc;cn++) {
    int n, ns1, ns2, i;
    long long sum1, sum2;
    long long a[500];
    bool u[500];
    vector<long long> s1, s2;

    scanf("%d", &n);
    for(i=0;i<n;i++)
      scanf("%lld", &a[i]);
    qsort(a,n,sizeof(a[0]),comp);

    for(ns1=1;ns1<n;ns1++) {
      s1.clear();
      for(i=0;i<n;i++) {
        s1.push_back(i);
        u[i]=false;
      }
      do {
        for(sum1=0,i=0;i<ns1;i++) {
          sum1+=a[s1[i]];
          u[s1[i]]=true;
          if(DEBUG) printf("%lld ", a[s1[i]]);
        }
          if(DEBUG) printf("sum1=%lld\n", sum1);

    for(ns2=1;ns2<n-ns1;ns2++) {
      s2.clear();
      for(i=0;i<n;i++)
        if(!u[i])
          s2.push_back(i);
      do {
        for(sum2=0,i=0;i<ns2;i++) {
          sum2+=a[s2[i]];
          if(DEBUG) printf("%lld ", a[s2[i]]);
        }
          if(DEBUG) printf("sum2=%lld\n", sum2);
        if(sum2>=sum1) break;
      } while(next_combination(s2.begin(),s2.begin()+ns2,s2.end()));
        if(sum1==sum2) break;
    }

        if(sum1==sum2) break;
        for(i=0;i<ns1;i++)
          u[s1[i]]=false;
      } while(next_combination(s1.begin(),s1.begin()+ns1,s1.end()));
        if(sum1==sum2) break;
    }

    printf("Case #%d:\n", cn);
    if(sum1==sum2) {
      printf("%lld", a[s1[0]]);
      for(i=1;i<ns1;i++)
        printf(" %lld", a[s1[i]]);
      printf("\n%lld", a[s2[0]]);
      for(i=1;i<ns2;i++)
        printf(" %lld", a[s2[i]]);   
      printf("\n");
    } else
      printf("Impossible\n");
  }
  return 0;
}
