using System;
using System.Linq;

namespace arc095_b
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int max = x.Max(); int ret = 0; int nearest = int.MaxValue;
            for (int i = 0; i < n; i++)
            {
                if (x[i] != max && nearest > Math.Abs(max - (x[i] * 2)))
                {
                    nearest = Math.Abs(max - (x[i] * 2));
                    ret = x[i];
                }
            }
            Console.WriteLine(max + " " + ret);
        }
    }
}