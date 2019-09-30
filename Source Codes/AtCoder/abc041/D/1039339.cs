using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static void Main()
    {
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = a[0], m = a[1];
        long[] dp = new long[1 << n];
        int[] t = new int[n];
        for (int i = 0; i < m; i++)
        {
            int[] b = Console.ReadLine().Split().Select(int.Parse).ToArray();
            b[0]--; b[1]--;
            t[b[1]] |= 1 << b[0];
        }
        dp[0] = 1;
        for (int i = 0; i < (1 << n); i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i >> j & 1) == 0 && (i | t[j]) == i)
                    dp[i | 1 << j] += dp[i];
            }
        }
        Console.WriteLine(dp[(1 << n) - 1]);
    }
}