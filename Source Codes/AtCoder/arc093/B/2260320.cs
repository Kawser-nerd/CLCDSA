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
		var I = G();
		int A = I[0] - 1, B = I[1] - 1;
		var map = new bool[100, 100];
		for (var i = 0; i < 100; i++) for (var j = 50; j < 100; j++) map[i, j] = true;
		for (var j = 0; B > 0 && j <= 48; j += 2) for (var i = 1; B > 0 && i <= 99; i += 2) { map[i, j] = true; B--; }
		for (var j = 99; A > 0 && j >= 51; j -= 2) for (var i = 1; A > 0 && i <= 99; i += 2) { map[i, j] = false; A--; }
		WriteLine("100 100");
		for (var i = 0; i < 100; i++)
		{
			for (var j = 0; j < 100; j++) Write(map[i, j] ? '#' : '.');
			WriteLine();
		}
	}
}