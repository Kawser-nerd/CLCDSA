using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N, M, K;
        public const long MOD = 1000000007;
        public void Run()
        {
            {
                var line = Input.ReadIntArray();
                N = line[0];
                M = line[1];
                K = line[2];
            }

            int D = (N + M - 1) / (K - 1);

            var DP = new long[D + 1, M + 1]; // ??????1??????
            DP[0, 0] = 1;

            for (int d = 1; d <= D; d++)
            {
                for (int m = 0; m <= M; m++)
                {
                    for (int k = 0; k < K && m + k <= M; k++)
                    {
                        DP[d, m + k] += DP[d - 1, m];
                        DP[d, m + k] %= MOD;
                    }
                }
            }

            long ret = 0;
            {
                int m = M;
                while (m > 0)
                {
                    int d = (N + m - 1) / (K - 1);
                    ret += DP[d, m];
                    ret %= MOD;
                    m -= K - 1;
                }
            }

            Console.WriteLine(ret);

       
        }
    }

    // libs ----------
    

    // common ----------

    internal static class Input
    {
        public static string ReadString()
        {
            string line = Console.ReadLine();
            return line;
        }

        public static int ReadInt()
        {
            string line = Console.ReadLine();
            return int.Parse(line);
        }

        public static int[] ReadIntArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(int.Parse).ToArray();            
        }

        public static long ReadLong()
        {
            string line = Console.ReadLine();
            return long.Parse(line);
        }

        public static long[] ReadLongArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(long.Parse).ToArray();
        }

        public static double[] ReadDoubleArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(double.Parse).ToArray();
        }
    }
    
    internal class Program
    {
        public static void Main(string[] args)
        {
            var s = new Solution();
            s.Run();
        }
    }
}