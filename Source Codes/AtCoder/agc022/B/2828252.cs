using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N;
        public void Run()
        {
            int[] A3 = new int[] { 2, 5, 63 };
            int[] A4 = new int[] { 2, 5, 20, 63 };
            int[,] V = new int[,]
            {
                { 0, 0,0,0,0,0,0,0 },
                { 6, 0,0,0,0,0,0,0 },
                { 2, 4,0,0,0,0,0,0 },
                { 2, 4,6,0,0,0,0,0 },
                { 2, 4,6,12,0,0,0,0 },
                { 2, 3,4,6,9,0,0,0 },
                { 2, 3,4,8,9,10,0,0 },
                { 2, 3,4,6,8,9,10,0 },
                { 2, 3,4,6,8,9,10,12 }
            };

            N = Input.ReadInt();
            if (N == 3)
            {
                Console.WriteLine(string.Join(" ", A3));
            }
            else if (N == 4)
            {
                Console.WriteLine(string.Join(" ", A4));
            }
            else
            {
                List<int> ret = new List<int>();
                int M = N % 8;
                int C = N / 8;
                for (int i = 0; i < C; i++)
                {
                    for(int j = 0; j < 8; j++)
                        ret.Add(V[8, j] + 12 * i);
                }

                {
                    for (int j = 0; j < 8; j++)
                    {
                        int v = V[M, j];
                        if (v != 0)
                            ret.Add(v + 12 * C);
                    }
                }

                Console.WriteLine(string.Join(" ", ret));   
            }
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