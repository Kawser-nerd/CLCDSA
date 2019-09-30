using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Competition
{
	public class SpaceEmergency2
	{
		public void tester()
		{
			var sb = new StringBuilder();
			//string loc = @"C:\Pub\input.txt";
			string loc = @"C:\Pub\B-large.in";
			string[] lines = System.IO.File.ReadAllLines(loc);
			int caseNo = 1;
			for (int i = 1; i < lines.Length; )
			{
				var spl = lines[i++].Split().Select(x => long.Parse(x)).ToArray();
				long L = spl[0];
				long t = spl[1];
				long N = spl[2];
				long C = spl[3];

				List<long> dist = new List<long>(spl.Skip(4));
				List<long> times = new List<long>();

				long time = 0;
				t = t / 2;
				for (int j = 0; j < N; j++)
				{
					long cur = dist[j % dist.Count];
					if (t > 0)
					{
						var maxMinus = Math.Min(cur, t);
						long addOne = cur - maxMinus;
						if (addOne > 0) times.Add(addOne);
						time += (maxMinus * 2);
						t -= maxMinus;
					}
					else
						times.Add(cur);
				}
				
				times.Sort();
				times.Reverse();
				int ltest = 0;
				foreach (var item in times)
				{
					if (ltest < L)
					{
						time += item;
						ltest++;
					}
					else
					{
						time += item;
						time += item;
					}
				}

				sb.AppendFormat("Case #{0}: ", caseNo++);
				sb.Append(time.ToString());
				sb.AppendLine();
			}
			string outloc = @"C:\Pub\test.txt";
			System.IO.File.WriteAllText(outloc, sb.ToString());
		}
	}
}
