using System;
using System.Linq;
using System.Collections.Generic;

namespace AtCoder
{
    class Program
    {
        public static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(' ');
            int N = int.Parse(s[0]);
            int M = int.Parse(s[1]);
            int[] X = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).OrderBy(x => x).ToArray();
            int[] Xs = new int[M - 1];
            for (int i = 0; i < Xs.Length; i++)
            {
                Xs[i] = X[i + 1] - X[i];
            }
            Xs = Xs.OrderBy(x => x).ToArray();
            int res = 0;
            for (int i = 0; i < M - N; i++)
            {
                res += Xs[i];
            }
            Console.WriteLine(res);
        }
    }
}