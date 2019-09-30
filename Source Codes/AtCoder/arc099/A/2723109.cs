using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N, K;
        public int[] A;

        public void Run()
        {
            // input
            {
                var line = Input.ReadIntArray();
                N = line[0];
                K = line[1];
            }

            {
                A = Input.ReadIntArray();
            }

            // position of 1
            int p1 = 0;
            for(int i = 0; i < N; i++)
                if (A[i] == 1)
                    p1 = i;
            
            // left, right of p1
            int left = p1;
            int right = (N - 1) - p1;

            int ret = int.MaxValue;
            for (int i = 0; i <= K - 1; i++)
            {
                int l = left - i;
                int r = right - (K - 1 - i);
                if (l >= 0 && r >= 0)
                {
                    int _ret = Count(l, K - 1) + Count(r, K - 1) + 1;
                    ret = Math.Min(ret, _ret);
                }
            }

            Console.WriteLine(ret);
        }

        public int Count(int x, int a)
        {
            return (x + a - 1) / a;
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