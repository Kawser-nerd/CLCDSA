using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Text;

public class ProblemA
{
	static void Main(string[] args)
	{
//		TextReader sr = new StreamReader(@"c:\temp\a.in");
//		TextReader sr = new StreamReader(@"c:\temp\a-small-attempt1.in");
		TextReader sr = new StreamReader(@"c:\temp\a-large.in");
//				TextReader sr = Console.In;
				TextWriter sw = new StreamWriter(@"c:\temp\a.out");
//		TextWriter sw = Console.Out;

		int N = int.Parse(sr.ReadLine());
		for (int caseNo = 1; caseNo <= N; caseNo++)
		{
			sw.Write("Case #" + caseNo + ": ");
			Console.WriteLine("Case #" + caseNo);
			
			Solve(sr, sw, false);
		}
		sw.Close();
	}

	private static char[,] map;
	private static int noBoxes;

	private struct Pos : IComparable<Pos>, IEquatable<Pos>
	{
		public int X, Y;

		public Pos(int x, int y)
		{
			X = x;
			Y = y;
		}

		public Pos(Pos oldPos, int d)
		{
			X = oldPos.X + dx[d];	
			Y = oldPos.Y + dy[d];	
		}

		public bool IsValid()
		{
			return X >= 0 && Y >= 0 && X < xsize && Y < ysize && map[Y, X] == '.';
		}

		public bool IsNeighbour(Pos p)
		{
			return Math.Abs(X - p.X) + Math.Abs(Y - p.Y) == 1;
		}

		public int CompareTo(Pos other)
		{
			return Y != other.Y ? Y - other.Y : X - other.X;
		}

		public bool Equals(Pos other)
		{
			return X == other.X && Y == other.Y;
		}
	}

	private class State
	{
		public Pos[] Boxes;
		private int _stable = -1;
		public int MovesRequired;
		public bool Direction;

		public State(List<int> x, List <int> y, bool dir)
		{
			Boxes = new Pos[noBoxes];
			for (int i = 0; i < noBoxes; i++)
			{
				Boxes[i] = new Pos(x[i], y[i]);
			}
			Direction = dir;
			Normalize();
		}

		public State(State state, int oldIndex, Pos pos)
		{
			Direction = state.Direction;
			Boxes = new Pos[noBoxes];
			for (int i = 0; i < noBoxes; i++)
			{
				Boxes[i] = i == oldIndex ? pos : state.Boxes[i];
			}
			Normalize();
		}

		public long Encode()
		{
			long code = 0;
			for (int i = 0; i < Boxes.Length; i++)
			{
				code *= 144;
				code += Boxes[i].Y*12 + Boxes[i].X;
			}
			return code;
		}
		
		private int Dfs(int cur, bool[] vis)
		{
			if (vis[cur]) return 0;
			vis[cur] = true;
			int sum = 1;
			for (int i = 0; i < noBoxes; i++)
			{
				if (Boxes[cur].IsNeighbour(Boxes[i]))
					sum += Dfs(i, vis);
			}
			return sum;
		}

		public bool IsStable()
		{
			if (_stable >= 0) return _stable == 1;
			int c = Dfs(0, new bool[noBoxes]);
			if (c == noBoxes)
			{
				_stable = 1;
				return true;
			}
			_stable = 0;
			return false;
		}

		public void Normalize()
		{
			Array.Sort(Boxes);
		}
	}

	private static int xsize, ysize;

	private static int[] dx = new int[] {0, 1, 0, -1};
	private static int[] dy = new int[] {1, 0, -1, 0};

	private static void Solve(TextReader sr, TextWriter sw, bool debug)
	{
		string[] strings = sr.ReadLine().Split(' ');
		ysize = int.Parse(strings[0]);
		xsize = int.Parse(strings[1]);
		map = new char[ysize,xsize];
		List<int> ex = new List<int>(), ey = new List<int>();
		List<int> sx = new List<int>(), sy = new List<int>();
		for (int i = 0; i < ysize; i++)
		{
			string line = sr.ReadLine();
			if (debug)
				Console.WriteLine(line);
			for (int j = 0; j < xsize; j++)
			{
				map[i, j] = '.';
				if (line[j] == '#' || line[j] == '.')
					map[i, j] = line[j];
				else if (line[j] == 'x')
				{
					ex.Add(j);
					ey.Add(i);
				}
				else if (line[j] == 'o')
				{
					sx.Add(j);
					sy.Add(i);
				}
				else if (line[j] == 'w')
				{
					ex.Add(j);
					ey.Add(i);
					sx.Add(j);
					sy.Add(i);
				}
			}
		}
		if (ex.Count != sx.Count)
		{
			sw.WriteLine("-1");
			return;
		}
		noBoxes = ex.Count;

		var endState = new State(ex, ey, true);
		var startState = new State(sx, sy, false);
		long endCode = endState.Encode();
		q = new Queue<State>();
		added1 = new Dictionary<long, int>();
		added2 = new Dictionary<long, int>();
		Add(startState, 0);
		int w;
		/*w = Add(endState, 0);
		if (w >= 0) {
			sw.WriteLine(w);
			return;
		}*/
		while (q.Count > 0)
		{
			State state = q.Dequeue();
			if (state.Encode() == endCode)
			{
				sw.WriteLine(state.MovesRequired);
				return;
			}
			bool stable = state.IsStable();
			for (int i = 0; i < noBoxes; i++)
			{
				for (int d = 0; d < 4; d++)
				{
					// try move box i in direction d
					Pos newPos = new Pos(state.Boxes[i], d);
					if (!newPos.IsValid()) continue;
					Pos emptyPos = new Pos(state.Boxes[i], (d+2)%4);
					if (!emptyPos.IsValid()) continue;
					bool bad = false;
					for (int j = 0; j < noBoxes && !bad; j++)
					{
						if (i == j) continue;
						if (newPos.Equals(state.Boxes[j])) bad = true;
						if (emptyPos.Equals(state.Boxes[j])) bad = true;
					}
					if (bad) continue;

					State newState = new State(state, i, newPos);
					if (!stable && !newState.IsStable())
						continue;
					Add(newState, state.MovesRequired + 1);
/*
					w = Add(newState, state.MovesRequired + 1);
					if (w >= 0)
					{
						sw.WriteLine(w);
						return;
					}*/
				}
			}
		}
		sw.WriteLine("-1");
	}

	private static Queue<State> q;
	private static Dictionary<long, int> added1;
	private static Dictionary<long, int> added2;

	private static int Add(State state, int pushes)
	{
		long code = state.Encode();
		Dictionary<long, int> my = state.Direction ? added2 : added1;
		Dictionary<long, int> other = state.Direction ? added1 : added2;
		if (my.ContainsKey(code))
		{
			return -1;
		}
		state.MovesRequired = pushes;
		my.Add(code, pushes);
		q.Enqueue(state);
		if (other.ContainsKey(code))
		{
			return pushes + other[code];
		}
		return -1;
	}
}
