using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using Library;
using Library.Extensions;
using System.Text;
using System.IO;

namespace WindowsFormsApplication1
{
	static class Program
	{
		[STAThread]
		static void Main()
		{
			string[] lines = System.IO.File.ReadAllLines(@"C:\Pub\B-small-attempt0.in");
			int caseN = 1;
			var sb = new StringBuilder();

			for (int i = 1; i < lines.Length; )
			{
				var num = lines[i++].Split();
				int N = int.Parse(num[0]);
				int K = int.Parse(num[1]);
				int B = int.Parse(num[2]);
				int T = int.Parse(num[3]);
				int[] dist = lines[i++].Split().Convert(x => int.Parse(x));
				int[] speeds = lines[i++].Split().Convert(x => int.Parse(x));

				//assume let them run free and wild, with infinite throws
				int[] naturalTime = new int[dist.Length];
				for (int j = 0; j < naturalTime.Length; j++)
				{
					int distLeft = B - dist[j];
					int time = distLeft / speeds[j];
					if (time * speeds[j] != distLeft) time++;

					naturalTime[j] = time;
				}

				int cnt = -1;
				//check for is possible
				int possibleMax = naturalTime.Count(x => x <= T);

				if (possibleMax >= K)
				{
					cnt = 0;

					int currentEnd = 0;
					int jumpers = 0;
					for (int j = naturalTime.Length - 1; j >= 0; j--)
					{
						int tt = naturalTime[j];
						if (tt > T)
						{
							jumpers++;
						}
						else
						{
							cnt += jumpers;
							currentEnd++;
							if (currentEnd >= K) break;
						}
					}

				}

				if (cnt < 0)
					sb.AppendFormat("Case #{0}: {1}\r\n", caseN, "IMPOSSIBLE");
				else
					sb.AppendFormat("Case #{0}: {1}\r\n", caseN, cnt);
				caseN++;
			}

			string haha = sb.ToString();
			File.WriteAllText(@"C:\Pub\small.txt", sb.ToString());
		}



	}
}
