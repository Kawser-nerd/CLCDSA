using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace codejam
{
	class Program
	{
		static void Main(string[] args)
		{
			string[] lines = File.ReadAllLines("A-small-attempt0.in");
			int cases = int.Parse(lines[0]);
			int lineAt = 1;
			string output = "";
			for (int c = 0; c < cases; c++)
			{
				string[] input = lines[lineAt++].Split(' ');

				int n = int.Parse(input[0]);
				int pd = int.Parse(input[1]);
				int pg = int.Parse(input[2]);

				bool ok = false;
				for (int d = 1; d <= n; d++)
				{
					// can this work?
					int w = d * pd / 100;
					int l = d * (100 - pd) / 100;
					if (w + l == d)
					{
						if (pg == 0 && w > 0 || pg == 100 && l > 0)
						{
							continue;
						}
						ok = true;
					}
				}
				string ans = ok ? "Possible" : "Broken";
				output += "Case #" + (c + 1) + ": " + ans + Environment.NewLine;
				
			}
			Console.WriteLine(output);
			File.WriteAllText("out.txt", output);
		}
		
	}
}
