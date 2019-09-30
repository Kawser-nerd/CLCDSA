using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine().Split();
            var n = Int32.Parse(str[0]);
            var k = Int32.Parse(str[1]);

            var graph = new bool[n, n];
            for (int i = 0; i < n-1; i++)
            {
                str = Console.ReadLine().Split();
                var a = Int32.Parse(str[0]) - 1;
                var b = Int32.Parse(str[1]) - 1;
                graph[a, b] = true;
                graph[b, a] = true;
            }

            Console.WriteLine(Solver.Solve(n, k, graph));
        }
    }

    public class Solver
    {
        static int _n;
        static List<List<int>> _nodes;

        static HashSet<int>[] dp;

        public static int Solve(int n, int k, bool[,] graph)
        {
            _n = n;

            _nodes = new List<List<int>>();
            for (int i = 0; i < n; i++)
            {
                var l = new List<int>();
                for (int j = 0; j < _n; j++)
                {
                    if (graph[i, j]) l.Add(j);
                }
                _nodes.Add(l);
            }

            var ret = Int32.MaxValue;
            dp = new HashSet<int>[n];

            if (k % 2 == 0)
            {
                for (int i = 0; i < _n; i++)
                {
                    if (k % 2 == 0)
                    {
                        var tgtNodes = GetFarNodes(i, k / 2);
                        ret = Math.Min(ret, tgtNodes.Count());
                    }
                }
            }
            else
            {
                var used = new bool[n, n];
                for (int i = 0; i < _n; i++)
                {
                    foreach (var j in _nodes[i])
                    {
                        if (used[i, j] || used[j, i]) continue;
                        var tgtNodesI = GetFarNodes(i, k / 2);
                        var tgtNodesJ = GetFarNodes(j, k / 2);
                        ret = Math.Min(ret, tgtNodesI.Intersect(tgtNodesJ).Count());
                        used[i, j] = true;
                        used[j, i] = true;
                    }
                }
            }

            return ret;
        }


        static HashSet<int> GetFarNodes(int idx, int dist)
        {
            if (dp[idx] != null) return dp[idx];

            var visit = new bool[_n];
            var ret = new HashSet<int>();
            Dfs(visit, ret, idx, 0, dist);

            dp[idx] = ret;
            return ret;
        }

        static void Dfs(bool[] visit, HashSet<int> ret, int idx, int currentDist, int maxDist)
        {
            if (visit[idx]) return;
            visit[idx] = true;

            if (currentDist > maxDist) ret.Add(idx);
            foreach(var next in _nodes[idx])
            {
                if (next == idx) continue;
                if (visit[next]) continue;
                Dfs(visit, ret, next, currentDist + 1, maxDist);
            }
        }
    }
}