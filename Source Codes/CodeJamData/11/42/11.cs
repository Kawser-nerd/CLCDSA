using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Competition
{
	public class SpinningBlade
	{
		public void tester()
		{
			var sb = new StringBuilder();
			//string loc = @"C:\Pub\input.txt";
			string loc = @"C:\Pub\B-small-attempt1.in";
			//string loc = @"C:\Pub\A-large.in";
			string[] lines = System.IO.File.ReadAllLines(loc);
			int caseNo = 1;
			for (int i = 1; i < lines.Length; )
			{
				var spl = lines[i++].Split().Select(x => int.Parse(x)).ToArray();
				var R = spl[0];
				var C = spl[1];
				var D = spl[2];

				int[,] grid = new int[R, C];
				for (int r = 0; r < R; r++)
				{
					var ln = lines[i++];
					for (int c = 0; c < C; c++)
					{
						grid[r, c] = D;
						grid[r, c] += int.Parse(ln[c].ToString());
					}
				}

				int size = 0;

				for (int s = Math.Min(R, C); s >= 3; s--)
				{
					for (int r = 0; r <= R - s; r++)
					{
						for (int c = 0; c <= C - s; c++)
						{
							if (IsValid(r, c, grid, s))
							{
								size = s;
								r = 100000000;
								s = -1;
								break;
							}
						}
					}
				}


				sb.AppendFormat("Case #{0}: ", caseNo++);
				if (size > 0)
				{
					sb.Append(size.ToString());
				}
				else
				{
					sb.Append("IMPOSSIBLE");
				}
				sb.AppendLine();
			}
			string outloc = @"C:\Pub\test.txt";
			System.IO.File.WriteAllText(outloc, sb.ToString());
		}

		private bool IsValid(int R, int C, int[,] grid, int size)
		{
			if (size % 2 == 1)
			{
				return IsValidOdd(R, C, grid, size);
			}
			else
			{
				return IsValidEven(R, C, grid, size);
			}
		}

		private bool IsValidEven(int R, int C, int[,] grid, int size)
		{
			int X = 0;
			int Y = 0;

			int evenPoint = size / 2;

			for (int r = 0; r < size; r++)
			{
				for (int c = 0; c < size; c++)
				{
					if ((r == 0 || r == size-1) && (c == 0 || c == size - 1)) continue;

					int multX = 1 + (2 * (evenPoint-1 - r));
					X += (multX * grid[R + r, c + C]);

					int multY = 1 + (2 * (evenPoint-1 - c));
					Y += (multY * grid[R + r, c + C]);
				}
			}

			return X == 0 && Y == 0;
		}

		private bool IsValidOdd(int R, int C, int[,] grid, int size)
		{
			int X = 0;
			int Y = 0;

			int evenPoint = size / 2;

			for (int r = 0; r < size; r++)
			{
				for (int c = 0; c < size; c++)
				{
					if ((r == 0 || r == size - 1) && (c == 0 || c == size - 1)) continue;

					int multX = (r - evenPoint);
					X += (multX * grid[R + r, c + C]);

					int multY = (c - evenPoint);
					Y += (multY * grid[R + r, c + C]);
				}
			}

			return X == 0 && Y == 0;
		}
	}
}
