
   #include <cstdio>
   #include <cstring>
   #include <cmath>
   #include <algorithm>
   
   using namespace std;
   
   int n;
   int a[105], b[105];
   int digit[10], pre[10];
   
   void init()
     {
        char c;
	while (1)
	  {
	      c = getchar();
	      if (c >= '0' && c <= '9') break;
	  }
	n = 1;
	a[1] = 0;
	while (c >= '0' && c <= '9') 
	  {
	      a[++ n] = c - '0';
	      c = getchar();
	  }
     }
     
   void work()
     {
        //for (int i = 1; i <= n; ++ i) printf("%d", a[i]); printf("\n");
	
        for (int i = n; i >= 1; -- i)
	  {
	      memset(digit, 0, sizeof(digit));
	      for (int j = i; j <= n; ++ j)
	         digit[a[j]] += 1;
		 
	      for (int j = a[i] + 1; j <= 9; ++ j)
	        if (digit[j] > 0)
		  {
		      for (int k = 1; k < i; ++ k) b[k] = a[k];
		      b[i] = j;
		      
		      for (int k = 0; k <= 9; ++ k) pre[k] = digit[k];
		      pre[j] -= 1;
		      
		      int l = 0;
		      for (int k = i + 1; k <= n; ++ k)
		        {
			   while (pre[l] == 0) ++ l;
			   pre[l] -= 1;
			   b[k] = l;
			}
		 
		      l = 1;
		      while (l <= n && b[l] == 0) ++ l;
		      for (int k = l; k <= n; ++ k) printf("%d", b[k]);
		      printf("\n");
		      return;
		  }
	  }
     }
     
   int main()
     {
         freopen("B-large.in", "r", stdin);
	    int caseNo;
	    scanf("%d", &caseNo);
	    for (int T = 1; T <= caseNo; ++ T)
	      {
	         printf("Case #%d: ", T);
		 init();
		 work();
	      }
	 return 0;
     }
     