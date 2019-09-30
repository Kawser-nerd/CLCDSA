using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_079
    {
        static Node[] nodes;

        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] hw = ReadInts();
            nodes = new Node[10];
            for(int i = 0; i < 10; i++)
            {
                int[] costs = ReadInts();
                nodes[i] = new Node(10);
                for(int j = 0; j < 10; j++)
                {
                    if (i == j) continue;
                    nodes[i].edges.Add(new Edge(j, costs[j]));
                }
            }
            var oneCost = new int[10];
            for(int i = 0; i < 10; i++)
            {
                if (i == 1)
                {
                    oneCost[i] = 0;
                }
                else
                {
                    InitializeNodes();
                    Dijkstra(i);
                    oneCost[i] = (int)nodes[i].distances[1];
                }
                //Console.WriteLine(oneCost[i]);
            }

            int res = 0;
            for(int i = 0; i < hw[0]; i++)
            {
                int[] wall = ReadInts();
                for(int j = 0; j < hw[1]; j++)
                {
                    res += wall[j] == -1 ? 0 : oneCost[wall[j]];
                }
            }
            Console.WriteLine(res);
        }

        static void InitializeNodes()
        {
            for (int i = 0; i < nodes.Length; i++)
            {
                for (int j = 0; j < nodes.Length; j++)
                {
                    nodes[i].distances[j] = -1;
                    nodes[i].isMin[j] = false;
                }
                nodes[i].distances[i] = 0;
                nodes[i].isMin[i] = true;
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

        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
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