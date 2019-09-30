using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Google.CodeJam2012
{
#if _ONLINE_JUDGE_
	[OnlineJudge.Task("CodeJam12 05A")]
#endif
	class Task05A
	{
		private InputTokenizer input = new InputTokenizer();
		private TextWriter output = Console.Out;

		private void Solve()
		{
			int T;
			input.Line().Read(out T);

			for (int _T = 0; _T < T; ++_T) {
				int N;
				input.Line().Read(out N);

				int[] d = new int[N + 1], l = new int[N + 1];
				for (int i = 0; i < N; ++i) input.Line().Read(out d[i]).Read(out l[i]);
				input.Line().Read(out d[N]);

				int[] dp = new int[++N];
				dp[0] = d[0];

				dp[N - 1] = -1;
				for (int i = 0; i < N; ++i) {
					for (int j = i + 1; j < N; ++j) {
						if (d[j] - d[i] > dp[i]) break;
						dp[j] = Math.Max(dp[j], Math.Min(d[j] - d[i], l[j]));
					}
				}

				output.WriteLine("Case #{0}: {1}", _T + 1, dp[N - 1] == -1 ? "NO" : "YES");
			}
		}

		public static void Main()
		{
			var obj = new Task05A();
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
