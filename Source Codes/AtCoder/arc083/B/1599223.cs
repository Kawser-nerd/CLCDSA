using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace AtCoder.ARC083
{
    class RestoringRoadNetwork
    {
        public static void Main()
        {
            var n = int.Parse(ReadLine().Trim());
            var graph = new Graph(n);
            for (var i = 0; i < n; ++i) { 
                var a = ReadLine().Trim().Split(' ').Select(_ => int.Parse(_)).ToArray();
                for (var j = i; j < n; ++j)
                    graph[i, j] = a[j];
            }
            WriteLine(CalMap(graph));
        }
        static long CalMap(Graph graph)
        {
            long res = 0;
            for (var from = 0; from < graph.Size; ++from) {
                for (var to = from + 1; to < graph.Size; ++to) {
                    bool hasEdge = true;
                    for (var mid = 0; mid < graph.Size; ++mid) {
                        if (from != mid && mid != to) {
                            if (graph[from, to] > graph[from, mid] + graph[mid, to]) return -1;
                            else if (graph[from, to] == graph[from, mid] + graph[mid, to]) {
                                mid = graph.Size;
                                hasEdge = false;
                            }
                        }
                    }
                    if (hasEdge) res += graph[from, to];
                }
            }
            return res;
        }
        class Graph
        {
            int[,] map;
            public Graph(int n)
            {
                map = new int[n, n];
            }
            public int Size { get { return map.GetLength(0); } }
            public int this[int from, int to]
            {
                get { return map[from, to]; }
                set { map[from, to] = map[to, from] = value; }
            }
        }
    }
}