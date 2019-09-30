using System;
using System.Linq;

namespace agc014_b
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] n = new int[x[0]];
            for (int i = 0; i < x[1]; i++)
            {
                int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
                n[a[0] - 1]++; n[a[1] - 1]++;
            }
            bool ok = true;
            for (int i = 0; i < x[0]; i++)
            {
                if (n[i] % 2 == 1) ok = false;
            }
            Console.WriteLine(ok ? "YES" : "NO");
        }
    }
}