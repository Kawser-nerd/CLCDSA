using System;
using System.Linq;
using System.Collections.Generic;

namespace AtCoder
{
    public class UnionFind
    {
        int[] par;
        int[] size;

        public UnionFind(int N)
        {
            par = new int[N];
            size = new int[N];
            for (int i = 0; i < N; i++)
            {
                par[i] = i;
                size[i] = 1;
            }
        }

        public int Root(int x)
        {
            if (par[x] == x) return x;
            return par[x] = Root(par[x]);
        }

        public void Unite(int x, int y)
        {
            int rootX = Root(x);
            int rootY = Root(y);
            if (rootX == rootY) return;
            par[rootX] = rootY;
            size[rootY] += size[rootX];
        }

        public bool Same(int x, int y)
        {
            int rootX = Root(x);
            int rootY = Root(y);
            return rootX == rootY;
        }

        public int Size(int x)
        {
            return size[Root(x)];
        }
    }

    public class Bridge
    {
        public int A;
        public int B;

        public Bridge(int a, int b)
        {
            A = a;
            B = b;
        }
    }

    class Program
    {
        public static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(' ');
            int N = int.Parse(s[0]);
            int M = int.Parse(s[1]);
            List<Bridge> l = new List<Bridge>();
            for (int i = 0; i < M; i++)
            {
                s = Console.ReadLine().Split(' ');
                l.Add(new Bridge(int.Parse(s[0]), int.Parse(s[1])));
            }

            long lastNum = (long)N * (long)(N - 1) / 2;
            List<long> reslist = new List<long>();
            reslist.Add(lastNum);

            UnionFind uf = new UnionFind(N + 1);

            for (int i = M - 1; i > 0; i--)
            {
                int anum = uf.Size(l[i].A), bnum = uf.Size(l[i].B);
                lastNum = (uf.Same(l[i].A, l[i].B))? lastNum:
                    lastNum - (long)anum * (long)bnum;
                uf.Unite(l[i].A, l[i].B);
                reslist.Add(lastNum);
            }

            for(int i = reslist.Count - 1; i >= 0; i--)
            {
                Console.WriteLine(reslist[i]);
            }
        }
    }
}