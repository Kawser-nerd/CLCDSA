using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N;
        public int[] P;
        public int[] A, B;
        public void Run()
        {
            N = Input.ReadInt();
            P = Input.ReadIntArray();

            A = new int[N];
            B = new int[N];

            for (int i = 0; i < N; i++)
            {
                A[i] = N * (i + 1);
                B[i] = N * (N - i);
            }

            for (int i = 0; i < N; i++)
            {
                B[P[i] - 1] += i;
            }

            Console.WriteLine(string.Join(" ", A));
            Console.WriteLine(string.Join(" ", B));
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