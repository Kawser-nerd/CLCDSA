using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Competition
{
	public class SquareTiles
	{
		public void tester()
		{
			var sb = new StringBuilder();
			//string loc = @"C:\Pub\input.txt";
			string loc = @"C:\Pub\A-large.in";
			string[] lines = System.IO.File.ReadAllLines(loc);
			int caseNo = 1;
			for (int i = 1; i < lines.Length; )
			{
				var spl = lines[i++].Split().Select(x => int.Parse(x)).ToArray();
				int r = spl[0];
				int c = spl[1];
				List<char[]> data = new List<char[]>();
				for (int k = 0; k < r; k++)
				{
					data.Add(lines[i++].ToCharArray());
				}
				bool possible = true;
				for (int k = 0; k < r; k++)
				{
					for (int j = 0; j < c; j++)
					{
						if (data[k][j] == '#')
						{
							if ( !Place(k, j, data))
							{
								possible = false;
								k = 10000;
								break;
							}
						}
					}
				}

				sb.AppendFormat("Case #{0}: ", caseNo++);
				sb.AppendLine();
				if (possible)
				{
					foreach (var s in data)
					{
						sb.AppendLine(new string(s));
					}
				}
				else
				{
					sb.AppendLine("Impossible");
				}
			}
			string outloc = @"C:\Pub\test.txt";
			System.IO.File.WriteAllText(outloc, sb.ToString());
		}

		public bool Place(int row, int col, List<char[]> data)
		{
			char[] r = data[row];
			if (col+1 >= r.Length) return false;
			if (r[col] != '#' || r[col + 1] != '#') return false;
			r[col] = '/';
			r[col+1] = '\\';
			if (row + 1 >= data.Count) return false;
			r = data[row + 1];
			if (r[col] != '#' || r[col + 1] != '#') return false;
			r[col] = '\\';
			r[col + 1] = '/';
			return true;
		}

	}
}
