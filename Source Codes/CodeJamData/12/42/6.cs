using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Google.CodeJam2012
{
#if _ONLINE_JUDGE_
	[OnlineJudge.Task("CodeJam12 05B")]
#endif
	class Task05B
	{
		private InputTokenizer input = new InputTokenizer();
		private TextWriter output = Console.Out;

		struct A : IComparable<A>
		{
			public int rad, index;

			public int CompareTo(A other)
			{
				return rad.CompareTo(other.rad);
			}
		};

		struct T {
			public double x, y;
			
			public override string ToString()
			{
				return "{" + x + ", " + y + "}";
			}
		};

		private void Solve()
		{
			int T;
			input.Line().Read(out T);

			for (int _T = 0; _T < T; ++_T) {
				int N;
				double W, L;
				int[] r;
				input.Line().Read(out N).Read(out W).Read(out L)
						 .Line().Read(N, out r);

				A[] a = new A[N];
				for (int i = 0; i < N; ++i) {
					a[i] = new A { index = i, rad = r[i] };
				}

				Array.Sort(a);

				T[] points = new T[N];

				double y = 0, x = -a[0].rad;
				for (int i = 0; i < N; ++i) {
					x += a[i].rad;
					if (x > W) {
						y += a[i - 1].rad;

						int t = 0, j = i;
						while (t <= W && j < N) t += a[j++].rad * 2;
						y += a[j - 1].rad;

						x = 0;
					}
					points[a[i].index] = new T { x = x, y = y };
					x += a[i].rad + 0.05;
				}

				output.Write("Case #{0}:", _T + 1);
				foreach (var pt in points) output.Write(" {0:0.00} {1:0.00}", pt.x, pt.y);
				output.WriteLine();

				bool valid = true;
				for (int i = 0; i < N; ++i) {
					if (points[i].x < 0 || points[i].x > W || points[i].y < 0 || points[i].y > L)
						valid = false;
					for (int j = i + 1; j < N; ++j)
						if ((r[i] + r[j]) * (r[i] + r[j]) > (points[i].x - points[j].x) * (points[i].x - points[j].x) + (points[i].y - points[j].y) * (points[i].y - points[j].y))
							valid = false;
				}

				if (!valid) throw new Exception("Invalid solution.");
			}
		}

		public static void Main()
		{
			var obj = new Task05B();
			obj.Solve();
		}

		#region
		private class InputTokenizer
		{
			private List<string> _tokens = new List<string>();
			private int _offset = 0;

			public InputTokenizer()
			{
			}

			public InputTokenizer String(String s)
			{
				_tokens.AddRange(s.Split(new char[] { ' ', '\n', '\t', '\r' }, StringSplitOptions.RemoveEmptyEntries));
				return this;
			}

			public InputTokenizer Line()
			{
				return String(Console.In.ReadLine());
			}

			public InputTokenizer Read(out int v)
			{
				v = int.Parse(_tokens[_offset++]);
				return this;
			}

			public InputTokenizer Read(int n, out int[] v)
			{
				v = new int[n];
				for (int i = 0; i < n; ++i) Read(out v[i]);
				return this;
			}

			public InputTokenizer Read(out long v)
			{
				v = long.Parse(_tokens[_offset++]);
				return this;
			}

			public InputTokenizer Read(int n, out long[] v)
			{
				v = new long[n];
				for (int i = 0; i < n; ++i) Read(out v[i]);
				return this;
			}

			public InputTokenizer Read(out ulong v)
			{
				v = ulong.Parse(_tokens[_offset++]);
				return this;
			}

			public InputTokenizer Read(int n, out ulong[] v)
			{
				v = new ulong[n];
				for (int i = 0; i < n; ++i) Read(out v[i]);
				return this;
			}

			public InputTokenizer Read(out double v)
			{
				v = double.Parse(_tokens[_offset++].Replace('.', '.'));
				return this;
			}

			public InputTokenizer Read(int n, out double[] v)
			{
				v = new double[n];
				for (int i = 0; i < n; ++i) Read(out v[i]);
				return this;
			}

			public InputTokenizer Read(out string v)
			{
				v = _tokens[_offset++];
				return this;
			}

			public InputTokenizer Read(int n, out string[] v)
			{
				v = new string[n];
				for (int i = 0; i < n; ++i) Read(out v[i]);
				return this;
			}
		}
		#endregion
	}
}
