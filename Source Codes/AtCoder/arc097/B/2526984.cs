using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{

    internal class Solution
    {
        public int N, M;
        public int[] P;


        public void Run()
        {
            {
                var line = Input.ReadIntArray();
                N = line[0];
                M = line[1];
                P = Input.ReadIntArray();
                for (int i = 0; i < N; i++) P[i]--;
            }

            var U = new UnionFind(N);
            for (int i = 0; i < M; i++)
            {
                var line = Input.ReadIntArray();
                int a = line[0] - 1;
                int b = line[1] - 1;
                U.Unite(a, b);
            }

            var dic = new Dictionary<int, List<int>>();
            for (int i = 0; i < N; i++)
            {
                int p = U.Find(i);
                if(!dic.ContainsKey(p)) dic.Add(p, new List<int>());
                dic[p].Add(i);
            }

            int ret = 0;
            foreach (var k in dic.Keys)
            {
                var vs = dic[k];
                var xs = vs.Select(i => P[i]).ToList();
                ret += vs.Intersect(xs).Count();
            }

            Console.WriteLine(ret);
        }
    }

    // libs ----------
    class UnionFind
    {
        public List<int> Par;
        public List<int> Sizes;

        public UnionFind(int n)
        {
            Par = new List<int>();
            Sizes = new List<int>();
            for (int i = 0; i < n; i++)
            {
                Par.Add(i);
                Sizes.Add(1);
            }
        }

        public int Find(int x)
        {
            if (x == Par[x]) return x;
            Par[x] = Find(Par[x]);
            return Par[x];
        }

        public void Unite(int x, int y)
        {
            x = Find(x);
            y = Find(y);
            if (x == y) return;

            if (Sizes[x] < Sizes[y])
            {
                // swap
                int temp = x;
                x = y;
                y = temp;
            }

            Par[y] = x;
            Sizes[x] += Sizes[y];
            Sizes[y] = 0;
        }

        public bool Same(int x, int y)
        {
            return Find(x) == Find(y);
        }

        public int Size(int x)
        {
            return Sizes[Find(x)];
        }
    }

    // common ----------

    internal static class Input
    {
        public static int ReadInt()
        {
            string line = Console.ReadLine();
            return int.Parse(line);
        }

        public static int[] ReadIntArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(int.Parse).ToArray();            
        }

        public static double[] ReadDoubleArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(double.Parse).ToArray();
        }
    }
    
    internal class Program
    {
        public static void Main(string[] args)
        {
            var s = new Solution();
            s.Run();
        }
    }
}