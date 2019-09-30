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
        static readonly TextReader input = File.OpenText(@"../../A/B-large.in");
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
                int[] inp = input.ReadLine().Split(' ').Select(int.Parse).ToArray();
                int d1 = inp[0 + 1],
                    d12 = inp[1 + 1],
                    d2 = inp[2 + 1],
                    d23 = inp[3 + 1],
                    d3 = inp[4 + 1],
                    d31 = inp[5 + 1];

                d1 -= d23;
                d2 -= d31;
                d3 -= d12;

                if (d1 < 0 || (d1 == 0 && d23 > 0 && (d2 + d3 + d12 + d31) > 0))
                {
                    output.WriteLine("Case #{0}: {1}", test + 1, "IMPOSSIBLE");
                    continue;
                }

                if (d2 < 0 || (d2 == 0 && d31 > 0 && (d1 + d3 + d12 + d23) > 0))
                {
                    output.WriteLine("Case #{0}: {1}", test + 1, "IMPOSSIBLE");
                    continue;
                }

                if (d3 < 0 || (d3 == 0 && d12 > 0 && (d2 + d1 + d23 + d31) > 0))
                {
                    output.WriteLine("Case #{0}: {1}", test + 1, "IMPOSSIBLE");
                    continue;
                }

                StringBuilder sb = new StringBuilder();
                if (d1 == 0 && d23 > 0 && (d2 + d3 + d12 + d31) == 0)
                {
                    for (; d23 > 0; d23--)
                    {
                        sb.Append("RG");
                    }
                    output.WriteLine("Case #{0}: {1}", test + 1, sb);
                    continue;
                }
                if (d2 == 0 && d31 > 0 && (d1 + d3 + d12 + d23) == 0)
                {
                    for (; d31 > 0; d31--)
                    {
                        sb.Append("YV");
                    }
                    output.WriteLine("Case #{0}: {1}", test + 1, sb);
                    continue;
                }
                if (d3 == 0 && d12 > 0 && (d2 + d1 + d23 + d31) == 0)
                {
                    for (; d12 > 0; d12--)
                    {
                        sb.Append("BO");
                    }
                    output.WriteLine("Case #{0}: {1}", test + 1, sb);
                    continue;
                }
                
                if (d1 == 1 && d2 + d3 == 0)
                {
                    if (d23 > 0)
                    {
                        output.WriteLine("Case #{0}: {1}", test + 1, "IMPOSSIBLE");
                        continue;
                    }
                    d23 = D23(d23, sb);//R
                    output.WriteLine("Case #{0}: {1}", test + 1, sb);
                    continue;
                }
                if (d2 == 1 && d1 + d3 == 0)
                {
                    if (d31 > 0)
                    {
                        output.WriteLine("Case #{0}: {1}", test + 1, "IMPOSSIBLE");
                        continue;
                    }
                    d31 = D31(d31, sb);//Y
                    output.WriteLine("Case #{0}: {1}", test + 1, sb);
                    continue;
                }
                if (d3 == 1 && d2 + d3 == 0)
                {
                    if (d12 > 0)
                    {
                        output.WriteLine("Case #{0}: {1}", test + 1, "IMPOSSIBLE");
                        continue;
                    }
                    d12 = D12(d12, sb);//B
                    output.WriteLine("Case #{0}: {1}", test + 1, sb);
                    continue;
                }

                if (d1 > d2 + d3 || d2 > d1 + d3 || d3 > d1 + d2)
                {
                    output.WriteLine("Case #{0}: {1}", test + 1, "IMPOSSIBLE");
                    continue;
                }
                
                for (; d1 > 0 && d2 > 0 && d3 > 0; d1 -= 1, d2 -= 1, d3 -= 1)
                {
                    d23 = D23(d23, sb);//R
                    d31 = D31(d31, sb);//Y
                    d12 = D12(d12, sb);//B
                }

                for (; d1 > 0 && d2 > 0; d1 -= 1, d2 -= 1)
                {
                    d23 = D23(d23, sb);//R
                    d31 = D31(d31, sb);//Y
                }

                for (; d3 > 0 && d2 > 0; d3 -= 1, d2 -= 1)
                {
                    d31 = D31(d31, sb);//Y
                    d12 = D12(d12, sb);//B
                }

                for (; d3 > 0 && d1 > 0; d3 -= 1, d1 -= 1)
                {
                    d23 = D23(d23, sb);//R
                    d12 = D12(d12, sb);//B
                }

                string res = sb.ToString();
                sb.Clear();
                for (int i = 0; i < res.Length; ++i)
                {
                    char next = (i + 1 < res.Length) ? res[i + 1] : res[0];
                    sb.Append(res[i]);
                    if (d3 > 0 && res[i] == 'R' && next == 'Y')
                    {
                        d3 -= 1;
                        sb.Append("B");
                    }
                    if (d3 > 0 && res[i] == 'Y' && next == 'R')
                    {
                        d3 -= 1;
                        sb.Append("B");
                    }

                    if (d2 > 0 && res[i] == 'R' && next == 'B')
                    {
                        d2 -= 1;
                        sb.Append("Y");
                    }
                    if (d2 > 0 && res[i] == 'B' && next == 'R')
                    {
                        d2 -= 1;
                        sb.Append("Y");
                    }

                    if (d1 > 0 && res[i] == 'Y' && next == 'B')
                    {
                        d1 -= 1;
                        sb.Append("R");
                    }
                    if (d1 > 0 && res[i] == 'B' && next == 'Y')
                    {
                        d1 -= 1;
                        sb.Append("R");
                    }
                }
                if (d1 > 0) 
                    sb.Append("R");
                if (d2 > 0) 
                    sb.Append("Y");
                if (d3 > 0) 
                    sb.Append("B");
                string rs = sb.ToString();
                if (rs.Length > 1 && rs[0] == rs[rs.Length - 1])
                {
                    output.WriteLine("Case #{0}: {1}", test + 1, "IMPOSSIBLE");
                    continue;
                }
                output.WriteLine("Case #{0}: {1}", test + 1, rs);
            }
        }

        private static int D23(int d23, StringBuilder sb)
        {
            if (d23 > 0)
            {
                sb.Append("R");
                for (; d23 > 0; d23--)
                {
                    sb.Append("GR");
                }
            }
            else
            {
                sb.Append("R");
            }
            return d23;
        }
        private static int D31(int d31, StringBuilder sb)
        {
            if (d31 > 0)
            {
                sb.Append("Y");
                for (; d31 > 0; d31--)
                {
                    sb.Append("VY");
                }
            }
            else
            {
                sb.Append("Y");
            }
            return d31;
        }
        private static int D12(int d12, StringBuilder sb)
        {
            if (d12 > 0)
            {
                sb.Append("B");
                for (; d12 > 0; d12--)
                {
                    sb.Append("OB");
                }
            }
            else
            {
                sb.Append("B");
            }
            return d12;
        }

        static void Main(string[] args)
        {
            SolveA();
            output.Flush();
        }
    }

    
}