using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int[] A;

        public void Run()
        {
            {
                A = Input.ReadIntArray();
            }

            Array.Sort(A);

            int ret = int.MaxValue;
            for (int i = 0; i < 100; i++)
            {
                int r = 0;
                for (int k = 0; k < 3; k++)
                {
                    r += T(i - A[k]);
                }
                ret = Math.Min(ret, r);

            }
            Console.WriteLine(ret);

        }

        public int T(int n)
        {
            if (n < 0) return -n;
            return (n + 1) / 2 + n % 2;
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