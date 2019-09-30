#define M 1000002013
int o[100];
int e[100];
int p[100];
int f[101];
int n;

int rec(int q, int w)
{
  int x, y, m, l, r=0, qq, ww;
  m = M;
  /*printf("%d %d\n", q, w);*/
  
  for(x=q; x<w; ++x)
  {
    if(f[x]<m)
    {
      y = x;
      m = f[y];
    }
  }
  
  if(m!=M)
  {
    for(x=q; x<w; ++x)
    {
      f[x] -= m;
    }
    l = w-q;
    r += (((l*n-(l*(l-1))/2)%M)*m)%M;
    
    x=q; 
    while(x<w)
    {
      if(f[x])
      {
        qq = x;
        while(x<w && f[x]) ++x;
        ww = x;
        r += (rec(qq, ww))%M;
      }
      ++x;
    }
  }
  return r;
}

int main()
{
  int t, tt, m, i, l, r, j, k;  
  
  scanf("%d", &tt);
  for(t=1; t<=tt; ++t)
  {
    scanf("%d%d", &n, &m);
    for(i=0; i<m; ++i)
      scanf("%d%d%d", &(o[i]), &(e[i]), &(p[i]));
    /*  
    printf("%d %d\n", n, m);
    for(i=0; i<m; ++i)
      printf("%d %d %d\n", o[i], e[i], p[i]);
    */    
    r = 0;    
    for(i=0; i<m; ++i)
    {
      l = e[i]-o[i];
      r += (((l*n-(l*(l-1))/2)%M)*p[i])%M;
      r %= M;
    }
    
    for(i=0; i<=100; ++i)      
     f[i] = 0;
    
    for(i=0; i<m; ++i)
    { 
      for(j=o[i]; j<e[i]; ++j)
      {
        f[j] += p[i];     
      }           
    }
    
    /*
    for(i=0; i<=n; ++i)
      printf("%d ", f[i]);
    printf("\n");
    */
    r -= rec(1, n);    
    printf("Case #%d: %d\n", t, r);    
  }

}  