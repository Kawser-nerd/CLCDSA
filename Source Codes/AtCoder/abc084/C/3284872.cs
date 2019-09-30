using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N;
        public int[] C, S, F;
        public void Run()
        {
            N = Input.ReadInt() - 1;
            C = new int[N];
            S = new int[N];
            F = new int[N];
            for (int i = 0; i < N; i++)
            {
                var line = Input.ReadIntArray();
                C[i] = line[0];
                S[i] = line[1];
                F[i] = line[2];
            }

            for (int i = 0; i < N; i++)
            {
               Console.WriteLine(Calc(i));   
            }
            Console.WriteLine(0);

        }

        public long Calc(int x)
        {
            long ret = 0;
            for (int i = x; i < N; i++)
            {
                long tt = ret - S[i];
                long st;
                if (tt <= 0)
                {
                    st = S[i];
                }
                else
                {
                    st = S[i] + (tt / F[i]) * F[i] + (tt % F[i] == 0 ? 0 : F[i]);
                }

                ret = st + C[i];
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