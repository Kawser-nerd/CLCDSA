using System.IO;

namespace Impl.Round1C
{
	public class ProblemA : ProblemBase
	{
		protected override bool SolveOne(TextReader input, TextWriter output, int testNumber)
		{
			string s;
			int n, c = 0, l = 0;
			Read(input, out s, out n);
			int i = 0;
			long res = 0;
			if (s.Length < n)
				return Write(output, testNumber, string.Format("{0}", 0));
			if (n == 0)
				return Write(output, testNumber, string.Format("{0}", ArifmSum(s.Length)));
			for (; i < s.Length; i++)
			{
				if (IsVowel(s[i]))
				{
					if (c >= n)
					{
						l = i - n + 1;
						if (l < 0)
							l = 0;
					}
					c = 0;
				}
				else
				{
					++c;
					if (c == n && i >= l + n)
						res += ArifmSum(i - l - n + 1);
				}
			}
			if (c < n && i >= l + n)
				res += ArifmSum(i - l - n + 1);
			res = ArifmSum(s.Length - n + 1) - res;
			return Write(output, testNumber, string.Format("{0}", res));
		}

		private static long ArifmSum(long l1)
		{
			return l1*(l1 + 1)/2;
		}

		private bool IsVowel(char c)
		{
			return
				c == 'a' ||
				c == 'e' ||
				c == 'i' ||
				c == 'o' ||
				c == 'u';
		}

		private static void Read(TextReader input, out string s, out int n)
		{
			var readLine = input.ReadLine();
			var parts = readLine.Split(' ');
			s = parts[0];
			n = int.Parse(parts[1]);
		}
	}
}