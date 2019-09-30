using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GCJ.Impl.Round2
{
	public class ProblemA : ProblemBase
	{
		private SortedDictionary<int, int> a = new SortedDictionary<int, int>();
		private Stack<KeyValuePair<int, int>> s = new Stack<KeyValuePair<int, int>>();

		public override bool SolveOne(StreamReader reader, StreamWriter writer, int testNumber)
		{
			a.Clear();
			s.Clear();
			int n, m;
			ReadInts(reader, out n, out m);
			long res = 0;
			for (int i = 0; i < m; i++)
			{
				int o, e, p;
				ReadInts(reader, out o, out e, out p);
				if (!a.ContainsKey(o))
					a[o] = 0;
				if (!a.ContainsKey(e))
					a[e] = 0;
				a[o] += p;
				a[e] -= p;
				res += Count(n, o, e, p);
			}
			int prev = 0;
			foreach (var point in a)
			{
				long sum = 0;
				foreach (KeyValuePair<int, int> pair in s)
					sum += Count(n - prev + pair.Key, prev, point.Key, pair.Value);
				res -= sum;
				if (point.Value > 0)
					s.Push(point);
				else
				{
					var cur = -point.Value;
					while (cur > 0)
					{
						var top = s.Pop();
						if (top.Value > cur)
						{
							s.Push(new KeyValuePair<int, int>(top.Key, top.Value - cur));
							cur -= cur;
						}
						else
						{
							cur -= top.Value;
						}
					}
				}
				prev = point.Key;
			}
			return Write(writer, testNumber, res);
		}

		private long Count(int n, int o, int e, long p)
		{
			return (n + n + 1 - e + o)*(e - o)*p / 2;
		}
	}
}