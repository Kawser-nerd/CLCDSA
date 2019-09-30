using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CSharp_C
{
    class c
    {
        static int[,] dp;

        static int func(int left, int right, int[] a)
        {
	        if (dp[left,right] >= 0) return dp[left,right];

	        if (left > right) {
		        return 0;
	        }

	        int min = -1;
	        for (int i = left; i <= right; ++i) {
		        int l = a[i] - a[left - 1] - 1;
		        int r = a[right + 1] - a[i] - 1;
		        int ll = func(left, i - 1, a);
		        int rr = func(i + 1, right, a);
		        int res = l + r + ll + rr;
		        if (min < 0 || min > res) min = res;
	        }

	        return dp[left,right] = min;
        }

        static void Main(string[] args)
        {
            int t, ca = 0, m, n;
            for (t = Convert.ToInt32(Console.ReadLine()); t > 0; --t) {
                string[] token = Console.ReadLine().Trim().Split();
		        n = Convert.ToInt32(token[0]); m = Convert.ToInt32(token[1]);
                dp = new int[m + 10,m + 10];
                int[] a = new int[m + 2];
                token = Console.ReadLine().Trim().Split();
		        for (int i = 1; i <= m; ++i) {
			        a[i] = Convert.ToInt32(token[i - 1]);
		        }
                a[0] = 0; a[m + 1] = n + 1;

                for (int i = 0; i < m + 10; ++i) for (int j = 0; j < m + 10; ++j) dp[i, j] = -1;

                Console.WriteLine("Case #{0}: {1}", ++ca, c.func(1, m, a));
	        }
        }
    }
}
