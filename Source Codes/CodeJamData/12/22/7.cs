using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Google.CodeJam2012
{
#if _ONLINE_JUDGE_
	[OnlineJudge.Task("CodeJam12 03B")]
#endif
	class Task03B
	{
		private InputTokenizer input = new InputTokenizer();
		private TextWriter output = Console.Out;

		struct State : IComparable<State>
		{
			public double Time, WaterLevel;
			public int Row, Column;
			public bool Dropping;

			public int CompareTo(State other)
			{
				int t;

				t = Time.CompareTo(other.Time);
				if (t != 0) return t;

				t = Dropping.CompareTo(other.Dropping);
				if (t != 0) return t;

				t = WaterLevel.CompareTo(other.WaterLevel);
				if (t != 0) return t;

				t = Row.CompareTo(other.Row);
				if (t != 0) return t;

				t = Column.CompareTo(other.Column);
				if (t != 0) return t;

				return 0;
			}
		}

		private void Solve()
		{
			int T;
			input.Line().Read(out T);

			for (int _T = 0; _T < T; ++_T) {
				int H, N, M;
				input.Line().Read(out H).Read(out N).Read(out M);

				int[,] floorLevel = new int[N, M];
				int[,] ceilLevel = new int[N, M];

				for (int i = 0; i < N; ++i) {
					input.Line();
					for (int j = 0; j < M; ++j) input.Read(out ceilLevel[i, j]);
				}

				for (int i = 0; i < N; ++i) {
					input.Line();
					for (int j = 0; j < M; ++j) input.Read(out floorLevel[i, j]);
				}

				SortedSet<State> set = new SortedSet<State>();
				set.Add(new State { Time = 0, WaterLevel = H, Row = 0, Column = 0, Dropping = false });

				int[] dx = { -1, 0, 0, 1 }, dy = { 0, -1, 1, 0 };

				bool[,] visited = new bool[N, M];
				while (set.Count > 0) {
					State e = set.Min;
					set.Remove(e);

					if (visited[e.Row, e.Column]) continue;

					visited[e.Row, e.Column] = true;

					if (e.Row == N - 1 && e.Column == M - 1) {
						output.WriteLine("Case #{0}: {1}", _T + 1, e.Time);
						break;
					}

					for (int j = 0; j < 4; ++j) {
						int r = e.Row + dy[j], c = e.Column + dx[j];
						if (0 <= r && r < N && 0 <= c && c < M && !visited[r, c] &&
								floorLevel[e.Row, e.Column] <= ceilLevel[r, c] - 50 && floorLevel[r, c] <= ceilLevel[r, c] - 50 && // Rule 1
								floorLevel[r, c] <= ceilLevel[e.Row, e.Column] - 50 // Rule 2
								) {

							State t = e;

							if (!t.Dropping) {
								if (t.WaterLevel <= ceilLevel[r, c] - 50) {
									set.Add(new State { Row = r, Column = c, Time = t.Time, Dropping = t.Dropping, WaterLevel = t.WaterLevel });
									continue;
								} else {
									t.Dropping = true;
								}
							}

							if (t.WaterLevel > ceilLevel[r, c] - 50) {
								double s = (t.WaterLevel - ceilLevel[r, c] + 50) / 10;
								t.Time += s;
								t.WaterLevel -= s * 10;
							}

							if (t.WaterLevel - floorLevel[e.Row, e.Column] >= 20) {
								t.Time += 1;
								t.WaterLevel -= 10;
							} else {
								t.Time += 10;
								t.WaterLevel -= 100;
							}

							set.Add(new State { Row = r, Column = c, Time = t.Time, Dropping = t.Dropping, WaterLevel = t.WaterLevel });
						}
					}
				}
			}
		}

		public static void Main()
		{
			var obj = new Task03B();
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
