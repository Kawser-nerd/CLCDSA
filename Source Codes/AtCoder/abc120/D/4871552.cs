using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Beg120D
{
    public class UnionFind
    {
        public int[] pars, ranks;

        public UnionFind(int N)
        {
            pars = new int[N];
            ranks = new int[N];
            for (int i = 0; i < N; i++)
            {
                ranks[i] = 0;
                pars[i] = i;
            }
        }

        private int root(int x)
        {
            if (pars[x] == x) return x;
            else
            {
                pars[x] = root(pars[x]);
                return pars[x];
            }
        }

        public void unit(int x, int y)
        {
            var rx = root(x);
            var ry = root(y);
            if (rx != ry)
            {
                pars[ry] = rx;
                var rank = ranks[rx] + ranks[ry] + 1;
                ranks[rx] = rank;
                ranks[ry] = rank;
            }
        }

        public bool isSame(int x, int y)
        {
            return root(x) == root(y);
        }
        public int getRootRank(int x)
        {
            return ranks[root(x)];
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var read = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            var N = read[0];
            var M = read[1];

            var As = new int[M];
            var Bs = new int[M];
            var tree = new UnionFind(N);
            for (int i=0;i<M;i++)
            {
                read = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
                As[i] = read[0];
                Bs[i] = read[1];
            }

            var ans = new long[M];
            ans[M - 1] = (long)N * (long)(N - 1) / 2;
            //if (!tree.isSame(As[M -1] - 1, Bs[M - 1] - 1)) tree.unit(As[M - 1] - 1, Bs[M - 1] - 1);

            for (int i = M-2;i>=0;i--)
            {
                var N1 = tree.getRootRank(As[i+1] - 1) + 1;
                var N2 = tree.getRootRank(Bs[i+1] - 1) + 1;
                ans[i] = tree.isSame(As[i+1] - 1, Bs[i+1] - 1) ? ans[i + 1] : ans[i + 1] - N1 * N2;
                if (!tree.isSame(As[i+1] - 1, Bs[i+1] - 1)) tree.unit(As[i+1] - 1, Bs[i+1] - 1);
            }
            for (int i = 0; i < M; i++)
                Console.WriteLine(ans[i]);
        }
    }
}