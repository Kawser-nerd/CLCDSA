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

        static IEnumerable<int> Solve(int N, Node<int>[] nodes1, Node<int>[] nodes2)
        {
            var dict = new Dictionary<Tuple<int, int>, int>();
            for (int i = 0; i < N; ++i)
            {
                int a = nodes1[i].Find().Item;
                int b = nodes2[i].Find().Item;
                var key = new Tuple<int, int>(a, b);
                if (!dict.ContainsKey(key)) { dict[key] = 0; }
                ++dict[key];
            }
            int[] ans = new int[N];
            for (int i = 0; i < N; ++i)
            {
                int a = nodes1[i].Find().Item;
                int b = nodes2[i].Find().Item;
                var key = new Tuple<int, int>(a, b);
                ans[i] = dict[key];
            }
            return ans;
        }
        static void Main(string[] args)
        {
            int[] v1 = ReadInts();
            int N = v1[0];
            int K = v1[1];
            int L = v1[2];
            var nodes1 = new Node<int>[N];
            var nodes2 = new Node<int>[N];
            for (int i = 0; i < N; ++i)
            {
                nodes1[i] = new Node<int>(i);
                nodes2[i] = new Node<int>(i);
            }
            for (int i = 0; i < K; ++i)
            {
                int[] v2 = ReadInts();
                int p = v2[0] - 1;
                int q = v2[1] - 1;
                Node<int>.Unite(nodes1[p], nodes1[q]);
            }
            for (int i = 0; i < L; ++i)
            {
                int[] v2 = ReadInts();
                int r = v2[0] - 1;
                int s = v2[1] - 1;
                Node<int>.Unite(nodes2[r], nodes2[s]);
            }
            Console.WriteLine(string.Join(" ", Solve(N, nodes1, nodes2)));
        }
    }
}