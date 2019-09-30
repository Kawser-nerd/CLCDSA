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
        static BigInteger toPay(long dist, long N)
        {
            if (dist == 0)
                return 0;

            BigInteger sum = N * dist;
            BigInteger discount = dist * (dist - 1) / 2;
            return sum - discount;
        }

        static BigInteger Solve(int N, int M, int[] o, int[] e, int[] p)
        {
            SortedSet<int> stops = new SortedSet<int>();
            for (int i = 0; i < M; i++)
            {
                stops.Add(o[i]); stops.Add(e[i]);
            }

            Dictionary<int, long> joined = new Dictionary<int, long>();
            Dictionary<int, long> left = new Dictionary<int, long>();

            foreach (var stop in stops)
            {
                joined[stop] = 0;
                left[stop] = 0;
            }

            for (int i = 0; i < M; i++)
            {
                joined[o[i]] += p[i];
                left[e[i]] += p[i];
            }

            SortedDictionary<int, long> joinedAt = new SortedDictionary<int, long>();
            BigInteger payed = 0;

            foreach (var stop in stops)
            {
                long delta = joined[stop] - left[stop];

                if (delta > 0)
                {
                    joinedAt[-stop] = delta;
                }
                else if(delta < 0)
                {
                    delta = -delta;
                    var keys = joinedAt.Keys.ToList();
                    foreach (var key in keys)
                    {
                        if (delta == 0)
                            break;

                        int entered = -key;
                        long passangers = Math.Min(joinedAt[key], delta);
                        joinedAt[key] -= passangers;
                        delta -= passangers;

                        int traveled = stop - entered;

                        BigInteger tmp = toPay(traveled, N);
                        tmp *= passangers;

                        payed += tmp;
                    }
                }
            }


            BigInteger mustpay = 0;
            for (int i = 0; i < M; i++)
            {
                BigInteger tmp = toPay(e[i] - o[i], N);
                tmp *= p[i];
                mustpay += tmp;
            }

            return (mustpay - payed) % 1000002013;
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                string[] line = Console.ReadLine().Split();
                int N = int.Parse(line[0]);
                int M = int.Parse(line[1]);

                int[] o = new int[M];
                int[] e = new int[M];
                int[] p = new int[M];

                for (int i = 0; i < M; i++)
                {
                    line = Console.ReadLine().Split();
                    o[i] = int.Parse(line[0]);
                    e[i] = int.Parse(line[1]);
                    p[i] = int.Parse(line[2]);
                }

                Console.WriteLine("Case #{0}: {1}", t, Solve(N, M, o, e, p));
            }
        }
    }
}
