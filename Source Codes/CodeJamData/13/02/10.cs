using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace B
{
    class Program
    {
        static bool Solve(int[][] a)
        {
            int N = a.Length;
            int M = a[0].Length;

            int[] rowmax = new int[N];
            int[] colmax = new int[M];

            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                {
                    rowmax[i] = Math.Max(rowmax[i], a[i][j]);
                    colmax[j] = Math.Max(colmax[j], a[i][j]);
                }


            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                    if (a[i][j] != rowmax[i] && a[i][j] != colmax[j])
                        return false;

            return true;
        }

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                string[] line = Console.ReadLine().Split();
                int N = int.Parse(line[0]);
                int M = int.Parse(line[1]);
                int[][] a = new int[N][];

                for (int i = 0; i < N; i++)
                    a[i] = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);

                Console.WriteLine("Case #{0}: {1}", t, Solve(a) ? "YES" : "NO");
            }
        }
    }
}
