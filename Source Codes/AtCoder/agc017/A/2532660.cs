using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{

    internal class Solution
    {
        public int N, P;
        public int[] A;

        public void Run()
        {
            {
                var line = Input.ReadIntArray();
                N = line[0];
                P = line[1];
                A = Input.ReadIntArray();
            }

            int[] mods = new int[2];
            for (int i = 0; i < N; i++)
            {
                int m = A[i] % 2;
                mods[m]++;
            }

            // corner case
            if (P == 1 && mods[1] == 0)
            {
                Console.WriteLine(0);
                return;
            }

            int c = mods[0] + Math.Max(mods[1] - 1, 0);
            long ret = Power(2, c);
            Console.WriteLine(ret);
        }

        public long Power(long x, long n)
        {
            long tmp = 1;

            if (n > 0)
            {
                tmp = Power(x, n / 2);
                if (n % 2 == 0) tmp = tmp * tmp;
                else tmp = tmp * tmp * x;
            }

            return tmp;
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