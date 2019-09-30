using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine();
            var strs = str.Split(' ');
            var N = int.Parse(strs[0]);
            var K = int.Parse(strs[1]);

            var h = new int[N];
            for (int i = 0; i < N; i++)
            {
                h[i] = int.Parse(Console.ReadLine());
            }

            Array.Sort(h);

            var diff = new List<int>();
            for (int i = 0; i + K - 1 < N; i++)
            {
                diff.Add(h[i + K - 1] - h[i]);
            }

            Console.WriteLine(diff.Min());
        }
    }
}