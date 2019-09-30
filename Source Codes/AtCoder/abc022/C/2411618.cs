using System;
using System.Linq;

namespace abc022_c
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[,] d = new int[x[0], x[0]];
            for (int i = 0; i < x[0]; i++)
            {
                for (int j = 0; j < x[0]; j++)
                {
                    if (i == j) continue;
                    d[i, j] = 100000000;
                }
            }
            for (int i = 0; i < x[1]; i++)
            {
                int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
                a[0]--; a[1]--;
                d[a[0], a[1]] = a[2]; d[a[1], a[0]] = a[2];
            }
            int[,] e = new int[x[0], x[0]];
            for (int i = 0; i < x[0]; i++)
            {
                for (int j = 0; j < x[0]; j++)
                {
                    e[i, j] = d[i, j];
                }
            }
            for (int k = 1; k < x[0]; k++)
            {
                for (int i = 1; i < x[0]; i++)
                {
                    for (int j = 1; j < x[0]; j++)
                    {
                        e[i, j] = Math.Min(e[i, j], e[i, k] + e[k, j]);
                    }
                }
            }
            long min = long.MaxValue;
            for (int i = 1; i < x[0]; i++)
            {
                for (int j = i + 1; j < x[0]; j++)
                {
                    min = Math.Min(min, d[0, i] + e[i, j] + d[j, 0]);
                }
            }
            Console.WriteLine(min < 100000000 ? min : -1);
        }
    }
}