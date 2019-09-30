#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

int* u;
int N;
int smallestI;

long long w(long long k, long long l, int i)
{
  return ((long long) l)*u[i] - ((long long)k)*i;
}

bool cando(long long k, long long l, long long m, long long n)
{
  //printf("cando(%d,%d,%d,%d)\n", k, l, m, n);
  smallestI = N + 1;
  std::map<long long, long long> mp;
  mp[w(k,l,N)] = w(m,n,N);
  //printf("%d %lld %lld\n", N, w(k,l,N), w(m,n,N));
  for (int j = N - 1; j >= 0; --j)
    {
      long long x1 = w(k, l, j);
      long long x2 = w(m, n, j);
      //printf("%d %lld %lld\n", j, x1, x2);
      if ((mp.find(x1) != mp.end()) && (mp[x1] <= x2))
	{
	  //printf("*");
	  smallestI = j;
	}
	else
	{
	  mp[x1] = x2;
	  map<long long, long long>::iterator mi = mp.find(x1);
	  map<long long, long long>::iterator mj = mi;
	  ++mj;
	  if ((mj != mp.end()) && (mj->second <= x2))
	    {
	      //printf(",");
	      smallestI = j;
	      mp.erase(mi,mj);
	    }
	  else
	    {
	      mj = mi;
	      map<long long, long long>::iterator mk = mj;
	      while ((mj != mp.begin()) && ((--mk)->second > x2))
		--mj;
	      if (mj != mi)
		{
		  //printf("&");
		  mp.erase(mj,mi);
		}
	    }
	}
	}
  return smallestI <= N;    
}

  int mill = 1000000;
  
int main()
{
  int T; scanf("%d", &T);
  char* t = new char[600000];
  u = new int[600000];
  for (int ci = 1; ci <= T; ++ci)
    {
      float F;
      scanf("%d %f", &N, &F);
      int F2 = (int)(F*1000000+0.5);
      scanf("%s", t);
      u[0] = 0;
      for (int i = 0; i < N; ++i)
	u[i + 1] = u[i] + t[i] - '0';
      if ((u[N] == 0) || (u[N] == N))
	{
	  printf("Case #%d: 0\n", ci, u[N]);
	}
      else
	{
	  if (cando(F2, 1000000, F2, 1000000))
		    {
		      printf("Case #%d: %d\n", ci, smallestI);
		    }
	  else
	    {
	      long long n1 = 0;
	      long long n2 = 1;
	      long long d1 = 1;
	      long long d2 = 1;
	      while (((d1 + d2) >> 40) == 0)
		{
		  if (((((long long) F2) * (d1 + d2)) >= (((long long) 1000000) * (n1 + n2)))
		      && cando(n1 + n2, d1 + d2, F2, 1000000))
		    {
		      n1 = n1 + n2;
		      d1 = d1 + d2;
		      n2 = 2 * n2;
		      d2 = 2 * d2;
		    }
		  else
		    {
		      n2 = n1 + n2;
		      d2 = d1 + d2;
		      n1 = 2 * n1;
		      d1 = 2 * d1;
		    }
		}
	      //printf("%lld,%lld,%lld,%lld)\n", n1, n2, d1, d2);
	      long long n2t = n2;
	      long long d2t = d2;
	      n1 = 0;
	      n2 = 1;
	      d1 = 1;
	      d2 = 1;
	      while ((d1 + d2) <= N)
		{
		  if ((n1 + n2) * d2t < (d1 + d2) * n2t)
		    {
		      n1 += n2;
		      d1 += d2;
		    }
		  else
		    {
		      n2 += n1;
		      d2 += d1;
		    }
		}
	      long long n3 = 0;
	      long long n4 = 1;
	      long long d3 = 1;
	      long long d4 = 1;
	      while (((d3 + d4) >> 40) == 0)
		{
		  if (((((long long) F2) * (d3 + d4)) <= (((long long) 1000000) * (n3 + n4)))
		      && cando(F2, 1000000, n3+n4, d3+d4))
		    {
		      n4 = n3 + n4;
		      d4 = d3 + d4;
		      n3 = 2 * n3;
		      d3 = 2 * d3;
		    }
		  else
		    {
		      n3 = n3 + n4;
		      d3 = d3 + d4;
		      n4 = 2 * n4;
		      d4 = 2 * d4;
		    }
		}
	      //printf("(%lld,%lld,%lld,%lld)\n", n3, d3, n4, d4);
	      long long n3t = n3;
	      long long d3t = d3;
	      n3 = 0;
	      n4 = 1;
	      d3 = 1;
	      d4 = 1;
	      while ((d3 + d4) <= N)
		{
		  if (n3t * (d3 + d4) < d3t * (n3 + n4))
		    {
		      d4 = d3 + d4;
		      n4 = n3 + n4;
		    }
		  else
		    {
		      d3 = d3 + d4;
		      n3 = n3 + n4;
		    }
		}
	      //printf("(%lld,%lld,%lld,%lld)\n", n1, d1, n4, d4);
	      long long na = ((long long) n1) * d4 + ((long long) n4) * d1;
	      long long da = ((long long) d1) * d4 * 2;
	      if (na * 1000000 > da * F2)
		{
		  cando(n1,d1,F2,1000000);
		  printf("Case #%d: %d\n", ci, smallestI);
		}
	      else if (na * 1000000 < da * F2)
		{
		  cando(F2,1000000,n4,d4);
		  printf("Case #%d: %d\n", ci, smallestI);
		}
	      else
		{
		  cando(n1,d1,F2,1000000);
		  int si = smallestI;
		  cando(F2,1000000,n4,d4);
		  printf("Case #%d: %d\n", ci, (si < smallestI) ? si : smallestI);
		}
	      //printf("Case #%d: ? (%lld,%lld) vs (%lld,%lld)\n", ci, n1, d1, n4, d4);
	    }
	}
    }
}
