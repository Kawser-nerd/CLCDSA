using System;
using System.Collections.Generic;

namespace AGC032B
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());

            List<Edge> Edges = new List<Edge>();

            for (int i = 1; i <= N; i++)
            {
                for (int j = N; j > i; j--)
                {
                    Edge edge = new Edge(i, j);
                    Edges.Add(edge);
                }
            }

            if (N % 2 == 0)
            {
                for (int i = 1; i <= N / 2; i++)
                {
                    Edge removeEdge = new Edge(i, N - i + 1);
                    Edges.Remove(removeEdge);
                }
            }
            else
            {
                for (int i = 1; i <= N / 2; i++)
                {
                    Edge removeEdge = new Edge(i, N - i);
                    Edges.Remove(removeEdge);
                }
            }

            Console.WriteLine(Edges.Count);
            for (int i = 0; i < Edges.Count; i++)
            {
                Console.WriteLine("" + Edges[i].a + " " + Edges[i].b);
            }
        }
    }

    class Edge
    {
        public int a;
        public int b;
        public Edge(int a, int b)
        {
            this.a = a;
            this.b = b;
        }

        public override bool Equals(object obj)
        {
            //obj?null???????????????
            if (obj == null || GetType() != obj.GetType())
            {
                return false;
            }
            //??????????????????????????????
            //if (!(obj is TestClass))

            //Number?????
            Edge c = (Edge)obj;
            return a == c.a & b == c.b;
        }
    }
}