using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace codejam
{
	class Solution
	{
		Solution(string fileName)
		{
			cin = File.OpenText(fileName);
			cout = new StreamWriter(@"D:\codejam\" + "output.txt");
			//cin = Console.In;
			//cout = Console.Out;
		}

		void Close()
		{
			cin.Close();
			cout.Close();
		}

		static public void Run(string fileName)
		{
			Solution solution = new Solution(@"D:\codejam\" + fileName);
			solution.Solve();
			solution.Close();
		}

		class Point
		{
			public int X;
			public double Y;
			public Point(int X, double Y)
			{
				this.X = X;
				this.Y = Y;
			}
		}

		double Find(double L, double A, double B, double S)
		{
			double l = 0;
			double u = 1;
			while (Math.Abs(u - l) > 1e-8)
			{
				double m = (l + u) / 2;
				double s = L * m * (2 * A + (B - A) * m) / 2;
				if (s > S)
					u = m;
				else
					l = m;
			}
			return (l + u) / 2;
		}

		void Solve()
		{
			
			int Test = Convert.ToInt32(cin.ReadLine());
			for (int testCase = 1; testCase <= Test; testCase++)
			{
				string[] s = cin.ReadLine().Split(' ');
				int W = Convert.ToInt32(s[0]);
				int L = Convert.ToInt32(s[1]);
				int U = Convert.ToInt32(s[2]);
				int G = Convert.ToInt32(s[3]);
				up.Clear(); down.Clear();
				for (int i = 0; i < L; i++)
				{
					s = cin.ReadLine().Split(' ');
					down.Add(new Point(Convert.ToInt32(s[0]), Convert.ToInt32(s[1])));
				}
				for (int i = 0; i < U; i++)
				{
					s = cin.ReadLine().Split(' ');
					up.Add(new Point(Convert.ToInt32(s[0]), Convert.ToInt32(s[1])));
				}
				double Area = 0;
				Point curPoint = up[0];
				for (int i = 1; i < U; i++)
				{
					Area += (up[i].X - curPoint.X) * (up[i].Y + curPoint.Y) / 2;
					curPoint = up[i];
				}
				curPoint = down[0];
				for (int i = 1; i < L; i++)
				{
					Area -= (down[i].X - curPoint.X) * (down[i].Y + curPoint.Y) / 2;
					curPoint = down[i];
				}
				int x = Math.Min(down[0].X, up[0].X);
				int l = 1, u = 1;
				while (x < W)
				{
					if (down[l].X == up[u].X)
					{
						x = down[l].X;
						l ++;
						u ++;
						continue;
					}
					if (down[l].X < up[u].X)
					{
						Point P = new Point(down[l].X, up[u - 1].Y + (up[u].Y - up[u - 1].Y) * (down[l].X - up[u - 1].X) / (up[u].X - up[u - 1].X));
						up.Insert(u, P);
					}
					else
					{
						Point P = new Point(up[u].X, down[l - 1].Y + (down[l].Y - down[l - 1].Y) * (up[u].X - down[l - 1].X) / (down[l].X - down[l - 1].X));
						down.Insert(l, P);
					}
					x = Math.Min(up[u].X, down[l].X);
					
				}
				Area /= G;
				double X = 0;
				double LY = down[0].Y, UY = up[0].Y;
				int ind = 1;
				cout.WriteLine("Case #{0}:", testCase);
				for (int i = 1; i < G; i++)
				{
					double S = Area;
					while (S > 1e-8)
					{
						double a = (double)(up[ind].X - X) * (UY - LY + up[ind].Y - down[ind].Y) / 2;
						if (a <= S)
						{
							S -= a;
							X = up[ind].X;
							LY = down[ind].Y;
							UY = up[ind].Y;
							ind++;
							continue;
						}
						double b = Find(up[ind].X - X, UY - LY, up[ind].Y - down[ind].Y, S);
						X = (up[ind].X - X) * b + X;
						LY = LY + (down[ind].Y - LY) * b;
						UY = UY + (up[ind].Y - UY) * b;
						S = 0;
					}
					cout.WriteLine(X.ToString("0.000000").Replace(',','.'));
				}
			}
		}

		List<Point> up = new List<Point>();
		List<Point> down = new List<Point>();
		TextReader cin;
		TextWriter cout;
	}
	class Program
	{
		static void Main(string[] args)
		{
			Solution.Run("A-large.in");
		}
	}
}
