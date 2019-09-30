using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Competition.Google.CodeJam2009.Qualification
{
	public class AlienLanguage : CodeJamProblem
	{
		protected override string Solve(string input)
		{
			if (input.Contains("()")) throw new Exception(); //does not handle empty case

			CodeJamIO io = new CodeJamIO(input);
			var val = io.GetSpaceSplit(0);
			int L = int.Parse(val[0]);
			int D = int.Parse(val[1]);
			int N = int.Parse(val[2]);

			int i = 1;
			List<string> look = new List<string>();
			for(var j=0;j<D;j++,i++)
			{
				var word = io[i];
				if (word.Length != L) throw new Exception();
				look.Add(word);
			}

			for (int j = 0; j < N; j++, i++)
			{ 
				var str = io[i];
				var matches = System.Text.RegularExpressions.Regex.Matches(str, @"\([a-z]+\)|[a-z]");
				if (matches.Count != L) throw new Exception();
				var v = from m in matches.Cast<System.Text.RegularExpressions.Match>()
								 select m.Value.Replace("(", "").Replace(")", "");
				var chars = v.ToArray();

				int cnt = 0;
				//Solve it here
				foreach (var s in look)
				{
					bool good = true;
					for(int k=0;k<s.Length;k++)
					{
						char cur = s[k];
						if (!chars[k].Contains(cur))
						{
							good = false;
							break;
						}
					}

					if (good) cnt++;
				}

				io.WriteCase(cnt.ToString());
			}

			return io.GetResults();
		}

		private class Node
		{
			public Dictionary<char, Node> Children = new Dictionary<char, Node>();
		}
	}
}
