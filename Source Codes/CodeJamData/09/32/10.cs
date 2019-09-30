using System;
using System.Collections.Generic;
using System.IO;

class Program
{
	const string input = @"D:\Visual Studio 2008 Projects\Center of Mass\B-large.in";
	const string output = @"D:\Visual Studio 2008 Projects\Center of Mass\B-large.out";

	static void Main()
	{
		FileStream rf = new FileStream(input, FileMode.Open, FileAccess.Read);
		StreamReader r = new StreamReader(rf);
		FileStream wf = new FileStream(output, FileMode.Create, FileAccess.Write);
		StreamWriter w = new StreamWriter(wf);

		var T = int.Parse(r.ReadLine());
		for (var i = 0; i++ < T; )
		{
			var ret = Process(r);
			w.Write("Case #{0}: {1} {2}", i,
				ret[0].ToString("0.00000000"), ret[1].ToString("0.00000000"));
			if (i != T) w.WriteLine();
		}

		r.Close();
		w.Close();
	}

	static double[] Process(StreamReader r)
	{
		var N = int.Parse(r.ReadLine());
		double[] cnt = new double[6];
		for (var i = 0; i < 6; i++) cnt[i] = 0;
		for (var i = 0; i < N; i++)
		{
			var dat = ReadIntegers(r.ReadLine());
			for (var j = 0; j < 6; j++)
				cnt[j] += dat[j];
		}
		for (var i = 0; i < 6; i++) cnt[i] /= N;

		double t = 0, s = 0;
		for (var i = 0; i < 3; i++)
		{
			t -= cnt[i] * cnt[i + 3];
			s += Math.Pow(cnt[i + 3], 2);
		}
		if (s != 0) t = Math.Max(t / s, 0);
		else t = 0;

		s = 0;
		for (var i = 0; i < 3; i++)
			s += Math.Pow(cnt[i] + t * cnt[i + 3], 2);
		s = Math.Sqrt(s);

		return new[] { s, t };
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
