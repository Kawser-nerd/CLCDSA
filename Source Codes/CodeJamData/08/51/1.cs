using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Pockets
{
	class Program
	{
		private static int[] dx = new int[] {0, 1, 0, -1};
		private static int[] dy = new int[] { 1, 0, -1, 0 };

		static void Main(string[] args)
		{
//			StreamReader sr = new StreamReader(@"c:\gcj\a.in");
//			StreamReader sr = new StreamReader(@"c:\gcj\a-small-attempt0.in");
			StreamReader sr = new StreamReader(@"c:\gcj\a-large.in");
//			TextWriter tw = Console.Out;
			TextWriter tw = new StreamWriter(@"c:\gcj\a.out");

			int noCases = int.Parse(sr.ReadLine());
			for (int caseNo = 0; caseNo < noCases; caseNo++)
			{
				int L = int.Parse(sr.ReadLine());
				List<string> pairs = new List<string>();
				while (pairs.Count < L*2)
				{
					var split = sr.ReadLine().Split(' ');
					pairs.AddRange(split);
				}
				int OFS = 7500;
				int[] left = new int[15000], right = new int[15000], top = new int[15000], bottom = new int[15000];
				for (int i = 0; i < 15000; i++)
				{
					left[i] = right[i] = top[i] = bottom[i] = -1;
				}
				long polyArea = 0;
				int minx = OFS, maxx = OFS, miny = OFS, maxy = OFS;
				int cx = OFS, cy = OFS, dir = 0;
				for (int i = 0; i < pairs.Count; i+=2)
				{
					string s = pairs[i];
					int cnt = int.Parse(pairs[i + 1]);
					for (int j = 0; j < cnt; j++)
					{
						foreach(char c in s)
						{
//							Console.WriteLine((cx-OFS)/2 + ", " + (cy-OFS)/2);
							if (cx < minx) minx = cx;
							if (cx > maxx) maxx = cx;
							if (cy < miny) miny = cy;
							if (cy > maxy) maxy = cy;
							/*if (cx < left[cy]) left[cy] = cx;
							if (cx > right[cy]) right[cy] = cx;
							if (cy < bottom[cx]) bottom[cx] = cy;
							if (cy > top[cx]) top[cx] = cy;*/
							if (c == 'F')
							{
								if (dx[dir] == 1)
								{
									polyArea += cy;
									if (bottom[cx+1] < 0) bottom[cx + 1] = cy;
									if (top[cx + 1] < 0) top[cx + 1] = cy;
									bottom[cx + 1] = Math.Min(bottom[cx + 1], cy);
									top[cx + 1] = Math.Max(top[cx + 1], cy);
								}
								else if (dx[dir] == -1)
								{
									polyArea -= cy;
									if (bottom[cx - 1] < 0) bottom[cx - 1] = cy;
									if (top[cx - 1] < 0) top[cx - 1] = cy;
									bottom[cx - 1] = Math.Min(bottom[cx - 1], cy);
									top[cx - 1] = Math.Max(top[cx - 1], cy);
								}
								else if (dy[dir] == 1)
								{
									if (left[cy+1] < 0) 
										left[cy + 1] = cx;
									if (right[cy + 1] < 0) right[cy + 1] = cx;
									left[cy + 1] = Math.Min(left[cy + 1], cx);
									right[cy + 1] = Math.Max(right[cy + 1], cx);
								}
								else
								{
									if (left[cy - 1] < 0) 
										left[cy - 1] = cx;
									if (right[cy - 1] < 0) right[cy - 1] = cx;
									left[cy - 1] = Math.Min(left[cy - 1], cx);
									right[cy - 1] = Math.Max(right[cy - 1], cx);
								}

								cx += 2*dx[dir];
								cy += 2*dy[dir];
							} else if (c=='R')
							{
								dir = (dir + 1)%4;
							}
							else if (c=='L')
							{
								dir = (dir + 3)%4;
							}
							else
								throw new Exception();
						}
					}
				}
				if (cx != OFS || cy != OFS)
					throw new Exception();
/*
				Console.WriteLine("left-right boundaries");
				for (int i = miny+1; i <= maxy-1; i+=2)
				{
					Console.WriteLine("y=" + (i-OFS) / 2 + ": " + (left[i] - OFS)/2 + " " + (right[i] - OFS)/2);
				}
				Console.WriteLine("bottom-up boundaries");
				for (int i = minx+1; i <= maxx-1; i += 2)
				{
					Console.WriteLine("x=" + (i - OFS) / 2 + ": " + (bottom[i] - OFS) / 2 + " " + (top[i] - OFS) / 2);
				}*/

				polyArea = Math.Abs(polyArea/2);
				int complexArea = 0;
				for (int y = miny+1; y < maxy; y+=2)
				{
					for (int x = minx + 1; x < maxx; x+=2)
					{
						if (left[y] < x && right[y] > x)
							complexArea++;
						else if (bottom[x] < y && top[x] > y)
							complexArea++;
					}
				}

				int pocketArea = (int) (complexArea - polyArea);

				tw.WriteLine("Case #" + (caseNo + 1) + ": " + pocketArea);
				
			}
			tw.Close();
		}
	}
}
