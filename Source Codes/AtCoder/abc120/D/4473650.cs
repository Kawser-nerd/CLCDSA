using System;
using System.Linq;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;

namespace procon
{

    class Solver
    {
        readonly Scanner cin = new Scanner();
        public void Solve()
        {
            int n = cin.nextint;
            int m = cin.nextint;

            int[,] edge = new int[m, 2];

            for (int i = 0; i < m; i++)
            {
                edge[i, 0] = cin.nextint - 1;
                edge[i, 1] = cin.nextint - 1;
            }

            UnionFind uf = new UnionFind(n);
            long[] ans = new long[m];
            ans[m - 1] = (long)n * (n - 1) / 2;

            for (int i = m - 1; i > 0; i--)
            {
                if (uf.IsSame(edge[i, 0], edge[i, 1]))
                {
                    ans[i - 1] = ans[i];
                }
                else
                {
                    long size = uf.size[uf.Root(edge[i, 0])] * uf.size[uf.Root(edge[i, 1])];
                    ans[i - 1] = ans[i] - size;

                    uf.Unite(edge[i, 0], edge[i, 1]);
                }
            }
            Console.WriteLine(String.Join("\n", ans));
        }


        class UnionFind
        {
            readonly int[] tree;
            public long[] size;

            public UnionFind(int length)
            {
                tree = new int[length];
                size = new long[length];

                for (int i = 0; i < length; i++)
                {
                    tree[i] = i;
                    size[i] = 1;
                }
            }

            public int Root(int x)
            {
                int rx = x;
                while (tree[rx] != rx)
                {
                    rx = tree[rx];
                }
                return rx;
            }

            public bool IsSame(int x, int y)
            {
                return Root(x) == Root(y);
            }

            public void Unite(int x, int y)
            {
                int rx = Root(x);
                int ry = Root(y);
                if (rx == ry) return;

                if (rx > ry)
                {
                    int temp = rx;
                    rx = ry;
                    ry = temp;
                }
                tree[ry] = rx;
                size[rx] += size[ry];
            }
        }

        static void Main()
        {
            var solver = new Solver();
            solver.Solve();
        }
    }

    class Scanner
    {
        string[] s; int i;
        readonly char[] cs = new char[] { ' ' };
        public Scanner() { s = new string[0]; i = 0; }
        public string[] scan => Console.ReadLine().Split();
        public int[] scanint => Array.ConvertAll(scan, int.Parse);
        public long[] scanlong => Array.ConvertAll(scan, long.Parse);
        public double[] scandouble => Array.ConvertAll(scan, double.Parse);
        public string next
        {
            get
            {
                if (i < s.Length) return s[i++];
                string st = Console.ReadLine();
                while (st == "") st = Console.ReadLine();
                s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
                i = 0;
                return next;
            }
        }
        public int nextint => int.Parse(next);
        public long nextlong => long.Parse(next);
        public double nextdouble => double.Parse(next);
    }
}