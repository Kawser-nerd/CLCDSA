using System;
using System.Linq;

namespace arc079_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            x[0]++;
            bool[,] d = new bool[x[0], 2];
            for (int i = 0; i < x[1]; i++)
            {
                int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
                Array.Sort(a);
                if (a[0] == 1) d[a[1], 0] = true;
                if (a[1] == x[0] - 1) d[a[0], 1] = true;
            }
            bool ret = false;
            for (int i = 0; i < x[0]; i++)
            {
                if (d[i, 0] && d[i, 1]) ret = true;
            }
            Console.WriteLine(ret ? "POSSIBLE" : "IMPOSSIBLE");
        }
    }
}