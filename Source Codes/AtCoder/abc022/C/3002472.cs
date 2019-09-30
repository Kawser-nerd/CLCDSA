using System;
using System.Collections.Generic;
using System.Linq;

namespace AtTest.C_Challenge.ABC_022
{
    class ABC_022
    {
        static Node[] nodes;

        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int m = int.Parse(input[1]);
            nodes = new Node[n];
            for(int i = 0; i < n; i++)
            {
                nodes[i] = new Node(n);
            }
            for (int i = 0; i < m; i++)
            {
                input = Console.ReadLine().Split(' ');
                int u = int.Parse(input[0]) - 1;
                int v = int.Parse(input[1]) - 1;
                int l = int.Parse(input[2]);
                nodes[u].edges.Add(new Edge(v, l));
                nodes[v].edges.Add(new Edge(u, l));
            }

            long minDistance = -1;
            for(int i = 0; i < nodes[0].edges.Count; i++)
            {
                InitializeNodeDistance(n);
                Edge subEdge = nodes[0].edges[0];
                int subIndex = subEdge.toIndex;
                nodes[0].edges.RemoveAt(0);
                nodes[subIndex].edges.RemoveAll(x => x.toIndex == 0);
                long distance = subEdge.distance;
                nodes[subIndex].distances[subIndex] = 0;
                nodes[subIndex].isMin[subIndex] = true;

                var posQueue = new Queue<int>();
                Dijkstra(subEdge.toIndex);
                distance += nodes[subEdge.toIndex].distances[0];
                if (nodes[subEdge.toIndex].distances[0] != -1
                    && (minDistance == -1 || distance < minDistance))
                {
                    minDistance = distance;
                }

                nodes[0].edges.Add(subEdge);
                nodes[subEdge.toIndex].edges.Add(new Edge(0, subEdge.distance));

            }
            Console.WriteLine(minDistance);
        }

        static void InitializeNodeDistance(int n)
        {
            for (int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    nodes[i].distances[j] = -1;
                    nodes[i].isMin[j] = false;
                }
            }
        }

        //???????
        static long Dijkstra(int start)
        {
            Node startNode = nodes[start];
            int cnt = 1;
            int nowIndex = start;

            while (cnt < nodes.Length)
            {
                for (int i = 0; i < nodes[nowIndex].edges.Count; i++)
                {
                    int destIndex = nodes[nowIndex].edges[i].toIndex;
                    if (startNode.isMin[destIndex]) continue;//????????

                    long distance = startNode.distances[nowIndex]
                        + nodes[nowIndex].edges[i].distance;
                    if (distance < startNode.distances[destIndex]
                        || startNode.distances[destIndex] == -1)
                    {
                        startNode.distances[destIndex] = distance;
                    }
                }

                int settleIndex = -1;
                for (int i = 0; i < startNode.distances.Length; i++)
                {
                    if (startNode.isMin[i] || startNode.distances[i] == -1) continue;

                    if (settleIndex == -1
                        || startNode.distances[i] < startNode.distances[settleIndex])
                    {
                        settleIndex = i;
                    }
                }
                if (settleIndex == -1) break;
                startNode.isMin[settleIndex] = true;
                nowIndex = settleIndex;
                cnt++;
            }

            long maxDistance = 0;
            for (int i = 0; i < startNode.distances.Length; i++)
            {
                if (maxDistance < startNode.distances[i])
                {
                    maxDistance = startNode.distances[i];
                }
            }

            return maxDistance;
        }
    }

    class Node
    {
        public long[] distances;
        public bool[] isMin;
        public List<Edge> edges;
        public Node(int length)
        {
            distances = new long[length];
            isMin = new bool[length];
            for (int i = 0; i < length; i++)
            {
                distances[i] = -1;
            }
            edges = new List<Edge>();
        }
    }

    class Edge
    {
        public int toIndex;
        public int distance;

        public Edge(int toIndex, int distance)
        {
            this.toIndex = toIndex;
            this.distance = distance;
        }
    }
}