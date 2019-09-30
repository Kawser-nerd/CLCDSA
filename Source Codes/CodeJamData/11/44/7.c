#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define INF 0x3E3E3E3E

typedef unsigned char bool;

bool graph[40][40];
int d[40], queue[40], beg, end;
int listdp[40][40], topdp[40];
int list[40];
int max;


int bfs(int s, int t, int size)
{
  int i;
  
  for(i = 0; i < size; i++)
    d[i] = INF;
  
  d[s] = 0;
  beg = end = 0;
  queue[end++] = 0;
  listdp[0][topdp[0]++] = s;
  
  while(beg < end)
  {
    int v = queue[beg++];
    
    for(i = 0; i < size; i++)
      if(graph[v][i] && d[i] == INF)
      {
        d[i] = d[v]+1;
        queue[end++] = i;
        listdp[d[i]][topdp[d[i]]++] = i;
        
        if(i == t)
          return d[i];
      }
  }

  return d[t];
}

void backtr(int v, int h, int size)
{
  int i, k;
  int temp[40];
  
  for(i = 0; i < size; i++)
    temp[i] = list[i];
  
  for(i = 0; i < topdp[h+1]; i++)
    if(graph[v][listdp[h+1][i]])
    {
      int u = listdp[h+1][i], m = 0;
        
      if(u == 1)
      {
        for(k = 0; k < size; k++)
          if(list[k] == 1)
            m++;
        if(m > max)
          max = m;
        
        for(k = 0; k < size; k++)
          list[k] = temp[k];
        return ;
      }
      
      for(k = 0; k < size; k++)
        if(graph[u][k] && list[k] != -1)
          list[k] = 1;
      list[u] = -1;
      
      backtr(u, h+1, size);
      
      for(k = 0; k < size; k++)
        list[k] = temp[k];
    }      
    
  for(i = 0; i < size; i++)
    list[i] = temp[i];
}

int main()
{
  int T, cont = 0;
  
  scanf("%d\n", &T);
  while(T--)
  {
    int p, w, conq, thr = 0;
    int i, k;
    
    scanf("%d %d", &p, &w);
    
    for(i = 0; i < p; i++)
      for(k = 0; k < p; k++)
        graph[i][k] = false;
      
    for(i = 0; i < p; i++)
      topdp[i] = 0;
      
    for(i = 0; i < w; i++)
    {
      int u, v;
      scanf("%d, %d", &u, &v);
      graph[u][v] = true;
      graph[v][u] = true;
    }
    
    conq = bfs(0, 1, p);
    
    for(i = 0; i < p; i++)
      list[i] = (int)graph[0][i];
    list[0] = -1;
    max = -1;
    backtr(0, 0, p);
    
    thr = max;
    printf("Case #%d: %d %d\n", ++cont, conq-1, thr);
  }
  
return 0;
}
