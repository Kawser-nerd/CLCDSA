using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Google.CodeJam2012
{
#if _ONLINE_JUDGE_
	[OnlineJudge.Task("CodeJam12 06A")]
#endif
	class Task06A
	{
		private InputTokenizer input = new InputTokenizer();
		private TextWriter output = Console.Out;

		struct T { public int p, idx; };

		private void Solve()
		{
			int T;
			input.Line().Read(out T);

			for (int _T = 0; _T < T; ++_T) {
				int N;
				int[] L, P;
				input.Line().Read(out N)
						 .Line().Read(N, out L)
						 .Line().Read(N, out P);

				T[] t = new T[N];
				for (int i = 0; i < N; ++i) {
					t[i].p = P[i];
					t[i].idx = i;
				}

				Array.Sort(t, (x, y) => {
					if (x.p != y.p) return y.p - x.p;
					return x.idx - y.idx;
				});

				output.Write("Case #{0}:", _T + 1);
				for (int i = 0; i < N; ++i) output.Write(" {0}", t[i].idx);
				output.WriteLine();
			}
		}

		public static void Main()
		{
			var obj = new Task06A();
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
