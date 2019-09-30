using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class Program
{
	const string input = @"D:\Visual Studio 2008 Projects\Bribe the Prisoners\C-small-attempt0.in";
	const string output = @"D:\Visual Studio 2008 Projects\Bribe the Prisoners\C-small-attempt0.out";

	//const string input = @"D:\Visual Studio 2008 Projects\Bribe the Prisoners\C-large.in";
	//const string output = @"D:\Visual Studio 2008 Projects\Bribe the Prisoners\C-large.out";

	static void Main()
	{
		FileStream rf = new FileStream(input, FileMode.Open, FileAccess.Read);
		StreamReader r = new StreamReader(rf);
		FileStream wf = new FileStream(output, FileMode.Create, FileAccess.Write);
		StreamWriter w = new StreamWriter(wf);

		var N = int.Parse(r.ReadLine());
		for (var i = 0; i++ < N; )
		{
			w.Write("Case #{0}: {1}", i, SmallProcess(r));
			if (i != N) w.WriteLine();
		}

		r.Close();
		w.Close();
	}

	static int SmallProcess(StreamReader r)
	{
		var pq = ReadIntegers(r.ReadLine());
		var release = ReadIntegers(r.ReadLine());

		bool[] cells = new bool[pq[0]];
		for (var i = 0; i < cells.Length; i++)
			cells[i] = true;

		return SmallRecursive(cells, (from rr in release select rr - 1).ToList());
	}

	static int SmallRecursive(bool[] cells, List<int> release)
	{
		int min = int.MaxValue;
		foreach (var rel in release)
		{
			var copy = cells.Clone() as bool[];
			var coin = 0;
			copy[rel] = false;
			for (var i = rel; i-- > 0 && copy[i]; coin++) ;
			for (var i = rel; ++i < cells.Length && copy[i]; coin++) ;

			var newRel = (from r in release
						  where r != rel
						  select r).ToList();
			if (newRel.Count != 0)
				coin += SmallRecursive(copy, newRel);
			if (coin < min) min = coin;
		}
		return min;
	}

	static int[] ReadIntegers(string line)
	{
		var tokens = line.Split(' ');
		var ret = new int[tokens.Length];
		for (var i = 0; i < tokens.Length; i++)
			ret[i] = int.Parse(tokens[i]);
		return ret;
	}
}
