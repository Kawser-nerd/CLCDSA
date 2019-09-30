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

            var e = new List<List<int>>();
            for (int i = 0; i < n; i++) e.Add(new List<int>());

            for (int i = 0; i < n - 1; i++)
            {
                str = Console.ReadLine().Split();
                var a = Int32.Parse(str[0]) - 1;
                var b = Int32.Parse(str[1]) - 1;
                e[a].Add(b);
                e[b].Add(a);
            }

            Console.WriteLine(Solver.Solve(n, k, e));
        }
    }

    public class Solver
    {
        static int maxDist;
        static List<List<int>> edges;

        public static int Solve(int n, int k, List<List<int>> e)
        {
            maxDist = k / 2;
            edges = e;

            var ret = Int32.MaxValue;
            for (int i = 0; i < n; i++ )
            {
                if (k % 2 == 0)
                    ret = Math.Min(ret, Dfs(i, -1, 0));
                else
                    foreach(var j in e[i]) 
                        ret = Math.Min(ret, Dfs(i, j, 0) + Dfs(j, i, 0));
            }
            return ret;
        }

        static int Dfs(int cur, int prev, int dist)
        {
            var ret = dist > maxDist ? 1 : 0;
            foreach (var next in edges[cur])
            {
                if (next == prev) continue;
                ret += Dfs(next, cur, dist + 1);
            }
            return ret;
        }
    }
}