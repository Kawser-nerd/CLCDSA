using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N;
        public long[] A;
        public long MOD = 1000000007;

        public void Run()
        {
            N = Input.ReadInt();
            A = Input.ReadLongArray();

            long r = 0;
            while (true)
            {
                bool flg = true;
                for (int i = 0; i < N; i++)
                {
                    long a = A[i] / N;
                    if (a > 0)
                    {
                        flg = false;
                        r += a;
                        for (int j = 0; j < N; j++)
                        {
                            if (i == j) A[j] -= a * N;
                            else A[j] += a;
                        }
                    }
                }

                if(flg) break;
            }

            Console.WriteLine(r);
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