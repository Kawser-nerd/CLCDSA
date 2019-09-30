int a, n;
int m[100];
int ss[1000001];
int ss1[1000001];

int main()
{
  int t, tt, i, j, k, max, r1, r2;

  scanf("%d", &tt);
  for(t=1; t<=tt; ++t)
  {
    scanf("%d%d", &a, &n);
    for(i=0; i<n; ++i)
      scanf("%d", &(m[i]));

    for(i=0; i<n-1; ++i)
      for(j=i+1; j<n; ++j)
        if(m[i]>m[j])
        {
          k = m[i];
          m[i] = m[j];
          m[j] = k;
        }

    max = 0;
    for(i=0; i<n; ++i)
      if(m[i]>max) max = m[i];

    for(i=0; i<=max; ++i)
      ss[i] = 0;

    for(k=n-1; k>=0; --k)
    {
      for(i=max; i>=0; --i)
      {
        if(m[k]<i)
        {
          j = i+m[k];
          if(j<=max)
          {
            ss1[i] = ss[j];
          } else
          {
            ss1[i] = 0;
          }
        } else
        { r1 = 1 + ss[i];
          if(i<=1)
          {
            ss1[i] = r1;
          } else
          {
            r2 = 0;
            j = i;
            while(j<=m[k])
            { j = 2*j-1;
              ++r2;
            }
            j += m[k];
            if(j<=max)
            {
              r2 += ss[j];
            }
            if(r1<r2)
            {
              ss1[i] = r1;
            } else
            {
              ss1[i] = r2;
            }
          }
        }
      }
      for(i=0; i<=max; ++i) ss[i]=ss1[i];
    }
    if(a>max)
	{
	  r1 = 0;
	} else
	{
	  r1 = ss[a];
	}
    //for(i=0; i<n; ++i) printf("%d ",m[i]);
    //printf("\n");
    printf("Case #%d: %d\n", t, r1);
  }

  return 0;
}