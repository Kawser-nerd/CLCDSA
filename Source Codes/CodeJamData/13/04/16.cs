using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;
using System.Numerics;

namespace Google.CodeJam2013
{
#if _ONLINE_JUDGE_
	[OnlineJudge.Task("CodeJam13 01D")]
#endif
	class Task01D
	{
		private class Solver
		{
			private InputTokenizer input = new InputTokenizer();
			private TextWriter output = Console.Out;

			public void Solve()
			{
				int T;
				input.Line().Read(out T);

				for (int _T = 0; _T < T; ++_T)
				{
					int K, N;
					input.Line().Read(out K).Read(out N);

					int last = (1 << N) - 1;

					int[] prev = new int[1 << N];
					var availableKeys = new Dictionary<int, int>[1 << N];
					var lastKeys = new Dictionary<int, int>();

					availableKeys[last] = lastKeys;
					prev[last] = -1;

					int[] keys = new int[K];
					input.Line().Read(K, out keys);
					for (int i = 0; i < K; ++i)
					{
						if (!lastKeys.ContainsKey(keys[i])) lastKeys[keys[i]] = 0;
						++lastKeys[keys[i]];
					}

					int[] requiredKey = new int[N];
					int[][] containedKeys = new int[N][];
					for (int i = 0, k; i < N; ++i)
					{
						input.Line().Read(out requiredKey[i]).Read(out k).Read(k, out containedKeys[i]);

						if (!lastKeys.ContainsKey(requiredKey[i])) lastKeys[requiredKey[i]] = 0;
						--lastKeys[requiredKey[i]];
						for (int j = 0; j < k; ++j)
						{
							if (!lastKeys.ContainsKey(containedKeys[i][j])) lastKeys[containedKeys[i][j]] = 0;
							++lastKeys[containedKeys[i][j]];
						}
					}

					var idx = Enumerable.Range(0, (1 << N) - 1).OrderByDescending(n => CountPopBits(n));
					foreach (var i in idx)
					{
						for (int j = 0; j < N; ++j)
						{
							if ((i & (1 << j)) == 0 && prev[i | (1 << j)] != 0)
							{
								var d = new Dictionary<int, int>(availableKeys[i | (1 << j)]);
								++d[requiredKey[j]];
								foreach (var x in containedKeys[j]) --d[x];
								if (d[requiredKey[j]] > 0)
								{
									prev[i] = j + 1;
									availableKeys[i] = d;
									break;
								}
							}
						}
					}

					if (prev[0] == 0)
						output.WriteLine("Case #{0}: IMPOSSIBLE", _T + 1);
					else
					{
						output.Write("Case #{0}:", _T + 1);
						for (int i = 0, mask = 0; i < N; ++i)
						{
							output.Write(" {0}", prev[mask]);
							mask |= (1 << (prev[mask] - 1));
						}
						output.WriteLine();
					}
				}
			}

			private int CountPopBits(int n)
			{
				int m = 0;
				while (n != 0)
				{
					m += n % 2;
					n /= 2;
				}
				return m;
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
