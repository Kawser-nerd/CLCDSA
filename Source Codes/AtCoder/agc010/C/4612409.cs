using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.AGC_Challenge
{
    class _010_C
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            long[] cnts = ReadLongs();
            List<int>[] graph = new List<int>[n];
            for (int i = 0; i < n; i++) graph[i] = new List<int>();
            for(int i = 0; i < n - 1; i++)
            {
                int[] ab = ReadInts();
                int a = ab[0] - 1;
                int b = ab[1] - 1;
                graph[a].Add(b);
                graph[b].Add(a);
            }
            bool[] visited = new bool[n];
            Stack<int> stack = new Stack<int>();
            bool ok = true;
            long cnt = DFS(graph, cnts, ref visited, ref ok, 0);
            if (ok && cnt != 0 && cnt != cnts[0]) ok = false;
            WriteLine(ok ? "YES" : "NO");
        }

        static long DFS(List<int>[] graph,long[] cnts,
            ref bool[] visited, ref bool ok, int now)
        {
            if (!ok) return 0;

            visited[now] = true;
            long cnt = 0;
            int nodes = 0;
            for(int i = 0; i < graph[now].Count; i++)
            {
                if (visited[graph[now][i]]) continue;
                nodes++;
                long tmp = DFS(graph, cnts,
                    ref visited, ref ok, graph[now][i]);
                if (cnts[now] < tmp)
                {
                    ok = false;
                    return 0;
                }
                cnt += tmp;
            }
            if (nodes == 0) return cnts[now];
            if (cnt < cnts[now] || cnt > cnts[now] * 2)
            {
                ok = false;
                return 0;
            }
            return cnts[now] * 2 - cnt;
        }

        private static string Read() { return ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}