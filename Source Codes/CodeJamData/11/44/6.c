#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


int T;
int P, W;

int counted[400];
set<int> neighs[400];

int dist[400];

bool g[400][400];//graph

int buildPath() {
 vector<int> cur;
 vector<int> next;
 bool found=true;
 
 cur.clear();
 cur.push_back(1);
 
 int d=1;
 while (found) {
  found=false;
  next.clear();
  for (int i=0;i<cur.size();i++) {
   int to=cur[i];
   for (int f=0;f<P;f++) {
    if (g[f][to]&&dist[f]==0) {
     dist[f]=d;
     next.push_back(f);
     found=true;
    }
   }
  }
  d++;
  cur=next;
 }
 
 return dist[0];
}


int countBest(int from, int sum) {
 
 if (from==1) return sum;
 
 int add=0;
 // count
 for (int t=0;t<P;t++) {
  if (g[t][from]&&counted[t]==-1) {
   counted[t]=from;
   add++;
  }
 }
 
 
// printf("%d: sum=%d add=%d\n", from, sum, add);
 int best=0;
 
 for (int t=0;t<P;t++) {
  
  if (g[from][t]&&dist[t]<dist[from]) {
   int cur=countBest(t, sum+add);
   if (best<cur) best=cur;
  }
 }
 
 // release counted
 for (int t=0;t<P;t++) {
  if (g[t][from]&&counted[t]==from) {
   counted[t]=-1;
  }
 }
 
 return best;
}

int main() {
 
 scanf("%d", &T);
 
 for (int test_idx=1;test_idx<=T;test_idx++) {
  memset(counted, -1, sizeof(counted));
  memset(dist, 0, sizeof(dist));
  memset(g, 0, sizeof(g));
  
  scanf("%d %d", &P, &W);
  
  for (int i=0;i<W;i++) {
   int f,t;
   scanf("%d,%d",&f, &t);
   g[f][t]=true;
   g[t][f]=true;
  }
  
  dist[1]=-1;
  
  
  int distance=buildPath()-1;
  counted[0]=1;
  
  int neighbours=countBest(0, 0);
  
  printf("Case #%d: %d %d\n",test_idx, distance, neighbours-distance);
 }
 
}