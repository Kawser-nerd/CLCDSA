using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace FulBinaryTree
{

  
    class Graph
    {
        public class Vertex
        {
            public int vertexIndex;
            public List<int> edges;
            public int state;//0 means undiscovered, 1 means seen, 2 means discovered
            public int level;
            public int numChilds;
        }

        public List<Vertex> vertices = new List<Vertex>();

        public Graph()
        {
        }

        public void AddVertex()
        {
            Vertex v = new Vertex();
            v.vertexIndex = vertices.Count;
            v.edges = new List<int>();
            v.state = 0;
            v.numChilds = 0;
            v.level = -1;
            vertices.Add(v);
        }

        public void AddEdge(int v1, int v2)
        {
            if (v1 >= vertices.Count || v2 >= vertices.Count)
            {
                throw new Exception();
            }
            if (vertices[v1].edges.Contains(v2))
            {
                throw new Exception();
            }

            vertices[v1].edges.Add(v2);

            vertices[v2].edges.Add(v1);
        }

        /*
        public int GetShortestPath(int sourceVertex, int destVertex)
        {
            if (sourceVertex >= vertices.Count || destVertex >= vertices.Count)
            {
                throw new Exception();
            }


            for (int i = 0; i < vertices.Count; i++)
            {
                vertices[i].state = 0;
                vertices[i].minCost = Int32.MaxValue;
            }

            vertices[sourceVertex].state = 1;
            vertices[sourceVertex].minCost = 0;
            List<int> seenVertices = new List<int>();
            seenVertices.Add(sourceVertex);

            while (seenVertices.Count > 0)
            {
                int minIndex = 0;
                int minCost = vertices[seenVertices[0]].minCost;

                for (int i = 1; i < seenVertices.Count; i++)
                {
                    if (vertices[seenVertices[i]].minCost < minCost)
                    {
                        minCost = vertices[seenVertices[i]].minCost;
                        minIndex = i;
                    }
                }

                int minVertex = seenVertices[minIndex];
                seenVertices.RemoveAt(minIndex);
                vertices[minVertex].state = 2;

                if (minVertex == destVertex)
                {
                    return minCost;
                }

                Vertex currentVertex = vertices[minVertex];
                for (int i = 0; i < currentVertex.edges.Count; i++)
                {
                    switch (vertices[currentVertex.edges[i]].state)
                    {
                        case 0:
                            vertices[currentVertex.edges[i]].state = 1;
                            vertices[currentVertex.edges[i]].minCost = currentVertex.minCost + currentVertex.edgeWeights[i];
                            seenVertices.Add(currentVertex.edges[i]);
                            break;
                        case 1:
                            int newCost = currentVertex.minCost + currentVertex.edgeWeights[i];
                            if (newCost < vertices[currentVertex.edges[i]].minCost)
                            {
                                vertices[currentVertex.edges[i]].minCost = newCost;
                            }
                            break;
                        case 2:
                        default:
                            break;
                    }
                }
            }

            throw new Exception();
        }
        */

        public int GetBestTree(int node)
        {
            if (vertices[node].numChilds == 0 || vertices[node].numChilds == 1)
            {
                return 1;
            }

            List<int> bestTrees = new List<int>();
            foreach (int e in vertices[node].edges)
            {
                if (vertices[e].level == vertices[node].level + 1)
                {
                    bestTrees.Add(GetBestTree(e));
                }
            }

            if (bestTrees.Count != vertices[node].numChilds)
            {
                throw new Exception();
            }

            bestTrees.Sort();
            bestTrees.Reverse();

            return bestTrees[0] + bestTrees[1] + 1;
            
        }

        public void BFS(int rootNode)
        {
            for(int i=0;i<vertices.Count;i++)
            {
                vertices[i].state=0;
                vertices[i].level=-1;
                vertices[i].numChilds=0;
            }

            vertices[rootNode].level = 0;
            vertices[rootNode].state = 1;

            List<int> processing = new List<int>();
            processing.Add(rootNode);
            int index = 0;

            while (index < processing.Count)
            {
                
                foreach (int e in vertices[processing[index]].edges)
                {
                    if (vertices[e].level < 0)
                    {
                        vertices[e].level = vertices[processing[index]].level + 1;
                        vertices[processing[index]].numChilds++;
                        processing.Add(e);
                    }
                }

                index++;
            }
        }
    }


    class Program
    {
        static void Main(string[] args)
        {
            
            //StreamReader sr = new StreamReader("D:\\a.txt");
            //StreamWriter sw = new StreamWriter("D:\\b.txt");

            //StreamReader sr = new StreamReader("D:\\B-small-attempt0.in");
            //StreamWriter sw = new StreamWriter("D:\\B-small-attempt0_.out");

            StreamReader sr = new StreamReader("D:\\B-large.in");
            StreamWriter sw = new StreamWriter("D:\\B-large.out");


            int numTestCases = Convert.ToInt32(sr.ReadLine());

            Random r=new  Random();
            for (int i = 0; i < numTestCases; i++)
            {

                Console.WriteLine(i);

                string[] str = sr.ReadLine().Split(' ');

                int N = Convert.ToInt32(str[0]);
                
                Graph graph = new Graph();

                for (int j = 0; j < N ; j++)
                {
                    graph.AddVertex();
                }

                for (int j = 0; j < N - 1; j++)
                {
                    str = sr.ReadLine().Split(' ');
                    graph.AddEdge(Convert.ToInt32(str[0])-1, Convert.ToInt32(str[1])-1);
                }


                int maxNodes = 0;
                for (int j = 0; j < N; j++)
                {
                    graph.BFS(j);
                    int numNodes = graph.GetBestTree(j);
                    if (numNodes > maxNodes)
                    {
                        maxNodes = numNodes;
                    }
                }


                sw.Write("Case #{0}: ", i + 1);
                sw.Write(N-maxNodes);
                sw.WriteLine();

            }
            sr.Close();
            sw.Close();
        }

    }
}
