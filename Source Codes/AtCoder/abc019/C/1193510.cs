using System;
using System.Linq;

namespace abc019_3
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            for (int i = 0; i < n; i++)
            {
                while (x[i] % 2 == 0)
                {
                    x[i] /= 2;
                }
            }
            x = x.Distinct().ToArray();
            Console.WriteLine(x.Count());
        }
    }
}