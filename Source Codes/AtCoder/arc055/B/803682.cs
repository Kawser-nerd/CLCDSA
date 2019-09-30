using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine().Split();
            var n = Int32.Parse(s[0]);
            var k = Int32.Parse(s[1]);

            var solver = new Solver();
            Console.WriteLine(solver.Solve(n, k));
        }
    }

    public class Solver
    {
        int _n;
        double[, ,] dp;
        public double Solve(int n, int k)
        {
            _n = n;

            dp = new double[n, k + 1, 2];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < k + 1; j++)
                    for (int l = 0; l < 2; l++)
                        dp[i, j, l] = -1;

            return dfs(0, k, 0);
        }

        double dfs(int idx, int k, int ateMaxVal)
        {
            if (idx == _n) return ateMaxVal;
            if (dp[idx, k, ateMaxVal] != -1) return dp[idx, k, ateMaxVal];

            //current one is not max
            //rate: i - 1 / i
            var ret = ((double)(idx + 1 - 1) / (double)(idx + 1)) * dfs(idx + 1, k, ateMaxVal);

            //current one is max
            //rate: 1 / i

            //don't eat
            var temp = (1.0 / (double)(idx + 1)) * dfs(idx + 1, k, 0);

            //eat
            if(k > 0)
                temp = Math.Max(temp, (1.0 / (double)(idx + 1)) * dfs(idx + 1, k - 1, 1));

            ret+=temp;

            dp[idx, k, ateMaxVal] = ret;
            return ret;
        }
    }
}