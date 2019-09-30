using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public long N;
        public long MOD = 1000000007;

        public void Run()
        {
            N = Input.ReadLong();

            int ret = int.MaxValue;
            for (long i = 1; i * i <= N; i++)
            {
                if (N % i != 0) continue;
                long a = i;
                long b = N / a;
                ret = Math.Min(ret, Math.Max(Digits(a), Digits(b)));
            }

            Console.WriteLine(ret);
        }

        int Digits(long n)
        {
            int ret = 0;
            while (n > 0)
            {
                ret++;
                n /= 10;
            }
            return ret;
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