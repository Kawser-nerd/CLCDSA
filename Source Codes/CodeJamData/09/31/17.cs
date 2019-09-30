using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using Library;
using Library.Extensions;

namespace Competition
{
	class Class1
	{
		public void Arg()
		{
			var file = System.IO.File.ReadAllLines(@"C:\Users\root\Documents\Downloads\A-large.in");

//            var file2 = @"3
//11001001
//cats
//zig";
//            var file = file2.Replace("\r", "").Split('\n');

			int line = 0;
			int cases = int.Parse(file[line++]);

			var sb = new System.Text.StringBuilder();
			for (int c = 1; c <= cases; c++)
			{
				var ln = file[line++];
				var ch = ln.ToCharArray();
				var distCh = ch.Distinct().ToArray();

				int realNum = distCh.Length;
				int baseNum = Math.Max(distCh.Length, 2);

				Dictionary<char, int> lookup = new Dictionary<char, int>();
				lookup.Add(ch[0], 1);

				if (realNum == 1)
				{
				}
				else
				{
					int num = 0;
					for (int i = 1; i < ch.Length; i++)
					{
						char cc = ch[i];
						if (!lookup.ContainsKey(cc))
						{
							lookup.Add(cc, num);
							num++;
						}
						if (num == 1) num = 2;
					}
				}

				long rtn = 0;
				for (int i = 0; i < ch.Length; i++)
				{
					long val = lookup[ch[i]];
					long newBase = baseNum;
					rtn *= newBase;
					rtn += val;
				}

				sb.AppendFormat("Case #{0}: {1}", c, rtn.ToString());
				sb.AppendLine();
			}

			System.IO.File.WriteAllText(@"C:\Pub\a2.txt", sb.ToString());
		}
	}
}