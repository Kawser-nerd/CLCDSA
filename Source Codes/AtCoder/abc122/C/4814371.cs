using System;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = ReadArrayInt();
            var N = input[0];
            var Q = input[1];
            var S = Read();
            var cnt = new int[N + 1];
            var max = 0;
            for (int i = 0; i < N - 1; i++)
            {
                if (S[i] == 'A' && S[i + 1] == 'C')
                {
                    cnt[i + 1] = cnt[i] + 1;
                    max++;
                }
                else cnt[i + 1] = cnt[i];
            }
            for (int i = 0; i < Q; i++)
            {
                input = ReadArrayInt();
                var l = input[0];
                var r = input[1];
                var ans = cnt[r - 1] - cnt[l - 1];
                Console.WriteLine(ans);
            }

            Console.WriteLine();
            Console.ReadLine();
        }

        static string Read() { return Console.ReadLine(); }
        static int ReadInt() { return int.Parse(Read()); }
        static long ReadLong() { return long.Parse(Read()); }
        static int[] ReadArrayInt() { return Read().Split(' ').Select(s => int.Parse(s)).ToArray(); }
        static long[] ReadArrayLong() { return Read().Split(' ').Select(s => long.Parse(s)).ToArray(); }
    }
}