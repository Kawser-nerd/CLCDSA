using System;
using System.Linq;

namespace arc037_b
{
    class Program
    {
        static bool[,] edge;
        static bool ok;
        static bool[] visited;
        static void DFS(int back, int x)
        {
            if (visited[x]) { ok = false; return; }
            visited[x] = true;
            for (int i = 0; i < visited.Count(); i++)
            {
                if (i == back) continue;
                if (edge[x, i]) DFS(x, i);
            }
            return;
        }
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            edge = new bool[x[0], x[0]];
            for (int i = 0; i < x[1]; i++)
            {
                int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
                a[0]--; a[1]--;
                edge[a[0], a[1]] = true; edge[a[1], a[0]] = true;
            }
            visited = new bool[x[0]]; int ret = 0;
            for (int i = 0; i < x[0]; i++)
            {
                if (!visited[i])
                {
                    ok = true;
                    DFS(-114514, i);
                    if (ok) ret++;
                }
            }
            Console.WriteLine(ret);
        }
    }
}