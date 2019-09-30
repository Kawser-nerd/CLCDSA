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
            Edge e1 = new Edge {a = a, b = b, cap = cap, flow = 0};
            Edge e2 = new Edge {a = b, b = a, cap = 0, flow = 0};
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
            for (;;)
            {
                if (!bfs()) break;
                ptr = new int[n];
                for (;;)
                {
                    int pushed = dfs(source, int.MaxValue);
                    if (pushed == 0) break;
                    flow += pushed;
                }
            }
            return flow;
        }

#if DEBUG
        static readonly TextReader input = File.OpenText(@"../../A/C-small-attempt0.in");
        static readonly TextWriter output = File.CreateText(@"../../A/A.out");
        //static readonly TextReader input = Console.In;
        //static readonly TextWriter output = Console.Out;
#else
        static readonly TextReader input = Console.In;
        static readonly TextWriter output = Console.Out;
#endif

        class Horse
        {
            public decimal distForHorse;
            public decimal timeAlready;
        };

        private static void SolveA()
        {
            int T = int.Parse(input.ReadLine());
            //int[] inp = input.ReadLine().Split(' ').Select(int.Parse).ToArray();
            for (int test = 0; test < T; ++test)
            {
                decimal[] inp = input.ReadLine().Split(' ').Select(decimal.Parse).ToArray();
                int n = (int) inp[0], Q = (int) inp[1];

                decimal[] can = new decimal[n];
                decimal[] speed = new decimal[n];

                decimal[][] city = new decimal[n][];
                for (int i = 0; i < n; ++i)
                {
                    inp = input.ReadLine().Split(' ').Select(decimal.Parse).ToArray();
                    can[i] = inp[0];
                    speed[i] = inp[1];
                }
                for (int i = 0; i < n; ++i)
                {
                    city[i] = input.ReadLine().Split(' ').Select(decimal.Parse).ToArray();
                    city[i][i] = 0;
                }

                StringBuilder sb = new StringBuilder();
                for (int q = 0; q < Q; ++q)
                {
                    inp = input.ReadLine().Split(' ').Select(decimal.Parse).ToArray();
                    int start = -1 + (int) inp[0], end = -1 + (int) inp[1];
                    Horse[,] all = new Horse[n, n];
                    all[start, start] = new Horse
                    {
                        distForHorse = 0,
                        timeAlready = 0
                    };

                    for (int i = 0; i + 1 < n; ++i)
                    {
                        int ne = i + 1;

                        all[ne, ne] = new Horse
                        {
                            distForHorse = 0,
                            timeAlready = decimal.MaxValue
                        };

                        for (int horse = 0; horse < n; ++horse)
                        {
                            if (all[i, horse] != null)
                            {
                                if (all[i, horse].distForHorse + city[i][ne] <= can[horse])
                                {
                                    all[ne, horse] = new Horse
                                    {
                                        distForHorse = all[i, horse].distForHorse + city[i][ne],
                                        timeAlready = all[i, horse].timeAlready
                                    };

                                    decimal addTime = (all[i, horse].distForHorse + city[i][ne]) / speed[horse];
                                    if (addTime + all[i, horse].timeAlready < all[ne, ne].timeAlready)
                                    {
                                        all[ne, ne].timeAlready = addTime + all[i, horse].timeAlready;
                                    }
                                }
                            }
                        }
                    }

                    decimal res = decimal.MaxValue;
                    for (int horse = 0; horse < n; ++horse)
                    {
                        if (all[end, horse] == null) continue;
                        decimal addTime = all[end, horse].distForHorse / speed[horse];
                        if (addTime + all[end, horse].timeAlready < res)
                            res = addTime + all[end, horse].timeAlready;
                    }
                    sb.Append(res + " ");
                }
                output.WriteLine("Case #{0}: {1}", test + 1, sb);
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