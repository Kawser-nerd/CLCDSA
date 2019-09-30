
  #include <cstdio>
  #include <cstring>
  #include <cmath>
  #include <vector>
  #include <algorithm>

  using namespace std;

  struct node
  {
     int x, y;
  }a[1005];
  
  vector < int > lis[35];
  vector < int > edge[1005];
  int yes[1005];
  int N;
  int OK;
  
  int cmp(node A, node B)
  {
       return A.x < B.x;
  }
  
  void init()
  {
       scanf("%d", &N);
       for (int i = 0; i < N; ++ i)
	  scanf("%d%d", &a[i].x, &a[i].y);
       sort(a, a + N, cmp);
       for (int i = 1; i <= 30; ++ i) lis[i].clear();
       for (int i = 0; i < N; ++ i)
	  lis[a[i].y].push_back(i);
  }
  
  void dfs(int i, int c)
  {
       if (!OK) return;
       if (yes[i] == c) return;
       if (yes[i] == 3 - c) { OK = 0; return; }
       yes[i] = c;
       for (int j = 0; j < edge[i].size(); ++ j)
          dfs(edge[i][j], 3 - c);
  }
  
  void work()
  {
       OK = 1;
       for (int i = 0; i < N; ++ i) edge[i].clear();
       for (int i = 0; i < N; ++ i)
       {
           for (int delta = -1; delta <= 1; ++ delta)
	   {
	     int dep = a[i].y + delta;
	     if (dep < 1 || dep > 30) continue;
             for (int j = 0; j < lis[dep].size(); ++ j)
	        {  
	            int k = lis[dep][j];
	  	    if (a[k].x > a[i].x) {  edge[i].push_back(k); edge[k].push_back(i); OK = 0; break; }
	        }
	   }
       }
       if (OK) { printf("1\n"); return; }
       OK = 1;
       memset(yes, 0, sizeof(yes));
       for (int i = 0; i < N; ++ i)
          if (!yes[i]) dfs(i, 1);
       if (OK) { printf("2\n"); return; }
       
	   int T = 0;
	   while (T <= 100000)
	   {
			OK = 1;
			memset(yes, 0, sizeof(yes));
			for (int i = N - 1; i >= 0; -- i)
			{
				int use[4];
				memset(use, 0, sizeof(use));
				for (int j = 0; j < edge[i].size(); ++ j)
					use[yes[edge[i][j]]] = 1;
				if (use[1] && use[2] && use[3]) { OK = 0; break; }
				while (1)
				{
				   yes[i] = rand() % 3 + 1;
				   if (!use[yes[i]]) break;
                }
			}
			if (OK) { printf("3\n"); return; }
			++ T;
	   }
	   printf("4\n");
  }
  
  int main()
    {
       freopen("C-small-attempt2.in", "r", stdin);
 
         int caseNo;
         scanf("%d", &caseNo);

         for (int t = 1; t <= caseNo; ++ t)
           {
              printf("Case #%d: ", t);
              init();
              work();
           }
       return 0;
    }
