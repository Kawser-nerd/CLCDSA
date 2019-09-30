using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemBBig
{
    class Program
    {
        static int N;
        static int[] X;
        static int[] Y;

        static void Main(string[] args)
        {
            int T = Convert.ToInt32(Console.ReadLine());
            for (int t = 1; t <= T; ++t)
            {
                N = Convert.ToInt32(Console.ReadLine());
                X = new int[N - 1];
                Y = new int[N - 1];
                for (int n = 0; n < N - 1; ++n)
                {
                    var XY = Console.ReadLine().Split(' ').Select(token => Convert.ToInt32(token)).ToArray();
                    X[n] = XY[0] - 1;
                    Y[n] = XY[1] - 1;
                }
                int maxW = 0;
                for (int r = 0; r < N; ++r)
                    maxW = Math.Max(maxW, Weigh(-1, r));
                Console.WriteLine("Case #{0}: {1}", t, N - maxW);
            }
        }

        static int Weigh(int p, int n)
        {
            var cl = (from e in Enumerable.Range(0, N - 1) where X[e] == n && Y[e] != p select Y[e]).Concat(from e in Enumerable.Range(0, N - 1) where Y[e] == n && X[e] != p select X[e]).ToList();
            if (cl.Count < 2)
                return 1;
            return (from c in cl let w = Weigh(n, c) orderby w descending select w).Take(2).Sum() + 1;
        }
    }
}
