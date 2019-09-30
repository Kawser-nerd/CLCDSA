using System;
using System.Collections.Generic;
using System.Dynamic;
using System.Globalization;
using System.IO;
//using System.Linq;
using System.Text;

namespace ContestRuns
{
    using System.ComponentModel;
    using System.Linq;
    using System.ServiceProcess;

    class Program
    {
        class Edge
        {
            public int a, b, cap, flow;
        };

        private static int n, source, target;
        private static int[] d, ptr, q;
        private static List<Edge> e = new List<Edge>();
        private static List<List<int>> g;

        static void add_edge(int a, int b, int cap)
        {
            Edge e1 = new Edge { a = a, b = b, cap = cap, flow = 0 };
            Edge e2 = new Edge { a = b, b = a, cap = 0, flow = 0 };
            g[a].Add(e.Count);
            e.Add(e1);
            g[b].Add(e.Count);
            e.Add(e2);
        }

        static bool bfs()
        {
            int qh = 0, qt = 0;
            q[qt++] = source;

            d = Enumerable.Repeat(-1, n).ToArray();
            d[source] = 0;
            while (qh < qt && d[target] == -1)
            {
                int v = q[qh++];
                for (int i = 0; i < g[v].Count; ++i)
                {
                    int id = g[v][i],
                        to = e[id].b;
                    if (d[to] == -1 && e[id].flow < e[id].cap)
                    {
                        q[qt++] = to;
                        d[to] = d[v] + 1;
                    }
                }
            }
            return d[target] != -1;
        }

        static int dfs(int v, int flow)
        {
            if (flow <= 0) return 0;
            if (v == target) return flow;
            for (; ptr[v] < g[v].Count; ++ptr[v])
            {
                int id = g[v][ptr[v]],
                    to = e[id].b;
                if (d[to] != d[v] + 1) continue;
                int pushed = dfs(to, Math.Min(flow, e[id].cap - e[id].flow));
                if (pushed != 0)
                {
                    e[id].flow += pushed;
                    e[id ^ 1].flow -= pushed;
                    return pushed;
                }
            }
            return 0;
        }

        static int dinic()
        {
            int flow = 0;
            for (; ; )
            {
                if (!bfs()) break;
                ptr = new int[n];
                for (; ; )
                {
                    int pushed = dfs(source, int.MaxValue);
                    if (pushed == 0) break;
                    flow += pushed;
                }
            }
            return flow;
        }

#if DEBUG
        static readonly TextReader input = File.OpenText(@"../../A/A-large.in");
        static readonly TextWriter output = File.CreateText(@"../../A/A.out");
        //static readonly TextReader input = Console.In;
        //static readonly TextWriter output = Console.Out;
#else
        static readonly TextReader input = Console.In;
        static readonly TextWriter output = Console.Out;
#endif

        private static void SolveA()
        {
            int T = int.Parse(input.ReadLine());
            //int[] inp = input.ReadLine().Split(' ').Select(int.Parse).ToArray();
            for (int test = 0; test < T; ++test)
            {
                decimal[] inp = input.ReadLine().Split(' ').Select(decimal.Parse).ToArray();
                decimal D = inp[0], n = inp[1];
                decimal result = -1;
                for (int i = 0; i < n; ++i)
                {
                    decimal[] inp1 = input.ReadLine().Split(' ').Select(decimal.Parse).ToArray();
                    decimal k = inp1[0], s = inp1[1];
                    decimal cur = D*s/(D-k);
                    if (cur < result || result == -1) result = cur;
                }
                output.WriteLine("Case #{0}: {1}", test + 1, result);
            }
        }

        static void Main(string[] args)
        {
            SolveA();
            output.Flush();
        }
    }

    
}