using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N;
        public int M;
        public int[,] A;
        public void Run()
        {
            {
                var line = Input.ReadIntArray();
                N = line[0];
                M = line[1];
            }

            A = new int[N, M];

            for (int i = 0; i < N; i++)
            {
                var line = Input.ReadIntArray();
                for (int j = 0; j < M; j++)
                {
                    // (j + 1) ??????????? A[i, j] - 1
                    A[i, line[j] - 1] = j + 1;
                }
            }

            int ret = int.MaxValue;

            for (int a = 0; a < M; a++)
            {
                var count = new int[M];

                for (int i = 0; i < N; i++)
                {   
                    for (int j = 0; j < M; j++)
                    {
                        if (A[i, j] == 1) count[j]++;
                    }
                }

                var s_mx = -1;
                var mx = -1;
                for (int j = 0; j < M; j++)
                {
                    if (count[j] > mx)
                    {
                        s_mx = j;
                        mx = count[j];
                    }
                }

                ret = Math.Min(ret, mx);

                for (int i = 0; i < N; i++)
                {
                    int priority = A[i, s_mx];
                    A[i, s_mx] = -1;

                    for (int j = 0; j < M; j++)
                    {
                        if (A[i, j] > priority) A[i, j]--;
                    }
                }
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