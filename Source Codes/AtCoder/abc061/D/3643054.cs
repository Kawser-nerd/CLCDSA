using System;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = ReadArrayLong();
            var N = input[0];
            var M = input[1];
            var inf = long.MaxValue;
            var sides = new long[M, 3];
            var dis = Enumerable.Repeat(inf, (int)N + 1).ToArray();
            for (int i = 0; i < M; i++)
            {
                input = ReadArrayLong();
                sides[i, 0] = input[0];
                sides[i, 1] = input[1];
                sides[i, 2] = -input[2];
            }
            dis[1] = 0;
            for (int i = 0; i < N - 1; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    if (dis[sides[j, 0]] != inf && dis[sides[j, 1]] > dis[sides[j, 0]] + sides[j, 2])
                    {
                        dis[sides[j, 1]] = dis[sides[j, 0]] + sides[j, 2];
                    }
                }
            }
            var ans = -dis[N];
            var neg = new bool[N + 1];
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    if (dis[sides[j, 0]] != inf && dis[sides[j, 1]] > dis[sides[j, 0]] + sides[j, 2])
                    {
                        dis[sides[j, 1]] = dis[sides[j, 0]] + sides[j, 2];
                        neg[sides[j, 1]] = true;
                    }
                    if (neg[sides[j, 0]] == true) neg[sides[j, 1]] = true;
                }
            }

            Console.WriteLine(neg[N] ? "inf" : ans.ToString());
            Console.ReadLine();
        }

        static string Read() { return Console.ReadLine(); }
        static int ReadInt() { return int.Parse(Read()); }
        static long ReadLong() { return long.Parse(Read()); }
        static int[] ReadArrayInt() { return Read().Split(' ').Select(s => int.Parse(s)).ToArray(); }
        static long[] ReadArrayLong() { return Read().Split(' ').Select(s => long.Parse(s)).ToArray(); }
    }
}