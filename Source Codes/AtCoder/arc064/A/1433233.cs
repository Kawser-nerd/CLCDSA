using System;
using System.Linq;

namespace arc064_a
{
    class Program
    {
        static void Main(string[] args)
        {
            long ret = 0;
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
            if (x[1] < a[0])
            {
                ret += a[0] - x[1];
                a[0] = x[1];
            }
            for (int i = 1; i < x[0]; i++)
            {
                if (x[1] < a[i - 1] + a[i])
                {
                    ret += a[i - 1] + a[i] - x[1];
                    a[i] = x[1] - a[i - 1];
                }
            }
            Console.WriteLine(ret);
        }
    }
}