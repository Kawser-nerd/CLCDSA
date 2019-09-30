using System;
using System.Linq;

namespace arc023_2
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[,] ban = new int[x[0], x[1]];
            for (int i = 0; i < x[0]; i++)
            {
                int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
                for (int j = 0; j < x[1]; j++) ban[i, j] = a[j];
            }
            int ret = int.MinValue;
            for (int i = 0; i < x[0]; i++)
            {
                for (int j = 0; j < x[1]; j++)
                {
                    if (i + j <= x[2] && (i + j) % 2 == x[2] % 2) ret = Math.Max(ret, ban[i, j]);
                }
            }
            Console.WriteLine(ret);
        }
    }
}