using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC_C
{
    class C075
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(' ');
            int N = int.Parse(s[0]);
            int M = int.Parse(s[1]);
            List<string[]> list = new List<string[]>();
            for (int i = 0; i < M; i++)
            {
                string[] s0 = Console.ReadLine().Split(' ');
                list.Add(s0);
            }

            Graph g = new Graph(N);
            foreach(string[] ss in list)
            {
                int L = int.Parse(ss[0]);
                int R = int.Parse(ss[1]);
                g.AddEdge(L, R);
            }
            var dd = g.BreadthFirstSearch(1);


            int counter = 0;
            for(int i = 0; i < M; i++)
            {
                Graph graph = new Graph(N);
                for (int j = 0; j < M; j++)
                {
                    if (i == j) continue;
                    string[] s0 = list[j];
                    int L = int.Parse(s0[0]), R = int.Parse(s0[1]);
                    graph.AddEdge(L, R);
                }
                var dic = graph.BreadthFirstSearch(1);
                if (dic.Count < N)
                {
                    counter++;
                }
            }

            Console.WriteLine(counter); 
        }


    }

    class Graph
    {
        private bool idZeroStart;
        public List<Node> Nodes { get; }
        public List<Edge> Edges { get; }
        public int[,] Matrix { get; }
        public bool IsDirectedGraph { get; set; }

        public Graph(int N, bool idZeroStart = false)
        {
            this.idZeroStart = idZeroStart;
            Nodes = new List<Node>();
            Edges = new List<Edge>();
            Matrix = new int[N, N];
            for (int i = 0; i < N; i++)
            {
                int id = idZeroStart ? i : i + 1;
                Node n = new Node(id);
                Nodes.Add(n);
            }
        }

        public void AddEdge(int idL, int idR, int d = 1)
        {
            int indexL = idZeroStart ? idL : idL - 1;
            int indexR = idZeroStart ? idR : idR - 1;

            Node nodeL = Nodes[indexL];
            Node nodeR = Nodes[indexR];
            Edge edge = new Edge(nodeL, nodeR, d, IsDirectedGraph);
            Edges.Add(edge);
            Matrix[indexL, indexR] = d;
            if (!IsDirectedGraph) Matrix[indexR, indexL] = d;
        }

        public Dictionary<int, int> BreadthFirstSearch(int idS)
        {
            Dictionary<int, int> distances = new Dictionary<int, int>();
            distances.Add(idS, 0);
            int index = idZeroStart ? idS : idS - 1;

            foreach (Node node in Nodes)
            {
                node.Visited = false;
            }

            List<Node> nodes = new List<Node>();
            Node nodeStart = Nodes[index];
            nodeStart.Visited = true;
            nodes.Add(nodeStart);
            int depth = 1;
            while (nodes.Count > 0)
            {
                List<Node> nextNodes = new List<Node>();
                foreach (Node node in nodes)
                {
                    foreach (Node cn in node.ConnectedNodes)
                    {
                        if (!cn.Visited)
                        {
                            nextNodes.Add(cn);
                            cn.Visited = true;
                            distances.Add(cn.Id, depth);
                        }
                    }
                }
                nodes = nextNodes;
                depth++;
            }
            return distances;
        }
    }

    class Node
    {
        public int Id { get; }
        public List<Edge> ConnectedEdges { get; private set; }
        public List<Node> ConnectedNodes { get; private set; }
        public bool Visited { get; set; }

        public Node(int id)
        {
            Id = id;
            ConnectedEdges = new List<Edge>();
            ConnectedNodes = new List<Node>();
        }


    }

    class Edge
    {
        public Node NodeL { get; }
        public Node NodeR { get; }
        public int D { get; }

        public Edge(Node nodeL, Node nodeR, int d, bool isDirected)
        {
            NodeL = nodeL;
            NodeR = nodeR;
            nodeL.ConnectedEdges.Add(this);
            nodeL.ConnectedNodes.Add(nodeR);
            if (!isDirected)
            {
                nodeR.ConnectedEdges.Add(this);
                nodeR.ConnectedNodes.Add(nodeL);
            }
            D = d;            
        }
    }

}