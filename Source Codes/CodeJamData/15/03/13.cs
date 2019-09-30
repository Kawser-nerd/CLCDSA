using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
	static class Symb
	{
		public const int s1 = 1;
		public const int i = 2;
		public const int j = 3;
		public const int k = 4;

		static int[][] symbolsCache;
		static Symb()
		{
			symbolsCache = new int[9][];
			for (var i = 0; i < 9; i++)
			{
				symbolsCache[i] = new int[9];
			}
			for (var i = -4; i <= 4; i++)
			{
				if (i == 0)
					continue;
				for (var j = -4; j <= 4; j++)
				{
					if (j == 0)
						continue;
					symbolsCache[i + 4][j + 4] = MultSymbolsInternal(i, j);
				}
			}
		}

		static int MultSymbolsInternal(int lhs, int rhs)
		{
			int sign = (lhs > 0 && rhs < 0 || lhs < 0 && rhs > 0) ? -1 : 1;
			return sign * MultSymbolsAbsInternal(Math.Abs(lhs), Math.Abs(rhs));
		}
		static int MultSymbolsAbsInternal(int lhs, int rhs)
		{
			if (lhs == 1)
				return rhs;
			if (rhs == 1)
				return lhs;
			if (lhs == rhs)
				return -1;
			if (lhs == Symb.i && rhs == Symb.j)
				return Symb.k;
			if (lhs == Symb.i && rhs == Symb.k)
				return -Symb.j;
			if (lhs == Symb.j && rhs == Symb.i)
				return -Symb.k;
			if (lhs == Symb.j && rhs == Symb.k)
				return Symb.i;
			if (lhs == Symb.k && rhs == Symb.i)
				return Symb.j;
			if (lhs == Symb.k && rhs == Symb.j)
				return -Symb.i;
			throw new NotImplementedException();
		}

		public static int Mult(int lhs, int rhs)
		{
			return symbolsCache[lhs + 4][rhs + 4];
		}
		public static int Power(int symb, int n)
		{
			if (n == 0 || n == -1)
				return 1;
			if (n == 1)
				return symb;

			int mult = 1;
			for (var i = 0; i < n; i++)
				mult = Mult(mult, symb);
			return mult;
		}
	}

	class Program
	{

		static void Main(string[] args)
		{
			var input = @"2
3 1
ijk
3 5
ijk";
			input = File.ReadAllText("input.txt");

			var outputStr = Solve(Parse(input));

			Console.WriteLine(outputStr);
			File.WriteAllText(GetFileName(), outputStr);

			//Console.ReadLine();
		}
		static string GetFileName()
		{
			return DateTime.Now.Ticks.ToString() + ".txt";
		}

		static List<Tuple<long, int[]>> Parse(string input)
		{
			var parts = input.Split(new char[] { '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries);
			var count = long.Parse(parts[0]);
			List<Tuple<long, int[]>> testCases = new List<Tuple<long, int[]>>();
			for (var i = 0; i < count; i++)
			{
				var s1 = parts[i * 2 + 1];
				var s2 = parts[i * 2 + 2];

				var r = long.Parse(s1.Split(' ')[1]);
				testCases.Add(new Tuple<long, int[]>(r, s2.Trim().Select(c =>
				{
					if (c == 'i')
						return Symb.i;
					if (c == 'j')
						return Symb.j;
					if (c == 'k')
						return Symb.k;
					throw new NotImplementedException();
				}).ToArray()));
			}
			return testCases;
		}

		static string Solve(List<Tuple<long, int[]>> testCases)
		{
			Init();

			List<string> output = new List<string>();
			for (var i = 0; i < testCases.Count; i++)
			{
				output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(testCases[i])));
			}
			return string.Join(Environment.NewLine, output);
		}

		
		static void Init()
		{
		}

		static string Solve(Tuple<long, int[]> d)
		{
			long r = d.Item1;
			int[] seq = d.Item2;

			if (r == 1)
			{
				var possibleIPos = FindAllIPos(seq).ToList();
				var possibleKPos = FindAllKPos(seq).Reverse().ToList();

				if (!possibleIPos.Any() || !possibleKPos.Any())
					return "NO";

				//possibleKPos.Reverse();
				//possibleKPos = possibleKPos.Where(kp => kp > (possibleIPos[0] + 1)).ToList();

				Dictionary<int, int> nextKPosMult = new Dictionary<int, int>();
				for (var i = 1; i < possibleKPos.Count; i++)
				{
					var cur = possibleKPos[i];
					var prev = possibleKPos[i - 1];
					nextKPosMult.Add(cur, MultSymbolsFromPosToPos(seq, prev, cur - 1));
				}

				foreach (var pI in possibleIPos)
				{
					possibleKPos = possibleKPos.Where(pK => pK > (pI + 1)).ToList();
					if (!possibleKPos.Any())
						break;

					int prevPK = possibleKPos[0];
					int prevMult = MultSymbolsFromPosToPos(seq, pI + 1, prevPK - 1);

					if (prevMult == Symb.j)
						return "YES";

					foreach (var pK in possibleKPos.Skip(1).ToList())
					{
						prevMult = Symb.Mult(prevMult, nextKPosMult[pK]);
						if (prevMult == Symb.j)
							return "YES";
					}
				}
				return "NO";
			}
			else if (r > 1)
			{
				int cf = MultSymbolsFromPosToPos(seq, 0, seq.Length - 1);

				//long newR = r % 4;
				long newR = Math.Min((r % 4) + 16, r);

				//for (var newR = (int)(r % 4); newR <= r && newR <= 100; newR += 4)
				//{
					for (var i = 0; i < newR; i++)
					{
						int cfpi = Symb.Power(cf, i);
						for (var k = i; k < newR; k++)
						{
							int cfpk = Symb.Power(cf, (int)(newR - 1 - k));
							int cfpj = Symb.Power(cf, k - i - 1);
							if (Solve(new Tuple<long, int[]>(1, Merge(seq, cfpi, cfpk, cfpj, k == i))) == "YES")
								return "YES";
						}
					}
				//}
				return "NO";
			}
			else
				throw new NotImplementedException();
		}
		static int[] Merge(int[] seq, int cfpi, int cfpk, int cfpj, bool kandi)
		{
			return Merge1(seq, cfpi, cfpk, cfpj, kandi).ToArray();
		}
		static IEnumerable<int> Merge1(int[] seq, int cfpi, int cfpk, int cfpj, bool kandi)
		{
			if (cfpi != 1)
				yield return cfpi;

			foreach (var i in seq)
				yield return i;

			if(cfpj != 1)
				yield return cfpj;

			if (!kandi)
			{
				foreach (var i in seq)
					yield return i;
			}

			if(cfpk != 1)
				yield return cfpk;
		}

		static int MultSymbolsFromPosToPos(int[] seq, int startPos, int endPos)
		{
			int mult = 1;
			for (var i = startPos; i <= endPos; i++)
			{
				mult = Symb.Mult(mult, seq[i]);
			}
			return mult;
		}

		static IEnumerable<int> FindAllIPos(int[] seq)
		{
			int mult = 1;
			for (var i = 0; i < seq.Length; i++)
			{
				mult = Symb.Mult(mult, seq[i]);
				if (mult == Symb.i)
					yield return i;
			}
		}
		static IEnumerable<int> FindAllKPos(int[] seq)
		{
			int mult = 1;
			for (var i = seq.Length - 1; i >= 0; i--)
			{
				mult = Symb.Mult(seq[i], mult);
				if (mult == Symb.k)
					yield return i;
			}
		}
	}
}
