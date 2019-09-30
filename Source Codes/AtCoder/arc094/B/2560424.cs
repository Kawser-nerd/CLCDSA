using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int Q;

        public void Run()
        {
            {
                Q = Input.ReadInt();
            }

            for (int i = 0; i < Q; i++)
            {
                long[] vals = Input.ReadLongArray();
                long ans = Solve(vals[0], vals[1]);
                Console.WriteLine(ans);
            }

        }

        public long Solve(long a, long b)
        {
            if (a == b) return a * 2 - 2;

            long n = N(a * b);
            if (a * b <= n * (n + 1)) return n * 2 - 2;

            return n * 2 - 1;
        }

        // N * N < X??????N(= N * N >= X??????N??1???????
        public long N(long x)
        {
            return BinarySearch.Search(x) - 1;
        }

    }

    // libs ----------
    internal class BinarySearch
    {
        // ???false, ???true????????
        public static bool Cond(long i, long x)
        {
            if (i * i >= x) return true;
            return false;
        }

        // ???Cond?true???index???
        // ?????????????N???
        public static long Search(long x)
        {
            long left = 0;
            long right = 1000000001;

            if (Cond(0, x)) return 0;
            if (!Cond(right - 1, x)) return right;

            while (left + 1 < right)
            {
                long mid = (left + right) / 2;
                if (!Cond(mid, x))
                {
                    left = mid;
                }
                else
                {
                    right = mid;
                }
            }
            return right;
        }
    }


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