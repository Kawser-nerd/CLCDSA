using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp
{
    class Program
    {
        static List<string> perms = new List<string>();

        static void Main(string[] args)
        {
            var strs = Console.ReadLine().Split();
            var N = int.Parse(strs[0]);
            var M = int.Parse(strs[1]);
            var X = int.Parse(strs[2]);
            var Y = int.Parse(strs[3]);

            var x = new int[N];
            var y = new int[M];

            strs = Console.ReadLine().Split();
            for (int i = 0; i < N; i++) x[i] = int.Parse(strs[i]);

            strs = Console.ReadLine().Split();
            for (int i = 0; i < M; i++) y[i] = int.Parse(strs[i]);

            if (Math.Max(X, x.Max()) < Math.Min(Y, y.Min()))
                Console.WriteLine("No War");
            else
                Console.WriteLine("War");
        }
    }
}