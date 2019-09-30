using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;
using System.Threading.Tasks;

namespace AtCoder
{
    class Point
    {
        public readonly int x;
        public readonly int y;
        public Point(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
    }

    class Map
    {
        private readonly int m_k;
        private int[][] m_count;
        private int[][] m_sum;
        public Map(int K)
        {
            m_k = K;
            m_count = new int[4 * K][];
            m_sum = new int[4 * K][];
            for (int i = 0; i < 4 * K; ++i)
            {
                m_count[i] = new int[4 * K];
                m_sum[i] = new int[4 * K];
            }
        }
        public void Dot(Point p)
        {
            int x1 = p.x;
            int y1 = p.y;
            int x2 = p.x + 2 * m_k;
            int y2 = p.y + 2 * m_k;
            ++m_count[y1][x1];
            ++m_count[y2][x1];
            ++m_count[y1][x2];
            ++m_count[y2][x2];
        }
        private int Sum(int x, int y)
        {
            if (x < 0 || y < 0)
            {
                return 0;
            }
            else
            {
                return m_sum[Math.Min(y, 4 * m_k - 1)][Math.Min(x, 4 * m_k - 1)];
            }
        }
        public void Calculate()
        {
            for (int y = 0; y < 4 * m_k; ++y)
            {
                for (int x = 0; x < 4 * m_k; ++x)
                {
                    m_sum[y][x] = m_count[y][x]
                                + Sum(x - 1, y)
                                + Sum(x, y - 1)
                                - Sum(x - 1, y - 1);
                }
            }
        }
        public int Area(int x1, int y1, int x2, int y2)
        {
            return Sum(x2, y2)
                 - Sum(x1 - 1, y2)
                 - Sum(x2, y1 - 1)
                 + Sum(x1 - 1, y1 - 1);
        }
    }
    class Program
    {
        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }

        private static int Solve(int N, int K, Point[] points)
        {
            Map map = new Map(K);
            foreach (var p in points) { map.Dot(p); }
            map.Calculate();
            int max = 0;
            for (int y = 0; y < 2 * K; ++y)
            {
                for (int x = 0; x < 2 * K; ++x)
                {
                    int s = 0;
                    s += map.Area(x, y, x + K - 1, y + K - 1);
                    s += map.Area(x + K, y + K, x + 2 * K - 1, y + 2 * K - 1);
                    max = Math.Max(s, max);
                }
            }
            return max;
        }
        static void Main(string[] args)
        {
            int[] values1 = ReadInts();
            int N = values1[0];
            int K = values1[1];
            var points = new Point[N];
            for (int i = 0; i < N; ++i)
            {
                string[] values2 = Read().Split();
                int x = int.Parse(values2[0]);
                int y = int.Parse(values2[1]);
                switch (values2[2][0])
                {
                case 'W':
                    points[i] = new Point(x % (2 * K), y % (2 * K));
                    break;
                case 'B':
                    points[i] = new Point(x % (2 * K), (y + K) % (2 * K));
                    break;
                }
            }
            Console.WriteLine(Solve(N, K, points));
        }
    }
}