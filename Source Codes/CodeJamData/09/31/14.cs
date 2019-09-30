using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ_2009
{
	class AllYourBase
	{
		public void SloveFile(string file)
		{
			using (StreamReader inf = new StreamReader(file, Encoding.ASCII)) 
			using (StreamWriter outf = new StreamWriter(file + ".out", false, Encoding.ASCII)) 
			{
				int cases = int.Parse(inf.ReadLine());
				for (int i = 1; i <= cases; i++) {
					string input = inf.ReadLine();
					long result = Slove(input);
					outf.WriteLine("Case #{0}: {1}", i, result);
					Console.WriteLine("Case #{0}: {1}", i, result);
				}
			}
		}
		public long Slove(string input)
		{
			Dictionary<char, int> bases = new Dictionary<char, int>();
			foreach (char c in input)  {
				if (!bases.ContainsKey(c))
					bases.Add(c, -1);
			}

			int b = bases.Count == 1 ? 2 : bases.Count;
			bases[input[0]] = 1;
			long ret = 1;
			int start = 0;
			Console.Write("Base:{0} :1", b);
			for (int i = 1; i < input.Length; i++) {
				char c = input[i];
				if (bases[c] == -1) {
					bases[c] = start;
					start = start == 0 ? 2 : start + 1;
				}
				ret = ret * b + bases[c];
				Console.Write(bases[c]);
			}
			Console.WriteLine();
			return ret;
		}
	}
}
