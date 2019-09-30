using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N;
        public int[,] F;
        public int[,] P;
        public int M = 10;
        public void Run()
        {

            N = Input.ReadInt();
            F = new int[N,M];
            P = new int[N, M + 1];
            {
                for (int i = 0; i < N; i++)
                {
                    var line = Input.ReadIntArray();
                    for (int m = 0; m < M; m++)
                    {
                        F[i, m] = line[m];
                    }
                }

                for (int i = 0; i < N; i++)
                {
                    var line = Input.ReadIntArray();
                    for (int m = 0; m <= M; m++)
                    {
                        P[i, m] = line[m];
                    }
                }
            }

            int B = 1 << M;
            int ret = int.MinValue;
            for (int b = 1; b < B; b++)
            {
                ret = Math.Max(Calc(b), ret);
            }

            Console.WriteLine(ret);
        }

        public int Calc(int b)
        {
            var count = new int[N];

            for (int m = 0; m < M; m++)
            {
                bool open = ((b >> m) & 1) == 1;
                if(open)
                for (int i = 0; i < N; i++)
                {
                    count[i] += F[i, m];
                }
            }

            int ret = 0;

            for (int i = 0; i < N; i++)
            {
                ret += P[i, count[i]];
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