using System;
using System.Linq;

namespace arc020_2
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] a = new int[x[0]];
            for (int i = 0; i < x[0]; i++) a[i] = int.Parse(Console.ReadLine());
            int ret = int.MaxValue;
            for (int i = 1; i <= 10; i++)
            {
                for (int j = 1; j <= 10; j++)
                {
                    if (i == j) continue;
                    int now = 0;
                    for (int k = 0; k < x[0]; k++)
                    {
                        if (k % 2 == 0) { if (a[k] != i) now += x[1]; }
                        else { if (a[k] != j) now += x[1]; }
                    }
                    ret = Math.Min(ret,now);
                }
            }
            Console.WriteLine(ret);
        }
    }
}