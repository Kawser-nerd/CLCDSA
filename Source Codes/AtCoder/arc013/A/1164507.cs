using System;
using System.Linq;

namespace arc013_1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] b = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int max = 0;
            if (a[0] / b[0] > 0 && a[1] / b[1] > 0 && a[2] / b[2] > 0)
            {
                max = Math.Max(max, (a[0] / b[0]) * (a[1] / b[1]) * (a[2] / b[2]));
            }
            if (a[0] / b[0] > 0 && a[1] / b[2] > 0 && a[2] / b[1] > 0)
            {
                max = Math.Max(max, (a[0] / b[0]) * (a[1] / b[2]) * (a[2] / b[1]));
            }
            if (a[0] / b[1] > 0 && a[1] / b[0] > 0 && a[2] / b[2] > 0)
            {
                max = Math.Max(max, (a[0] / b[1]) * (a[1] / b[0]) * (a[2] / b[2]));
            }
            if (a[0] / b[1] > 0 && a[1] / b[2] > 0 && a[2] / b[0] > 0)
            {
                max = Math.Max(max, (a[0] / b[1]) * (a[1] / b[2]) * (a[2] / b[0]));
            }
            if (a[0] / b[2] > 0 && a[1] / b[0] > 0 && a[2] / b[1] > 0)
            {
                max = Math.Max(max, (a[0] / b[2]) * (a[1] / b[0]) * (a[2] / b[1]));
            }
            if (a[0] / b[2] > 0 && a[1] / b[1] > 0 && a[2] / b[0] > 0)
            {
                max = Math.Max(max, (a[0] / b[2]) * (a[1] / b[1]) * (a[2] / b[0]));
            }
            Console.WriteLine(max);
        }
    }
}