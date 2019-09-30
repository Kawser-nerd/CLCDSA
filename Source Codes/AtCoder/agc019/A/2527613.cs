using System;
using System.Collections.Generic;
using System.Linq;

namespace Competitive
{

    internal class Solution
    {
        public long[] P; // 1, 2, 4, 8
        public long N;
        public long[] DP;

        public void Run()
        {
            var P = Input.ReadLongArray();
            N = Input.ReadLong() * 4;

            DP = new long[8 + 1];
            DP[0] = 0;
            for (int i = 1; i < DP.Length; i++)
            {
                DP[i] = long.MaxValue;
                if (i - 1 >= 0) DP[i] = Math.Min(DP[i], DP[i - 1] + P[0]);
                if (i - 2 >= 0) DP[i] = Math.Min(DP[i], DP[i - 2] + P[1]);
                if (i - 4 >= 0) DP[i] = Math.Min(DP[i], DP[i - 4] + P[2]);
                if (i - 8 >= 0) DP[i] = Math.Min(DP[i], DP[i - 8] + P[3]);
            }

            long unit = N / 8;
            long mod = N % 8;

            Console.WriteLine(unit * DP[8] + DP[mod]);
        }

    }

    // libs ----------
    
    // common ----------

    internal static class Input
    {
        public static int ReadInt()
        {
            string line = Console.ReadLine();
            return int.Parse(line);
        }

        public static long ReadLong()
        {
            string line = Console.ReadLine();
            return long.Parse(line);
        }

        public static int[] ReadIntArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(int.Parse).ToArray();            
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