using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Numerics;

namespace B
{
    class Program
    {
        static int N;
        static int[] A;
        static int[] perm;
        static int[] perm_i;
        static bool[] used;
        static int best;

        static void Permute(int p)
        {
            if (p == N)
            {
                bool good = true;
                bool up = true;
                for (int i = 1; good && i < N; i++)
                {
                    if (up && A[perm[i]] < A[perm[i - 1]])
                    {
                        up = false;
                    }
                    else if (!up && A[perm[i]] > A[perm[i - 1]])
                    {
                        good = false;
                    }
                }

                if (good)
                {
                    for (int i = 0; i < N; i++)
                        perm_i[perm[i]] = i;

                    int total = 0;
                    for (int i = 0; i < N; i++)
                    {
                        for (int j = 0; j < i; j++)
                        {
                            if (perm_i[j] > perm_i[i])
                                total++;
                        }
                    }

                    best = Math.Min(best, total);
                }

                return;
            }

            for (int i = 0; i < N; i++)
            {
                if (!used[i])
                {
                    used[i] = true;
                    perm[p] = i;
                    Permute(p + 1);
                    used[i] = false;
                }
            }
        }

        static int Solve()
        {
            used = new bool[N];
            perm = new int[N];
            perm_i = new int[N];
            best = int.MaxValue;
            Permute(0);

            return best;
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                N = int.Parse(Console.ReadLine());
                A = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
                Console.WriteLine("Case #{0}: {1}", t, Solve());
            }
        }
    }
}
