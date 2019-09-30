using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Triangle
{
	class Program
	{
		static void Main(string[] args)
		{
			string filename = "A-small-attempt0";

			TextReader reader = new StreamReader(filename + ".in");
			TextWriter writer = new StreamWriter(filename + ".out");

			int numCases = int.Parse(reader.ReadLine());

			for (int i = 0; i < numCases; i++)
			{
				string[] s = reader.ReadLine().Split(' ');
				int numTrees = int.Parse(s[0]);
				long a = int.Parse(s[1]);
				long b = int.Parse(s[2]);
				long c = int.Parse(s[3]);
				long d = int.Parse(s[4]);
				long x = int.Parse(s[5]);
				long y = int.Parse(s[6]);
				long m = int.Parse(s[7]);

				List<Point> points = new List<Point>();
				points.Add(new Point(x, y));
				for (long j = 1; j < numTrees; j++)
				{
					x = (a * x + b) % m;
					y = (c * y + d) % m;
					points.Add(new Point(x, y));
				}

				long answer = FindTriangles(points);
				writer.WriteLine("Case #" + (i + 1) + ": " + answer);
			}

			reader.Close();
			writer.Close();
		}

		static long FindTriangles(List<Point> points)
		{
			long answer = 0;
			for (int x = 0; x < points.Count; x++)
			{
				for (int y = x + 1; y < points.Count; y++)
				{
					for (int z = y + 1; z < points.Count; z++)
					{
						bool newX = (points[x].x + points[y].x + points[z].x) % 3 == 0;
						bool newY = (points[x].y + points[y].y + points[z].y) % 3 == 0;
						if (newX && newY)
						{
							answer++;
						}
					}
				}
			}
			return answer;
		}
	}

	struct Point
	{
		public long x;
		public long y;
		public Point(long x, long y)
		{
			this.x = x;
			this.y = y;
		}
	}
}
