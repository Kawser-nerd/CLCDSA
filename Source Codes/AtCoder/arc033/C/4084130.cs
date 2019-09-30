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
	long[] GL => Strs.Select(long.Parse).ToArray();
	string Str => ReadLine();
	string[] Strs => Str.Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
	const int MOD = 1000000007;
	public K()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	void Solve()
	{
		/*var hoge = new List<int>();
		for (var i = 0; i < 20; i++) hoge.Add(Treap<int>.rand.Next(100));
		var tr = new Treap<int>();
		foreach (var x in hoge) tr.Insert(x);
		WriteLine("hoge = " + string.Join(", ", hoge));
		WriteLine("tr   = " + string.Join(", ", tr));
		hoge.Sort();
		WriteLine("hoge = " + string.Join(", ", hoge));
		WriteLine(tr);
		var a = hoge[Treap<int>.rand.Next(20)];
		tr.Remove(a);
		WriteLine($"removed {a}");
		WriteLine(tr);*/
		var Q = F;
		var tr = new Treap<int>();
		while (Q-- > 0)
		{
			var I = G;
			if (I[0] == 1) tr.Insert(I[1]);
			else
			{
				var x = tr.At(I[1] - 1);
				WriteLine(x.Value);
				tr.Remove(x.Value);
			}
		}
	}
}
class Treap<T> : IEnumerable<T> where T : IComparable<T>
{
	public static Random rand = new Random(471289567);
	public class Node : IEnumerable<T>
	{
		public static int GetSize(Node n) => n?.Size ?? 0;
		public int Size { get; private set; }
		public T Value;
		public readonly double Priority;
		public Node[] Children = new Node[2];
		public Node(T v) { Priority = rand.NextDouble(); Value = v; Update(); }
		public Node(T v, double p, params Node[] ch) { Value = v; Priority = p; ch.CopyTo(Children, 0); Update(); }
		public Node Update() { Size = 1 + Children.Sum(GetSize); return this; }
		public IEnumerator<T> GetEnumerator()
		{
			if (Children[0] != null) foreach (var x in Children[0]) yield return x;
			yield return Value;
			if (Children[1] != null) foreach (var x in Children[1]) yield return x;
		}
		IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();
		string Label => $"{Value}({Priority:f2})";
		public override string ToString()
		{
			var sb = new StringBuilder();
			ToString(sb);
			return sb.ToString();
		}
		void ToString(StringBuilder sb)
		{
			sb.AppendLine(Label);
			for (var i = 0; i < 2; i++)
				if (Children[i] != null)
				{
					sb.AppendLine($"{Label} {Children[i].Label}");
					Children[i].ToString(sb);
				}
		}
	}
	Node root;
	public void Insert(T val) { root = Insert(root, new Node(val)); }
	public bool Remove(T val) { var x = Find(root, val); if (x != null) root = Remove(root, x); return x != null; }
	public Node At(int i)
	{
		var r = root;
		while (r != null)
		{
			var l = Node.GetSize(r.Children[0]);
			if (l == i) return r;
			if (l < i) { i -= l + 1; r = r.Children[1]; }
			else r = r.Children[0];
		}
		return null;
	}
	// r ? r[id] ?????????
	Node Rotate(Node r, int id)
	{
		var c = r.Children[id];
		r.Children[id] = c.Children[1 - id];
		c.Children[1 - id] = r;
		c.Update(); r.Update();
		return c;
	}
	Node Insert(Node r, Node v)
	{
		if (r == null) return v;
		var id = r.Value.CompareTo(v.Value) > 0 ? 0 : 1;
		r.Children[id] = Insert(r.Children[id], v).Update();
		if (r.Priority < r.Children[id].Priority) r = Rotate(r, id);
		return r.Update();
	}
	Node Find(Node r, T val)
	{
		if (r == null) return null;
		var c = r.Value.CompareTo(val);
		if (c == 0) return r;
		return Find(r.Children[c > 0 ? 0 : 1], val);
	}
	Node Remove(Node r, Node v)
	{
		if (r == null) return root;
		if (r == v)
		{
			if (v.Children.All(c => c == null)) return null;
			var id = v.Children[0] != null && (v.Children[1] == null || v.Children[0].Priority >= v.Children[1].Priority) ? 0 : 1;
			var s = Rotate(v, id);
			s.Children[1 - id] = Remove(v, v);
			return s.Update();
		}
		else
		{
			var id = r.Value.CompareTo(v.Value) > 0 ? 0 : 1;
			r.Children[id] = Remove(r.Children[id], v);
			return r.Update();
		}
	}
	Node Merge(Node l, Node r)
	{
		var p = new Node(default(T), 100, l, r);
		return Remove(p, p);
	}
	public IEnumerator<T> GetEnumerator() => root.GetEnumerator();
	IEnumerator IEnumerable.GetEnumerator() => root.GetEnumerator();
	public override string ToString() => root.ToString();
}