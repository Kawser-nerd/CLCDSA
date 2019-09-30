//#pragma warning disable
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System;
using System.Numerics;
using System.Threading.Tasks;
using static System.Math;
using static System.Console;
class Z { static void Main() => new K(); }
class K
{
	int F() => int.Parse(ReadLine());
	long FL() => long.Parse(ReadLine());
	int[] G() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
	long[] GL() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(long.Parse).ToArray();
	public const int MOD = 1000000007;
	public K()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	void Solve()
	{
		var com = Console.ReadLine();
		var c = com.ToArray();
		var N = c.Length;
		var I = G();
		var dx = new List<int>();
		var dy = new List<int>();
		Action<int,int> f = (d, l) => {
			if (d % 2 == 0) dx.Add(l);
			else dy.Add(l);
		};
		var dir = 0;
		var i = 0;
		while (i < N && c[i] == 'F') i++;
		I[0] -= i;
		while (i < N)
		{
			var l = 0;
			while (i < N && c[i] == 'F') { i++; l++; }
			if (l > 0) f(dir, l);
			while (i < N && c[i] == 'T') { i++; dir++; }
		}
		Console.WriteLine(Calc(dx, I[0]) && Calc(dy, I[1]) ? "Yes" : "No");
	}
	bool Calc(List<int> dx, int sum)
	{
		var s = new HashSet<int>{ 0 };
		foreach (var d in dx)
		{
			var t = new HashSet<int>();
			foreach (var x in s)
			{
				t.Add(x + d);
				t.Add(x - d);
			}
			s = t;
		}
		return s.Contains(sum);
	}
}