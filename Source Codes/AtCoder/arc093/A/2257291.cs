using System;
using System.Linq;

namespace arc093_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] sa = new int[n + 1];
            sa[0] = Math.Abs(x[0]);
            for (int i = 1; i < n; i++)
            {
                sa[i] = Math.Abs(x[i - 1] - x[i]);
            }
            sa[n] = Math.Abs(x[n - 1]);
            long sum = sa.Sum();
            Console.WriteLine(sum - (sa[0] + sa[1]) + Math.Abs(x[1]));
            for (int i = 2; i <= n - 1; i++)
            {
                Console.WriteLine(sum - (sa[i - 1] + sa[i]) + Math.Abs(x[i - 2] - x[i]));
            }
            Console.WriteLine(sum - (sa[n - 1] + sa[n]) + Math.Abs(x[n - 2]));
        }
    }
}