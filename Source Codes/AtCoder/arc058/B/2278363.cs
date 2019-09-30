using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtCoder
{
    class Modulo
    {
        public readonly int M = 1000000007;
        private readonly int[] m_facs;
        public Modulo(int n)
        {
            m_facs = new int[n + 1];
            m_facs[0] = 1;
            for (int i = 1; i <= n; ++i)
            {
                m_facs[i] = (int)(Math.BigMul(m_facs[i - 1], i) % M);
            }
        }
        public int Fac(int n)
        {
            return m_facs[n];
        }
        public int Pow(int a, int m)
        {
            switch (m)
            {
            case 0:
                return 1;
            case 1:
                return a;
            default:
                int p1 = Pow(a, m / 2);
                long p2 = Math.BigMul(p1, p1) % M;
                return (int)(((m & 1) == 0) ? p2 : p2 * a % M);
            }
        }
        public long Ncr(int n, int r)
        {
            if (n < r) { return 0; }
            if (n == r) { return 1; }
            long res = Fac(n);
            res *= Pow(Fac(r), M - 2);
            res %= M;
            res *= Pow(Fac(n - r), M - 2);
            res %= M;
            return res;
        }
    }

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

        static long Solve(int H, int W, int A, int B)
        {
            var modulo = new Modulo(H + W);
            Func<int, int, long> Path = (x, y) => modulo.Ncr(x + y, x);
            long sum = 0;
            for (int x = B; x < W; ++x)
            {
                sum += Path(x, H - A - 1) * Path(W - x - 1, A - 1);
                sum %= MODULO;
            }
            return sum;
        }
        static void Main(string[] args)
        {
            int[] v = ReadInts();
            Console.WriteLine(Solve(v[0], v[1], v[2], v[3]));
        }
    }
}