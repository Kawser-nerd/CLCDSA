using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam
{
	
	class Program
	{
		static void Main(string[] args)
		{
			string[] lines = File.ReadAllLines("D-small-attempt0.in");
			int lineat = 0;
			int count = int.Parse(lines[lineat++]);
			string output = "";
			for (int i = 0; i < count; i++)
			{
				string[] l = lines[lineat++].Split(' ');
				int r = int.Parse(l[0]);
				int c = int.Parse(l[1]);
				bool[,] burned = new bool[r, c];
				int sr=0, sc = 0;
				for (int j = 0; j < r; j++)
				{
					string what = lines[lineat++];
					for (int k = 0; k < c; k++)
					{
						burned[j,k] = what[k] == '#';
						if (what[k] == 'K')
						{
							sr = j;
							sc = k;
						}
					}
				}

				Program p = new Program();
				p.burned = burned;
				p.r = r;
				p.c = c;
				char answer = p.solve(0, sr, sc, ((1 << (r * c)) - 1) ^ (1<< (sr * c + sc)));
				output += "Case #" + (i + 1) + ": " + answer + Environment.NewLine;
			}
			File.WriteAllText("output.txt", output);
			Console.WriteLine(output);
		}
		char[,,,] memo = new char[2,4,4,1 << (16)];
		bool[,] burned;
		int r;
		int c;
		int[] dx = new int[] { -1, -1, -1,  0, 0,  1, 1, 1 };
		int[] dy = new int[] { -1,  0,  1, -1, 1, -1, 0, 1 };
		char solve(int turn, int ar, int ac, int open)
		{
			if (memo[turn, ar, ac, open] == 'A' || memo[turn, ar, ac, open] == 'B') return memo[turn, ar, ac, open];

			char res = turn == 0 ? 'B' : 'A';
			char me = turn == 0 ? 'A' : 'B';
			for (int i = 0; i < 8; i++)
			{
				int ddr = ar + dx[i];
				int ddc = ac + dy[i];
				if (ddr >= 0 && ddr < r && ddc >= 0 && ddc < c && !burned[ddr, ddc] && (open & (1 << (ddr * c + ddc))) != 0)
				{
					char them = solve(1 - turn, ddr, ddc, open ^ (1 << (ddr * c + ddc)));
					if (them == me)
					{
						res = me;
						break;
					}
				}
			}
			memo[turn, ar, ac, open] = res;
			return res;
		}
	}
}
