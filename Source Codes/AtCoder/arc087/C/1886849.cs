using System;
using System.Linq;
using static System.Console;
class Z { static void Main() => new K(); }
class K
{
	long g, L;
	public K()
	{
		var I = ReadLine().Split().Select(long.Parse).ToArray();
		var N = I[0];
		L = I[1];
		var root = new object[2];
		for (var i = 0; i < N; i++)
		{
			var s = ReadLine();
			var n = root;
			for (var j = 0; j < s.Length; j++)
			{
				var x = s[j] - '0';
				n = (object[])(n[x] = n[x] ?? new object[2]);
			}
		}
		DFS(root, 0);
		WriteLine(g != 0 ? "Alice" : "Bob");
	}
	int C(object o)
	{
		return o == null ? 0 : 1;
	}
	void DFS(object[] n, int d)
	{
		if (C(n[0]) + C(n[1]) == 1) g ^= F(L - d);
		foreach (var c in n) if (c != null) DFS((object[])c, d + 1);
	}
	long F(long n)
	{
		var c = 1L;
		while (n % 2 == 0) { c <<= 1; n >>= 1; }
		return c;
	}
}