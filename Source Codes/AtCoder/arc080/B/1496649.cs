using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtCoder
{
    class Program
    {
        private static int[][] Solve(int H, int W, int[] A)
        {
            int[][] C = new int[H][];
            for (int i = 0; i < H; ++i) { C[i] = new int[W]; }
            int c = 0;
            for (int i = 0; i < H * W; ++i)
            {
                while (A[c] == 0) { ++c; }
                int h = i / W;
                int w = (h % 2 == 0) ? i % W : W - i % W - 1;
                C[h][w] = c + 1;
                --A[c];
            }
            return C;
        }
        static void Main(string[] args)
        {
            int[] values = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int N = int.Parse(Console.ReadLine());
            int[] A = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            foreach (int[] c in Solve(values[0], values[1], A))
            {
                Console.WriteLine(string.Join(" ", c));
            }
        }
    }
}