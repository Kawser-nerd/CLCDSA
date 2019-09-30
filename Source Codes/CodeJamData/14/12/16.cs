using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace RAVE
{
	class TestCase
	{
		int N;
		Edge[] Edges;

		public TestCase(TextReader input)
		{
			N = input.ReadInts()[0];
			Edges = Enumerable.Range(0, N - 1).Select(i => new Edge(input)).ToArray();
		}

		public int GetResult()
		{
			var vertices = Enumerable.Range(0, N).Select(i => new List<DirectedEdge>()).ToArray();
			Edges.ForEach((e, i) => {
				vertices[e.A].Add(new DirectedEdge() { Edge = i, Vertex = e.B });
				vertices[e.B].Add(new DirectedEdge() { Edge = i, Vertex = e.A });
			});

			int largestPossible = Enumerable.Range(0, N).Select(i => FullBinaryTreeSize(vertices, i)).Max();
			return N - largestPossible;
		}

		private int FullBinaryTreeSize(List<DirectedEdge>[] vertices, int i)
		{
			bool[] used = new bool[N - 1];
			return FullBinaryTreeSize(vertices, used, i);
		}

		private int FullBinaryTreeSize(List<DirectedEdge>[] vertices, bool[] used, int i)
		{
			var edges = vertices[i].Where(e => !used[e.Edge]).ToArray();
			if (edges.Length < 2)
				return 1;
			foreach (var e in edges)
				used[e.Edge] = true;
			var sizes = edges.Select(e => FullBinaryTreeSize(vertices, used.ToArray(), e.Vertex));
			return 1 + Top2(sizes);
		}

		private int Top2(IEnumerable<int> sizes)
		{
			int a = 0, b = 0;
			foreach (var s in sizes)
				if (s > a)
				{
					b = a;
					a = s;
				}
				else if (s > b)
					b = s;
			return a + b;
		}

		class Edge
		{
			public int A, B;

			public Edge(TextReader input)
			{
				var r = input.ReadInts();
				A = r[0] - 1; B = r[1] - 1;
			}
		}

		class DirectedEdge
		{
			public int Edge;
			public int Vertex;
		}
	}
}