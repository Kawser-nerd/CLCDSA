using System;
using System.Linq;
using System.Collections.Generic;
using System.Diagnostics;
using Debug = System.Diagnostics.Trace;
using SB = System.Text.StringBuilder;
using System.Numerics;
using static System.Math;
using static System.Console;
using Number = System.Int64;
namespace Program {
	public class Solver {
		Random rnd = new Random();
		public void Solve() {
			var s = rs;
			var pre = stringEx.ZAlgorithm(s);
			var suf = stringEx.ZAlgorithm(s.Reverse().AsString()).Reverse().ToArray();
			var ans = 0L;
			for (int i = 0; i < s.Length; i++) {
				var L = s.Length - i;
				//[i,n)
				var a = Min(L - 1, pre[i]);
				//[0,i)
				var c = Min(L - 1, suf[i]);
				if (L * 2 >= s.Length) continue;
				//Console.WriteLine($"{i} {a} {c} {L}");
				ans += Max(0, a - (L - c) + 1);
			}
			Console.WriteLine(ans);
		}



		const long INF = 1L << 60;
		static int[] dx = { -1, 0, 1, 0 };
		static int[] dy = { 0, 1, 0, -1 };
		int ri { get { return sc.Integer(); } }
		long rl { get { return sc.Long(); } }
		double rd { get { return sc.Double(); } }
		string rs { get { return sc.Scan(); } }
		public IO.StreamScanner sc = new IO.StreamScanner(Console.OpenStandardInput());

		static T[] Enumerate<T>(int n, Func<int, T> f) {
			var a = new T[n];
			for (int i = 0; i < n; ++i) a[i] = f(i);
			return a;
		}
		static public void Swap<T>(ref T a, ref T b) { var tmp = a; a = b; b = tmp; }
	}
}

#region main
static class Ex {
	static public string AsString(this IEnumerable<char> ie) { return new string(ie.ToArray()); }
	static public string AsJoinedString<T>(this IEnumerable<T> ie, string st = " ") {
		return string.Join(st, ie);
	}
	static public void Main() {
		Console.SetOut(new Program.IO.Printer(Console.OpenStandardOutput()) { AutoFlush = false });
		var solver = new Program.Solver();
		solver.Solve();
		Console.Out.Flush();
	}
}
#endregion
#region Ex
namespace Program.IO {
	using System.IO;
	using System.Text;
	using System.Globalization;

	public class Printer : StreamWriter {
		public override IFormatProvider FormatProvider { get { return CultureInfo.InvariantCulture; } }
		public Printer(Stream stream) : base(stream, new UTF8Encoding(false, true)) { }
	}

	public class StreamScanner {
		public StreamScanner(Stream stream) { str = stream; }

		public readonly Stream str;
		private readonly byte[] buf = new byte[1024];
		private int len, ptr;
		public bool isEof = false;
		public bool IsEndOfStream { get { return isEof; } }

		private byte read() {
			if (isEof) return 0;
			if (ptr >= len) {
				ptr = 0;
				if ((len = str.Read(buf, 0, 1024)) <= 0) {
					isEof = true;
					return 0;
				}
			}
			return buf[ptr++];
		}

		public char Char() {
			byte b = 0;
			do b = read(); while ((b < 33 || 126 < b) && !isEof);
			return (char)b;
		}
		public string Scan() {
			var sb = new StringBuilder();
			for (var b = Char(); b >= 33 && b <= 126; b = (char)read()) sb.Append(b);
			return sb.ToString();
		}
		public string ScanLine() {
			var sb = new StringBuilder();
			for (var b = Char(); b != '\n' && b != 0; b = (char)read()) if (b != '\r') sb.Append(b);
			return sb.ToString();
		}
		public long Long() { return isEof ? long.MinValue : long.Parse(Scan()); }
		public int Integer() { return isEof ? int.MinValue : int.Parse(Scan()); }
		public double Double() { return isEof ? double.NaN : double.Parse(Scan(), CultureInfo.InvariantCulture); }
	}
}

#endregion

#region Disjoint Set
public class DisjointSet {
	int[] par;
	byte[] rank;
	public DisjointSet(int N) {
		par = new int[N];
		rank = new byte[N];
		for (int i = 0; i < N; i++)
			par[i] = -1;
	}
	public int this[int id] {
		get {
			if ((par[id] < 0)) return id;
			return par[id] = this[par[id]];
		}
	}
	public bool Unite(int x, int y) {
		x = this[x]; y = this[y];
		if (x == y) return false;
		if (rank[x] < rank[y]) { var tmp = x; x = y; y = tmp; }
		par[x] += par[y];
		par[y] = x;
		if (rank[x] == rank[y])
			rank[x]++;
		return true;
	}
	public int Size(int x) { return -par[this[x]]; }

	public bool Same(int x, int y) { return this[x] == this[y]; }

}
#endregion


#region Set
public class Set<T> {
	Node root;
	readonly IComparer<T> comparer;
	readonly Node nil;
	public bool IsMultiSet { get; set; }
	public Set(IComparer<T> comparer) {
		nil = new Node(default(T));
		root = nil;
		this.comparer = comparer;
	}
	public Set(Comparison<T> comaprison) : this(Comparer<T>.Create(comaprison)) { }
	public Set() : this(Comparer<T>.Default) { }
	public bool Add(T v) {
		return insert(ref root, v);
	}
	public bool Remove(T v) {
		return remove(ref root, v);
	}
	public T this[int index] { get { return find(root, index); } }
	public int Count { get { return root.Count; } }
	public void RemoveAt(int k) {
		if (k < 0 || k >= root.Count) throw new ArgumentOutOfRangeException();
		removeAt(ref root, k);
	}
	public T[] Items {
		get {
			var ret = new T[root.Count];
			var k = 0;
			walk(root, ret, ref k);
			return ret;
		}
	}
	void walk(Node t, T[] a, ref int k) {
		if (t.Count == 0) return;
		walk(t.lst, a, ref k);
		a[k++] = t.Key;
		walk(t.rst, a, ref k);
	}

	bool insert(ref Node t, T key) {
		if (t.Count == 0) { t = new Node(key); t.lst = t.rst = nil; t.Update(); return true; }
		var cmp = comparer.Compare(t.Key, key);
		bool res;
		if (cmp > 0)
			res = insert(ref t.lst, key);
		else if (cmp == 0) {
			if (IsMultiSet) res = insert(ref t.lst, key);
			else return false;
		}
		else res = insert(ref t.rst, key);
		balance(ref t);
		return res;
	}
	bool remove(ref Node t, T key) {
		if (t.Count == 0) return false;
		var cmp = comparer.Compare(key, t.Key);
		bool ret;
		if (cmp < 0) ret = remove(ref t.lst, key);
		else if (cmp > 0) ret = remove(ref t.rst, key);
		else {
			ret = true;
			var k = t.lst.Count;
			if (k == 0) { t = t.rst; return true; }
			if (t.rst.Count == 0) { t = t.lst; return true; }


			t.Key = find(t.lst, k - 1);
			removeAt(ref t.lst, k - 1);
		}
		balance(ref t);
		return ret;
	}
	void removeAt(ref Node t, int k) {
		var cnt = t.lst.Count;
		if (cnt < k) removeAt(ref t.rst, k - cnt - 1);
		else if (cnt > k) removeAt(ref t.lst, k);
		else {
			if (cnt == 0) { t = t.rst; return; }
			if (t.rst.Count == 0) { t = t.lst; return; }

			t.Key = find(t.lst, k - 1);
			removeAt(ref t.lst, k - 1);
		}
		balance(ref t);
	}
	void balance(ref Node t) {
		var balance = t.lst.Height - t.rst.Height;
		if (balance == -2) {
			if (t.rst.lst.Height - t.rst.rst.Height > 0) { rotR(ref t.rst); }
			rotL(ref t);
		}
		else if (balance == 2) {
			if (t.lst.lst.Height - t.lst.rst.Height < 0) rotL(ref t.lst);
			rotR(ref t);
		}
		else t.Update();
	}

	T find(Node t, int k) {
		if (k < 0 || k > root.Count) throw new ArgumentOutOfRangeException();
		for (; ; )
		{
			if (k == t.lst.Count) return t.Key;
			else if (k < t.lst.Count) t = t.lst;
			else { k -= t.lst.Count + 1; t = t.rst; }
		}
	}
	public int LowerBound(T v) {
		var k = 0;
		var t = root;
		for (; ; )
		{
			if (t.Count == 0) return k;
			if (comparer.Compare(v, t.Key) <= 0) t = t.lst;
			else { k += t.lst.Count + 1; t = t.rst; }
		}
	}
	public int UpperBound(T v) {
		var k = 0;
		var t = root;
		for (; ; )
		{
			if (t.Count == 0) return k;
			if (comparer.Compare(t.Key, v) <= 0) { k += t.lst.Count + 1; t = t.rst; }
			else t = t.lst;
		}
	}

	void rotR(ref Node t) {
		var l = t.lst;
		t.lst = l.rst;
		l.rst = t;
		t.Update();
		l.Update();
		t = l;
	}
	void rotL(ref Node t) {
		var r = t.rst;
		t.rst = r.lst;
		r.lst = t;
		t.Update();
		r.Update();
		t = r;
	}


	class Node {
		public Node(T key) {
			Key = key;
		}
		public int Count { get; private set; }
		public sbyte Height { get; private set; }
		public T Key { get; set; }
		public Node lst, rst;
		public void Update() {
			Count = 1 + lst.Count + rst.Count;
			Height = (sbyte)(1 + Math.Max(lst.Height, rst.Height));
		}
		public override string ToString() {
			return string.Format("Count = {0}, Key = {1}", Count, Key);
		}
	}
}
#endregion

#region Z algorithm
static public partial class stringEx {
	static public int[] ZAlgorithm(string s) {
		var a = new int[s.Length + 1];
		a[0] = s.Length;
		int i = 1, j = 0;
		while (i < s.Length) {
			while (i + j < s.Length && s[j] == s[i + j]) ++j;
			a[i] = j;
			if (j == 0) { ++i; continue; }
			int k = 1;
			while (i + k < s.Length && k + a[k] < j) { a[i + k] = a[k]; ++k; }
			i += k; j -= k;
		}
		return a;
	}
}
#endregion