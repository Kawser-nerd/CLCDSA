using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace EndlessKnight
{
	class Program
	{
		static void Main(string[] args)
		{
//			StreamReader sr = new StreamReader(@"c:\gcj\d.in");
			StreamReader sr = new StreamReader(@"c:\gcj\d-small-attempt0.in");
//			TextWriter tw = Console.Out;
			TextWriter tw = new StreamWriter(@"c:\gcj\d.out");

			int noCases = int.Parse(sr.ReadLine());
			for (int caseNo = 0; caseNo < noCases; caseNo++)
			{
				var split = sr.ReadLine().Split(' ');
				int ysize = int.Parse(split[0]);
				int xsize = int.Parse(split[1]);
				int rooks = int.Parse(split[2]);
				int[] rx = new int[rooks], ry = new int[rooks];
				for (int i = 0; i < rooks; i++)
				{
					var split1 = sr.ReadLine().Split(' ');
					ry[i] = int.Parse(split1[0]);
					rx[i] = int.Parse(split1[1]);
					ry[i]--;
					rx[i]--;
					if (rx[i] >= xsize || ry[i] >= ysize) throw new Exception();
				}
				
				int[,] ways = new int[ysize,xsize];
				for (int y = 0; y < ysize; y++)
				{
					for (int x = 0; x < xsize; x++)
					{
						bool rook = false;
						for (int i = 0; i < rooks; i++)
						{
							if (rx[i] == x && ry[i] == y)
								rook = true;
						}
						if (y == 0 && x == 0)
							ways[y, x] = 1;
						else if (rook)
							ways[y, x] = 0;
						else
							ways[y, x] = (y >= 2 && x >= 1 ? ways[y - 2, x - 1] : 0) + (y >= 1 && x >= 2 ? ways[y - 1, x - 2] : 0);
						ways[y, x] %= 10007;
					}
				}

				tw.WriteLine("Case #" + (caseNo + 1) + ": " + ways[ysize - 1, xsize - 1]);
			}

			tw.Close();
		}
	}
}
