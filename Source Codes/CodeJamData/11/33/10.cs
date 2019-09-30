using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Competition
{
	public class PerfectHarmony2
	{
		public void tester()
		{
			var sb = new StringBuilder();
			//string loc = @"C:\Pub\input.txt";
			string loc = @"C:\Pub\C-small-attempt0.in";
			string[] lines = System.IO.File.ReadAllLines(loc);
			int caseNo = 1;
			for (int i = 1; i < lines.Length; )
			{
				var spl = lines[i++].Split().Select(x => long.Parse(x)).ToArray();
				long N = spl[0];
				long L = spl[1];
				long H = spl[2];
				spl = lines[i++].Split().Select(x => long.Parse(x)).ToArray();
				var freq = spl;

				long finalFreq = -1;

				for (long test = L; test <= H; test++)
				{
					if (Possible(test, freq))
					{
						finalFreq = test;
						break;
					}
				}

				sb.AppendFormat("Case #{0}: ", caseNo++);

				if (finalFreq > 0)
				{
					sb.Append(finalFreq.ToString());
				}
				else
				{
					sb.Append("NO");
				}
				sb.AppendLine();
			}
			string outloc = @"C:\Pub\test.txt";
			System.IO.File.WriteAllText(outloc, sb.ToString());
		}

		private bool Possible(long test, long[] freq)
		{
			foreach (var item in freq)
			{
				if (item > test)
				{
					if (item % test != 0) return false;
				}
				else if (item < test)
				{
					if (test % item != 0) return false;
				}
			}

			return true;
		}
	}
}
