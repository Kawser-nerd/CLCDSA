using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_C
{
    class _026
    {
        static void Main(string[] args)
        {
            Method(args);
        }

        static void Method(string[] args)
        {
            int[] nl = ReadInts();
            int n = nl[0];
            int length = nl[1];
            int[][] lrcs = new int[n][];
            for (int i = 0; i < n; i++) lrcs[i] = ReadInts();
            Array.Sort(lrcs, (a, b) => a[0] - b[0]);
            SegTree<long> tree = new SegTree<long>(length,
                long.MaxValue / 2, Min, long.MaxValue / 2);
            for (int i = 0; i < n; i++)
            {
                if (lrcs[i][0] == 0)
                {
                    if (lrcs[i][2] < tree.Look(lrcs[i][1] - 1))
                    {
                        tree.Update(lrcs[i][1] - 1, lrcs[i][2]);
                    }
                }
                else
                {
                    long val = lrcs[i][2]
                        + tree.Run(lrcs[i][0] - 1, lrcs[i][1] - 1);
                    if (val < tree.Look(lrcs[i][1] - 1))
                    {
                        tree.Update(lrcs[i][1] - 1, val);
                    }
                }
            }
            WriteLine(tree.Look(length - 1));
        }

        class SegTree<T>
        {
            int n;
            T[] tree;
            Func<T, T, T> function;
            T exnum;

            public SegTree(int length, Func<T, T, T> function, T exnum)
            {
                this.function = function;
                this.exnum = exnum;
                n = 1;
                while (n < length) n <<= 1;

                tree = new T[2 * n - 1];
                for (int i = 0; i < tree.Length; i++) tree[i] = exnum;
            }

            public SegTree(int length, T init, Func<T, T, T> function, T exnum)
                : this(length, function, exnum)
            {
                for (int i = 0; i < length; i++) tree[i + n - 1] = init;
                UpdateAll();
            }

            public void AssignWithoutUpdate(int i, T value)
            {
                tree[i + n - 1] = value;
            }

            public void Update(int i, T value)
            {
                int j = i + n - 1;
                tree[j] = value;
                while (j > 0)
                {
                    j = (j - 1) >> 1;
                    tree[j] = function(tree[(j << 1) + 1], tree[(j << 1) + 2]);
                }
            }

            public void UpdateAll()
            {
                for (int i = n - 2; i >= 0; i--)
                {
                    tree[i] = function(tree[(i << 1) + 1], tree[(i << 1) + 2]);
                }
            }

            public T Look(int i) { return tree[i + n - 1]; }

            //[s,t)
            public T Run(int s, int t) { return Query(s, t, 0, 0, n); }

            T Query(int s, int t, int k, int l, int r)
            {
                if (r <= s || t <= l) return exnum;
                if (s <= l && r <= t) return tree[k];

                return function(Query(s, t, (k << 1) + 1, l, (l + r) >> 1),
                    Query(s, t, (k + 1) << 1, (l + r) >> 1, r));
            }
        }

        private static string Read() { return ReadLine(); }
        private static char[] ReadChars() { return Array.ConvertAll(Read().Split(), a => a[0]); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}