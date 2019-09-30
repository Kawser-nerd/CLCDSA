using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication4
{
    class Program
    {
        static void Main(string[] args)
        {
            // ?????
            int N = int.Parse(Console.ReadLine());
            // ?????????????
            int[][] D = new int[N][];
            int i, j;
            for (i = 0; i < N; i++) D[i] = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            // ?????
            int Q = int.Parse(Console.ReadLine());
            int[] P = new int[Q];
            for (i = 0; i < Q; i++) P[i] = int.Parse(Console.ReadLine());

            //???????????
            int[] max1 = new int[N * N];
            for (i = 0; i < N * N; i++)
            {
                max1[i] = 0;
            }
            int x, y, l, h, val1 = 0, k,q;

            for (x = 0; x < N; x++)
            {
                for (y = 0; y < N; y++)
                {
                    for (l = 1; l < (N - x + 1); l++)
                    {
                        for (h = 1; h < (N - y + 1); h++)
                        {
                            val1 = 0;
                            //for (k = 0; k < l * h; k++)
                            //{
                            //    val1 = val1 + D[x + l - 1][y + h - 1];
                            //}
                            for (k = 0; k < l; k++)
                            {
                                for (q = 0; q < h; q++)
                                {
                                    val1 = val1 + D[x + k][y + q];
                                }
                            }
                            if (val1 > max1[l * h - 1]) max1[l * h - 1] = val1;
                        }
                    }
                }
            }
            for (i = 0; i < Q; i++)
            {
                int max_p = 0;
                for (j = 0; j < P[i]; j++)
                {
                    if (max1[j] > max_p) max_p = max1[j];
                }
                Console.WriteLine(max_p);
            }
        }
    }
}