#include<stdio.h>

int pot2[11] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
int ingresso[16][1024];
int p;

int bt(int n, int b, int m[1050], int ti, int tf)
{
  int re, rd;
  int v, t, i;
  int ma = -1;
  int dif = tf - ti;
  int mt[1050];
  
  if(n == p)
  {
    
    //printf("n = %d, b = %d, m[b] = %d\n", n, b, m[b]);
    
    if(m[b] == 0) return 0;
    else return -1;
  }
   
   
  for(i = ti; i <= tf; i++) mt[i] = m[i];
  
  v = ingresso[n][b];
  //Não Comprando o ingresso.
  re = bt(n + 1, b*2, mt, ti, ti + dif/2);
  rd = bt(n + 1, b*2 + 1, mt, ti + dif/2 + 1, tf);
  
  if(re != -1 && rd != -1)
  {
    
    t = re + rd;
    if(ma == -1 || t < ma) ma = t;
  }
  
  //Comprando o ingresso.
  for(i = ti; i <= tf; i++) if(mt[i] > 0) mt[i]--;
  
  re = bt(n + 1, b*2, mt, ti, ti + dif/2);
  rd = bt(n + 1, b*2 + 1, mt, ti + dif/2 + 1, tf);
  
  if(re != -1 && rd != -1)
  { 
    t = v + re + rd;
    if(ma == -1 || t < ma) ma = t;
  }  
  
  //printf("n = %d, b = %d, ma = %d\n", n, b, ma);
  
  return ma;
  
}



int main(void)
{
  int c = 1, t, i, j;
  int m[1050];

  
  scanf("%d", &t);
  
  while(c <= t)
  {
    scanf("%d", &p);

    for(j = 0; j < pot2[p]; j++)
    {
      scanf("%d", &m[j]);
      m[j] = p - m[j];
    }
    
    for(i = p-1; i >= 0; i--)
    {
      for(j = 0; j < pot2[i]; j++)
      {
	scanf("%d", &ingresso[i][j]);
      }
    }
    
    printf("Case #%d: %d\n", c, bt(0,0,m,0,pot2[p]-1));
    c++;
  }
  
  return 0;  
}