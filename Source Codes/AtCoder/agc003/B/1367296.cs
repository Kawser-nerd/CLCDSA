using System;

namespace agc003_b
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = int.Parse(Console.ReadLine());
            }
            ulong x = 0;
            x += (ulong)a[0] / 2;
            a[0] = a[0] % 2;
            for (int i = 1; i < n; i++)
            {
                if (a[i - 1] == 1 && a[i] > 0)
                {
                    a[i]--;
                    a[i - 1]--;
                    x++;
                }
                x += (ulong)a[i] / 2;
                a[i] = a[i] % 2;
            }
            Console.WriteLine(x);
        }
    }
}