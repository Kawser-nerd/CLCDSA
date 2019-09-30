using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace Competition.Google.CodeJam2009.Qualification
{
	public class WelcometoCodeJam : CodeJamProblem
	{
		protected override string Solve(string input)
		{
			CodeJamIO io = new CodeJamIO(input);
			for (int i = 1; i < io.Length; i++)
			{
				string str = io[i];
				int len = str.Length;
				memo = new Dictionary<Point, int>();
				int num = La(0, 0, str);
				io.WriteCase(num.ToString("0000"));
			}

			return io.GetResults();
		}

		private Dictionary<Point, int> memo;

		private int La(int strLoc, int inputLoc, string len)
		{
			const string welc = @"welcome to code jam";
			if (strLoc == welc.Length) return 1;
			if (inputLoc >= len.Length) return 0;
			
			Point p = new Point(strLoc, inputLoc);
			if (memo.ContainsKey(p)) return memo[p];

			char cur = welc[strLoc];
			char inp = len[inputLoc];

			int val;
			if (cur == inp)
			{
				//skip
				int skip = La(strLoc, inputLoc + 1, len);
				//match
				int match = La(strLoc + 1, inputLoc + 1, len);
				val = skip + match;
			}
			else
			{
				val = La(strLoc, inputLoc + 1, len);
			}

			val = val % 10000;
			memo[p] = val;
			return val;
		}
	}
}
