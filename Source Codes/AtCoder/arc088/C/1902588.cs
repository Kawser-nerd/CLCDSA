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
		Console.WriteLine(Solve());
		Out.Flush();
	}
	long Solve()
	{
		var S = Console.ReadLine();
		var s = S.Select(c => c - 'a').ToArray();
		var N = S.Length;
		var cnt = new int[26];
		foreach (var c in s) cnt[c]++;
		var odd = 0;
		foreach (var c in cnt) if (c % 2 == 1) odd++;
		if (odd > 1) return -1;
		var center = -1;
		if (odd > 0) for (var c = 0; c < 26; c++) if (cnt[c] % 2 == 1) cnt[center = c]--;
		for (var c = 0; c < 26; c++) cnt[c] /= 2;
		var half = N / 2;
		var left = new List<int>();
		foreach (var c in s) if (cnt[c] > 0) { cnt[c]--; left.Add(c); }
		var t = new int[N];
		for (var i = 0; i < left.Count; i++) t[N - 1 - i] = t[i] = left[i];
		if (center >= 0) t[N / 2] = center;
		var ind = new int[26];
		var p = new int[N];
		for (var i = 0; i < N; i++)
		{
			var c = s[i];
			while (t[ind[c]] != c) ind[c]++;
			p[i] = ind[c]++;
		}
		//return Distance(s, t);
		return Inversion(p);
	}
	long Distance(int[] s, int[] t)
	{
		var N = s.Length;
		var ans = 0L;
		for (var c = 0; c < 26; c++)
		{
			int a = 0, b = 0;
			while (true)
			{
				while (a < N && s[a] != c) a++;
				if (a >= N) break;
				while (b < N && t[b] != c) b++;
				ans += Abs(a++ - b++);
			}
		}
		return ans / 2;
	}
	long Inversion(int[] s)
	{
		var ans = 0L;
		var bit = new BITSet(s.Length);
		for (var j = 0; j < s.Length; j++)
		{
			ans += j - bit.GetRank(s[j]);
			bit.Add(s[j]);
		}
		return ans;
	}
}
class BinaryIndexedTree
{
	public readonly int Size;
	readonly int[] bit;
	public BinaryIndexedTree(int size) { Size = size; bit = new int[size + 1]; }
	public void Add(int index, int value) { for (var i = index + 1; i <= Size; i += i & (-i)) bit[i] += value; }
	public int Sum(int from, int to) => Sum(to) - Sum(from);
	int Sum(int to) { var sum = 0; for (var i = to; i > 0; i -= i & (-i)) sum += bit[i]; return sum; }
}
class BITSet : BinaryIndexedTree
{
	public BITSet(int size) : base(size) { }
	public void Add(int item) => Add(item, 1);
	public bool Contains(int item) => Sum(item, item + 1) > 0;
	public int Count(int item) => Sum(item, item + 1);
	// ?? = item ???????????(0-indexed)
	public int GetRank(int item) => Sum(0, item);
	public void Remove(int item) => Add(item, -1);
	public void RemoveAll(int item) => Add(item, -Count(item));
	/*// 0-indexed ???? rank ???????
	// ????? Size ???
	public int GetValue(int rank) => Func.FirstBinary(0, Size, t => Sum(0, t + 1) >= rank + 1);*/
}