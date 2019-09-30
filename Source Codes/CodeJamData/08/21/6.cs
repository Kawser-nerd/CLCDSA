using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CropTriangles
{
	class Program
	{
		static void Main(string[] args)
		{
			var sr = new StreamReader(@"c:\temp\A-large.in");
			var sw = new StreamWriter(@"c:\temp\A.out");

			int N = int.Parse(sr.ReadLine());
			for (int i = 0; i < N; i++)
			{
				string[] split = sr.ReadLine().Split(' ');
				int n = int.Parse(split[0]);
				long A = int.Parse(split[1]);
				long B = int.Parse(split[2]);
				long C = int.Parse(split[3]);
				long D = int.Parse(split[4]);
				long x0 = int.Parse(split[5]);
				long y0 = int.Parse(split[6]);
				long m = int.Parse(split[7]);

				var coords = new List<Coord>(n);
				long X = x0, Y = y0;
				coords.Add(new Coord(X, Y));

				var cnt = new long[3,3];
				cnt[X%3, Y%3]++;

				for (int j = 1; j < n; j++)
				{
					X = (A*X + B)%m;
					Y = (C*Y + D)%m;
					cnt[X % 3, Y % 3]++;
					coords.Add(new Coord(X, Y));
				}
				long count = 0;
				/*
								for (int a = 0; a < n; a++)
								{
									for (int b = a+1; b < n; b++)
									{
										for (int c = b+1; c < n; c++)
										{
											long cx = coords[a].X + coords[b].X+ coords[c].X;
											long cy = coords[a].Y + coords[b].Y+ coords[c].Y;
											if (cx % 3 == 0 && cy % 3 == 0)
											{
				//								Console.WriteLine(a + " " + b + " " + c + " is tri");
												count++;
											}
										}
									}
								}
								sw.WriteLine("Case #" + (i+1) + ": " + count);*/

				count = 0;
				for (int ax = 0; ax < 3; ax++)
					for (int ay = 0; ay < 3; ay++)
						for (int bx = 0; bx < 3; bx++)
							for (int by = 0; by < 3; by++)
							{
								int cx = (3 - (ax + bx)%3)%3, cy = (3 - (ay + by)%3)%3;
								int a = ax*3 + ay, b = bx*3 + by, c = cx*3 + cy;
								if (a > b || b > c)
									continue;

								long tc;

								if (ax == bx && ay == by && ax == cx && ay == cy)
									tc = (cnt[ax, ay] * (cnt[ax, ay] - 1) * (cnt[ax, ay] - 2)) / 6;
								else if (ax == bx && ay == by)
									tc = (cnt[ax, ay]*(cnt[ax, ay] - 1)*cnt[cx, cy]) /2;
								else if (ax == cx && ay == cy)
									tc = (cnt[ax, ay] *(cnt[ax,ay]-1)* cnt[bx, by]) / 2;
								else if (bx == cx && by == cy)
									tc = (cnt[ax, ay]*cnt[bx, by]*(cnt[bx, by] - 1)) / 2;
								else 
									tc = cnt[ax, ay]*cnt[bx, by]*cnt[cx, cy];
								count += tc;
							}
				
				sw.WriteLine("Case #" + (i + 1) + ": " + count);
			}
			sr.Close();
			sw.Close();
		}

		class Coord
		{
			public long X, Y;

			public Coord(long x, long y)
			{
				X = x;
				Y = y;
			}

			public bool Equals(Coord obj)
			{
				if (ReferenceEquals(null, obj)) return false;
				if (ReferenceEquals(this, obj)) return true;
				return obj.X == X && obj.Y == Y;
			}

			public override bool Equals(object obj)
			{
				if (ReferenceEquals(null, obj)) return false;
				if (ReferenceEquals(this, obj)) return true;
				if (obj.GetType() != typeof (Coord)) return false;
				return Equals((Coord) obj);
			}

			public override int GetHashCode()
			{
				unchecked
				{
					return (X.GetHashCode()*397) ^ Y.GetHashCode();
				}
			}

			public override string ToString()
			{
				return X + "," + Y;
			}
		}
	}
}
