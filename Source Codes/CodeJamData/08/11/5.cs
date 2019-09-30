using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;

namespace GCJ2008
{
	class Program
	{
		static void Main(string[] args)
		{
			string[] lines = File.ReadAllLines("A-large.in");
			int lineAt = 0;
			string output = "";

			int cases = int.Parse(lines[lineAt++]);
			for (int i = 0; i < cases; i++)
			{
				int size = int.Parse(lines[lineAt++]);
				long[] v1 = new long[size];
				long[] v2 = new long[size];
				
				string[] s1 = lines[lineAt++].Split(' ');
				for (int j = 0; j < size; j++)
				{
					v1[j] = long.Parse(s1[j]);
				}
				Array.Sort(v1);
				
				s1 = lines[lineAt++].Split(' ');
				for (int j = 0; j < size; j++)
				{
					v2[j] = long.Parse(s1[j]);
				}
				Array.Sort(v2);
				Array.Reverse(v2);

				long sum = 0;
				for (int k = 0; k < size; k++)
				{
					sum += v1[k] * v2[k];
				}

				output += "Case #" + (i + 1) + ": " + sum;
				output += Environment.NewLine;
			}
			File.WriteAllText("output.txt", output);
		}
	}
}
