using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ARC_B
{
    class _056
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nms = ReadInts();
            int n = nms[0];
            int m = nms[1];
            int s = nms[2] - 1;
            List<int>[] edges = new List<int>[n];
            for(int i = 0; i < n; i++)
            {
                edges[i] = new List<int>();
            }
            for(int i = 0; i < m; i++)
            {
                int[] uv = ReadInts();
                int u = uv[0] - 1;
                int v = uv[1] - 1;
                if (u < v)
                {
                    edges[u].Add(v);
                }
                else
                {
                    edges[v].Add(u);
                }
            }
            bool[] parkables = new bool[n];
            parkables[s] = true;
            UnionFind unionFind = new UnionFind(n);
            for (int i = n - 1; i >= 0; i--)
            {
                for (int j = 0; j < edges[i].Count; j++)
                {
                    unionFind.Unite(edges[i][j], i);
                }
                parkables[i] = i <= s && unionFind.IsSame(i, s);
            }
            for(int i = 0; i < n; i++)
            {
                if (parkables[i]) Console.WriteLine(i + 1);
            }
        }

        class UnionFind
        {
            int[] tree;
            int[] rank;
            int[] size;

            public UnionFind(int length)
            {
                tree = new int[length];
                rank = new int[length];
                for(int i = 0; i < length; i++)
                {
                    tree[i] = i;
                }
            }

            public int Root(int x)
            {
                int rx = x;
                while (tree[rx] != rx)
                {
                    rx = tree[rx];
                }
                tree[x] = rx;
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
                if (rank[rx] < rank[ry])
                {
                    int temp = rx;
                    rx = ry;
                    ry = temp;
                }
                if (rank[rx] == rank[ry])
                {
                    rank[rx]++;
                }
                tree[ry] = rx;
            }
        }

        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}