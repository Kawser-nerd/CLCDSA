using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N;
        public long[] A, S;

        public void Run()
        {
            {
                N = Input.ReadInt();
                A = Input.ReadLongArray();
            }

            S = new long[N];
            for (int i = 0; i < N; i++)
            {
                S[i] = (i == 0 ? 0 : S[i - 1]) + A[i];
            }

            long ret = 0;
            int check = 0;
            for (int i = 0; i < N; i++)
            {
                while (true)
                {
                    long s = (i == 0 ? 0 : S[i-1]) - (check == 0 ? 0 : S[check-1]);
                    if ((s | A[i]) == s + A[i]) break;
                    check++;
                }

                ret += (i - check) + 1;
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