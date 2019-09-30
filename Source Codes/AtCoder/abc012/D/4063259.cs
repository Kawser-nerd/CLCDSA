using System;
using System.Collections.Generic;
using System.Linq;

namespace AtTest.Dijkstra
{
    class ABC_012_D
    {
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

            Node[] nodes = new Node[n];
            for (int i = 0; i < n; i++)
            {
                nodes[i] = new Node();
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
            long res = long.MaxValue;
            for(int i = 0; i < n; i++)
            {
                long distance;
                Dijkstra(i, nodes, out distance);
                res = Math.Min(res, distance);
            }
            Console.WriteLine(res);
        }

        //????????
        //?????????
        //?????????
        static long[] Dijkstra(int startIndex,
            Node[] nodes,out long maxDistance)
        {
            Node startNode = nodes[startIndex];
            var pQueue = new PriorityQueue<int>();
            var visitFlags = new bool[nodes.Length];
            var distances = new long[nodes.Length];
            maxDistance = 0;

            //Initialize nodes
            for (int i = 0; i < distances.Length; i++)
            {
                distances[i] = long.MaxValue;
                visitFlags[i] = false;
            }
            pQueue.Enqueue(0, startIndex);
            distances[startIndex] = 0;

            while (pQueue.Exist())
            {
                KeyValuePair<long, int> pair = pQueue.Dequeue();
                long distance = pair.Key;
                int index = pair.Value;

                if (visitFlags[index]) continue;

                //Confirm distances
                Node nowNode = nodes[index];
                visitFlags[index] = true;
                maxDistance = Math.Max(maxDistance, distance);

                //Update priority queue
                for (int i = 0; i < nowNode.edges.Count; i++)
                {
                    int nextIndex = nowNode.edges[i].toIndex;
                    if (visitFlags[nextIndex]) continue;

                    long nextDistance = distance + nowNode.edges[i].distance;
                    if (nextDistance < distances[nextIndex])
                    {
                        distances[nextIndex] = nextDistance;
                        pQueue.Enqueue(nextDistance, nextIndex);
                    }
                }
            }
            return distances;
        }

        class Node
        {
            public List<Edge> edges;
            public Node()
            {
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

        class PriorityQueue<T>
        {
            private readonly List<KeyValuePair<long, T>> list;
            private int count;

            public PriorityQueue()
            {
                list = new List<KeyValuePair<long, T>>();
                count = 0;
            }

            private void Add(KeyValuePair<long, T> pair)
            {
                if (count == list.Count)
                {
                    list.Add(pair);
                }
                else
                {
                    list[count] = pair;
                }
                count++;
            }

            private void Swap(int a, int b)
            {
                KeyValuePair<long, T> tmp = list[a];
                list[a] = list[b];
                list[b] = tmp;
            }

            public void Enqueue(long key, T value)
            {
                Add(new KeyValuePair<long, T>(key, value));
                int c = count - 1;
                while (c > 0)
                {
                    int p = (c - 1) / 2;
                    if (list[c].Key >= list[p].Key) break;

                    Swap(p, c);
                    c = p;
                }
            }

            public KeyValuePair<long, T> Dequeue()
            {
                KeyValuePair<long, T> pair = list[0];
                count--;
                if (count == 0) return pair;

                list[0] = list[count];
                int p = 0;
                while (true)
                {
                    int c1 = p * 2 + 1;
                    int c2 = p * 2 + 2;
                    if (c1 >= count) break;

                    int c = (c2 >= count || list[c1].Key < list[c2].Key)
                        ? c1 : c2;
                    if (list[c].Key >= list[p].Key) break;

                    Swap(p, c);
                    p = c;
                }
                return pair;
            }

            public bool Exist() { return count > 0; }
        }
    }
}