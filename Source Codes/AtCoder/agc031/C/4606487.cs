using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using static System.Math;
class Z { static void Main() => new K(); }
class K
{
	int F => int.Parse(Str);
	long FL => long.Parse(Str);
	int[] G => Strs.Select(int.Parse).ToArray();
	decimal[] GD => Strs.Select(decimal.Parse).ToArray();
	long[] GL => Strs.Select(long.Parse).ToArray();
	string Str => ReadLine();
	string[] Strs => Str.Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
	static T[] ConstantArray<T>(int n, T val) { var a = new T[n]; for (var i = 0; i < n; i++) a[i] = val; return a; }
	static T[] MakeArray<T>(int n, Func<int, T> f) { var a = new T[n]; for (var i = 0; i < n; i++) a[i] = f(i); return a; }
	const int MOD = 1000000007;
	public K()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	void Solve()
	{
		var I = G;
		int N = I[0];
		uint A = (uint)I[1], B = (uint)I[2];
		if (BitCount(A ^ B) % 2 == 0) { WriteLine("NO"); return; }
		WriteLine("YES");
		WriteLine(string.Join(" ", Generate(N, A, B)));
	}
	List<uint> Generate(int N, uint A, uint B)
	{
		if (N == 1) return new List<uint> { A, B };
		B ^= A;
		var cnt = BitCount(B);
		// B ? bit ??????
		int[] perm = new int[N], iperm = new int[N];
		int on = N - 1, off = 0;
		for (var i = 0; i < N; i++) { perm[i] = (B & (1u << i)) != 0 ? on-- : off++; iperm[perm[i]] = i; }
		B = ((1u << cnt) - 1) << (N - cnt);
		// ??
		var ans = new List<uint>();
		var lim = 1u << (N - 1);
		for (var i = 0u; i < lim; i++) ans.Add(i ^ (i >> 1));   // ??? gray code
		foreach (var i in Generate(N - 1, 1u << (N - 2), B ^ lim)) ans.Add(i ^ lim);    // ?????
																						// ?? (perm ? ??? B^=A)
		for (var i = 0; i < ans.Count; i++)
		{
			var s = 0u;
			for (var j = 0; j < N; j++) if ((ans[i] & (1u << j)) != 0) s |= 1u << iperm[j];
			ans[i] = s ^ A;
		}
		return ans;
	}
	public static int BitCount(uint n)
	{
		n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
		n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
		n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
		n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
		return (int)((n & 0x0000ffff) + ((n >> 16) & 0x0000ffff));
	}
}