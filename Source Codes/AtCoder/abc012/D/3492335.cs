using System;
using System.Collections.Generic;
using System.Linq;

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
                nodes[i].distances[i] = 0;
                nodes[i].isMin[i] = true;
            }

            for (int i = 0; i < m; i++)
            {
                string[] nodeInput = Console.ReadLine().Split(' ');
                int n1 = int.Parse(nodeInput[0]) - 1;
                int n2 = int.Parse(nodeInput[1]) - 1;
                int t = int.Parse(nodeInput[2]);
                nodes[n1].edges.Add(new Edge(n2, t));
                nodes[n2].edges.Add(new Edge(n1, t));
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
            var pQueue = new PriorityQueue<long, int>();

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

            public Edge(int toIndex, int distance)
            {
                this.toIndex = toIndex;
                this.distance = distance;
            }
        }

        public class PriorityQueue<TKey, TValue>
        {
            SortedDictionary<TKey, Queue<TValue>> dict
                = new SortedDictionary<TKey, Queue<TValue>>();

            public int Count { get; private set; } = 0;

            public void Add(TKey key, TValue value)
            {
                if (!dict.ContainsKey(key))
                {
                    dict[key] = new Queue<TValue>();
                }

                dict[key].Enqueue(value);
                Count++;
            }

            public KeyValuePair<TKey, TValue> Dequeue()
            {
                var queue = dict.First();
                if (queue.Value.Count <= 1)
                {
                    dict.Remove(queue.Key);
                }
                Count--;
                return new KeyValuePair<TKey, TValue>(
                    queue.Key, queue.Value.Dequeue());
            }
        }
    }
}