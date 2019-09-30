using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace NoCheating
{
	class Program
	{
		static void Main(string[] args)
		{
//			StreamReader sr = new StreamReader(@"c:\gcj\c.in");
//			StreamReader sr = new StreamReader(@"c:\gcj\c-small-attempt0.in");
//			StreamReader sr = new StreamReader(@"c:\gcj\c-small-attempt1.in");
			StreamReader sr = new StreamReader(@"c:\gcj\c-large.in");
//			TextWriter tw = Console.Out;
			TextWriter tw = new StreamWriter(@"c:\gcj\c.out");

			int noCases = int.Parse(sr.ReadLine());
			for (int caseNo = 0; caseNo < noCases; caseNo++)
			{
				var split = sr.ReadLine().Split(' ');
				int ysize = int.Parse(split[0]);
				int xsize = int.Parse(split[1]);

				bool[,] broken = new bool[ysize,xsize];
				for (int y = 0; y < ysize; y++)
				{
					var line = sr.ReadLine();
					for (int x = 0; x < xsize; x++)
					{
						if (line[x] == 'x')
							broken[y, x] = true;
					}
				}

				int best = 0;

				for (int odd = 0; odd < 1; odd++)
				{
					Network network = new Network(ysize*xsize);
					int count = 0;
					for (int y = 0; y < ysize; y++)
					{
						for (int x = 0; x < xsize; x++)
						{
							if (broken[y, x])
								continue;

							int myNode = y*xsize + x;
							count++;
							if (x%2 == odd)
								network.AddSinkEdge(myNode, 1);
							else
								network.AddSourceEdge(myNode, 1);
							
							bool iso = true;

							if (x > 0 && !broken[y, x - 1])
							{
								iso = false;
								if (x % 2 != odd)
									network.AddEdge(myNode, myNode - 1, 1);
							}
							if (x > 0 && y > 0 && !broken[y - 1, x - 1])
							{
								iso = false;
								if (x % 2 != odd)
									network.AddEdge(myNode, myNode - 1 - xsize, 1);
							}

							if (x > 0 && (y+1 < ysize) && !broken[y + 1, x - 1])
							{
								iso = false;
								if (x % 2 != odd)
									network.AddEdge(myNode, myNode - 1 + xsize, 1);
							}


							if ((x + 1 < xsize) && !broken[y, x + 1])
							{
								iso = false;
								if (x % 2 != odd)
									network.AddEdge(myNode, myNode + 1, 1);
							}
							if ((x + 1 < xsize) && (y > 0) && !broken[y - 1, x + 1])
							{
								iso = false;
								if (x % 2 != odd)
									network.AddEdge(myNode, myNode + 1 - xsize, 1);
							}
							if ((x + 1 < xsize) && (y + 1 < ysize) && !broken[y + 1, x + 1])
							{
								iso = false;
								if (x % 2 != odd)
									network.AddEdge(myNode, myNode + 1 + xsize, 1);
							}

//							if (iso)
//								count++;
						}
					}

					var flow = network.Flow();
					int res = count - flow;
//					tw.WriteLine("Case #" + (caseNo + 1) + ": " + res);
					if (res > best) best = res;
				}
				tw.WriteLine("Case #" + (caseNo + 1) + ": " + best);
			}
			tw.Close();
		}
	}

	public class Network
	{
		private List<int>[] _edges;
		private int _source, _sink, _cookie = 1, _totalFlow = 0;
		private int[,] _capacity, _flow;
		private int[] _tag;

		public Network(int maxNodes)
		{
			_source = maxNodes;
			_sink = maxNodes + 1;
			maxNodes += 2;
			_edges = new List<int>[maxNodes];
			for (int i = 0; i < maxNodes; i++) _edges[i] = new List<int>();
			_capacity = new int[maxNodes, maxNodes];
			_flow = new int[maxNodes, maxNodes];
			_tag = new int[maxNodes];
		}

		public void AddSourceEdge(int dest, int capacity) { AddEdge(_source, dest, capacity); }
		public void AddSinkEdge(int src, int capacity) { AddEdge(src, _sink, capacity); }

		public void AddEdge(int src, int dest, int capacity)
		{
//			Console.WriteLine(src + " -> " + dest);
			if (_capacity[src, dest] == 0 && _capacity[dest, src] == 0)
			{
				if (src != _sink) _edges[src].Add(dest);
				if (src != _source) _edges[dest].Add(src);
			}
			_capacity[src, dest] += capacity;
		}

		private int Go(int cur, int flow)
		{
			if (cur == _source) _cookie++;
			if (cur == _sink) return flow;
			if (_tag[cur] == _cookie || flow == 0) return 0;
			_tag[cur] = _cookie;
			foreach (int v in _edges[cur])
			{
				int f = Go(v, Math.Min(flow, _capacity[cur, v] - _flow[cur, v] + _flow[v, cur]));
				if (f > 0) { _flow[cur, v] += f; return f; }
			}
			return 0;
		}

		public int Flow()
		{
			int f;
			while ((f = Go(_source, int.MaxValue)) > 0) _totalFlow += f;
			return _totalFlow;
		}
	}
}
