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

            long minDistance = long.MaxValue;
            for (int i = 0; i < n; i++)
            {
                long distance = Dijkstra(i);
                minDistance = Math.Min(minDistance, distance);
            }
            Console.WriteLine(minDistance);
        }

        //???????
        static long Dijkstra(int startIndex)
        {
            Node startNode = nodes[startIndex];
            int nowIndex = startIndex;
            var pQueue = new PriorityQueueNum();
            var visiteds = new bool[nodes.Length];

            for(int i = 0; i < startNode.distances.Length; i++)
            {
                startNode.distances[i] = long.MaxValue;
                visiteds[i] = false;
            }
            pQueue.Add(0, startIndex);
            startNode.distances[startIndex] = 0;
            long maxDistance = 0;

            while (pQueue.Count > 0)
            {
                KeyValuePair<long, int> pair = pQueue.Dequeue();
                long distance = pair.Key;
                nowIndex = pair.Value;

                if (startNode.distances[nowIndex] < distance) continue;

                Node nowNode = nodes[nowIndex];
                visiteds[nowIndex] = true;
                maxDistance = Math.Max(maxDistance, distance);

                for (int i = 0; i < nowNode.edges.Count; i++)
                {
                    int nextIndex = nowNode.edges[i].toIndex;
                    if (visiteds[nextIndex]) continue;

                    long nextDistance = distance + nowNode.edges[i].distance;
                    if (startNode.distances[nextIndex]>nextDistance)
                    {
                        startNode.distances[nextIndex] = nextDistance;
                        pQueue.Add(nextDistance, nextIndex);
                    }
                }
            }
            return maxDistance;
        }

        class Node
        {
            public long[] distances;
            public List<Edge> edges;
            public Node(int length)
            {
                distances = new long[length];
                edges = new List<Edge>();
            }
        }

        class Edge
        {
            public int toIndex;
            public long distance;

            public Edge(int toIndex, long distance)
            {
                this.toIndex = toIndex;
                this.distance = distance;
            }
        }

        public class PriorityQueueNum
        {
            SortedDictionary<long, Queue<int>> dict
                = new SortedDictionary<long, Queue<int>>();

            public int Count { get; private set; } = 0;
            bool reverse = false;

            public PriorityQueueNum(bool reverse = false)
            {
                this.reverse = reverse;
            }

            public void Add(long key, int value)
            {
                if (reverse) key = -key;
                if (!dict.ContainsKey(key))
                {
                    dict[key] = new Queue<int>();
                }
                dict[key].Enqueue(value);
                Count++;
            }

            public KeyValuePair<long, int> Dequeue()
            {
                KeyValuePair<long, Queue<int>> queue = dict.First();
                if (queue.Value.Count <= 1)
                {
                    dict.Remove(queue.Key);
                }
                Count--;
                long key = queue.Key;
                if (reverse) key = -key;
                return new KeyValuePair<long, int>(
                    key, queue.Value.Dequeue());
            }
        }
    }
}