using System;
using System.Linq;

namespace arc013_2
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] a = new int[n];
            int[] b = new int[n];
            int[] c = new int[n];
            for (int i = 0; i < n; i++)
            {
                int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
                Array.Sort(x);
                a[i] = x[0]; b[i] = x[1]; c[i] = x[2];
            }
            Console.WriteLine(a.Max() * b.Max() * c.Max());
        }
    }
}