using System;

public class A
{
	private static void Solve(char[,] cs, int w, int h)
	{
		var rowCount = 0;
		var ds = new char[h, w];
		var rows = new int[h];

		for (var i = 0; i < h; i++)
		{
			var allQ = true;

			for (var j = 0; j < w; j++)
			{
				ds[rowCount, j] = cs[i, j];

				if (cs[i, j] != '?')
				{
					allQ = false;
				}
			}

			if (allQ)
			{
				if (rowCount > 0)
				{
					rows[i] = rowCount - 1;
				}
				else
				{
					rows[i] = 0;
				}
			}
			else
			{
				rows[i] = rowCount++;
			}
		}

		for (var i = 0; i < rowCount; i++)
		{
			var c = '?';

			for (var j = 0; j < w; j++)
			{
				if (ds[i, j] == '?')
				{
					if (c != '?')
					{
						ds[i, j] = c;
					}
				}
				else
				{
					if (c == '?')
					{
						for (var k = 0; k < j; k++)
						{
							ds[i, k] = ds[i, j];
						}
					}

					c = ds[i, j];
				}
			}
		}

		for (var i = 0; i < h; i++)
		{
			for (var j = 0; j < w; j++)
			{
				cs[i, j] = ds[rows[i], j];
			}
		}
	}

	public static void Print(char[,] cs, int w, int h)
	{
		for (var i = 0; i < h; i++)
		{
			for (var j = 0; j < w; j++)
			{
				Console.Write("{0}", cs[i, j]);
			}

			Console.Write('\n');
		}
	}

	public static void Main(string[] args)
	{
		var T = int.Parse(Console.ReadLine());

		for (var Q = 1; Q <= T; Q++)
		{
			var words = Console.ReadLine().Split(' ');
			var h = int.Parse(words[0]);
			var w = int.Parse(words[1]);

			var cs = new char[h, w];

			for (var i = 0; i < h; i++)
			{
				var row = Console.ReadLine();

				for (var j = 0; j < w; j++)
				{
					cs[i, j] = row[j];
				}
			}

			Solve(cs, w, h);

			Console.Write("Case #{0}:\n", Q);

			Print(cs, w, h);
		}
	}
}