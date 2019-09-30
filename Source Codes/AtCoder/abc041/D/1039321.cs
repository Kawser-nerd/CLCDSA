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
        List<int>[] ls = new List<int>[n];
        for(int i = 0; i < n; i++)
        {
            ls[i] = new List<int>();
        }
        for(int i = 0; i < m; i++)
        {
            int[] b = Console.ReadLine().Split().Select(int.Parse).ToArray();
            b[0]--;b[1]--;
            ls[b[1]].Add(b[0]);
        }
        dp[0] = 1;
        for(int i = 0; i < (1 << n); i++)
        {
            for(int j = 0; j < n; j++)
            {
                if ((i >> j & 1) != 0) continue;
                bool ok = true;
                foreach(int k in ls[j])
                {
                    if ((i >> k & 1) == 0)
                    {
                        ok = false;break;
                    }
                }
                if (ok) dp[i | 1 << j] += dp[i];
            }
        }
        Console.WriteLine(dp[(1 << n) - 1]);
    }
}