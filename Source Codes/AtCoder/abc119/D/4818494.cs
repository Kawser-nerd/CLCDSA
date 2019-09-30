using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Treap<T> where T : IComparable
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
    static int A, B, Q;

    public static void Main(string[] args)
    {
        MainModule(Console.In);
    }

    public static void MainModule(TextReader In)
    {
        var lin = In.ReadLine().Split(' ').Select(n => int.Parse(n)).ToArray();
        A = lin[0];
        B = lin[1];
        Q = lin[2];

        var ss = new Treap<long>();
        var ts = new Treap<long>();
        var xs = new long[Q];
        for (int i = 0; i < A; i++)
            ss.Insert(long.Parse(In.ReadLine()));
        for (int i = 0; i < B; i++)
            ts.Insert(long.Parse(In.ReadLine()));
        for (int i = 0; i < Q; i++)
            xs[i] = long.Parse(In.ReadLine());

        const long SmallValue = -100000000000L;
        const long BigValue = 100000000000L;
        foreach (var x in xs)
        {
            var si = ss.FindIndex(x);
            var s0 = si <= 0 ? SmallValue : ss[si - 1];
            var s1 = si >= A ? BigValue : ss[si];
            var ti = ts.FindIndex(x);
            var t0 = ti <= 0 ? SmallValue : ts[ti - 1];
            var t1 = ti >= B ? BigValue : ts[ti];
            var s0t0 = Math.Max(x - s0, x - t0);
            var s0t1 = (x - s0) + (t1 - x) + Math.Min((x - s0), (t1 - x));
            var s1t0 = (s1 - x) + (x - t0) + Math.Min((s1 - x), (x - t0));
            var s1t1 = Math.Max(s1 - x, t1 - x);
            var can = new long[] { s0t0, s0t1, s1t0, s1t1, };
            Console.WriteLine(can.Min());
        }
    }
}