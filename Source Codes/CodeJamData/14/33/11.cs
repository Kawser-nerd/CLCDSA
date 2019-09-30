using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C
{
	class Program
	{
		static StreamReader inp;
		static StreamWriter oup;

		static void Main(string[] args)
		{
			inp = new StreamReader(new FileStream("C.in", FileMode.Open, FileAccess.Read));
			oup = new StreamWriter(new FileStream("C.out", FileMode.Create, FileAccess.Write));
			var line = inp.ReadLine();
			var T = int.Parse(line);
			for (int caseIndex = 0; caseIndex < T; caseIndex++)
			{
				line = inp.ReadLine();
				var parts = line.Split(' ').Select(x => int.Parse(x)).ToArray();
				var N = parts[0];
				var M = parts[1];
				var K = parts[2];

				var p = N * M;
				var pp = 1;
				for (int i = 0; i < p; i++)
				{
					pp *= 2;
				}

				var min = int.MaxValue;
				var places = new bool[N, M];
				var q = new Queue<P>(2000000);
				var reachable = new bool[N, M];
				for (int i = 0; i < pp; i++)
				{
					var t = i;
					var b = 0;
					for (int y = 0; y < M; y++)
					{
						for (int x = 0; x < N; x++)
						{
							if (t % 2 == 1)
							{
								places[x, y] = true;
								b++;
							}
							else
							{
								places[x, y] = false;
							}
							t /= 2;
						}
					}
					if (b >= min)
					{
						continue;
					}
					//q.Clear();
					for (var x = 0; x < N; x++)
					{
						if (!places[x, 0])
						{
							q.Enqueue(new P(x, 0));
						}
						if (!places[x, M - 1])
						{
							q.Enqueue(new P(x, M - 1));
						}
					}
					for (var y = 1; y < M - 1; y++)
					{
						if (!places[0, y])
						{
							q.Enqueue(new P(0, y));
						}
						if (!places[N - 1, y])
						{
							q.Enqueue(new P(N - 1, y));
						}
					}
					for (int y = 0; y < M; y++)
					{
						for (int x = 0; x < N; x++)
						{
							reachable[x, y] = false;
						}
					}
					while (q.Count > 0)
					{
						var pl = q.Dequeue();
						reachable[pl.X, pl.Y] = true;
						if (pl.X > 0)
						{
							if (!places[pl.X - 1, pl.Y] && !reachable[pl.X - 1, pl.Y])
							{
								reachable[pl.X - 1, pl.Y] = true;
								q.Enqueue(new P(pl.X - 1, pl.Y));
							}
						}
						if (pl.Y > 0)
						{
							if (!places[pl.X, pl.Y - 1] && !reachable[pl.X, pl.Y - 1])
							{
								reachable[pl.X, pl.Y - 1] = true;
								q.Enqueue(new P(pl.X, pl.Y - 1));
							}
						}
						if (pl.X < N - 1)
						{
							if (!places[pl.X + 1, pl.Y] && !reachable[pl.X + 1, pl.Y])
							{
								reachable[pl.X + 1, pl.Y] = true;
								q.Enqueue(new P(pl.X + 1, pl.Y));
							}
						}
						if (pl.Y < M - 1)
						{
							if (!places[pl.X, pl.Y + 1] && !reachable[pl.X, pl.Y + 1])
							{
								reachable[pl.X, pl.Y + 1] = true;
								q.Enqueue(new P(pl.X, pl.Y + 1));
							}
						}
					}

					var blocked = 0;
					for (int y = 0; y < M; y++)
					{
						for (int x = 0; x < N; x++)
						{
							if (!reachable[x, y])
							{
								blocked++;
							}
						}
					}
					if (blocked >= K)
					{
						min = b;
					}
				}


				oup.WriteLine("Case #" + (caseIndex + 1).ToString() + ": " + min.ToString());
				Console.WriteLine(caseIndex.ToString());
			}
			oup.Close();
		}
	}

	struct P
	{
		public P(int x, int y)
		{
			X = x;
			Y = y;
		}
		public int X, Y;
	}
}