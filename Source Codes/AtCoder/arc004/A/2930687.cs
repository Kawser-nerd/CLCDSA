using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N;
        public int[] X, Y;
        public void Run()
        {
            N = Input.ReadInt();
            X = new int[N];
            Y = new int[N];
            for (int i = 0; i < N; i++)
            {
                var line = Input.ReadIntArray();
                X[i] = line[0];
                Y[i] = line[1];
            }

            double ret = 0;
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                {
                    var value = Math.Sqrt(Math.Pow(X[i] - X[j], 2.0) + Math.Pow(Y[i] - Y[j], 2.0));
                    ret = Math.Max(ret, value);
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