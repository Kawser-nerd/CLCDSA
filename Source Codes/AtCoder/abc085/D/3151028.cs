using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public long N;
        public long H;
        public long[] A, B, S;
        public void Run()
        {
            {
                var line = Input.ReadLongArray();
                N = line[0];
                H = line[1];
            }

            A = new long[N];
            B = new long[N];
            for (int i = 0; i < N; i++)
            {
                var line = Input.ReadLongArray();
                A[i] = line[0];
                B[i] = line[1];
            }

            Array.Sort(A);
            Array.Reverse(A);
            Array.Sort(B);
            Array.Reverse(B);

            S = new long[N + 1];
            for (int i = 0; i < N; i++)
            {
                S[i+1] = S[i] + B[i];
            }

            long ret = long.MaxValue;
            for (int b = 0; b <= N; b++)
            {
                long t = b;
                long h = H - S[b];
                if (h > 0)
                {
                    t += (h + A[0] - 1) / A[0];
                }

                ret = Math.Min(t, ret);
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