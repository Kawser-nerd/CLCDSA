using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Competition
{
	public class AirportWalkways
	{
		public void tester()
		{
			var sb = new StringBuilder();
			//string loc = @"C:\Pub\input.txt";
			//string loc = @"C:\Pub\A-small-attempt0.in";
			string loc = @"C:\Pub\A-large.in";
			string[] lines = System.IO.File.ReadAllLines(loc);
			int caseNo = 1;
			for (int i = 1; i < lines.Length; )
			{
				var spl = lines[i++].Split().Select(x => decimal.Parse(x)).ToArray();
				decimal X = spl[0];
				decimal S = spl[1];
				decimal R = spl[2];
				decimal t = spl[3];
				decimal walkCnt = spl[4];
				List<decimal[]> walk = new List<decimal[]>();
				for (int w = 0; w < walkCnt; w++)
				{
					var temp = lines[i++].Split().Select(x => decimal.Parse(x)).ToArray();
					decimal[] blah = new decimal[2];
					blah[0] = temp[1] - temp[0];
					blah[1] = temp[2] + S;
					walk.Add(blah);
				}

				decimal endTotal = X;
				foreach (var w in walk)
				{
					endTotal = endTotal - w[0];
				}

				var walkOne = new decimal[2];
				walkOne[0] = endTotal;
				walkOne[1] = S;
				walk.Add(walkOne);

				//add in running times
				walk.Sort(delegate(decimal[] x, decimal[] y)
				{
					return x[1].CompareTo(y[1]);
				});

				for (int s = 0; s < walk.Count; s++)
				{
					if (t > 0)
					{
						var ww = walk[s];
						decimal time = (ww[0] / ww[1]);
						decimal time2 = (ww[0] / (ww[1]-S+R));

						decimal temp = Math.Min(t, time2);
						t = t - temp;

						//reduce length
						decimal Lred = temp * (R - S);
						ww[0] = ww[0] - Lred;
					}
				}

				//find totalTime
				decimal result = 0;
				foreach (var w in walk)
				{
					result += (w[0] / w[1]);
				}

				sb.AppendFormat("Case #{0}: {1}", caseNo++, result);
				sb.AppendLine();
			}
			string outloc = @"C:\Pub\test.txt";
			System.IO.File.WriteAllText(outloc, sb.ToString());
		}
	}
}
