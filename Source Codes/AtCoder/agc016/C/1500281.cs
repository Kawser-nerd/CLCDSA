using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtCoder
{
    class Program
    {
        private static int[][] Solve(int H, int W, int h, int w)
        {
            if (h * w == 1) { return null; }
            int[][] matrix = new int[H][];
            long sum = 0;
            int n = 999999999 / (h * w - 1);
            for (int i = 0; i < H; ++i)
            {
                matrix[i] = new int[W];
                for (int j = 0; j < W; ++j)
                {
                    int value = (i % h == h - 1 && j % w == w - 1) ? -1000000000 : n;
                    matrix[i][j] = value;
                    sum += value;
                }
            }
            return (sum > 0) ? matrix : null;
        }
        static void Main(string[] args)
        {
            int[] values = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            var matrix = Solve(values[0], values[1], values[2], values[3]);
            if (matrix != null)
            {
                Console.WriteLine("Yes");
                foreach (int[] row in matrix) { Console.WriteLine(string.Join(" ", row)); }
            }
            else
            {
                Console.WriteLine("No");
            }
        }
    }
}