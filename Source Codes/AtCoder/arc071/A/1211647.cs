using System.Collections.Generic;
using System.IO;
using System.Linq;
using System;
using static System.Math;
using static System.Console;

class E { static void Main() => new J(); }
class J
{
	int F() => int.Parse(ReadLine());
	int[] G() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
	public J()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	void Solve()
	{
		var n = F();
		var mc = new int[26];
		for (var i = 0; i < 26; i++) mc[i] = 100;
		for (var i = 0; i < n; i++)
		{
			var c = new int[26];
			var s = ReadLine();
			foreach (var ch in s) c[ch - 'a']++;
			for (var j = 0; j < 26; j++) mc[j] = Min(mc[j], c[j]);
		}
		for (var i = 0; i < 26; i++) for (var j = 0; j < mc[i]; j++) Write((char)('a' + i));
		WriteLine();
	}
}