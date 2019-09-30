using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P1
{
	class Program
	{
		static char left = '<', right = '>', up = '^', down = 'v';
		static char[] chars = new char[] { left, right, up, down };

		public static int gdx(char c)
		{
			if (c == left) return -1;
			if (c == right) return 1;
			return 0;
		}

		public static int gdy(char c)
		{
			if (c == up) return -1;
			if (c == down) return 1;
			return 0;
		}

		static void Main(string[] args)
		{
			using (var input = new FileStream("in.in", FileMode.Open, FileAccess.Read))
			{
				using (var reader = new StreamReader(input))
				{
					using (var output = new FileStream("out.out", FileMode.Create, FileAccess.Write))
					{
						using (var writer = new StreamWriter(output))
						{
							var s = reader.ReadLine();
							var T = int.Parse(s);
							for (var t = 1; t <= T; t++)
							{
								s = reader.ReadLine();
								var parts = s.Split(' ');
								var R = int.Parse(parts[0]);
								var C = int.Parse(parts[1]);
								var grid = new string[R];
								for (var i = 0; i < R; i++)
								{
									grid[i] = reader.ReadLine();
								}
								bool possible = true;
								var cnt = 0;
								for (var i = 0; i < R; i++)
								{
									for (var j = 0; j < C; j++)
									{
										if (grid[i][j] == '.')
										{
											continue;
										}
										var dx = gdx(grid[i][j]);
										var dy = gdy(grid[i][j]);
										var x = j + dx;
										var y = i + dy;
										bool done = false;
										while (x >= 0 && x < C && y >= 0 && y < R)
										{
											if (grid[y][x] != '.')
											{
												done = true;
												break;
											}
											x += dx;
											y += dy;
										}
										if (done)
										{
											continue;
										}
										foreach (var c in chars)
										{
											dx = gdx(c);
											dy = gdy(c);
											x = j + dx;
											y = i + dy;
											while (x >= 0 && x < C && y >= 0 && y < R)
											{
												if (grid[y][x] != '.')
												{
													cnt++;
													done = true;
													break;
												}
												x += dx;
												y += dy;
											}
											if (done)
											{
												break;
											}
										}
										if (!done)
										{
											possible = false;
											break;
										}
									}
									if (!possible)
									{
										break;
									}
								}
								writer.WriteLine(String.Format("Case #{0}: {1}", t, possible ? cnt.ToString() : "IMPOSSIBLE"));
							}
						}
					}
				}
			}
		}
	}
}