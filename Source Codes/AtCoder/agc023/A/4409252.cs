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
            var A = ReadArrayInt();
            var S = new long[N + 1];
            for (int i = 0; i < N; i++) S[i + 1] = S[i] + A[i];
            var ans = 0L;
            Array.Sort(S);
            var idx = 0;
            while (idx < N + 1)
            {
                var cnt = 0;
                var num = S[idx];
                idx++;
                while (idx < N + 1 && num == S[idx])
                {
                    cnt++;
                    idx++;
                }
                while (cnt > 0)
                {
                    ans += cnt;
                    cnt--;
                }
            }

            Console.WriteLine(ans);
            Console.ReadLine();
        }

        static string Read() { return Console.ReadLine(); }
        static int ReadInt() { return int.Parse(Read()); }
        static long ReadLong() { return long.Parse(Read()); }
        static int[] ReadArrayInt() { return Read().Split(' ').Select(s => int.Parse(s)).ToArray(); }
        static long[] ReadArrayLong() { return Read().Split(' ').Select(s => long.Parse(s)).ToArray(); }
    }
}