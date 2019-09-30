#pragma warning disable
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System;
class E { static void Main() { new J(); } }
class J
{
	int F() { return int.Parse(Console.ReadLine()); }
	int[] G() { return Console.ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray(); }
	List<int>[] es;
	int[] d;
	public J()
	{
		Console.SetOut(new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });
		var N = F();
		es = new List<int>[N];
		for (var i = 0; i < N; i++) es[i] = new List<int>();
		for (var i = 1; i < N; i++) es[F() - 1].Add(i);
		d = new int[N];
		for (var i = 0; i < N; i++) d[i] = -1;
		Console.WriteLine(Calc(0));
		Console.Out.Flush();
	}
	int Calc(int u)
	{
		if (d[u] < 0)
		{
			d[u] = 0;
			var z = new int[es[u].Count];
			for (var i = 0; i < z.Length; i++) z[i] = -Calc(es[u][i]);
			Array.Sort(z);
			for (var i = 0; i < z.Length; i++) d[u] = Math.Max(d[u], -z[i] + i + 1);
		}
		return d[u];
	}
}