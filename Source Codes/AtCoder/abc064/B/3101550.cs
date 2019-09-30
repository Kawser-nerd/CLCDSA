using System;
using System.Linq;

namespace Sample101
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int[] a = Console.ReadLine()
                .Split(' ')
                .Select(s => int.Parse(s))
                .ToArray();
            Array.Sort(a);

            int result = 0;
            for (int i = 0; i < a.Length - 1; ++i)
            {
                result += a[i + 1] - a[i];
            }
            Console.WriteLine(result);
        }
    }
}