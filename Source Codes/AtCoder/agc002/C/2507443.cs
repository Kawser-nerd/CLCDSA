using System;
using System.Linq;

namespace agc002_c
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
            bool flag = true;
            for (int i = 1; i < x[0] && flag; i++)
            {
                if (a[i - 1] + a[i] >= x[1])
                {
                    flag = false;
                    Console.WriteLine("Possible");
                    for (int j = 1; j < i; j++) Console.WriteLine(j);
                    for (int j = x[0] - 1; j >= i; j--) Console.WriteLine(j);
                }
            }
            if (flag) Console.WriteLine("Impossible");
        }
    }
}