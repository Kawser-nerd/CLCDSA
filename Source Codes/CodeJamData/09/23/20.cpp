
  #include <cstdio>
  #include <cstring>
  #include <cmath>
  #include <string>
  #include <iostream>
  #include <algorithm>
  
  using namespace std;
  
  const int dx[4] = {-1, 1, 0, 0};
  const int dy[4] = {0, 0, -1, 1};
  
  const int CONST = 500;
  const int lim = 2000;
    
  struct node
    {
        int x, y, z;
    }que[25 * 25 * lim];
    
  
  bool cvr[25][25], newcvr[25][25];
  char a[25][25];
  int f[25][25][lim];
  int sum, n, m;
  
  void init()
    {
        scanf("%d%d", &n, &m);
	//printf("%d %d\n", n, m);
	for (int i = 1; i <= n; ++ i)
	  for (int j = 1; j <= n; ++ j)
	    {
	        char c;
		while (1)
		  {
		     c = getchar();
		     if ((c >= '0' && c <= '9') || (c == '+') || (c == '-')) break;
		  }
		a[i][j] = c;
		//printf("%c", a[i][j]);
		//if (j == n) printf("\n");
	    }
    }
  
  bool digit(char c)
    {
        return c >= '0' && c <= '9';
    }
    
  void update(int &x, int y)
    {
        if (x < 0 || y < x) x = y;
    }
    
  void work()
    {
        memset(f, 255, sizeof(f));
	int h = 0, t = 0;
	
	for (int i = 1; i <= n; ++ i)
	  for (int j = 1; j <= n; ++ j)
	    if (digit(a[i][j]))
	      {
	         f[i][j][CONST] = 1;
		 ++ t;
		 que[t].x = i;
		 que[t].y = j;
		 que[t].z = CONST;
	      }
	
	while (h < t)
	{
	    ++ h;
	    int i = que[h].x;
	    int j = que[h].y;
	    int k = que[h].z;
	    
            if (a[i][j] >= '0' && a[i][j] <= '9')
		       {
		           for (int v = 0; v < 4; ++ v)
			     {
			         int x = i + dx[v];
			         int y = j + dy[v];
			         if (x < 1 || x > n || y < 1 || y > n || digit(a[x][y])) continue;
			         int tmp;
			         if (a[x][y] == '+') tmp = k + a[i][j] - '0';
			            else tmp = k - (a[i][j] - '0');
				 if (tmp < 0 || tmp >= lim) continue;
			         if (f[x][y][tmp] < 0)
				   {
				      f[x][y][tmp] = f[i][j][k] + 1;
				      ++ t;
				      que[t].x = x;
				      que[t].y = y;
				      que[t].z = tmp;
				   }
			     }
		      } else
		      {
		          for (int v = 0; v < 4; ++ v)
		 	    {
			        int x = i + dx[v];
			        int y = j + dy[v];
			        if (x < 1 || x > n || y < 1 || y > n || !digit(a[x][y])) continue;
				if (f[x][y][k] < 0)
				  {
				      f[x][y][k] = f[i][j][k] + 1;
				      ++ t;
				      que[t].x = x;
				      que[t].y = y;
				      que[t].z = k;
				  }
			    }
		      }
        }
		
	for (int i = 1; i <= m; ++ i)
	  {
	      scanf("%d", &sum);
	      int res = -1;
	      for (int i = 1; i <= n; ++ i)
	        for (int j = 1; j <= n; ++ j)
		  if (digit(a[i][j]))
		    {
		        int tmp = sum + CONST - (a[i][j] - '0');
			if (tmp >= 0 && tmp < lim && f[i][j][tmp] >= 0) update(res, f[i][j][tmp]);
		    }
	
	      //printf("%d %d\n", sum, res);
	      
	      for (int i = 1; i <= n; ++ i)
	        for (int j = 1; j <= n; ++ j)
		  if (!digit(a[i][j])) 
		    newcvr[i][j] = 1;
	
	      char last = '+';
	      string ans = "";
	      sum += CONST;
	      
	      for (int i = 1; i <= res; ++ i)
	        {
		   for (int j = 1; j <= n; ++ j)
                     for (int k = 1; k <= n; ++ k)
                        cvr[j][k] = newcvr[j][k];
                   memset(newcvr, 0, sizeof(newcvr));			
		 
		   char best = ' ';
		   if (i & 1)
		     {
		        for (int j = 1; j <= n; ++ j)
			  for (int k = 1; k <= n; ++ k)
			    if (cvr[j][k])
			      {
			         for (int v = 0; v < 4; ++ v)
				   {
				      	int x = j + dx[v];
					int y = k + dy[v];
			                if (x < 1 || x > n || y < 1 || y > n || !digit(a[x][y])) continue;
					int tmp;
					if (last == '+') tmp = sum - (a[x][y] - '0');
					   else tmp = sum + (a[x][y] - '0');
					if (tmp < 0 || tmp >= lim) continue;
					if (f[x][y][tmp] == res - i + 1)
					  if (best == ' ' || a[x][y] < best) best = a[x][y];
				   }
			      }
		     } else
		     {
		        for (int j = 1; j <= n; ++ j)
			  for (int k = 1; k <= n; ++ k)
			    if (cvr[j][k])
			      {
			         for (int v = 0; v < 4; ++ v)
				   {
				      	int x = j + dx[v];
					int y = k + dy[v];
			                if (x < 1 || x > n || y < 1 || y > n || digit(a[x][y])) continue;
					if (f[x][y][sum] == res - i + 1)
					  if (best == ' ' || a[x][y] < best) best = a[x][y];
				   }
			      }
		     }
		    ans += best;
		    
		    if (i & 1)
		     {
		        for (int j = 1; j <= n; ++ j)
			  for (int k = 1; k <= n; ++ k)
			    if (cvr[j][k])
			      {
			         for (int v = 0; v < 4; ++ v)
				   {
				      	int x = j + dx[v];
					int y = k + dy[v];
			                if (x < 1 || x > n || y < 1 || y > n || !digit(a[x][y])) continue;
					int tmp;
					if (last == '+') tmp = sum - (a[x][y] - '0');
					   else tmp = sum + (a[x][y] - '0');
					if (tmp < 0 || tmp >= lim) continue;
					if (f[x][y][tmp] == res - i + 1 && a[x][y] == best) newcvr[x][y] = 1;
				   }
			      }
			if (last == '+') sum -= (best - '0'); else sum += (best - '0');
		     } else
		     {
		        for (int j = 1; j <= n; ++ j)
			  for (int k = 1; k <= n; ++ k)
			    if (cvr[j][k])
			      {
			         for (int v = 0; v < 4; ++ v)
				   {
				      	int x = j + dx[v];
					int y = k + dy[v];
			                if (x < 1 || x > n || y < 1 || y > n || digit(a[x][y])) continue;
					if (f[x][y][sum] == res - i + 1 && a[x][y] == best) newcvr[x][y] = 1;
				   }
			      }
			last = best;
		     }
		}
	      printf("%s\n", ans.c_str());
	  }
    }
    
  int main()
    {
        freopen("C-large.in", "r", stdin);
        int caseNo;
	scanf("%d", &caseNo);
        for (int T = 1; T <= caseNo; ++ T)
	  {
	     printf("Case #%d:\n", T);
	     init();
	     work();
	  }
	return 0;
    }
    