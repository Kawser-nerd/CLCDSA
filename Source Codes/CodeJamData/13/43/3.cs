using System.IO;
using System.Linq;

namespace GCJ.Impl.Round2
{
	public class ProblemC : ProblemBase
	{
		private bool[,] e;
		private bool[] taken;
		int[] a;
		int[] b;

		protected override bool SolveOne(StreamReader reader, StreamWriter writer, int testNumber)
		{
			var n = int.Parse(reader.ReadLine());
			e = new bool[n,n];
			taken = new bool[n];
			a = ReadInts(reader).Select(x => x - 1).ToArray();
			b = ReadInts(reader).Select(x => x - 1).ToArray();
			var c = Enumerable.Repeat(-1, n).ToArray();
			for (int i = 0; i < n; i++)
			{
				if (c[a[i]] != -1)
					IsLess(i, c[a[i]]);
				if (a[i] > 0 && c[a[i] - 1] != -1)
					IsLess(c[a[i] - 1], i);
				c[a[i]] = i;
			}
			c = Enumerable.Repeat(-1, n).ToArray();
			for (int i = n - 1; i >= 0; i--)
			{
				if (c[b[i]] != -1)
					IsLess(i, c[b[i]]);
				if (b[i] > 0 && c[b[i] - 1] != -1)
					IsLess(c[b[i] - 1], i);
				c[b[i]] = i;
			}
			Floid(n);
			taken = new bool[n];
			result = new int[n];
			if (Brute(n, 0))
			return Write<int>(writer, testNumber, result);
			return false;
		}

		private int Get(int i, int n)
		{
			int res = 0;
			for (var k = 0; k < n; k++)
			{
				if (e[k, i])
					++res;
			}
			while (taken[res])
				++res;
			taken[res] = true;
			return res + 1;
		}

		private void Floid(int n)
		{
			for (int j = 0; j < n; j++)
			{
				for (int i = 0; i < n; i++)
				{
					for (int k = 0; k < n; k++)
					{
						if (e[i,j] && e[j,k])
							IsLess(i, k);
					}
				}
			}
		}

		private int[] result;

		private bool Brute(int n, int i)
		{
			if (i == n)
				return Check(n);

			for (result[i] = 1; result[i] <= n; result[i]++)
			{
				if (taken[result[i] - 1])
					continue;
				int t = -1;
				for (int k = 0; k < i; k++)
				{
					if (result[k] < result[i] && t < a[k])
						t = a[k];
				}
				if (t != a[i] - 1)
					continue;
				t = 0;
				for (int k = 0; k < i; k++)
				{
					if (e[i, k] && result[k] < result[i])
					{
						t = 1;
						break;
					}
				}
				if (t == 1)
					continue;
				taken[result[i] - 1] = true;
				if (Brute(n, i + 1))
					return true;
				taken[result[i] - 1] = false;
			}
			return false;
		}

		private bool Check(int n)
		{
			for (int i = n - 1; i >= 0; i--)
			{
				int t = -1;
				for (int k = i + 1; k < n; k++)
				{
					if (result[k] < result[i] && t < b[k])
						t = b[k];
				}
				if (t != b[i] - 1)
					return false;
			}
			return true;
		}

		private void IsLess(int l, int r)
		{
			e[l, r] = true;
		}
	}
}