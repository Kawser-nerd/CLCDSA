using System;
using System.Linq;

namespace abc079_d
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[,] d = new int[10, 10];
            for (int i = 0; i < 10; i++)
            {
                int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
                for (int j = 0; j < 10; j++)
                {
                    d[i, j] = a[j];
                }
            }
            for (int k = 0; k < 10; k++)
            {
                for (int i = 0; i < 10; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        d[i, j] = Math.Min(d[i, j], d[i, k] + d[k, j]);
                    }
                }
            }
            int ret = 0;
            for (int i = 0; i < x[0]; i++)
            {
                int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
                for (int j = 0; j < x[1]; j++)
                {
                    if (a[j] >= 0) ret += d[a[j], 1];
                }
            }
            Console.WriteLine(ret);
        }
    }
}