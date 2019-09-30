int n, xx, yy;
int m[50][50];

double rec(int i, int x, int y, int my, double p)
{ double r;
  if(i>=n)
  {
    if(m[xx+25][yy])
	{ 
	  return p;
	} else
	{ 
	  return 0;
	}
  }
  
  while(y>0)
  { if(m[x-1][y-1])
    {
	  if(m[x+1][y-1])
	  {
	    break;
	  } else
	  {
	    ++x;
		--y;
	  }
	} else
	{
	  if(m[x+1][y-1])
	  {
	    --x;
		--y;
	  } else
	  {
	    return rec(i, x-1, y-1, my, p/2)+rec(i, x+1, y-1, my, p/2);		
	  }
	}
  }
  m[x][y] = 1;
  if(x==25)
  {
    my = y+2;
  }
  r = rec(i+1, 25, my, my, p);
  m[x][y] = 0;  
  return r;
}

int main()
{
  int t, tt, i, j;  
  
  scanf("%d", &tt);
  for(t=1; t<=tt; ++t)
  {
    scanf("%d%d%d", &n, &xx, &yy);
	for(i=0; i<50; ++i)
	  for(j=0; j<50; ++j)
	    m[i][j] = 0;		
	if ((xx>=25)||(xx<=-25)||(yy>=25)) printf("Case #%d: %lf\n", t, 0); else
	printf("Case #%d: %lf\n", t, rec(0, 25, 0, 0, 1));
  }
  
  return 0;
}