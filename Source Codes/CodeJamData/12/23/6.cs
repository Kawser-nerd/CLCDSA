using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Google.CodeJam2012
{
#if _ONLINE_JUDGE_
	[OnlineJudge.Task("CodeJam12 03C")]
#endif
	class Task03C
	{
		private InputTokenizer input = new InputTokenizer();
		private TextWriter output = Console.Out;

		private void Solve()
		{
			int T;
			input.Line().Read(out T);

			for (int _T = 0; _T < T; ++_T) {
				int N;
				int[] S;
				input.Line().Read(out N).Read(N, out S);

				output.WriteLine("Case #{0}:", _T + 1);

				int sum = S.Aggregate(0, (a, b) => a + b);

				bool found = false;

				int[] tmp = new int[sum + 1];
				for (int i = 1, L = 1 << N; i < L; ++i) {
					int s = 0;
					for (int j = 0, k = 1; j < N; ++j, k <<= 1)
						if ((i & k) != 0)
							s += S[j];

					if (tmp[s] == 0)
						tmp[s] = i;
					else {
						List<int> A = new List<int>(), B = new List<int>();
						for (int j = 0, k = 1; j < N; ++j, k <<= 1)
							if ((i & k) != 0)
								A.Add(S[j]);

						for (int j = 0, k = 1; j < N; ++j, k <<= 1)
							if ((tmp[s] & k) != 0)
								B.Add(S[j]);

						output.Write(A[0]);
						for (int j = 1; j < A.Count; ++j) output.Write(" {0}", A[j]);
						output.WriteLine();

						output.Write(B[0]);
						for (int j = 1; j < B.Count; ++j) output.Write(" {0}", B[j]);
						output.WriteLine();

						found = true;
						break;
					}
				}

				if (!found) output.WriteLine("Impossible");
			}
		}

		public static void Main()
		{
			var obj = new Task03C();
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
