using System;
using System.Text.RegularExpressions;
using System.Linq;
using System.Collections.Generic;
using System.IO;
using System.Numerics;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = Int32.Parse(Console.ReadLine());
            var a = Int32.Parse(Console.ReadLine());

            var typeAs = new List<Tuple<int, int>>();
            while (a > 0)
            {
                var str = Console.ReadLine().Split();
                var x = Int32.Parse(str[0]) - 1;
                var y = Int32.Parse(str[1]) - 1;
                typeAs.Add(new Tuple<int, int>(x, y));  //x, y
                a--;
            }

            var typeBs = new List<Tuple<int, int>>();
            var b = Int32.Parse(Console.ReadLine());
            while (b > 0)
            {
                var str = Console.ReadLine().Split();
                var u = Int32.Parse(str[0]) - 1;
                var v = Int32.Parse(str[1]) - 1;
                typeBs.Add(new Tuple<int, int>(u, v));  //u, v
                b--;
            }

            var ret = 0;
            var scc = new Scc();
            for (int mask = 0; mask < 1 << typeBs.Count(); mask++)
            {
                scc.Init(n);

                foreach (var typeA in typeAs) scc.AddEdge(typeA.Item2, typeA.Item1);    //y -> x

                var notUse = new bool[n];
                for (int i = 0; i < typeBs.Count(); i++)
                {
                    var typeB = typeBs[i];
                    if ((mask >> i) % 2 == 1)
                        scc.AddEdge(typeB.Item1, typeB.Item2);  //u -> v
                    else
                        notUse[typeB.Item1] = true;             //don't use u
                }

                scc.GetScc();

                //nodes in a closed loop => cannot paind
                for (int sccIdx = 0; sccIdx < scc.SComponents.Count(); sccIdx++)
                {
                    if (scc.SComponents[sccIdx].Count() > 1)
                    {
                        foreach (var comp in scc.SComponents[sccIdx])
                            notUse[comp] = true;
                    }
                }

                //nodes afer not painted one => cannot paint
                for (int j = 0; j < n; j++)
                    for (int i = 0; i < n; i++)
                        if (notUse[i]) foreach (var child in scc.E[i]) notUse[child] = true;

                ret = Math.Max(ret, notUse.Count(v => !v));
            }

            Console.WriteLine(ret);
        }
    }

    //?????(Strongly Connected Component)??
    public class Scc
    {
        public List<List<int>> E;
        public List<List<int>> RE;

        bool[] _vis;
        List<int> _num = new List<int>();

        //?????????????????
        public int[] Cmp;

        //?????????????
        public List<List<int>> SComponents = new List<List<int>>();

        int _vn;

        public void Init(int vn)
        {
            _vn = vn;

            E = new List<List<int>>();
            for (int i = 0; i < vn; i++) E.Add(new List<int>());

            RE = new List<List<int>>();
            for (int i = 0; i < vn; i++) RE.Add(new List<int>());

            Cmp = new int[vn];
            _vis = new bool[vn];
        }

        public void AddEdge(int from, int to)
        {
            E[from].Add(to);
            RE[to].Add(from);
        }

        void Dfs(int v)
        {
            _vis[v] = true;
            for (int i = 0; i < E[v].Count(); i++)
            {
                if (!_vis[E[v][i]]) Dfs(E[v][i]);
            }
            _num.Add(v);
        }

        void RDfs(int cu, int ind)
        {
            _vis[cu] = true;
            Cmp[cu] = ind;
            SComponents[ind].Add(cu);
            for (int i = 0; i < RE[cu].Count(); i++)
            {
                if (!_vis[RE[cu][i]]) RDfs(RE[cu][i], ind);
            }
        }

        //Cmp[]?Components????????????????
        public int GetScc()
        {
            int c = 0;
            SComponents.Clear();
            for (int i = 0; i < _vn; i++) SComponents.Add(new List<int>());
            _num.Clear();

            for (int i = 0; i < _vis.Length; i++) _vis[i] = false;
            for (int i = 0; i < _vn; i++)
            {
                if (!_vis[i]) Dfs(i);
            }


            for (int i = 0; i < _vis.Length; i++) _vis[i] = false;
            for (int i = _num.Count() - 1; i >= 0; i--)
            {
                if (!_vis[_num[i]])
                {
                    RDfs(_num[i], c);
                    SComponents[c].Sort();
                    c++;
                }
            }

            SComponents = SComponents.Take(c).ToList();
            return c;
        }
    }
}