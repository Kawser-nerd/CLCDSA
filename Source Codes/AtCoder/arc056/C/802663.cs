using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int n, k;
            int[,] w;

            var s = Console.ReadLine().Split();
            n = Int32.Parse(s[0]);
            k = Int32.Parse(s[1]);

            w = new int[n, n];
            for (int i = 0; i < n; i++)
            {
                var ws = Console.ReadLine().Split();
                for (int j = 0; j < n; j++)
                {
                    w[i, j] = Int32.Parse(ws[j]);
                    w[j, i] = w[i, j];
                }
            }

            var solver = new Solver();
            Console.WriteLine(solver.Solve(n, k, w));
        }
    }

    public class Solver
    {
        public int Solve(int n, int k, int[,] w)
        {
            // ??????????????
            var sub = new int[1 << 17];
            
            for (int b = 0; b < 1 << n; b++)
                for (int i = 0; i < n; i++)
                    for (int j = i + 1; j < n; j++)
                        if (((1 << i) & b) != 0 && ((1 << j) & b) != 0) sub[b] += w[i, j];

            // dp[S] ???S??
            var dp = new int[1 << 17];
            for (int i = 0; i < 1 << n; i++)
                dp[i] = k;

            // S???t???u????????
            // dp[S]? dp[t] + k - sub[S] + sub[t] + sub[u] ???
            for (int s = 0; s < 1 << n; s++)
            {
                for (int t = (s - 1) & s; t > 0; t = (t - 1) & s)
                {
                    dp[s] = Math.Max(dp[s], dp[t] + k - sub[s] + sub[t] + sub[s - t]);
                }
            }

            return dp[(1 << n) - 1];    //dp[1 << n - 1] ??????????
        }
    }
}