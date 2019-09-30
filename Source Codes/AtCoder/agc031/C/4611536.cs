using System.Collections.Generic;
using System.Linq;
using static System.Console;
class K
{
	static void Main()
	{
		var I = ReadLine().Split().Select(int.Parse).ToArray();
		int N = I[0], A = I[1], B = I[2];
		if (BitCount(A ^ B) % 2 < 1) { WriteLine("NO"); return; }
		WriteLine("YES");
		WriteLine(string.Join(" ", Generate(N, A, B)));
	}
	static IEnumerable<int> Generate(int N, int A, int B)
	{
		if (N == 1) return new[] { A, B };
		var p = new int[N];
		int c = BitCount(B ^= A), o = N - 1, z = 0;
		for (var i = 0; i < N; i++) p[i] = (B & (1u << i)) != 0 ? o-- : z++;
		B = ((1 << c) - 1) << (N - c);
		var l = new List<int>();
		var M = 1 << (N - 1);
		for (var i = 0; i < M; i++) l.Add(i ^ (i >> 1));
		foreach (var i in Generate(N - 1, 1 << (N - 2), B ^ M)) l.Add(i ^ M);
		return l.Select(x =>
		{
			var s = A;
			for (var j = 0; j < N; j++) s ^= ((x >> p[j]) & 1) << j;
			return s;
		});
	}
	static int BitCount(int n)
	{
		n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
		n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
		n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
		n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
		return (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
	}
}