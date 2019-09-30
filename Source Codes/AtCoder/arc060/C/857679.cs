using System;
using System.IO;
using System.Linq;
class E { static void Main() { new K(); } }
class K
{
	int F() { return int.Parse(Console.ReadLine()); }
	int[] G() { return Console.ReadLine().Split().Select(_ => int.Parse(_)).ToArray(); }
	public K()
	{
		Console.SetOut(new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });
		var N = F();
		var x = G();
		int L = F(), Q = F();
		var r = new int[N];
		for (var i = 0; i < N; i++) r[i] = FirstBinary(i, N, k => x[k] > x[i] + L) - 1;
		var rn = new int[20][];
		rn[0] = r;
		for (var c = 1; c < 20; c++)
		{
			rn[c] = new int[N];
			for (var i = 0; i < N; i++) rn[c][i] = rn[c - 1][rn[c - 1][i]];
		}
		for (var q = 0; q < Q; q++)
		{
			var I = G();
			Array.Sort(I);
			Console.WriteLine(FirstBinary(1, N, d =>
			{
				var p = I[0] - 1;
				for (var c = 0; c < 20; c++) if ((d & (1 << c)) != 0) p = rn[c][p];
				return p >= I[1] - 1;
			}));
		}
		Console.Out.Flush();
	}
	int FirstBinary(int s, int t, Predicate<int> p)
	{
		while (s < t)
		{
			var m = (s + t) / 2;
			if (p(m)) t = m;
			else s = m + 1;
		}
		return s;
	}
}