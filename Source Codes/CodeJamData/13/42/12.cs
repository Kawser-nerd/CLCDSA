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
        static string Solve(int N, int P)
        {
            int x, y;

            if (P == (1 << N))
            {
                x = (1 << N) - 1;
                y = (1 << N) - 1;
                return string.Format("{0} {1}", x, y);
            }

            int l = 0, r = (1 << N) - 1;
            while (r - l > 1)
            {
                int m = (l + r) / 2;

                int prises = P;
                bool ok = false;
                int half = (1 << (N - 1));
                int aboves = m;

                for (int i = 0; i < N; i++)
                {
                    if (aboves == 0 && prises > 0)
                    {
                        ok = true;
                        break;
                    }

                    prises -= half;
                    half = half / 2;
                    aboves = (aboves - 1) / 2;

                    if (prises == 0)
                        break;
                }

                if (ok)
                    l = m;
                else
                    r = m;
            }
            x = l;

            l = 0; r = (1 << N) - 1;
            while (r - l > 1)
            {
                int m = (l + r) / 2;

                int aboves = m;
                int pool = (1 << N);
                int prises = P;
                bool ok = false;

                for (int i = 0; i < N; i++)
                {
                    if (prises >= aboves + 1)
                    {
                        ok = true;
                        break;
                    }

                    if (aboves + 1 < pool)
                    {
                        aboves = (1 + aboves) / 2;
                    }
                    else
                    {
                        ok = prises >= pool;
                        break;
                    }

                    pool = pool / 2;
                }

                if (ok)
                    l = m;
                else
                    r = m;
            }
            y = l;

            return string.Format("{0} {1}", x, y);
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                string[] line = Console.ReadLine().Split();
                int N = int.Parse(line[0]);
                int P = int.Parse(line[1]);
                Console.WriteLine("Case #{0}: {1}", t, Solve(N, P));
            }
        }
    }
}
