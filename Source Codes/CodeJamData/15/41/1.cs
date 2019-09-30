using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Linq;

public class A
{
	public static void Main(string[] args)
	{
		Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
		int CASES = int.Parse(Console.ReadLine());
		for (int CASE = 1; CASE <= CASES; CASE++)
		{
			Console.Error.WriteLine("Case " + CASE);

			string[] ps = Console.ReadLine().Split();
			int R = int.Parse(ps[0]);
			int C = int.Parse(ps[1]);
			string[] grid = new string[R];
			for (int i = 0; i < R; i++)
				grid[i] = Console.ReadLine();

			bool ok = true;
			int count = 0;
			string dirs = "^>v<";
			int[] dr = { -1, 0, 1, 0 };
			int[] dc = { 0, 1, 0, -1 };

			for (int r = 0; r < R; r++)
			{
				for (int c = 0; c < C; c++)
				{
					if (grid[r][c] == '.') continue;
					bool can = false;
					bool canI = false;
					for (int d = 0; d < 4; d++)
					{
						bool hasArrow = false;
						int nr = r + dr[d];
						int nc = c + dc[d];
						while (nr >= 0 && nr < R && nc >= 0 && nc < C && !hasArrow)
						{
							if (grid[nr][nc] != '.') hasArrow = true;
							nr += dr[d];
							nc += dc[d];
						}
						if (hasArrow)
						{
							can = true;
							if (dirs[d] == grid[r][c])
								canI = true;
						}
					}
					if (canI) ;
					else if (can) count++;
					else ok = false;
				}
			}

			Console.WriteLine("Case #" + CASE + ": " + (ok ? count.ToString() : "IMPOSSIBLE"));
		}
	}
}
