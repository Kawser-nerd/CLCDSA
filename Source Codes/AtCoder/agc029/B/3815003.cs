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

        static int Partner(int n)
        {
            long N = 2;
            while (N <= n) { N <<= 1; }
            return (int)(N - n);
        }

        static int Solve(int N, int[] A)
        {
            var counts = new Dictionary<int, int>();
            foreach (int a in A)
            {
                if (!counts.ContainsKey(a)) { counts[a] = 0; }
                ++counts[a];
            }
            int ans = 0;
            foreach (int i in counts.Keys.OrderByDescending(i => i).ToArray())
            {
                int j = Partner(i);
                while (counts[i] > 0)
                {
                    --counts[i];
                    if (counts.ContainsKey(j) && counts[j] > 0)
                    {
                        --counts[j];
                        ++ans;
                    }
                }
            }
            return ans;
        }

        static void Main(string[] args)
        {
            int N = ReadInt();
            int[] A = ReadInts();
            Console.WriteLine(Solve(N, A));
        }
    }
}