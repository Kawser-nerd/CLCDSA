using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int NX, NY;
        public long[] X, Y, XS, YS;
        public long MOD = 1000000007;
        public void Run()
        {
            {
                var line = Input.ReadIntArray();
                NX = line[0];
                NY = line[1];
            }
            X = Input.ReadLongArray();
            Y = Input.ReadLongArray();

            XS = new long[NX];
            YS = new long[NY];
            for (int i = 0; i < NX; i++)
            {
                XS[i] = X[i] + (i == 0 ? 0 : XS[i - 1]);
            }
            for (int i = 0; i < NY; i++)
            {
                YS[i] = Y[i] + (i == 0 ? 0 : YS[i - 1]);
            }

            long XX = 0;
            long YY = 0;
            for (int i = 0; i < NX; i++)
            {
                XX += (X[i] * (1 + i) - XS[i]);
                XX %= MOD;
            }
            for (int i = 0; i < NY; i++)
            {
                YY += (Y[i] * (1 + i) - YS[i]);
                YY %= MOD;
            }

            Console.WriteLine((XX * YY) % MOD);
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