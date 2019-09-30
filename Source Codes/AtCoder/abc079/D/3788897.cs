using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int H, W;
        public long MOD = 1000000007;
        public long[,] DP;
        public void Run()
        {
            {
                var line = Input.ReadIntArray();
                H = line[0];
                W = line[1];
            }

            DP = new long[10, 10];
            for (int i = 0; i < 10; i++)
            {
                var line = Input.ReadIntArray();
                for (int j = 0; j < 10; j++)
                {
                    DP[i, j] = line[j];
                }
            }
            
            for (int k = 0; k < 10; k++)
            {
                for (int i = 0; i < 10; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        if (DP[i, j] > DP[i, k] + DP[k, j])
                            DP[i, j] = DP[i, k] + DP[k, j];
                    }
                }
            }

            long ret = 0;
            for (int i = 0; i < H; i++)
            {
                var line = Input.ReadIntArray();
                for (int j = 0; j < W; j++)
                {
                    if (line[j] != -1)
                    {
                        ret += DP[line[j], 1];
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