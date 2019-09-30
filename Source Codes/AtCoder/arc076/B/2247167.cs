using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Node
    {
        private int m_height = 0;
        private Node m_parent = null;
        public Node Find()
        {
            if (m_parent == null)
            {
                return this;
            }
            else
            {
                Node parent = m_parent.Find();
                m_parent = parent;
                return parent;
            }
        }
        public static void Unite(Node a, Node b)
        {
            Node p = a.Find();
            Node q = b.Find();
            if (p.m_height < q.m_height)
            {
                p.m_parent = q;
                q.m_height = Math.Max(p.m_height + 1, q.m_height);
            }
            else
            {
                q.m_parent = p;
                p.m_height = Math.Max(q.m_height + 1, p.m_height);
            }
        }
    }
    class Point
    {
        public readonly int n;
        public readonly int x;
        public readonly int y;
        public Point(int n, int[] args)
        {
            this.n = n;
            x = args[0];
            y = args[1];
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

        static long Solve(int N, Point[] points)
        {
            var paths = new List<Tuple<int, Point, Point>>();
            Array.Sort(points, (a, b) => a.x - b.x);
            for (int i = 1; i < N; ++i)
            {
                Point a = points[i - 1];
                Point b = points[i];
                paths.Add(new Tuple<int, Point, Point>(b.x - a.x, a, b));
            }
            Array.Sort(points, (a, b) => a.y - b.y);
            for (int i = 1; i < N; ++i)
            {
                Point a = points[i - 1];
                Point b = points[i];
                paths.Add(new Tuple<int, Point, Point>(b.y - a.y, a, b));
            }
            long sum = 0;
            var nodes = new Node[N];
            for (int i = 0; i < N; ++i) { nodes[i] = new Node(); }
            foreach (var path in paths.OrderBy(path => path.Item1))
            {
                Node a = nodes[path.Item2.n];
                Node b = nodes[path.Item3.n];
                if (a.Find() != b.Find())
                {
                    Node.Unite(a, b);
                    sum += path.Item1;
                }
            }
            return sum;
        }

        static void Main(string[] args)
        {
            int N = ReadInt();
            var points = new Point[N];
            for (int i = 0; i < N; ++i) { points[i] = new Point(i, ReadInts()); }
            Console.WriteLine(Solve(N, points));
        }
    }
}