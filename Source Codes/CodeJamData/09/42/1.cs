using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Google_Code_Jam
{
	#region problemA
	class problemA
	{
		public static void Solve(TextReader tr, TextWriter tw)
		{
			int T = int.Parse(tr.ReadLine());
			for (int i = 1; i <= T; i++)
			{
				int N = int.Parse(tr.ReadLine());
				int[] last = new int[N];
				for (int j = 0; j < N; j++)
				{
					string s = tr.ReadLine();
					last[j] = s.LastIndexOf('1');
				}
				int ans = 0;
				for (int k = 0; k < N; k++)
				{
					int j = k;
					while (last[j] > k)
						j++;
					for (int q = j; q > k; q--)
						last[q] = last[q - 1];
					ans += (j - k);
				}
				tw.WriteLine(String.Format("Case #{0}: {1}", i, ans));
			}
		}
	}
	#endregion

	class problemB
	{
		private bool[,] map = null;
		private bool[,] smap = null;
		private int[,,] dig = null;
		int R, C, F;
		public static readonly int inf = 1000000;
		private void Read(TextReader tr)
		{
			
			string[] s = tr.ReadLine().Split(' ');
			R = int.Parse(s[0]);
			C = int.Parse(s[1]);
			F = int.Parse(s[2]);
			map = new bool[R + 1, C];
			smap = new bool[R + 1, C];
			for (int i = 0; i < R; i++)
			{
				string s1 = tr.ReadLine();
				for (int j = 0; j < C; j++)
				{
					map[i, j] = s1[j] == '.';
					smap[i, j] = map[i, j];
				}
			}
		}
		private int Calc()
		{
			dig = new int[R + 1, C, C];
			for (int i = 0; i <= R; i++)
				for (int j = 0; j < C; j++)
					for (int k = 0; k < C; k++)
						dig[i, j, k] = inf;
			dig[0, 0, 0] = 0;
			for (int y = 0; y < R -1; y++)
			{
				for (int x = 0; x < C; x++)
					for (int i = 0; i < C; i++)
						if (dig[y,x,i] != inf)
						{
							for (int k = x; k <= i; k++)
								map[y, k] = true;
							for (int k = i; k <= x; k++)
								map[y, k] = true;

							int left = x;
							while (left >= 0 && map[y, left] && (!map[y+1, left]))
								left--;
							left++;
							int right = x;
							while (right <= (C - 1) && map[y, right] && (!map[y+1, right]))
								right++;
							right--;

							for (int j = left; j <= right; j++)
							{
								for (int q = left; q < j; q++)
								{
									int yy = y + 2;
									while (map[yy, j - 1])
										yy++;
									if (yy - y - 1 > F)
										continue;
									if (yy == y + 2)
									{
										dig[y + 1, j - 1, q] = Math.Min(dig[y + 1, j - 1, q], dig[y, x, i] + (j - q));
									}
									else
									{
										dig[yy - 1, j - 1, j - 1] = Math.Min(dig[yy - 1, j - 1, j - 1], dig[y, x, i] + (j - q));
									}
								}
								for (int q = right; q > j; q--)
								{
									int yy = y + 2;
									while (map[yy, j + 1])
										yy++;
									if (yy - y - 1 > F)
										continue;
									if (yy == y + 2)
									{
										dig[y + 1, j + 1, q] = Math.Min(dig[y + 1, j + 1, q], dig[y, x, i] + (q - j));
									}
									else
									{
										dig[yy - 1, j + 1, j + 1] = Math.Min(dig[yy - 1, j + 1, j + 1], dig[y, x, i] + (q - j));
									}
								}
							}

							if (left > 0 && map[y, left - 1])
							{
								int yy = y + 2;
								while (map[yy, left - 1])
									yy++;
								if (yy - y - 1 <= F)
								{
									dig[yy - 1, left - 1, left - 1] = Math.Min(dig[yy - 1, left - 1, left - 1], dig[y, x, i]);
								}
							}
							if (right < (C - 1) && map[y, right + 1])
							{
								int yy = y + 2;
								while (map[yy, right + 1])
									yy++;
								if (yy - y - 1 <= F)
								{
									dig[yy - 1, right + 1, right + 1] = Math.Min(dig[yy - 1, right + 1, right + 1], dig[y, x, i]);
								}
							}

							for (int k = x; k <= i; k++)
								map[y, k] = smap[y, k];
							for (int k = i; k <= x; k++)
								map[y, k] = smap[y, k];
						}
			}
			int min = inf;
			for (int x = 0; x < C; x++)
				for (int i = 0; i < C; i++)
					min = Math.Min(min, dig[R - 1, x, i]);
			return min;
		}
		public static void Solve(TextReader tr, TextWriter tw)
		{
			int N = int.Parse(tr.ReadLine());
			for (int i = 1; i <= N; i++)
			{
				problemB problem = new problemB();
				problem.Read(tr);
				int ans = problem.Calc();
				if (ans != problemB.inf)
					tw.WriteLine(String.Format("Case #{0}: Yes {1}", i, ans));
				else
					tw.WriteLine(String.Format("Case #{0}: No", i));
			}
		}
	}

	class Program
	{
		static void Main(string[] args)
		{
			TextReader tr = new StreamReader(@"C:\GCJ\B-large.in");
			TextWriter tw = new StreamWriter(@"C:\GCJ\B-large.out");
			problemB.Solve(tr, tw);
			tr.Close(); tw.Close();
		}
	}
}
