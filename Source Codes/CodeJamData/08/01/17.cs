using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

class Program
{
	static void Main(string[] args)
	{
		string infile = "A-large.in";
		string outfile = "A-large.out";
		int N, S, Q, res;
		string[] engines;
		bool[] hits;
		int nhits;
		TextReader tr = new StreamReader(infile);
		TextWriter tw = new StreamWriter(outfile);
		N = int.Parse(tr.ReadLine());
		for (int i = 0; i < N; ++i)
		{
			S = int.Parse(tr.ReadLine());
			engines = new string[S];
			hits = new bool[S];
			for (int j = 0; j < S; ++j)
				engines[j] = tr.ReadLine();
			Q = int.Parse(tr.ReadLine());
			res = 0;
			nhits = 0;
			for (int j = 0; j < Q; ++j)
			{
				string query = tr.ReadLine();
				int t;
				for (t = 0; t < S; ++t) if (engines[t] == query) break;
				if (hits[t] == false) { hits[t] = true; ++nhits; }
				if (nhits == S)
				{
					nhits = 1;
					for (int k = 0; k < S; ++k) hits[k] = false;
					hits[t] = true;
					++res;
				}
			}
			tw.WriteLine("Case #{0}: {1}", i+1, res);
		}
		tw.Close();
	}
}
