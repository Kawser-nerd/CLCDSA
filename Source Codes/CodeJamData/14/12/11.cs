using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ14
{
    using System.Globalization;

    public class B
    {
        public string[] Solve(string[] lines)
        {
            int cases = int.Parse(lines[0]);
            string[] res = new string[cases];
            for (int i = 1, c = 1; i < lines.Length; i++, c++)
            {
                int n = int.Parse(lines[i]);
                List<int>[] edges = new List<int>[n];
                for (int j = 1; j < n; j++)
                {
                    var zline = lines[++i].Split(' ').Select(s => int.Parse(s)).ToList();
                    int q = zline[0]-1;
                    int w = zline[1]-1;
                    if (edges[q] == null)
                        edges[q] = new List<int>();
                    edges[q].Add(w);

                    if (edges[w] == null)
                        edges[w] = new List<int>();
                    edges[w].Add(q);
                }

                this._tree = edges;
                int ans = this.Calc();
                res[c-1] = string.Format("Case #{0}: {1}", c, ans);
            }
            return res;
        }

        private List<int>[] _tree;

        private int Go(int root, int from)
        {
            List<int> maxSurvive = new List<int>();
            for (int i = 0; i < _tree[root].Count; i++)
            {
                if (_tree[root][i] != from)
                {
                    int g = this.Go(_tree[root][i], root);
                    maxSurvive.Add(g);
                }
            }

            if (maxSurvive.Count < 2)
                return 1;
           
            maxSurvive.Sort();

            return maxSurvive[maxSurvive.Count - 1] + maxSurvive[maxSurvive.Count - 2] + 1;
        }

        private int[] _childs;
        private int CountChilds(int root, int from)
        {
            int res = 0;
            for (int i = 0; i < _tree[root].Count; i++)
            {
                if (_tree[root][i] != from)
                {
                    res += 1 + this.CountChilds(_tree[root][i], root);
                }
            }

            return _childs[root] = res;
        }

        private int Calc()
        {
            int res = 1;
            for (int i = 0; i < _tree.Length; i++)
            {
                _childs = new int[_tree.Length];
                this.CountChilds(i, -1);
                res = Math.Max(res, this.Go(i, -1));
            }

            return _tree.Length - res;
        }
    }
}
