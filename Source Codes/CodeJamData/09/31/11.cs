using System;
using System.Collections.Generic;
using System.IO;

class Program
{
	const string input = @"D:\Visual Studio 2008 Projects\All Your Base\A-large.in";
	const string output = @"D:\Visual Studio 2008 Projects\All Your Base\A-large.out";

	static void Main()
	{
		FileStream rf = new FileStream(input, FileMode.Open, FileAccess.Read);
		StreamReader r = new StreamReader(rf);
		FileStream wf = new FileStream(output, FileMode.Create, FileAccess.Write);
		StreamWriter w = new StreamWriter(wf);

		var n = int.Parse(r.ReadLine());
		for (var i = 0; i++ < n; )
		{
			w.Write("Case #{0}: {1}", i, Process(r.ReadLine()));
			if (i != n) w.WriteLine();
		}

		r.Close();
		w.Close();
	}

	static long Process(string line)
	{
		Dictionary<char, long> dic = new Dictionary<char, long>();
		List<long> nums = new List<long>();
		long i = 0;

		foreach (var ch in line)
		{
			if (dic.ContainsKey(ch))
				nums.Add(dic[ch]);
			else
			{
				if (i == 0) dic.Add(ch, 1);
				else if (i == 1) dic.Add(ch, 0);
				else dic.Add(ch, i);
				nums.Add(dic[ch]);
				i++;
			}
		}
		if (i == 1) i = 2;

		long k = 1, ret = 0;
		for (var j = nums.Count; j-- > 0; )
			checked
			{
				ret += nums[j] * k;
				k *= i;
			}
		return ret;
	}
}