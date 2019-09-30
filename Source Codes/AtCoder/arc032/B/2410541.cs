using System;
using System.Collections.Generic;
using System.Linq;

namespace arc032_2
{
    public class Unionfind
    {
        public static int[] par;//?
        public static int[] rank; //??
        public void init(int n)//???
        {
            par = new int[n]; rank = new int[n];
            for (int i = 0; i < n; i++)
            {
                par[i] = i;
                rank[i] = 0;
            }
        }
        public int root(int x)//?????
        {
            if (par[x] == x) return x;
            else return par[x] = root(par[x]);
        }
        public void unite(int x, int y)//?????
        {
            x = root(x); y = root(y);
            if (x == y) return;
            else
            {
                if (rank[x] < rank[y]) par[x] = y;
                else
                {
                    par[y] = x;
                    if (rank[x] == rank[y]) rank[x]++;
                }
            }
        }
        public bool issame(int x, int y)//???????????
        {
            return root(x) == root(y);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Unionfind a = new Unionfind();
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            a.init(x[0]);
            for (int i = 0; i < x[1]; i++)
            {
                int[] b = Console.ReadLine().Split().Select(int.Parse).ToArray();
                a.unite(b[0] - 1, b[1] - 1);
            }
            HashSet<int> ret = new HashSet<int>();
            for (int i = 0; i < x[0]; i++)
            {
                ret.Add(a.root(i));
            }
            Console.WriteLine(ret.Count - 1);
        }
    }
}