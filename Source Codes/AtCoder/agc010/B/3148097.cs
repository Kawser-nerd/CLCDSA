using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public long N;
        public long[] A;
        public void Run()
        {
            N = Input.ReadLong();
            A = Input.ReadLongArray();

            long S = A.Sum();
            long X = N * (N + 1) / 2;

            if (S % X != 0)
            {
                Console.WriteLine("NO");
                return;
            }

            long T = S / X;

            long C = 0;
            for (int i = 0; i < N; i++)
            {
                long d = A[i] - (i == 0 ? A[N - 1] : A[i - 1]);
                long dd = T - d;
                if (dd % N != 0 || dd / N < 0)
                {
                    Console.WriteLine("NO");
                    return;
                }

                C += dd / N;
            }

            if (T == C)
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
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