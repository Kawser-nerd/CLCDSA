using System;
using System.Linq;

namespace arc095_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] y = new int[n];
            for (int i = 0; i < n; i++) y[i] = x[i];
            Array.Sort(x);
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine(x[n / 2 - 1] < y[i] ? x[n / 2 - 1] : x[n / 2]);
            }
        }
    }
}