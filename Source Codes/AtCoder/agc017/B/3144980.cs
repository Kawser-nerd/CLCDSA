using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public long N, A, B, C, D;
        public long X;
        public void Run()
        {
            {
                var line = Input.ReadLongArray();
                N = line[0];
                A = line[1];
                B = line[2];
                C = line[3];
                D = line[4];
            }

            X = B - A;
            N--;

            for (int p = 0; p < N; p++)
            {
                long m = N - p;
                long mx = D * p - C * m;
                long mn = C * p - D * m;

                if (X >= mn && X <= mx)
                {
                    Console.WriteLine("YES");
                    return;
                }
            }

            Console.WriteLine("NO");

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