using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_C
{
    class _015
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            var nameDict = new Dictionary<string, int>();
            var nameDictRev = new Dictionary<int, string>();
            var graph = new List<List<Edge>>();
            var graphRev = new List<List<Edge>>();
            for (int i = 0; i < n; i++)
            {
                string[] strs = Read().Split();
                if (!nameDict.ContainsKey(strs[0]))
                {
                    nameDict.Add(strs[0], graph.Count);
                    nameDictRev.Add(graph.Count, strs[0]);
                    graph.Add(new List<Edge>());
                    graphRev.Add(new List<Edge>());
                }
                if (!nameDict.ContainsKey(strs[2]))
                {
                    nameDict.Add(strs[2], graph.Count);
                    nameDictRev.Add(graph.Count, strs[2]);
                    graph.Add(new List<Edge>());
                    graphRev.Add(new List<Edge>());
                }
                graph[nameDict[strs[2]]].Add(
                    new Edge(nameDict[strs[0]], int.Parse(strs[1])));
                graphRev[nameDict[strs[0]]].Add(
                    new Edge(nameDict[strs[2]], int.Parse(strs[1])));
            }

            int length = graph.Count;
            double res = 0;
            string maxName = "";
            string minName = "";
            for (int i = 0; i < length; i++)
            {
                bool[] visited = new bool[length];
                double[] dists = new double[length];
                dists[i] = 1;

                Queue<int> queue = new Queue<int>();
                queue.Enqueue(i);
                visited[i] = true;

                while (queue.Count > 0)
                {
                    int index = queue.Dequeue();
                    for (int j = 0; j < graph[index].Count; j++)
                    {
                        int to = graph[index][j].to;
                        if (visited[to]) continue;

                        visited[to] = true;
                        dists[to]= dists[index]
                            * graph[index][j].len;
                        queue.Enqueue(to);
                    }
                    for (int j = 0; j < graphRev[index].Count; j++)
                    {
                        int to = graphRev[index][j].to;
                        if (visited[to]) continue;

                        visited[to] = true;
                        dists[to] = dists[index] / graphRev[index][j].len;
                        queue.Enqueue(to);
                    }
                }

                for(int j = 0; j < length; j++)
                {
                    if (res < dists[j])
                    {
                        minName = nameDictRev[i];
                        maxName = nameDictRev[j];
                        res =dists[j];
                    }
                }
            }
            WriteLine(1 + maxName + "=" + Round(res) + minName);
        }

        class Edge
        {
            public int to;
            public long len;
            
            public Edge(int to,long len)
            {
                this.to = to;
                this.len = len;
            }
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