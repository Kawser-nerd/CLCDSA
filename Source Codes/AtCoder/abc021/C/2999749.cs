using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge.ABC_021
{
    class ABC_021
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string[] input = Console.ReadLine().Split(' ');
            int a = int.Parse(input[0])-1;
            int b = int.Parse(input[1])-1;
            int m= int.Parse(Console.ReadLine());
            var nodes = new Node[n];
            for(int i = 0; i < n; i++)
            {
                nodes[i] = new Node();
            }

            for (int i = 0; i < m; i++)
            {
                input = Console.ReadLine().Split(' ');
                int x = int.Parse(input[0]) - 1;
                int y = int.Parse(input[1]) - 1;
                nodes[x].edges.Add(new Edge(y, 1));
                nodes[y].edges.Add(new Edge(x, 1));
            }

            nodes[a].distance = 0;
            nodes[a].patterns = 1;
            var posQueue = new Queue<int>();
            posQueue.Enqueue(a);

            while (posQueue.Count > 0)
            {
                int index = posQueue.Dequeue();
                long distance = nodes[index].distance + 1;

                for (int i = 0; i < nodes[index].edges.Count; i++)
                {
                    int targetIndex = nodes[index].edges[i].toIndex;
                    long targetDistance = nodes[targetIndex].distance;
                    if (targetDistance == -1 || distance < targetDistance)
                    {
                        nodes[targetIndex].distance = distance;
                        posQueue.Enqueue(targetIndex);
                        nodes[targetIndex].patterns = nodes[index].patterns;
                    }
                    else if (distance == targetDistance)
                    {
                        nodes[targetIndex].patterns
                            = (nodes[targetIndex].patterns
                            + nodes[index].patterns) % 1000000007;
                    }
                }
            }
            Console.WriteLine(nodes[b].patterns);
        }
    }

    class Node
    {
        public long distance;
        public long patterns;
        public List<Edge> edges;
        public Node(bool isStart = false)
        {
            distance = isStart ? 0 : -1;
            patterns = 0;
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