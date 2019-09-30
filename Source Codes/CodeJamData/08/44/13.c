#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

char s[50002],t[50002];

int main(){
  int z,Z,i,c,m,k,n;
  scanf("%d",&Z);
  for(z=0;z<Z;z++){
    vector<int> p;
    scanf("%d %s", &k, s);
    n=strlen(s);
    m=n;
    for(i=0;i<k;i++) p.push_back(i);
    do {
      for(i=0;i<n;i++) t[i]=s[(i/k)*k+p[i%k]];
      c=1;
      for(i=1;i<n;i++) if(t[i]!=t[i-1]) c++;
      if(c<m) m=c;
    } while (next_permutation(p.begin(),p.end()));
    printf("Case #%d: %d\n", z+1, m);
  }
  return 0;
}

