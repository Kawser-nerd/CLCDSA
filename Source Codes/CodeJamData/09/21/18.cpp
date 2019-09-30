#pragma comment(linker,"/STACK:100000000")  

#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int n, tn, nt;

char s[1000000];

struct node
{
  double p;
  string name;
  int left, right;

} nodes[10000000];

void get(int x, int &y)
{
  n=x+1;
  while (s[y]!='(') y++;
  y++;
  while (s[y]==' ') y++;
  sscanf(s+y, "%lf", &nodes[x].p);
  y++;
  while (s[y]!=' ' && s[y]!=')') y++;
  while (s[y]==' ') y++;
  if (s[y]==')')
  {
     nodes[x].name="";
     nodes[x].left=nodes[x].right=-1;
     y++;
     return;
  }
  string cur="";
  cur.resize(0);
  while (s[y]!=' ' && s[y]!='(')
     cur=cur+(char)s[y++];

  nodes[x].name=cur;
  nodes[x].left=n;
  get(n, y);
  nodes[x].right=n;
  get(n, y);
  while (s[y]!=')') y++;
}

set <string> features;

double calc(int x)
{
   double p=nodes[x].p;
   if (nodes[x].name!="")
   {
      if (features.count(nodes[x].name)) p*=calc(nodes[x].left);
      else p*=calc(nodes[x].right);
   }
   return p;
}

int main(void)
{
   int i, j, k, l, m;
//   freopen("A-small-attempt0.in", "r", stdin);
//   freopen("A-small-attempt0.out", "w", stdout);
   freopen("A-large.in", "r", stdin);
   freopen("A-large.out", "w", stdout);

   scanf("%d\n", &nt);
   for (tn=0; tn<nt; tn++)
   {
      fprintf(stderr, "Case #%d: ", tn+1);
      scanf("%d\n", &l);
      for (j=i=0; i<l; i++)
      {
         gets(s+j);
         while (s[j]!=0) j++;
      }
      m=0;
      get(0, m);
      fprintf(stderr, "%d\n", n);

      printf("Case #%d:\n", tn+1);
      scanf("%d", &l);
      for (i=0; i<l; i++)
      {
         features.clear();
         scanf("%s%d", s, &k);
         for (j=0; j<k; j++)
         {
           scanf("%s", s);
           features.insert(s);
         }
         printf("%.7lf\n", calc(0));
      }
   }
   return 0;
}
