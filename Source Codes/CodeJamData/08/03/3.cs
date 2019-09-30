using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ
{
	static class Ext
	{

		static char[] emptyChars = "\r\n\t ".ToCharArray();

		public static string[] SplitByWhiteSpaces(this string source)
		{
			return source.Split(emptyChars, StringSplitOptions.RemoveEmptyEntries);
		}
	}

	class Program
	{

		static StreamReader fin;
		static StreamWriter fout;

		static void Main(string[] args)
		{
			DateTime s = DateTime.Now;
			using (fout = new StreamWriter("../../out.txt"))
			{
				using (fin = new StreamReader("../../in.in"))
				{

					int n = Int32.Parse(fin.ReadLine());

					for (int i = 1; i <= n; ++i)
					{
						fout.Write("Case #{0}: ", i);
						new Program().Solve();
					}

				}
			}

			TimeSpan d = DateTime.Now - s;

			Console.WriteLine(d);
			Console.ReadLine();
		}

		public class point
		{
			public double x, y;

			public point(double x, double y)
			{
				this.x = x;
				this.y = y;
			}

			public double distTo(point p2)
			{
				var dx = x - p2.x;
				var dy = y - p2.y;
				return Math.Sqrt(dx * dx + dy * dy);
			}

			public override string ToString()
			{
				return String.Format("X = {0}, Y = {1}", x, y);
			}
		}

		//double tranAngle2(double r, point p1, point p2)
		//{
		//    return tranAngle2(r, p1, p2) * 180 / Math.PI;
		//}

		//double tranAngle(double r, point p1, point p2)
		//{
		//    double d = p1.distTo(p2);
		//    var b1 = d / 2;
		//    double b2 = Math.Sqrt(r * r - b1 * b1);
		//    var tg = b1 / b2;
		//    return Math.Atan(tg);
		//}

		//double fanArea(double r, point p1, point p2)
		//{
		//    return r * r * tranAngle(r, p1, p2) / 2;
		//}

		static point OrgPoint = new point(0, 0);

		double bowArea(double r, point p1, point p2)
		{
			double d = p1.distTo(p2);
			var b1 = d / 2;
			double b2 = Math.Sqrt(r * r - b1 * b1);
			var tg = b1 / b2;
			var angle = Math.Atan(tg) * 2;
			//Console.WriteLine(angle * (180 / Math.PI));
			var fanA = r * r * angle / 2;
			var tranA = b1 * b2;
			return fanA - tranA;
		}

		double f, R, t, r, g;
		double innerR, grid, flyR;
		double sqPass;
		double passG;

		public void Solve()
		{
			var tmp = fin.ReadLine().SplitByWhiteSpaces();

			f = Double.Parse(tmp[0]);
			R = Double.Parse(tmp[1]);
			t = Double.Parse(tmp[2]);
			r = Double.Parse(tmp[3]);
			g = Double.Parse(tmp[4]);

			//Console.WriteLine(bowArea(1, new point(0, 1), new point(1, 0)));
			//Console.WriteLine(Math.PI / 4);

			innerR = R - t;
			flyR = innerR - f;
			grid = g + r + r;
			passG = g - f - f;
			if (passG <= 0)
			{
				fout.WriteLine("{0:F6}", 1.0);
				return;
			}
			sqPass = passG * passG;

			double passArea = 0.0;
			for (double vstring = 0.0; vstring < innerR; vstring += grid)
			{
				for (double hstring = 0.0; hstring <= innerR; hstring += grid)
				{
					passArea += calcPass(vstring, hstring);
				}
			}

			passArea *= 4;
			double totArea = Math.PI * R * R;
			fout.WriteLine("{0:F6}", (totArea - passArea) / totArea);
		}

		double otherCood(double r, double cood)
		{
			return Math.Sqrt(r * r - cood * cood);
		}

		private double calcPass(double vstring, double hstring)
		{
			var x1 = vstring + r;
			var x2 = x1 + g;
			var y1 = hstring + r;
			var y2 = y1 + g;
			x1 += f;
			x2 -= f;
			y1 += f;
			y2 -= f;

			var leftBottom = new point(x1, y1);
			// totally out
			if (OrgPoint.distTo(leftBottom) >= flyR)
			{
				return 0;
			}

			var rightTop = new point(x2, y2);
			if (rightTop.distTo(OrgPoint) <= flyR)
			{
				return sqPass;
			}
			var rightBottom = new point(x2, y1);
			bool rightBottomOut = rightBottom.distTo(OrgPoint) >= flyR;
			var leftTop = new point(x1, y2);
			bool leftTopOut = leftTop.distTo(OrgPoint) >= flyR;

			double res = 0;

			// 1
			if (!rightBottomOut && !leftTopOut)
			{
				var p1 = new point(x2, otherCood(flyR, x2));
				var p2 = new point(otherCood(flyR, y2), y2);

				res += bowArea(flyR, p1, p2);
				res += sqPass;
				res -= ((x2 - p2.x) * (y2 - p1.y)) / 2;
			}
			else if (rightBottomOut && !leftTopOut)
			{
				var p1 = new point(otherCood(flyR, y1), y1);
				var p2 = new point(otherCood(flyR, y2), y2);
				res += bowArea(flyR, p1, p2);
				var lx = Math.Max(p1.x, p2.x);
				var sx = Math.Min(p1.x, p2.x);
				res += passG * (sx - x1);
				res += (passG * (lx - sx)) / 2;
			}
			else if (!rightBottomOut && leftTopOut)
			{
				var p1 = new point(x2, otherCood(flyR, x2));
				var p2 = new point(x1, otherCood(flyR, x1));
				res += bowArea(flyR, p1, p2);
				var ly = Math.Max(p1.y, p2.y);
				var sy = Math.Min(p1.y, p2.y);
				res += passG * (sy - y1);
				res += (passG * (ly - sy)) / 2;
			}
			else if (rightBottomOut && leftTopOut)
			{
				var p1 = new point(x1, otherCood(flyR, x1));
				var p2 = new point(otherCood(flyR, y1), y1);
				res += bowArea(flyR, p1, p2);
				res += ((p1.y - y1) * (p2.x - x1)) / 2;
			}

			return res;
		}
	}
}