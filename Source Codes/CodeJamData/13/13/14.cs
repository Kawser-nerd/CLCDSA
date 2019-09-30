using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace Google.CodeJam2013
{
#if _ONLINE_JUDGE_
	[OnlineJudge.Task("CodeJam13 02C")]
#endif
	class Task02C
	{
		private class Solver
		{
			private InputTokenizer input = new InputTokenizer();
			private TextWriter output = Console.Out;

			public void Solve()
			{
				int T;
				input.Line().Read(out T);

				int R, N, M, K;
				for (int _T = 0; _T < T; ++_T)
				{
					input.Line().Read(out R).Read(out N).Read(out M).Read(out K);

					output.WriteLine("Case #{0}:", _T + 1);

					int[] C;
					for (int i = 0; i < R; ++i)
					{
						input.Line().Read(K, out C);

						bool found = false;
						for (int a = 2; !found && a <= 5; ++a)
							for (int b = 2; !found && b <= 5; ++b)
								for (int c = 2; !found && c <= 5; ++c)
								{
									bool[] possible = new bool[200];
									possible[1] = possible[a] = possible[b] = possible[c] = possible[a * b] = possible[a * c] = possible[b * c] = possible[a * b * c] = true;

									bool valid = true;
									for (int j = 0; j < K; ++j)
										if (!possible[C[j]])
											valid = false;

									if (valid)
									{
										found = true;
										output.WriteLine("{0}{1}{2}", a, b, c);
									}
								}
					}
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
