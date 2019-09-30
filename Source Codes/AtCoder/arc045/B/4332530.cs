using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ARC_B
{
    class _045
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nm = ReadInts();
            int n = nm[0];
            int m = nm[1];
            int[][] sts = new int[m][];
            for(int i = 0; i < m; i++)
            {
                sts[i] = ReadInts();
            }
            int[] imos = new int[n];
            for(int i = 0; i < m; i++)
            {
                int s = sts[i][0] - 1;
                int t = sts[i][1] - 1;
                imos[s]++;
                if (t + 1 < n) imos[t + 1]--;
            }
            for(int i = 1; i < n; i++)
            {
                imos[i] += imos[i - 1];
                //Console.WriteLine(imos[i]);
            }
            UnionFind unionFind = new UnionFind(n);
            unionFind.size[0] = imos[0] >= 2 ? 1 : 0;
            for(int i = 1; i < n; i++)
            {
                if (imos[i] >= 2)
                {
                    unionFind.size[i] = 1;
                    if (imos[i - 1] >= 2)
                    {
                        unionFind.Unite(i - 1, i);
                    }
                }
            }
            List<int> res = new List<int>();
            for (int i = 0; i < m; i++)
            {
                int s = sts[i][0] - 1;
                int t = sts[i][1] - 1;
                if (unionFind.IsSame(s, t)
                    && unionFind.size[s] > 0) res.Add(i + 1);
            }
            Console.WriteLine(res.Count);
            for (int i = 0; i < res.Count; i++) Console.WriteLine(res[i]);
        }

        class UnionFind
        {
            int[] tree;
            public int[] size;

            public UnionFind(int length)
            {
                tree = new int[length];
                size = new int[length];
                for (int i = 0; i < length; i++)
                {
                    tree[i] = i;
                    size[i] = 0;
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

        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}