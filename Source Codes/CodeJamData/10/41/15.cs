using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ2010
{
	class Round2A
	{
		public void SloveFile(string inputfile)
		{
			using (StreamReader reader = new StreamReader(inputfile))
			using (StreamWriter writer = new StreamWriter(inputfile + ".out")) {
				int caseCount = int.Parse(reader.ReadLine());
				for (int caseNo = 1; caseNo <= caseCount; caseNo++) {
					int k = int.Parse(reader.ReadLine());
					
					int[,] diamond = new int[2 * k - 1, 2 * k - 1];
					
					for (int i = 0; i < 2 * k - 1; i++) {
						var s = reader.ReadLine();
						for (int j = 0; j < 2 * k - 1; j++) {
							if (j < s.Length) {
								if (s[j] == ' ')
									diamond[i, j] = -1;
								else
									diamond[i, j] = int.Parse(s[j].ToString());
							} else {
								diamond[i, j] = -1;
							}							
						}
					}
					
					Print(k, diamond);

					int result = SloveCase(k, diamond);
					writer.WriteLine("Case #{0}: {1}", caseNo, result);
					Console.WriteLine("Case #{0}: {1}", caseNo, result);
					// Console.ReadLine();
				}
			}
		}

		public int SloveCase(int k, int[,] diamond)
		{
			if (k == 1)
				return 0;

			int r = int.MaxValue;
			for (int y = 0; y < 2 * k - 1; y++) {
				for (int x = 0; x < 2 * k - 1; x++) {
					if (Symmetry(diamond, x, y, k)) {
						int t =  Math.Abs(x - (k - 1)) + Math.Abs(y - (k - 1));
						Console.WriteLine("Symmetry at {0},{1} t={2}", x, y, t);
						r = Math.Min(t, r);
					}
				}
			}

			Console.WriteLine("r={0}", r);
			return (k + r) * (k + r) - k * k;
		}

		public void Print(int k, int[,] diamond)
		{
			for (int y = 0; y < 2 * k - 1; y++) {
				for (int x = 0; x < 2 * k - 1; x++) {
					Console.Write(diamond[y, x] >= 0 ? diamond[y, x].ToString() : " ");
				}
				Console.WriteLine();
			}
		}

		public bool Symmetry(int[,] diamond, int x0, int y0, int k)
		{
			int dx = x0 > k ? -1 : 1;
			
			for (int x = x0; x >= 0 && x < 2 * k - 1; x += dx) {
				int sx = x0 + (x0 - x);
				if (sx < 0 || sx >= 2 * k - 1)
					continue;
					 
				for (int y = 0; y < 2 * k - 1; y++){
					if (diamond[y, x] == -1 || diamond[y, sx] == -1)
						continue;

					if (diamond[y, x] != diamond[y, sx])
						return false;
				}
			}
			int dy = y0 > k ? -1 : 1;
			
			for (int y = y0; y >= 0 && y < 2 * k - 1; y += dx) {
				int sy = y0 + (y0 - y);
				if (sy < 0 || sy >= 2 * k - 1)
					continue;
					 
				for (int x = 0; x < 2 * k - 1; x++){
					if (diamond[y, x] == -1 || diamond[sy, x] == -1)
						continue;

					if (diamond[y, x] != diamond[sy, x])
						return false;
				}
			}
			return true;
		}
	}
}
