using System;
using System.Linq;

namespace arc038_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            Array.Sort(x);
            Array.Reverse(x);
            int a = 0;
            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                {
                    a += x[i];
                }
            }
            Console.WriteLine(a);
        }
    }
}