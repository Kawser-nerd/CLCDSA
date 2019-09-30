using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace AtTest.ForBlue.ABC_073
{
    class D
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
            int r = int.Parse(input[2]);
            nodes = new Node[n];
            var rs = new int[r];

            string[] rInput = Console.ReadLine().Split(' ');
            for (int i = 0; i < r; i++)
            {
                rs[i] = int.Parse(rInput[i]) - 1;
            }
            for (int i = 0; i < n; i++)
            {
                nodes[i] = new Node(n);
                nodes[i].distances[i] = 0;//???0?
                nodes[i].isMin[i] = true;
            }
            for (int i = 0; i < m; i++)
            {
                string[] mInput = Console.ReadLine().Split(' ');
                int a = int.Parse(mInput[0]) - 1;
                int b = int.Parse(mInput[1]) - 1;
                int c = int.Parse(mInput[2]);
                nodes[a].edges.Add(new Edge(b, c));
                nodes[b].edges.Add(new Edge(a, c));
            }

            for (int i = 0; i < r; i++)
            {
                Dijkstra(rs[i]);
            }

            int[,] array = FactorialArray(r);
            long minDistance = 0;
            for(int i = 0; i < array.GetLength(0); i++)
            {
                long distance = 0;
                for (int j = 1; j < array.GetLength(1); j++)
                {
                    distance += nodes[rs[array[i, j - 1]]].distances[rs[array[i, j]]];
                }
                if (i == 0 || distance<minDistance)
                {
                    minDistance = distance;
                }
            }

            Console.WriteLine(minDistance);
        }

        static long Factorial(int n)
        {
            if (n == 0) return 1;

            return n * Factorial(n - 1);
        }

        static int[,] FactorialArray(int n)
        {
            long allPat = Factorial(n);
            var array = new int[allPat, n];
            var indexArray = new int[n];
            for(int i = 0; i < n; i++)
            {
                indexArray[i] = i;
            }

            int modder = n;
            int divider = 1;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < allPat; j++)
                {
                    array[j, i] = j / divider % modder;
                }
                divider *= modder;
                modder--;
            }

            var indexList = new List<int>();
            for (int i = 0; i < allPat; i++)
            {
                indexList.AddRange(indexArray);
                for (int j = 0; j < n; j++)
                {
                    int index = array[i, j];
                    array[i, j] = indexList[index];
                    indexList.RemoveAt(index);
                }
            }

            return array;
        }

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

        public Edge(int to, int dist)
        {
            toIndex = to;
            distance = dist;
        }
    }
}