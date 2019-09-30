
  #include <cstdio>
  #include <cstring>
  #include <cmath>
  #include <string>
  #include <iostream>
  #include <algorithm>
  
  using namespace std;
  
  bool yes[105];
  string name[105];
  double prob[105];
  int lc[105], rc[105];
  int n, m;
  double res;
  
  int dfs()
    {
        char c;
	while (1)
	  {
	      c = getchar();
	      if (c == '(') break;
	  }
	++ n;
	int pre = n;
	name[n] = "";
	scanf("%lf", &prob[n]);
	while (1)
	  {
	      c = getchar();
	      if ((c >= 'a' && c <= 'z') || c == ')') break;	      
	  }
	if (c == ')') return n;
	
	while (c >= 'a' && c <= 'z')
	  {
	     name[n] += c; c = getchar();
	  }
	
	int x;
        x = dfs(); lc[pre] = x;
        x = dfs(); rc[pre] = x;	
	
	while (1)
	  {
	     c = getchar();
	     if (c == ')') break;
	  }
	return pre;
    }
    
  void init()
    {
        int L;
	scanf("%d", &L);
	
	memset(lc, 255, sizeof(lc));
	memset(rc, 255, sizeof(rc));
	
	n = 0;
	dfs();
    }
    
  void go(int x)
    {
        if (x < 0) return;
	res *= prob[x];
	if (yes[x]) go(lc[x]); else go(rc[x]);
    }
    
  void work()
    {
        char s[200];
	
        scanf("%d", &m);
	while (m > 0) {
	
	memset(yes, 0, sizeof(yes));
	scanf("%s", &s);
	int cnt;
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; ++ i)
	  {
	      scanf("%s", &s);
	      for (int j = 1; j <= n; ++ j)
	        if ((string)(s) == name[j]) yes[j] = 1;
	  }
	
	res = 1.0;
	go(1);
	m --;
	printf("%.7lf\n", res);
	}
    }
    
  int main()
    {
        freopen("A-large.in", "r", stdin);
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
    