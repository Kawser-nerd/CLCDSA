using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

public class ProblemB
{
	static void Main(string[] args)
	{
//		TextReader sr = new StreamReader(@"c:\temp\b.in");
//		TextReader sr = new StreamReader(@"c:\temp\b-small-attempt2.in");
		TextReader sr = new StreamReader(@"c:\temp\b-large.in");
//				TextReader sr = Console.In;
				TextWriter sw = new StreamWriter(@"c:\temp\b.out");
//		TextWriter sw = Console.Out;

		int N = int.Parse(sr.ReadLine());
		for (int caseNo = 1; caseNo <= N; caseNo++)
		{
			sw.Write("Case #" + caseNo + ": ");
			Solve(sr, sw);
		}
		sw.Close();
	}

	private static int xsize, ysize, maxFall;
	private static char[,] map;

	private static int Encode(int x, int y, int dx1, int dx2)
	{
		// dx1 <-> dx2 digged interval, dx1 or dx2 must be x
		int state = y*xsize + x;
		state *= 120;
		if (dx1 == x)
			state += dx2 - dx1;
		else
		{
			state += dx2 - dx1 + 60;
		}
		return state;
	}

	private static void Decode(int state, out int x, out int y, out int dx1, out int dx2)
	{
		int v = state%120;
		state /= 120;
		x = state%xsize;
		y = state/xsize;
		if (v < 60)
		{
			dx1 = x;
			dx2 = v + dx1;
		}
		else
		{
			dx2 = x;
			dx1 = dx2 - (v - 60);
		}
	}

	private static void Solve(TextReader sr, TextWriter sw)
	{
		string[] strings = sr.ReadLine().Split(' ');
		ysize = int.Parse(strings[0]);
		xsize = int.Parse(strings[1]);
		maxFall = int.Parse(strings[2]);
		map = new char[ysize,xsize];
		
		for (int i = 0; i < ysize; i++)
		{
			string line = sr.ReadLine();
			for (int j = 0; j < xsize; j++)
			{
				map[i, j] = line[j];
			}
		}
		
		var dijkstra = new DijkstraHelper<int>(xsize*ysize*120);
		dijkstra.Add(Encode(0, 0, 0, 0), 0);
		int ans = -1;
		while (true)
		{
			int node = dijkstra.GetNext();
			if (node < 0)
				break;
			int x, y, dx1, dx2;
			Decode(node, out x, out y, out dx1, out dx2);
			int curDist = dijkstra.GetDistance(node);
//			Console.WriteLine("At " + x + "," + y + " [" + dx1 + "," + dx2 + "] after " + curDist + " digs.");
			if (y == ysize - 1)
			{
				ans = curDist;
				break;
			}
			// Find move interval
			int left = x, right = x;
			while (left - 1 >= 0 && map[y+1,left-1] == '#' && (map[y, left - 1] == '.' || (left - 1 >= dx1 && left - 1 <= dx2)))
				left--;
			while (right + 1 < xsize && map[y + 1, right + 1] == '#' && (map[y, right + 1] == '.' || (right + 1 >= dx1 && right + 1 <= dx2)))
				right++;

			if (left - 1 >= 0 && (map[y, left - 1] == '.' || (left - 1 >= dx1 && left - 1 <= dx2)) && map[y + 1, left - 1] == '.')
				Fall(dijkstra, left - 1, y, curDist, 0, left - 1, left - 1);
			if (right + 1 < xsize && (map[y, right + 1] == '.' || (right + 1 >= dx1 && right + 1 <= dx2)) && map[y + 1, right + 1] == '.')
				Fall(dijkstra, right + 1, y, curDist, 0, right + 1, right + 1);

			for (int nx = left; nx <= right; nx++)
			{
				// Dig the interval [nx,tx] and fall down into tx
				for (int tx = nx; tx < right; tx++)
				{
					Fall(dijkstra, tx, y+1, curDist+(tx-nx+1), 1, nx, tx);
				}

				// Dig the interval [tx,nx] and fall down into tx
				for (int tx = left + 1; tx <= nx; tx++)
				{
					Fall(dijkstra, tx, y + 1, curDist + (nx - tx + 1), 1, tx, nx);
				}
			}
		}
		if (ans < 0)
		{
			sw.WriteLine("No");
		}
		else
		{
			sw.WriteLine("Yes " + ans);
		}
	}

	private static void Fall(DijkstraHelper<int> dijkstra, int x, int y, int dist, int fallDist, int dx1, int dx2)
	{
		while (y + 1 < ysize && map[y + 1, x] == '.')
		{
			y++;
			fallDist++;
		}
		if (fallDist <= maxFall)
		{
			if (fallDist > 1)
			{
				dx1 = dx2 = x;	
			}
			dijkstra.Add(Encode(x,y,dx1,dx2), dist);
		}
	}

	public class DijkstraHelper<TDist>
		where TDist : struct, IComparable<TDist>
	{
		private struct State : IComparable<State>
		{
			public readonly int Node;
			public readonly TDist Distance;

			public State(int node, TDist distance)
			{
				Node = node;
				Distance = distance;
			}

			public int CompareTo(State other)
			{
				int cmp = Distance.CompareTo(other.Distance);
				if (cmp != 0)
					return cmp;
				return Node - other.Node;
			}
		}

		private readonly SortedDictionary<State, object> _stateByDistance;
		private readonly TDist[] _distanceByNode;
		private readonly byte[] _state;
		
		public DijkstraHelper(int noNodes)
		{
			_distanceByNode = new TDist[noNodes];
			_stateByDistance = new SortedDictionary<State, object>();
			_state = new byte[noNodes];
		}

		public void Add(int node, TDist distance)
		{
			switch (_state[node])
			{
				case 0:
					_distanceByNode[node] = distance;
					_state[node] = 1;
					_stateByDistance.Add(new State(node, distance), null);
					break;
				case 1:
					if (distance.CompareTo(_distanceByNode[node]) < 0)
					{
						_stateByDistance.Remove(new State(node, _distanceByNode[node]));
						_distanceByNode[node] = distance;
						_stateByDistance.Add(new State(node, distance), null);
					}
					break;
			}
		}

		public int GetNext()
		{
			SortedDictionary<State, object>.Enumerator e = _stateByDistance.GetEnumerator();
			if (!e.MoveNext())
				return -1;
			State state = e.Current.Key;
			_state[state.Node] = 2;
			_stateByDistance.Remove(state);
			return state.Node;
		}

		public TDist GetDistance(int node)
		{
			return _distanceByNode[node];
		}
	}

}
