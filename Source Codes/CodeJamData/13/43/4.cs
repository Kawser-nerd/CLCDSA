using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;

namespace Google.CodeJam2013
{
#if _ONLINE_JUDGE_
	[OnlineJudge.v2.Task]
#endif
	class Task05C
	{
		private class Solver
		{
			private InputTokenizer input = new InputTokenizer();
			private TextWriter output = Console.Out;

			public void Solve()
			{
				int T;
				input.Line().Read(out T);

				int N;
				int[] A, B;
				for (int _T = 0; _T < T; ++_T)
				{
					input.Line().Read(out N)
							 .Line().Read(N, out A)
							 .Line().Read(N, out B);

					List<int> temp = new List<int>();
					for (int i = 1; i <= N; ++i) temp.Add(i);

					int[] X = new int[N], dpInc = new int[N], dpDec = new int[N];
					
					for (int i = 0; i < N; ++i) dpInc[i] = -1;
					for (int i = 0; i < N; ++i) dpDec[i] = -1;

					if (!f(temp, 0, N, X, dpInc, A, B))
						output.WriteLine("FAIL!");

					output.Write("Case #{0}:", _T + 1);
					for (int i = 0; i < N; ++i) output.Write(" {0}", X[i]);
					output.WriteLine();
				}
			}

			private bool f(List<int> temp, int index, int N, int[] X, int[] dpInc, int[] A, int[] B)
			{
				if (index == N)
				{
					int[] dpDec = new int[N];

					for (int i = N - 1; i >= 0; --i) {
						dpDec[i] = 1;
						for (int j = i + 1; j < N; ++j)
							if (X[i] > X[j])
								dpDec[i] = Math.Max(dpDec[i], dpDec[j] + 1);

						if (dpDec[i] != B[i]) return false;
					}

					return true;
				}

				for (int i = 0; i < temp.Count; ++i)
				{
					int value = temp[i];

					dpInc[value - 1] = 1;
					for (int j = 1; j < value; ++j)
						if (dpInc[j - 1] != -1)
							dpInc[value - 1] = Math.Max(dpInc[value - 1], dpInc[j - 1] + 1);

					if (dpInc[value - 1] == A[index])
					{
						X[index] = value;
						temp.RemoveAt(i);
						if (f(temp, index + 1, N, X, dpInc, A, B)) return true;
						temp.Insert(i, value);
					}

					dpInc[value - 1] = -1;
				}

				return false;
			}
		}

		#region
		public static void Main()
		{
			var obj = new Solver();
			obj.Solve();
		}

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

			public String ReadLine()
			{
				return Console.In.ReadLine();
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
				v = double.Parse(_tokens[_offset++].Replace('.', ','));
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
