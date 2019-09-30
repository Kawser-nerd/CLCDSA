using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public long N, X;
        public long MOD = 1000000007;
        public long[] A, B;
        public void Run()
        {
            {
                var line = Input.ReadLongArray();
                N = line[0];
                X = line[1];
            }

            A = new long[N + 1];
            B = new long[N + 1];

            for (int i = 0; i <= N; i++)
            {
                if (i == 0)
                {
                    A[i] = 1;
                    B[i] = 1;
                }
                else
                {
                    A[i] = A[i - 1] * 2 + 3;
                    B[i] = B[i - 1] * 2 + 1;
                }
            }

            long ret = Count(N, X);
            Console.WriteLine(ret);
        }

        public long Count(long n, long x)
        {
            if (x >= A[n]) return B[n];

            long r = 0;

            x--;
            if (x <= 0) return r;

            r += Count(n - 1, x);
            x -= A[n - 1];
            if (x <= 0) return r;

            r++;
            x--;
            if (x <= 0) return r;

            r += Count(n - 1, x);
            x -= A[n - 1];
            if (x <= 0) return r;

            return r;
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