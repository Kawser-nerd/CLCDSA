using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int n, k;
            var s = Console.ReadLine().Split();
            n = int.Parse(s[0]);
            k = int.Parse(s[1]);

            var a = new List<int>();
            for (int i = 0; i < n; i++)
            {
                a.Add(int.Parse(Console.ReadLine()));
            }

            var solver = new Solver();
            Console.WriteLine(solver.Solve(n, k, a));
        }
    }

    public class Solver
    {
        const int INF = 500000 * 2000 + 1;

        int[] sum;
        List<int> _a;
        public int Solve(int n, int k, List<int> a)
        {
            if (a.Sum() == k) return 1;

            _a = a;
            sum = new int[a.Count()];
            sum[0] = a[0];
            for (int i = 1; i < a.Count(); i++)
            {
                sum[i] = sum[i - 1] + a[i];
            }

            var dp = new int[n, n + 1];
            for (int i = 0; i < n; i++) for (int j = 0; j < n + 1; j++) dp[i, j] = INF;
            for (int i = 0; i < n; i++) dp[i, 0] = 0;

            dp[0, 1] = a[0] > 0 ? 1 : 0;

            for (int i = 1; i < n; i++)
            {
                for (int j = 1; j < n + 1; j++)
                {
                    dp[i, j] = Math.Min(dp[i - 1, j], GetMinWinNum(dp[i - 1, j - 1], i));
                }
            }

            var ret = 0;
            for (int i = 1; i < n + 1; i++)
            {
                if (dp[n - 1, i] > k) continue;
                ret = Math.Max(ret, i);
            }

            return ret;
        }

        int GetMinWinNum(int prevWinSum, int idx)
        {
            if (prevWinSum == INF) return INF;
            var prevWinRate = (double)prevWinSum / (double)sum[idx - 1];
            var needWinCnt = (int)Math.Ceiling(prevWinRate * (double)_a[idx]);
            if ((double)needWinCnt / (double)_a[idx] <= prevWinRate) needWinCnt++;
            if (needWinCnt > _a[idx]) return INF;
            return prevWinSum + needWinCnt;
        }
    }
}