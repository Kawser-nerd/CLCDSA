using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N, K;
        public long[] A;
        public long[] S, SPlus;
        public void Run()
        {
            {
                var line = Input.ReadIntArray();
                N = line[0];
                K = line[1];
            }

            A = Input.ReadLongArray();

            S = new long[N + 1];
            SPlus = new long[N + 1];

            // ????????????
            for (int i = 0; i < N; i++)
            {
                S[i + 1] = S[i] + A[i];
                SPlus[i + 1] = SPlus[i] + Math.Max(A[i], 0);
            }

            long ret = long.MinValue;
            for (int i = 0; i < N; i++)
            {
                if (i + K > N) continue;
                long r = SPlus[N] - SPlus[0];
                r -= (SPlus[i + K] - SPlus[i]);
                r += Math.Max(0, S[i + K] - S[i]);

                ret = Math.Max(ret, r);
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