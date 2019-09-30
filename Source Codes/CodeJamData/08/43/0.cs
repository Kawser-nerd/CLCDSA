using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

namespace StarWars
{
	class Ship
	{
		public int X, Y, Z, P;

		public Ship(int x, int y, int z, int p)
		{
			X = x;
			Y = y;
			Z = z;
			P = p;
		}
	}
	class Program
	{
		static void Main(string[] args)
		{
			StreamReader sr = new StreamReader(@"c:\temp\c-small-attempt0.in");
//			StreamReader sr = new StreamReader(@"c:\temp\c.in");
//			TextWriter tw = Console.Out;
			TextWriter tw = new StreamWriter(@"c:\temp\c.out");

			int noCases = int.Parse(sr.ReadLine());
			for (int caseNo = 0; caseNo < noCases; caseNo++)
			{
				int T = int.Parse(sr.ReadLine());
				Ship[] ships = new Ship[T];
				for (int i = 0; i < T; i++)
				{
					string[] split = sr.ReadLine().Split(' ');
					ships[i] = new Ship(int.Parse(split[0]), int.Parse(split[1]), int.Parse(split[2]), int.Parse(split[3]));
				}
				double lo = 0, hi = 10000000;
				for (int i = 0; i < 200; i++)
				{
					double x = (lo + hi)/2;
					bool ok = true;
					for (int j = 0; j < T && ok; j++)
					{
						for (int k = j + 1; k < T && ok; k++)
						{
							int xdif = Math.Abs(ships[j].X - ships[k].X);
							int ydif = Math.Abs(ships[j].Y - ships[k].Y);
							int zdif = Math.Abs(ships[j].Z - ships[k].Z);
							double d = (double) (xdif+ydif+zdif) / (ships[j].P + ships[k].P);
							if (d > x)
								ok = false;
						}
					}
					if (ok)
						hi = x;
					else
						lo = x;
				}
				tw.WriteLine("Case #{0}: {1}", (caseNo + 1), lo.ToString("0.000000", CultureInfo.InvariantCulture));
			}
			tw.Close();
		}
	}
}
