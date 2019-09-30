using System.Collections.Generic;
using System.Linq;
using static System.Console;
class K
{
	static void Main()
	{
		var I = ReadLine().Split().Select(int.Parse).ToArray();
		int N = I[0], A = I[1], B = I[2];
		if (C(A ^ B) % 2 < 1) { WriteLine("NO"); return; }
		WriteLine("YES");
		WriteLine(string.Join(" ", G(N, A, B)));
	}
	static IEnumerable<int> G(int N, int A, int B)
	{
		if (N == 1) return new[] { A, B };
		var p = new int[N];
		int c = C(B ^= A), o = N - 1, z = 0;
		for (var i = 0; i < N; i++) p[i] = (B & (1 << i)) > 0 ? o-- : z++;
		B = ((1 << c) - 1) << (N - c);
		var l = new List<int>();
		var M = 1 << (N - 1);
		for (var i = 0; i < M; i++) l.Add(i ^ (i >> 1));
		foreach (var i in G(N - 1, 1 << (N - 2), B ^ M)) l.Add(i ^ M);
		return l.Select(x =>
		{
			var s = A;
			for (var j = 0; j < N; j++) s ^= ((x >> p[j]) & 1) << j;
			return s;
		});
	}
	static int C(int n)
	{
		n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
		n = (n & 858993459) + ((n >> 2) & 858993459);
		n = (n & 252645135) + ((n >> 4) & 252645135);
		n = (n & 16711935) + ((n >> 8) & 16711935);
		return (n & 65535) + ((n >> 16) & 65535);
	}
}