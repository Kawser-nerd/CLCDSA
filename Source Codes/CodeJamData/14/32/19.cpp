#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int md=1000000007;
int t,tt,i,j,k,e,sk,se,n,m,r,ins[29],a[29][29];
long long f[111];
char s[111];
bool q,was[29],ww[29],uu[111];
string str[111];
int ks[111],rr;
void rec(int l) {
  if (l==n) {
    string st="";
    for (int i=0; i<n; i++) st+=str[ks[i]];
    for (int i=0; i<26; i++) ww[i]=false;
    int i=0;
    for (i=0; i<st.length(); i++) if (i==0 || st[i]!=st[i-1]) {
      if (ww[st[i]-'a']) break;
      ww[st[i]-'a']=true;
    }
    //puts(st.c_str());
    if (i>=st.length()) { rr++;
    //puts("ok");
    //puts(st.c_str());
    }
    return;
  }
  for (int i=0; i<n; i++) if (!uu[i]) {
    ks[l]=i;
    uu[i]=true;
    rec(l+1);
    uu[i]=false;
  }
}
int main() {
  freopen("Bl.in","r",stdin);
  freopen("Bl.out","w",stdout);
  for (f[0]=i=1; i<111; i++) f[i]=(f[i-1]*i)%md;
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d",&n);
    q=true;
    for (i=0; i<26; i++) {
      ins[i]=0;
      was[i]=false;
      for (j=0; j<26; j++) a[i][j]=0;
    }
    for (i=0; i<n; i++) {
      scanf("%s",s);
      str[i]=s;
      m=strlen(s);
      for (j=0; j<m; j++) { s[j]-='a'; was[s[j]]=true; }
      a[s[0]][s[m-1]]++;
      for (j=0; j<m; j++) if (s[j]!=s[0]) break;
      if (s[0]==s[m-1] && j!=m) {
        q=false;
        continue;
      }
      for (k=m-1; k>=0; k--) if (s[k]!=s[m-1]) break;
      for (; j<=k; j++) if (s[j]!=s[j-1]) ins[s[j]]++;
    }
    for (i=sk=se=0; i<26; i++) if (q && was[i]) {
      if (ins[i]>1) q=false;
      for (j=k=e=0; j<26; j++) {
        if (ins[i]==1 && (a[i][j]>0 || a[j][i]>0)) q=false;
        if (i!=j) {
          k+=a[i][j];
          e+=a[j][i];
        }
      }
      if (k>1 || e>1) q=false;
      if (ins[i]==0) {
        if (k==0) sk++;
        if (e==0) se++;
      }
    }
    printf("Case #%d: ",t);
    //if (n<10) {
    //rr=0;
    //rec(0);
    //printf(" %d ",rr);
    if (q && sk==se && sk>0) {
      r=f[sk];
      for (i=0; i<26; i++) if (a[i][i]>0) r=(r*f[a[i][i]])%md;
      printf("%d\n",r);
      //if (r!=rr) puts("!!!");
    } else {
    puts("0");
    //if (rr!=0) puts("!!!!");
    }
    //}
  }
  return 0;
}
