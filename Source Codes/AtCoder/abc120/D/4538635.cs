using System; 
using System.Collections;

namespace CSharp
{
    class Edge 
    {
        public int x, y;
        public Edge(int _x, int _y)
        {
            x = _x;
            y = _y;
        }
    }

    class Program
    {

        private static int[] parent, size, rank;

        private static int find(int u) 
        {
            if (u == parent[u]) return u;
            return parent[u] = find(parent[u]);
        }

        private static long merge(int u, int v)
        {
            u = find(u); v = find(v);
            if (u == v) return -1L;
            int size_u = size[u], size_v = size[v];
            if (rank[u] < rank[v])
            {
                parent[u] = v;
                size[v] += size[u];
            }
            else
            {
                parent[v] = u;
                size[u] += size[v];
            }
            if (rank[u] == rank[v]) rank[u]++;
            return size_u * (size_u - 1L) * 1L / 2L + size_v * (size_v - 1L) * 1L / 2L;
        }

        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split();
            int n = int.Parse(s[0]);
            int m = int.Parse(s[1]);

            parent = new int[n + 1];
            size = new int[n + 1];
            rank = new int[n + 1];

            Edge[] edges = new Edge[m];
            for (int i = 0; i < m; i++) {
                string[] es = Console.ReadLine().Split();
                int u = int.Parse(es[0]);
                int v = int.Parse(es[1]);

                edges[i] = new Edge(u, v);
            }

            for (int i = 1; i <= n; i++) {
                parent[i] = i;
                size[i] = 1;
            }

            long[] ans = new long[m];
            long tmp = n * (n - 1L) * 1L / 2L;

            for (int i = 0; i < m; i++) {
                ans[m - i - 1] = tmp;
                Edge edge = edges[m - i - 1];
                long delta = merge(edge.x, edge.y);
                if (delta == -1L) continue;
                tmp += delta;
                int nsize = size[find(edge.x)];
                tmp -= nsize * (nsize - 1L) * 1L / 2L;
            }

            for (int i = 0; i < m; i++) {
                Console.WriteLine(ans[i]);
            }
        }
    }
}