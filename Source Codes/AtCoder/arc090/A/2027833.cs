using System;
using System.Linq;

namespace arc090_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] x1 = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] x2 = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int ret = x1[0] + x2.Sum();
            int b = ret;
            for (int i = 1; i < n; i++)
            {
                int a = b - x2[i - 1] + x1[i];
                ret = Math.Max(ret,a);
                b = a;
            }
            Console.WriteLine(ret);
        }
    }
}