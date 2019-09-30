using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtCoder
{
    class Program
    {
        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }

        static int Solve(int N)
        {
            var primes = new List<int>();
            for (int i = 2; i < 100; ++i)
            {
                if (primes.All(prime => i % prime != 0)) { primes.Add(i); }
            }
            var factors = new Dictionary<int, int>();
            for (int i = 2; i <= N; ++i)
            {
                int j = i;
                foreach (int prime in primes)
                {
                    if (j < prime) { break; }
                    while (j % prime == 0)
                    {
                        j /= prime;
                        if (!factors.ContainsKey(prime)) { factors[prime] = 0; }
                        ++factors[prime];
                    }
                }
            }
            var values = factors.Values.ToArray();
            int ans = 0;
            int C = values.Length;
            for (int i = 0; i < C; ++i)
            {
                int x = values[i];
                if (x >= 74) { ++ans; }
                for (int j = i + 1; j < C; ++j)
                {
                    int y = values[j];
                    if (x >= 4 && y >= 14) { ++ans; }
                    if (x >= 14 && y >= 4) { ++ans; }
                    if (x >= 2 && y >= 24) { ++ans; }
                    if (x >= 24 && y >= 2) { ++ans; }
                    for (int k = j + 1; k < C; ++k)
                    {
                        int z = values[k];
                        if (x >= 2 && y >= 4 && z >= 4) { ++ans; }
                        if (x >= 4 && y >= 2 && z >= 4) { ++ans; }
                        if (x >= 4 && y >= 4 && z >= 2) { ++ans; }
                    }
                }
            }
            return ans;
        }

        static void Main(string[] args)
        {
            Console.WriteLine(Solve(ReadInt()));
        }
    }
}