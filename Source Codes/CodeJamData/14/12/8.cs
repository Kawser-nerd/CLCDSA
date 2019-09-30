using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class Program
    {

        static void Go()
        {
            string s = Console.ReadLine();
            int n;
            Int32.TryParse(s, out n);
            for(int _i = 1; _i <= n; ++_i)
            {
                int r;
                //StringBuilder result = new StringBuilder();

                string l1;
                l1 = Console.ReadLine();
                int _n, _l;
                Int32.TryParse(l1, out _n);

                List<int>[] tree = new List<int>[_n+1];
                for(int i=0; i<_n+1; ++i)
                    tree[i] = new List<int>();

                for (int i = 0; i < _n - 1; ++i)
                {
                    string l2;
                    l2 = Console.ReadLine();
                    string[] t1 = l2.Split(' ');
                    int _n1, _n2;
                    Int32.TryParse(t1[0], out _n1);
                    Int32.TryParse(t1[1], out _n2);

                    tree[_n1].Add(_n2);
                    tree[_n2].Add(_n1);
                }

                int max = 0;
                for (int i = 1; i <= _n; ++i)
                {
                    int mm = MaxDepth(i, -1, tree);
                    if (mm > max)
                        max = mm;
                }

                //int tree_size = (int)Math.Pow(2, 1 + max);
                Console.WriteLine("Case #{0}: {1}", _i, _n - max);
            }

        }

        private static int treeSize(int depth)
        {
            return -1 + (int)Math.Pow(2, 1 + depth);
        }

        private static int MaxDepth(int _n, int from, List<int>[] tree)
        {
            var t = tree[_n];
            int[] d = new int[t.Count];
            if (from != -1)
            {
                if (t.Count <= 2)
                    return 1;
            }
            if (from == -1)
            {
                if (t.Count < 2)
                    return 1;
            }
            for (int i = 0; i < t.Count; ++i)
            {
                int node = t[i];
                if (node == from)
                {
                    d[i] = -1;
                    continue;
                }
                d[i] = MaxDepth(node, _n, tree);
            }

            Array.Sort(d);
            return 1 + d[d.Length - 2] + d[d.Length - 1];
        }


        static void Main(string[] args)
        {
            try
            {
                Go();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                Console.WriteLine(e.StackTrace);
            }
        }
    }
}
