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
            var e = new int[101];
            for (int i = N; i >= 2; i--)
            {
                var chk = 2;
                var rem = i;
                while (rem > 1)
                {
                    if (rem % chk == 0)
                    {
                        e[chk]++;
                        rem /= chk;
                    }
                    else
                    {
                        chk++;
                    }
                }
            }
            var sortE = new List<int>[5];
            for (int i = 0; i < 5; i++) sortE[i] = new List<int>();
            for (int i = 0; i < e.Length; i++)
            {
                if (e[i] >= 74) sortE[0].Add(i);
                if (e[i] >= 24) sortE[1].Add(i);
                if (e[i] >= 14) sortE[2].Add(i);
                if (e[i] >= 4) sortE[3].Add(i);
                if (e[i] >= 2) sortE[4].Add(i);
            }
            var ans = sortE[0].Count;
            if (sortE[1].Count > 0 && sortE[4].Count > 1) ans += sortE[1].Count * (sortE[4].Count - 1);
            if (sortE[2].Count > 0 && sortE[3].Count > 1) ans += sortE[2].Count * (sortE[3].Count - 1);
            if (sortE[3].Count > 1 && sortE[4].Count > 2) ans += (int)nCr(sortE[3].Count, 2) * (sortE[4].Count - 2);
            
            Console.WriteLine(ans);
            Console.ReadLine();
        }

        static long Factorial(long num) { if (num == 0) return 1L; return num * Factorial(num - 1); }
        static long nCr(long n, long r) { return Factorial(n) / Factorial(r) / Factorial(n - r); }

        static string Read() { return Console.ReadLine(); }
        static int ReadInt() { return int.Parse(Read()); }
        static long ReadLong() { return long.Parse(Read()); }
        static int[] ReadArrayInt() { return Read().Split(' ').Select(s => int.Parse(s)).ToArray(); }
        static long[] ReadArrayLong() { return Read().Split(' ').Select(s => long.Parse(s)).ToArray(); }
    }
}