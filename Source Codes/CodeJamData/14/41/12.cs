using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Numerics;

namespace A
{
    class Program
    {
        static int Solve(int X, int[] S)
        {
            int N = S.Length;
            Array.Sort(S);

            int p = 0;
            int q = N - 1;

            int total = 0;
            while (q >= p)
            {
                total++;
                if (p != q && S[p] + S[q] <= X)
                    p++;
                q--;
            }

            return total;
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                string[] line = Console.ReadLine().Split();
                int N = int.Parse(line[0]);
                int X = int.Parse(line[1]);
                int[] S = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
                Console.WriteLine("Case #{0}: {1}", t, Solve(X, S));
            }
        }
    }
}
