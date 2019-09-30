using System;
using System.Collections.Generic;
using System.Linq;

namespace AtTest.Dijkstra
{
    class ABC_051
    {
        static Node[] nodes;
        static Dictionary<int, bool> usedDict;

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
            for (int i = 0; i < n; i++)
            {
                nodes[i] = new Node(n);
                nodes[i].distances[i] = 0;
                nodes[i].isMin[i] = true;
            }

            for (int i = 0; i < m; i++)
            {
                string[] nodeInput = Console.ReadLine().Split(' ');
                int n1 = int.Parse(nodeInput[0]) - 1;
                int n2 = int.Parse(nodeInput[1]) - 1;
                int t = int.Parse(nodeInput[2]);
                nodes[n1].edges.Add(new Edge(n2, t, i));
                nodes[n2].edges.Add(new Edge(n1, t, i));
            }

            usedDict = new Dictionary<int, bool>();
            for (int i = 0; i < n; i++)
            {
                Dijkstra(i);
                /*for(int j = 0; j < n; j++)
                {
                    Console.Write(nodes[i].distances[j] + " ");
                }
                Console.WriteLine();*/
            }
            
            /*for(int i = 0; i < n-1; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    int now = j;
                    while (now != i)
                    {
                        int next = now;
                        int edgeId = -1;
                        for (int k = 0; k < nodes[now].edges.Count; k++)
                        {
                            int index = nodes[now].edges[k].toIndex;
                            if (nodes[i].distances[index]
                                < nodes[i].distances[next])
                            {
                                next = k;
                                edgeId = nodes[now].edges[k].id;
                            }
                        }
                        if (!usedDict.ContainsKey(edgeId))
                        {
                            usedDict.Add(edgeId, true);
                        }
                        Console.WriteLine(edgeId);
                        now = next;
                    }
                }
            }*/
            Console.WriteLine(m - usedDict.Count);
        }

        //???????
        static long Dijkstra(int start)
        {
            Node startNode = nodes[start];
            int cnt = 1;
            int nowIndex = start;

            while (cnt < nodes.Length)
            {
                Node nowNode = nodes[nowIndex];
                for (int i = 0; i < nowNode.edges.Count; i++)
                {
                    int destIndex = nowNode.edges[i].toIndex;
                    if (startNode.isMin[destIndex]) continue;//????????

                    long distance = startNode.distances[nowIndex]
                        + nowNode.edges[i].distance;
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
                for (int i = 0; i < nodes[nowIndex].edges.Count; i++)
                {
                    int pair = nodes[nowIndex].edges[i].toIndex;
                    if (!usedDict.ContainsKey(nodes[nowIndex].edges[i].id)
                        && startNode.isMin[pair]
                        && startNode.distances[nowIndex]
                        == startNode.distances[pair]
                        + nodes[nowIndex].edges[i].distance)
                    {
                        usedDict.Add(nodes[nowIndex].edges[i].id, true);
                        break;
                    }
                }
            }
            return startNode.distances[nowIndex];
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
            public int id;

            public Edge(int toIndex, int distance,int id)
            {
                this.toIndex = toIndex;
                this.distance = distance;
                this.id = id;
            }
        }
    }
}