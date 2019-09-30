using System;
using System.Linq;

namespace arc_013_A
{
    class Program
    {
        static void Main(string[] args)
        {
            int max = 0;
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] b = Console.ReadLine().Split().Select(int.Parse).ToArray();
            max = Math.Max(max, (a[0] / b[0]) * (a[1] / b[1]) * (a[2] / b[2]));
            max = Math.Max(max, (a[0] / b[0]) * (a[2] / b[1]) * (a[1] / b[2]));
            max = Math.Max(max, (a[1] / b[0]) * (a[0] / b[1]) * (a[2] / b[2]));
            max = Math.Max(max, (a[1] / b[0]) * (a[2] / b[1]) * (a[0] / b[2]));
            max = Math.Max(max, (a[2] / b[0]) * (a[0] / b[1]) * (a[1] / b[2]));
            max = Math.Max(max, (a[2] / b[0]) * (a[1] / b[1]) * (a[0] / b[2]));
            Console.WriteLine(max);
        }
    }
}