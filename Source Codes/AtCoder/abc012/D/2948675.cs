using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.Dijkstra
{
    class ABC_012_D
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
            for (int i = 0; i < n; i++)
            {
                nodes[i] = new Node(n);
                nodes[i].isMin[i] = true;
                nodes[i].distances[i] = 0;
            }

            for (int i = 0; i < m; i++)
            {
                string[] nodeInput = Console.ReadLine().Split(' ');
                int n1 = int.Parse(nodeInput[0]) - 1;
                int n2 = int.Parse(nodeInput[1]) - 1;
                int t = int.Parse(nodeInput[2]);
                nodes[n1].edgeTo.Add(n2);
                nodes[n1].edgeDistances.Add(t);
                nodes[n2].edgeTo.Add(n1);
                nodes[n2].edgeDistances.Add(t);
            }

            long minDistance = 0;
            for (int i = 0; i < n; i++)
            {
                long distance = Dijkstra(i);
                if (i == 0 || distance < minDistance)
                {
                    minDistance = distance;
                }
            }
            Console.WriteLine(minDistance);
        }

        //???????
        static long Dijkstra(int start)
        {
            Node startNode = nodes[start];
            int cnt = 1;
            int nowIndex = start;

            while (cnt < nodes.Length)
            {
                for (int i = 0; i < nodes[nowIndex].edgeTo.Count; i++)
                {
                    int destIndex = nodes[nowIndex].edgeTo[i];
                    if (startNode.isMin[destIndex]) continue;//????????

                    long distance = startNode.distances[nowIndex]
                        + nodes[nowIndex].edgeDistances[i];
                    if (distance < startNode.distances[destIndex]
                        || startNode.distances[destIndex] == -1)
                    {
                        startNode.distances[destIndex] = distance;
                    }
                }

                int settleIndex = -1;
                for (int i = 0; i < startNode.distances.Length; i++)
                {
                    //Console.WriteLine(startNode.distances[i]);
                    if (startNode.isMin[i] || startNode.distances[i] == -1) continue;

                    if (settleIndex == -1
                        || startNode.distances[settleIndex] > startNode.distances[i])
                    {
                        settleIndex = i;
                    }
                }
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
        public List<int> edgeTo;
        public List<long> edgeDistances;
        public Node(int length)
        {
            distances = new long[length];
            isMin = new bool[length];
            for (int i = 0; i < length; i++)
            {
                distances[i] = -1;
            }
            edgeTo = new List<int>();
            edgeDistances = new List<long>();
        }
    }

    class Edge
    {
        public int toIndex;
        public int distance;

        public Edge(int to,int dist)
        {
            toIndex = to;
            distance = dist;
        }
    }
}