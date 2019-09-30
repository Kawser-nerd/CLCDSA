using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

namespace AtCoder
{
    class Treap<T> where T : IComparable
    {
        private class Node
        {
            private static Random g_rand = new Random();
            private readonly int m_rank = g_rand.Next();
            private readonly T m_value;
            private Node m_lch;
            private Node m_rch;
            private int m_count;

            public Node(T value)
            {
                m_value = value;
                m_count = 1;
            }

            private static int Count(Node node)
            {
                return (node != null) ? node.m_count : 0;
            }

            private Node Update()
            {
                m_count = Count(m_lch) + Count(m_rch) + 1;
                return this;
            }

            public static Node Merge(Node a, Node b)
            {
                if (a == null) { return b; }
                if (b == null) { return a; }

                if (a.m_rank < b.m_rank)
                {
                    a.m_rch = Merge(a.m_rch, b);
                    return a.Update();
                }
                else
                {
                    b.m_lch = Merge(a, b.m_lch);
                    return b.Update();
                }
            }

            public static Tuple<Node, Node> Split(Node t, int k)
            {
                if (t == null) { return new Tuple<Node, Node>(null, null); }

                if (k <= Count(t.m_lch))
                {
                    var pair = Split(t.m_lch, k);
                    t.m_lch = pair.Item2;
                    return new Tuple<Node, Node>(pair.Item1, t.Update());
                }
                else
                {
                    var pair = Split(t.m_rch, k - Count(t.m_lch) - 1);
                    t.m_rch = pair.Item1;
                    return new Tuple<Node, Node>(t.Update(), pair.Item2);
                }
            }

            public int FindIndex(T value)
            {
                int L = Count(m_lch);
                if (value.CompareTo(m_value) < 0)
                {
                    return (m_lch != null) ? m_lch.FindIndex(value) : 0;
                }
                else if (value.CompareTo(m_value) > 0)
                {
                    return (m_rch != null) ? m_rch.FindIndex(value) + L + 1 : L + 1;
                }
                else
                {
                    return L;
                }
            }

            public T this[int i]
            {
                get
                {
                    int L = Count(m_lch);
                    if (i < L)
                    {
                        return m_lch[i];
                    }
                    else if (i > L)
                    {
                        return m_rch[i - L - 1];
                    }
                    else
                    {
                        return m_value;
                    }
                }
            }
        }

        private Node node;

        public void Insert(T value)
        {
            if (node != null)
            {
                int k = node.FindIndex(value);
                var pair = Node.Split(node, k);
                node = Node.Merge(Node.Merge(pair.Item1, new Node(value)), pair.Item2);
            }
            else
            {
                node = new Node(value);
            }
        }

        public int FindIndex(T value)
        {
            return node.FindIndex(value);
        }

        public T this[int i]
        {
            get
            {
                return node[i];
            }
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

        static long Solve(int N, int[] A)
        {
            var tuples = new Tuple<int, int>[N];
            for (int i = 0; i < N; ++i)
            {
                tuples[i] = new Tuple<int, int>(A[i], i);
            }
            Array.Sort(tuples);

            long sum = 0;
            var treap = new Treap<int>();
            treap.Insert(-1);
            treap.Insert(N);
            for (int i = 0; i < N; ++i)
            {
                int n = tuples[i].Item2;
                treap.Insert(n);
                int j = treap.FindIndex(n);
                int L = treap[j - 1];
                int R = treap[j + 1];
                sum += Math.BigMul(n - L, R - n) * tuples[i].Item1;
            }
            return sum;
        }

        static void Main(string[] args)
        {
            int N = ReadInt();
            int[] A = ReadInts();
            Console.WriteLine(Solve(N, A));
        }
    }
}