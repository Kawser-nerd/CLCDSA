using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CompetitiveProgCsLib
{
	class MainProg
	{
		static string R => Console.ReadLine();
		static int RI => int.Parse(R);
		static double RD => double.Parse(R);
		static int[] RIs => R.Split(' ').Select(int.Parse).ToArray();
		static double[] RDs => R.Split(' ').Select(double.Parse).ToArray();
		static void Out(object obj) => Console.WriteLine(obj);
		static void Outb(bool b) => Out(b ? "Yes" : "No");
		static void OutB(bool b) => Out(b ? "YES" : "NO");

		static void Main(string[] args)
		{
			var N = RI;
			var A = RIs;
			var Ap = new List<int>();
			Ap.Add(0);
			Ap.AddRange(A);
			Ap.Add(0);
			var li = new List<int>();
			SegmentTree<int> seg = new SegmentTree<int>(Ap.Count, (x, y) => x + y);
			for (int i = 1; i < Ap.Count; i++)
			{
				seg.Update(i - 1, Math.Abs(Ap[i] - Ap[i - 1]));
			}
			for (int i = 0; i < N; i++)
			{
				var a = seg[i];
				var b = seg[i + 1];
				seg.Update(i, 0);
				seg.Update(i + 1, Math.Abs(Ap[i + 2] - Ap[i]));
				Out(seg.Evaluate(0, seg.Length));
				seg.Update(i, a);
				seg.Update(i + 1, b);
			}
		}
	}

	public class SegmentTree<T>
	{
		#region member
		/// <summary>
		/// ???????
		/// </summary>
		private Func<T, T, T> associativeOperation;
		/// <summary>
		/// ???????????
		/// </summary>
		private T[] tree;
		/// <summary>
		/// ???
		/// </summary>
		private T identityElement;
		/// <summary>
		/// tree[origin]???????????
		/// </summary>
		private int origin;
		#endregion

		#region property
		/// <summary>
		/// ?????
		/// </summary>
		public int Length
		{
			get;
			private set;
		}
		/// <summary>
		/// ????????
		/// </summary>
		/// <param name="index"></param>
		/// <returns></returns>
		public T this[int index]
		{
			get
			{
				return tree[origin + index];
			}
			private set
			{
				tree[origin + index] = value;
			}
		}
		#endregion

		#region private method
		private T evaluate(int a, int b, int k, int l, int r)
		{
			if (r <= a || b <= l) return identityElement;
			if (a <= l && r <= b) return tree[k];
			else
			{
				T val_l = this.evaluate(a, b, k * 2 + 1, l, (l + r) / 2);
				T val_r = this.evaluate(a, b, k * 2 + 2, (l + r) / 2, r);
				return associativeOperation.Invoke(val_l, val_r);
			}
		}
		#endregion

		#region constructor
		public SegmentTree(int n, Func<T, T, T> operation, T identity = default(T)) : this((new T[n]).Select(x => x = identity).ToArray(), operation, identity)
		{
		}

		public SegmentTree(T[] array, Func<T, T, T> operation, T identity = default(T))
		{
			Length = array.Length;
			associativeOperation = operation;
			int size = 1 << (int)Math.Ceiling(Math.Log(Length, 2));
			identityElement = identity;
			tree = (new T[size * 2 - 1]).Select(x => x = identityElement).ToArray();
			origin = tree.Length - size;
			for (int i = 0; i < array.Length; i++)
			{
				this[i] = array[i];
			}
			for (int i = origin - 1; i >= 0; i--)
			{
				tree[i] = associativeOperation.Invoke(tree[i * 2 + 1], tree[i * 2 + 2]);
			}
		}
		#endregion

		#region public method
		/// <summary>
		/// index??????value?????
		/// </summary>
		/// <param name="index"></param>
		/// <param name="value"></param>
		public void Update(int index, T value)
		{
			this[index] = value;
			int position = origin + index;
			while (position > 0)
			{
				position = (position - 1) / 2;
				tree[position] = associativeOperation.Invoke(tree[position * 2 + 1], tree[position * 2 + 2]);
			}
		}

		/// <summary>
		/// a &lt;= x &lt; b ????????????
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns></returns>
		public T Evaluate(int a, int b)
		{
			var ret = evaluate(a, b, 0, 0, (tree.Length + 1) / 2);
			return ret;
		}
		#endregion
	}
}