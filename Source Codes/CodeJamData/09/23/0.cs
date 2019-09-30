using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

public class ProblemC
{
	static void Main(string[] args)
	{
//		TextReader sr = new StreamReader(@"c:\temp\c.in");
//			TextReader sr = new StreamReader(@"c:\temp\c-small-attempt0.in");
			TextReader sr = new StreamReader(@"c:\temp\c-large.in");
//				TextReader sr = Console.In;
//					TextWriter sw = new StreamWriter(@"c:\temp\c-small.out");
					TextWriter sw = new StreamWriter(@"c:\temp\c-large.out");
//		TextWriter sw = Console.Out;

		int N = int.Parse(sr.ReadLine());
		for (int caseNo = 1; caseNo <= N; caseNo++)
		{
			Console.WriteLine("Case #" + caseNo);
			sw.WriteLine("Case #" + caseNo + ":");
			Solve(sr, sw);
		}
		sw.Close();
	}

	private const int LIMIT = 510;
	private static int size;
	private static string[] map;
	private static List<int>[,,] memoLists;
	private static List<string>[,,] memoStrings;

	private static void Solve(TextReader sr, TextWriter sw)
	{
		var parts = sr.ReadLine().Split(' ');
		size = int.Parse(parts[0]);
		int queries = int.Parse(parts[1]);
		map = new string[size];
		for (int i = 0; i < size; i++)
		{
			map[i] = sr.ReadLine();
		}
		memoLists = new List<int>[LIMIT*2+1,size,size];
		memoStrings = new List<string>[LIMIT*2+1,size,size];
		for (int i = 0; i < LIMIT*2+1; i++)
		{
			for (int y = 0; y < size; y++)
			{
				for (int x = 0; x < size; x++)
				{
					memoLists[i, y, x] = new List<int>(10);
					memoStrings[i, y, x] = new List<string>(10);
				}
			}
		}

		int[] q = Array.ConvertAll<string, int>(sr.ReadLine().Split(' '), int.Parse);
		for (int i = 0; i < queries; i++)
		{
			int sum = q[i];
			string best = null;
			for (int steps = 0; best == null; steps++)
			{
				
				for (int y = 0; y < size; y++)
				{
					for (int x = 0; x < size; x++)
					{
						if (char.IsDigit(map[y][x]))
						{
							string s = Get(sum - (map[y][x]-'0'), x, y, steps);
							if (s != null)
							{
								if ((best == null || string.CompareOrdinal(s, best) < 0))
								{
									best = s;
								}
							}
						}
					}
				}
			}
			sw.WriteLine(best);
			Console.WriteLine("Query " + (i + 1) + " done");
		}
	}

	private static int[] dx = new int[]{0, 1, 0, -1};
	private static int[] dy = new int[] {1, 0, -1, 0};

	private static string Get(int sum, int x, int y, int steps)
	{
		if (sum < -LIMIT || sum > LIMIT)
			return null;

		if (steps == 0)
		{
			if (sum == 0)
				return "" + map[y][x];
			return null;
		}
		List<int> memoList = memoLists[sum + LIMIT, x, y];
		List<string> memoString = memoStrings[sum + LIMIT, x, y];
		while (memoList.Count <= steps)
		{
			memoList.Add(0);
			memoString.Add(null);
		}
		if (memoList[steps] < 0) return null;
		if (memoList[steps] > 0)
		{
			return memoString[steps];
/*
			int t = memoList[steps] - 1;
			int d = t%4, d2 = t/4;
			int nx = x + dx[d], ny = y + dy[d];
			int nx2 = nx + dx[d2], ny2 = ny + dy[d2];

			int wanted = sum, dd = map[ny2][nx2] - '0';
			if (map[ny][nx] == '+')
				wanted -= dd;
			else if (map[ny][nx] == '-')
				wanted += dd;
			
			string s = Get(wanted, nx2, ny2, steps - 1);
			s = "" + map[y][x] + map[ny][nx] + s;
			return s;*/
		}

		string best = null;
		for (int d = 0; d < 4; d++)
		{
			int nx = x + dx[d], ny = y + dy[d];
			if (nx >= 0 && ny >= 0 && nx<size && ny<size)
			{
				for (int d2 = 0; d2 < 4; d2++)
				{
					int nx2 = nx + dx[d2], ny2 = ny + dy[d2];
					if (nx2 >= 0 && ny2 >= 0 && nx2<size && ny2<size)
					{
						int wanted = sum, dd = map[ny2][nx2] - '0';
						if (map[ny][nx] == '+')
							wanted -= dd;
						else if (map[ny][nx] == '-')
							wanted += dd;
						else
						{
							throw new Exception();
						}
						
						string s = Get(wanted, nx2, ny2, steps - 1);
						if (s != null)
						{
							s = "" + map[y][x] + map[ny][nx] + s;
							if(best == null || string.CompareOrdinal(s, best) < 0)
							{
								best = s;
								memoList[steps] = 1 + d + d2*4;
								memoString[steps] = best;
							}	
						} 
					}
				}
			}
		}
		if (best == null)
			memoList[steps] = -1;
		return best;
	}
}
