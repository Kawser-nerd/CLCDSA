using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Runtime;

namespace b
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());

            int[] p = new int[n];
            for (int i = 0; i < n; i++)
            {
                p[i] = int.Parse(Console.ReadLine());
            }

            int[] memo = new int[n + 1];
            for (int i = 0; i < n; i++)
            {
                if (memo[p[i] - 1] == 0)
                {
                    memo[p[i]] = 1;
                    continue;
                }
                memo[p[i]] = memo[p[i] - 1] + 1;
            }

            Console.WriteLine(n - memo.Max());
        }
    }
}