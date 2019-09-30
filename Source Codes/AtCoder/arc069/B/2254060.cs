using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtCoder
{
    class Program
    {
        private const int MODULO = 1000000007;
        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }

        static int Mod(int a, int b)
        {
            return (a % b + b) % b;
        }
        static int[] Convert(string s)
        {
            return s.Select(c => (c == 'S') ? 1 : -1).ToArray();
        }
        static int[] Solve(int N, int[] S)
        {
            foreach (int[] t in new[] { new[] { -1, -1 }, new[] { -1, 1 },new[] { 1, -1 }, new[] { 1, 1 } })
            {
                int[] ans = new int[N];
                Array.Copy(t, ans, 2);
                for (int i = 2; i < N; ++i)
                {
                    int a0 = Mod(i - 2, N);
                    int a1 = Mod(i - 1, N);
                    int a2 = Mod(i - 0, N);
                    ans[a2] = ans[a0] * ans[a1] * S[a1];
                }
                if (Enumerable.Range(0, N).All(i =>
                {
                    int a0 = Mod(i - 1, N);
                    int a1 = Mod(i, N);
                    int a2 = Mod(i + 1, N);
                    return (ans[a0] * ans[a2] == ans[a1] * S[a1]);
                }))
                {
                    return ans;
                }
            }
            return null;
        }
        static void Main(string[] args)
        {
            int N = ReadInt();
            string s = Read();
            int[] ans = Solve(N, s.Select(c => (c == 'o') ? 1 : -1).ToArray());
            Console.WriteLine((ans != null) ? new string(Array.ConvertAll(ans, n => (n == 1) ? 'S' : 'W')) : "-1");
        }
    }
}