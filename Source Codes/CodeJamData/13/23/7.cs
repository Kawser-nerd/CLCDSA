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
	[OnlineJudge.Task("CodeJam13 03C")]
#endif
	class Task03C
	{
		private class Solver
		{
			private InputTokenizer input = new InputTokenizer();
			private TextWriter output = Console.Out;

			public void Solve()
			{
				List<string> dictionary = new List<string>();
				//
				using (var file = new StreamReader(@"C:\Development\Visual Studio 2012\Projects\OnlineJudge\Judge .NET\Google Code Jam\2013\03 Round 1B\garbled_email_dictionary.txt"))
				{
					String line;
					while ((line = file.ReadLine()) != null)
						dictionary.Add(line);
				}

				int T;
				input.Line().Read(out T);

				int[] changes = new int[100];

				string S;
				for (int _T = 0; _T < T; ++_T)
				{
					input.Line().Read(out S);
					
					int N = S.Length;

					int[,] dp = new int[N + 1, 5];

					for (int i = 0; i <= N; ++i)
						for (int j = 0; j < 5; ++j)
							dp[i, j] = 0x3fffffff;
					dp[0, 4] = 0;

					for (int i = 0; i < N; ++i)
					{
						foreach (var word in dictionary)
						{
							if (i + 1 < word.Length) continue;
							
							int cnt = 1;
							for (int k = i - word.Length + 1, z = 0; k <= i; ++k, ++z)
								if (word[z] != S[k])
									changes[cnt++] = k;

							for (int k = 0; k < 5; ++k) {
								changes[0] = i - word.Length - k;

								bool valid = true;
								for (int z = 1; z < cnt; ++z)
									if (changes[z] - changes[z - 1] < 5)
										valid = false;

								if (valid)
									dp[i + 1, Math.Min(i - changes[cnt - 1], 4)] = Math.Min(dp[i + 1, Math.Min(i - changes[cnt - 1], 4)], dp[i - word.Length + 1, k] + cnt - 1);
							}
						}
					}

					int best = 0x3fffffff;
					for (int i = 0; i < 5; ++i) best = Math.Min(best, dp[N, i]);
					output.WriteLine("Case #{0}: {1}", _T + 1, best);
				}
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
