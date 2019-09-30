using System;

namespace agc003_c
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] x = new int[n]; int[] a = new int[n];
            for (int i = 0; i < n; i++)
            {
                x[i] = int.Parse(Console.ReadLine());
                a[i] = i;
            }
            Array.Sort(x,a);
            int ret = 1;
            for (int i = 0; i < n; i++) if (Math.Abs(a[i] - i) % 2 == 1) ret++;
            Console.WriteLine(ret / 2);
        }
    }
}