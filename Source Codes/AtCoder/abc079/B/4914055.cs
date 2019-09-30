using System;
using System.Collections.Generic;

namespace B___Lucas_Number
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());

            Console.WriteLine(Lucas(N));
        }

        static long Lucas(int n)
        {
            var res = new List<long> { 2, 1 };

            for (int i = 1; i < n; i++)
            {
                res.Add(res[i] + res[i - 1]);
            }
            return res[n];
        }
    }
}