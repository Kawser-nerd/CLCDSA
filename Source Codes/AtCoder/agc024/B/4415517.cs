using System;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = ReadInt();
            var P = Enumerable.Repeat(0, N).Select(i => ReadInt()).ToArray();
            var Q = new int[N];
            for (int i = 0; i < N; i++) Q[P[i] - 1] = i;
            var ans = 0;
            var cnt = 0;
            var chk = -1;
            for (int i = 0; i < N; i++)
            {
                if (Q[i] > chk)
                {
                    cnt++;
                    chk = Q[i];
                }
                else
                {
                    if (cnt > ans) ans = cnt;
                    cnt = 1;
                    chk = Q[i];
                }
            }
            if (cnt > ans) ans = cnt;

            Console.WriteLine(N - ans);
            Console.ReadLine();
        }

        static string Read() { return Console.ReadLine(); }
        static int ReadInt() { return int.Parse(Read()); }
        static long ReadLong() { return long.Parse(Read()); }
        static int[] ReadArrayInt() { return Read().Split(' ').Select(s => int.Parse(s)).ToArray(); }
        static long[] ReadArrayLong() { return Read().Split(' ').Select(s => long.Parse(s)).ToArray(); }
    }
}