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
        static long Dijkstra(int start)
        {
            Node startNode = nodes[start];
            int cnt = 1;
            int nowIndex = start;
            var pQueue = new PriorityQueue<long, int>();
            var pDict = new Dictionary<int, long>();

            for(int i = 0; i < startNode.distances.Length; i++)
            {
                startNode.distances[i] = -1;
            }
            startNode.distances[start] = 0;

            while (cnt < nodes.Length)
            {
                Node nowNode = nodes[nowIndex];
                for (int i = 0; i < nowNode.edges.Count; i++)
                {
                    int destIndex = nowNode.edges[i].toIndex;
                    if (startNode.distances[destIndex] >= 0)
                    {
                        continue;//????????
                    }

                    long distance = startNode.distances[nowIndex]
                        + nowNode.edges[i].distance;
                    if ((pDict.ContainsKey(destIndex)
                       && distance < pDict[destIndex]))
                    {
                        pQueue.RemoveKeyValue(pDict[destIndex], destIndex);
                        pQueue.Add(distance, destIndex);
                        pDict[destIndex] = distance;
                    }
                    else if (!pDict.ContainsKey(destIndex))
                    {
                        pQueue.Add(distance, destIndex);
                        pDict.Add(destIndex, distance);
                    }
                }

                if (pQueue.Count == 0) break;
                var pair = pQueue.Dequeue();
                pDict.Remove(pair.Value);
                nowIndex = pair.Value;
                startNode.distances[nowIndex] = pair.Key;
                cnt++;
            }
            return startNode.distances[nowIndex];
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
            public int distance;

            public Edge(int toIndex, int distance)
            {
                this.toIndex = toIndex;
                this.distance = distance;
            }
        }

        public class PriorityQueue<TKey, TValue>
        {
            SortedDictionary<TKey, Dictionary<TValue, bool>> dict
                = new SortedDictionary<TKey, Dictionary<TValue, bool>>();

            public int Count { get; private set; } = 0;

            public void Add(TKey key, TValue value)
            {
                if (!dict.ContainsKey(key))
                {
                    dict[key] = new Dictionary<TValue, bool>();
                }

                dict[key].Add(value, true);
                Count++;
            }

            public KeyValuePair<TKey, TValue> Dequeue(bool reverse = false)
            {
                KeyValuePair<TKey, Dictionary<TValue, bool>> queue;
                if (reverse)
                {
                    queue = dict.Last();
                }
                else
                {
                    queue = dict.First();
                }
                if (queue.Value.Count <= 1)
                {
                    dict.Remove(queue.Key);
                }
                Count--;
                TValue val = queue.Value.First().Key;
                queue.Value.Remove(val);
                return new KeyValuePair<TKey, TValue>(
                    queue.Key, val);
            }

            public void RemoveKeyValue(TKey key, TValue val)
            {
                if (!dict.ContainsKey(key)) return;
                if (!dict[key].ContainsKey(val)) return;

                var valDict = dict[key];
                if (valDict.Count <= 1)
                {
                    dict.Remove(key);
                }
                else
                {
                    valDict.Remove(val);
                }
                Count--;
            }
        }
    }
}