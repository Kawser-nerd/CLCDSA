using System;
using System.Linq;

namespace arc037_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int ret = 0;
            for (int i = 0; i < n; i++)
            {
                if (x[i] < 80)
                {
                    ret += 80 - x[i];
                }
            }
            Console.WriteLine(ret);
        }
    }
}