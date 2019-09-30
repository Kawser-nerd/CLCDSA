using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int H, W;
        public char[,] M;

        public void Run()
        {
            {
                var line = Input.ReadIntArray();
                H = line[0];
                W = line[1];
            }
            M = new char[H, W];
            for (int y = 0; y < H; y++)
            {
                var line = Console.ReadLine();
                for (int x = 0; x < W; x++)
                    M[y, x] = line[x];
            }

            bool flag = true;
            for (int y = 0; y < H; y++)
            for (int x = 0; x < W; x++)
            {
                if (M[y, x] == '#')
                {
                    if ((y == 0 && x == 0) || (y == H - 1 && x == W - 1))
                    {
                        if (AdjCount(y, x) != 1) flag = false;
                    }
                    else
                    {
                        if (AdjCount(y, x) != 2) flag = false;
                    }
                }
            }

            int count = 0;
            for (int y = 0; y < H; y++)
            for (int x = 0; x < W; x++)
            {
                if (M[y, x] == '#') count++;
            }
            if (count != H + W - 1) flag = false;

            Console.WriteLine(flag ? "Possible" : "Impossible");
        }

        public int AdjCount(int y, int x)
        {
            int ret = 0;
            if (IsPainted(y - 1, x)) ret++;
            if (IsPainted(y + 1, x)) ret++;
            if (IsPainted(y, x + 1)) ret++;
            if (IsPainted(y, x - 1)) ret++;
            return ret;
        }

        public bool IsPainted(int y, int x)
        {
            if (y < 0 || y >= H || x < 0 || x >= W) return false;
            return M[y, x] == '#';
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