using System;
using System.Linq;

namespace abc012_4
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
                    d[i, j] = 10000000;
                }
            }
            for (int i = 0; i < x[1]; i++)
            {
                int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
                a[0]--; a[1]--;
                d[a[0], a[1]] = a[2]; d[a[1], a[0]] = a[2];
            }
            for (int k = 0; k < x[0]; k++)
            {
                for (int i = 0; i < x[0]; i++)
                {
                    for (int j = 0; j < x[0]; j++)
                    {
                        d[i, j] = Math.Min(d[i, j], d[i, k] + d[k, j]);
                    }
                }
            }
            int min = int.MaxValue;
            for (int i = 0; i < x[0]; i++)
            {
                int now = 0;
                for (int j = 0; j < x[0]; j++) now = Math.Max(now, d[i, j]);
                min = Math.Min(min, now);
            }
            Console.WriteLine(min);
        }
    }
}