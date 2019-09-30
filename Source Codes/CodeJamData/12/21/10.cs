using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Google.CodeJam2012
{
#if _ONLINE_JUDGE_
	[OnlineJudge.Task("CodeJam12 03A")]
#endif
	class Task03A
	{
		private InputTokenizer input = new InputTokenizer();
		private TextWriter output = Console.Out;

		private void Solve()
		{
			int T;
			input.Line().Read(out T);

			for (int _T = 0; _T < T; ++_T) {
				int N;
				int[] s;
				input.Line().Read(out N).Read(N, out s);

				int X = s.Aggregate(0, (a, b) => a + b);
				
				output.Write("Case #{0}:", _T + 1);
				for (int i = 0; i < N; ++i) {
					double low = 0, high = 1;
					while (high - low > 1e-8) {
						double mid = (low + high) / 2;

						double pts = s[i] + mid * X;
						
						double req = 0;
						for (int j = 0; j < N; ++j) {
							if (i != j) {
								if (s[j] > pts + 1e-8)
									continue;
								else {
									req += (pts - s[j]) / X;
								}
							}
						}

						if (req > 1.00000001 - mid)
							high = mid;
						else
							low = mid;
					}
					output.Write(" {0}", low * 100);
				}
				output.WriteLine();
			}
		}

		public static void Main()
		{
			var obj = new Task03A();
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
