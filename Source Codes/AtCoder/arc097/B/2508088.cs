using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtCoder
{
    class Node<T>
    {
        private int m_height;
        private Node<T> m_parent;
        public T Item { get; private set; }
        public Node(T item)
        {
            m_height = 0;
            m_parent = this;
            Item = item;
        }
        public Node<T> Find()
        {
            if (m_parent == this) { return this; }

            Node<T> parent = m_parent.Find();
            m_parent = parent;
            return parent;
        }
        public static void Unite(Node<T> a, Node<T> b)
        {
            Node<T> p = a.Find();
            Node<T> q = b.Find();
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

        static int Solve(int N, int[] P, Tuple<int, int>[] tuples)
        {
            var nodes = new Node<int>[N];
            for (int i = 0; i < N; ++i) { nodes[i] = new Node<int>(i); }
            foreach (var tuple in tuples)
            {
                int a = tuple.Item1;
                int b = tuple.Item2;
                Node<int>.Unite(nodes[a], nodes[b]);
            }
            int count = 0;
            for (int i = 0; i < N; ++i)
            {
                if (nodes[i].Find().Item == nodes[P[i]].Find().Item) { ++count; }
            }
            return count;
        }
        static void Main(string[] args)
        {
            var V1 = ReadInts();
            int N = V1[0];
            int M = V1[1];
            var P = ReadInts().Select(p => p - 1).ToArray();
            var tuples = new Tuple<int, int>[M];
            for (int i = 0; i < M; ++i)
            {
                var V2 = ReadInts();
                tuples[i] = new Tuple<int, int>(V2[0] - 1, V2[1] - 1);
            }
            Console.WriteLine(Solve(N, P, tuples));
        }
    }
}