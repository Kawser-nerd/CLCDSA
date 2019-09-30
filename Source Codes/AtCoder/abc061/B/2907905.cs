using System;
using System.Collections.Generic;
using System.Linq;

namespace arugo
{
    class Program
    {
        static void Main(string[] args)
        {
            var NM = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
            var N = NM[0];
            var M = NM[1];
            var d = new int[N];
            for (var i = 0; i < M; i++)
            {
                var ab = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
                d[ab[0] - 1]++;
                d[ab[1] - 1]++;
            }
            foreach (var D in d)
                Console.WriteLine(D);
        }
    }
}