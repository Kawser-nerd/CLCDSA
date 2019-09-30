using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N;
        public List<List<int>> D;
        public void Run()
        {
            // Input
            N = Input.ReadInt();

            D = new List<List<int>>();
            for (int i = 0; i < N; i++)
            {
                D.Add(new List<int>());
            }

            for (int i = 1; i < N; i++)
            {
                var w = Input.ReadInt() - 1;
                int l = i;
                D[w].Add(l);
            }

            int ret = Depth(0);
            Console.WriteLine(ret);
        }

        public int Depth(int i)
        {
            int c = D[i].Count;
            if (c == 0) return 0;
            if (c == 1) return Depth1(i);
             
            int[] depths = new int[c];
            for (int j = 0; j < c; j++)
            {
                depths[j] = Depth(D[i][j]);
            }

            Array.Sort(depths);

            for (int d = 0; d < c; d++)
            {
                depths[d] += (c - d);
            }

            int ret = 0;
            for (int d = 0; d < c; d++)
            {
                ret = Math.Max(ret, depths[d]);
            }

            return ret;
        }

        public int Depth1(int i)
        {
            return Depth(D[i][0]) + 1;
        }
    }


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