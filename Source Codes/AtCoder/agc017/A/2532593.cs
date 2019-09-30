using System;
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

            int ONES = 0;
            int TWOS = 0;
            for (int i = 0; i < N; i++)
            {
                if (A[i] % 2 == 1) ONES++;
                else TWOS++;
            }

            if (P == 1 && ONES == 0)
            {
                Console.WriteLine(0);
                return;
            }

            long ret = 1;
            for (int i = 0; i < TWOS; i++)
            {
                ret *= 2;
            }
            for (int i = 0; i < ONES-1; i++)
            {
                ret *= 2;
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