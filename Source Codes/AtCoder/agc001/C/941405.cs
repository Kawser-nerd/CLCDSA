using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Pair = System.Collections.Generic.KeyValuePair<int, int>;
namespace AGC001_C2
{
    class Edge
    {
        public int t;
        public int w;
        public Edge(int t)
        {
            this.t = t;
            w = 1;
        }
    }

    class Program
    {
        const int MAX = 3000;
        const int INF = 1 << 30;
        static int N, K;
        static int[] d;
        static List<Edge>[] G = Enumerable.Range(0, MAX).Select(i => new List<Edge>()).ToArray();
        

        static void Main(string[] args)
        {
            var H = new List<Pair>();

            var t = scan;
            N = t[0]; K = t[1];
            for (int i = 0; i < N - 1; i++)
            {
                t = scan; t[0]--; t[1]--;
                G[t[0]].Add(new Edge(t[1]));
                G[t[1]].Add(new Edge(t[0]));
                H.Add(new Pair(t[0], t[1]));
            }

            int ans = int.MaxValue;

            if (K % 2 == 0)
            {
                for (int i = 0; i < N; i++)
                {
                    bfs(i);
                    //Console.WriteLine(string.Join(" ", d));
                    ans = Math.Min(ans, d.Count(s => s > K / 2));
                }
            }
            else
            {
                foreach (var h in H)
                {
                    bfs(h.Key, h.Value);
                    //Console.WriteLine(string.Join(" ", d));
                    ans = Math.Min(ans, d.Count(s => s > K / 2));
                }
            }
            Console.WriteLine(ans);
            
        }
        static void bfs(int s)
        {
            d = Enumerable.Repeat(INF, N).ToArray();
            var Q = new Queue<int>();
            Q.Enqueue(s);
            d[s] = 0;
            int u;
            while (Q.Any())
            {
                u = Q.Dequeue();
                for (int i = 0; i < G[u].Count; i++)
                {
                    Edge e = G[u][i];
                    if (d[e.t] == INF)
                    {
                        d[e.t] = d[u] + e.w;
                        Q.Enqueue(e.t);
                    }
                }
            }
        }
        static void bfs(int s, int s2)
        {
            d = Enumerable.Repeat(INF, N).ToArray();
            var Q = new Queue<int>();
            Q.Enqueue(s);
            d[s] = 0;
            Q.Enqueue(s2);
            d[s2] = 0;
            int u;
            while (Q.Any())
            {
                u = Q.Dequeue();
                for (int i = 0; i < G[u].Count; i++)
                {
                    Edge e = G[u][i];
                    if (d[e.t] == INF)
                    {
                        d[e.t] = d[u] + e.w;
                        Q.Enqueue(e.t);
                    }
                }
            }
        }
        static int[] scan { get { return Array.ConvertAll(Console.ReadLine().Split(), int.Parse); } }
    }
}