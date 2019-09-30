using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC040_D
{
    class Program
    {
        static void Main(string[] args)
        {
            var sb = new StringBuilder();
            var k = scan;
            var s = k[1];
            var U = new UnionFind(k[0]);
            var G = new List<data>();
            var T = new Dictionary<int, int>();
            for (int i = 0; i < k[1]; i++)
            {
                var t = scan;
                G.Add(new data(1, t[0]-1, t[1]-1, t[2]));
                
            }
            k = scan;
            for (int i = 0; i < k[0]; i++)
            {
                var t = scan;
                G.Add(new data(0, i, t[0]-1, t[1]));
                T[i] = 0;
            }

            var A = G.OrderByDescending(g => g.year).ThenBy(g => g.NQ).ToArray();

            foreach (var a in A)
            {
                //Console.WriteLine(a.NQ +" " + a.year);
                if (a.NQ == 0)
                {
                    T[a.num] = U.Weight(a.to);
                }
                else
                {
                    U.Unite(a.num, a.to);
                }
            }

            foreach (var t in T)
            {
                sb.AppendLine(t.Value.ToString());
            }
            Console.Write(sb);
        }

        static int[] scan { get { return Array.ConvertAll(Console.ReadLine().Split(), int.Parse); } }
    }
    class data
    {
        public int NQ, num, to, year;
        public data(int a, int b, int c, int d)
        {
            NQ = a;
            num = b;
            to = c;
            year = d;
        }
    }

    class UnionFind
    {
        internal int[] rank;
        internal int[] p;
        internal int[] weight;
        public UnionFind(int size)
        {
            rank = new int[size];
            p = new int[size];
            weight = new int[size];
            for (int i = 0; i < size; i++)
            {
                rank[i] = 0;
                p[i] = i;
                weight[i] = 1;
            }
        }
        public void Unite(int x, int y)
        {
            x = FindSet(x);
            y = FindSet(y);
            if (x == y) return;
            if (rank[x] > rank[y])
            {
                p[y] = x;
                weight[x] += weight[y];
            }

            if (rank[x] < rank[y])
            {
                p[x] = y;
                weight[y] += weight[x];
            }
            if (rank[x] == rank[y])
            {
                p[x] = y;
                rank[y]++;
                weight[y] += weight[x];
            }
        }
        public bool Same(int x, int y)
        {
            return FindSet(x) == FindSet(y);
        }
        public int FindSet(int x)
        {
            var H = new HashSet<int>();
            while (p[x] != x)
            {
                H.Add(x);
                x = p[x];
            }
            foreach (var h in H)
            {
                p[h] = x;
            }
            return x;
        }
        public int Weight(int x)
        {
            return weight[FindSet(x)];
        }
    }
}