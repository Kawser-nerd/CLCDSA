using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public long N, S;
        public void Run()
        {
            N = Input.ReadLong();
            S = Input.ReadLong();

            if (N == S)
            {
                Console.WriteLine(N+1);
            }
            else if (N < S)
            {
                Console.WriteLine(-1);
            }
            else
            {
                for (int i = 2; i < 1000000; i++)
                {
                    if (Success(i))
                    {
                        Console.WriteLine(i);
                        return;
                    }
                }

                for (int m = 1000000; m >= 1; m--)
                {
                    if (SuccessMod(m) != -1)
                    {
                        Console.WriteLine(SuccessMod(m));
                        return;
                    }
                }

                Console.WriteLine(-1);
            }
        }

        public bool Success(int b)
        {
            long s = 0;
            long n = N;
            while (n > 0)
            {
                s += n % b;
                n /= b;
            }
            return s == S;
        }

        public long SuccessMod(int m)
        {
            if (S - m < 0) return -1;
            long x = N - (S - m);
            if (x < 0) return -1;
            if (x % m != 0) return -1;
            long b = x / m;
            if (b <= S - m) return -1;
            return b;
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