using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using Library;
using Library.Extensions;

namespace Competition.Google.CodeJam2009.Qualification
{
	public class Watersheds : CodeJamProblem
	{
		private class N
		{
			public char ch = '7';
			public N child = null;
		}

		protected override string Solve(string input)
		{
			CodeJamIO io = new CodeJamIO(input);
			int la = int.Parse(io[0]);
			int line = 1;
			for (int map = 0; map < la; map++)
			{
				int height = int.Parse(io.GetSpaceSplit(line)[0]);
				int width = int.Parse(io.GetSpaceSplit(line)[1]);
				line++;

				int[,] alt = new int[height, width];
				N[,] stuff = new N[height, width];
				for (int h = 0; h < height; h++, line++)
				{
					var l = io.GetSpaceSplit(line);
					if ( l.Length != width ) throw new Exception();
					for (int w = 0; w < l.Length; w++)
					{
						alt[h, w] = int.Parse(l[w]);
						stuff[h, w] = new N();
					}
				}

				for (int h = 0; h < height; h++)
					for (int w = 0; w < width; w++)
						PutChild(stuff, h, w, alt);

				StringBuilder sb = new StringBuilder();
				sb.AppendLine();

				char ch = 'a';
				for (int h = 0; h < height; h++)
				{
					for (int w = 0; w < width; w++)
					{
						N n = stuff[h, w];
						while (n.child != null)
							n = n.child;

						if (n.ch == '7')
						{
							n.ch = ch;
							ch++;
						}

						sb.Append(n.ch);
						sb.Append(' ');
					}
					sb.AppendLine();
				}

				sb.Length = sb.Length - 2;
				io.WriteCase(sb.ToString());
			}

			return io.GetResults();
		}

		private int[] H = 
		{
			-1,
			0,
			0,
			1,
		};
		private int[] W = 
		{
			0,
			-1,
			1,
			0,
		};

		private void PutChild(N[,] child, int h, int w, int[,] alt)
		{
			int curLevel = alt[h, w];
			int newH = h;
			int newW = w;

			for (int i = 0; i < 4; i++)
			{
				int hh = h + H[i];
				int ww = w + W[i];
				if (hh >= 0 && ww >= 0 &&
					hh < alt.GetLength(0) &&
					ww < alt.GetLength(1) &&
					curLevel > alt[hh, ww])
				{
					curLevel = alt[hh, ww];
					newH = hh;
					newW = ww;
				}
			}

			if (newH != h || newW != w)
			{
				child[h, w].child = child[newH, newW];
			}
		}
	}
}
