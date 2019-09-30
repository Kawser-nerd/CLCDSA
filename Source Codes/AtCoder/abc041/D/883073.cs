using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC041_D
{
    class Program
    {
        static List<int>[] G;
        static void Main(string[] args)
        {

            var t = scan;
            int n = t[0];
            int m = t[1];
            G = Enumerable.Range(0, n).Select(g => new List<int>()).ToArray();
            for (int i = 0; i < m; i++)
            {
                t = scan;
                G[t[0] - 1].Add(t[1] - 1);
            }

            var dp = new long[1 << n];
            dp[0] = 1;

            for (int S = 1; S < 1 << n; S++)
            {
                for (int j = 0; j < n; j++)
                {
                    if((S >> j & 1) == 1 && Check(S, j))
                    {
                        dp[S] += dp[S ^ 1 << j];
                        //Console.WriteLine("dp[{0}]= {1}", S, dp[S]);
                    }
                }
            }

            Console.WriteLine(dp[(1 << n) - 1]);
        }
        static bool Check(int S, int J)
        {
            foreach (var j in G[J])
            {
                if ((S >> j & 1) == 1) return false;
            }
            return true;
        }
        

        static int[] scan { get { return Array.ConvertAll(Console.ReadLine().Split(), int.Parse); } }
    }
}