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
            var S = Read();
            var cnt = new Dictionary<char, int>();
            for (char c = 'a'; c <= 'z'; c++) cnt.Add(c, 0);
            for (int i = 0; i < N; i++) cnt[S[i]]++;
            int mod = (int)Math.Pow(10, 9) + 7;
            var ans = 1L;
            foreach(var c in cnt)
            {
                if (c.Value > 0)
                {
                    ans *= (c.Value + 1);
                    ans %= mod;
                }
            }
            ans--;

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