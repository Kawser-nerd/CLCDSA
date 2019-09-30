using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;

namespace RAVE
{
	public static class Utility
	{
		static void Main()
		{
			Console.InputEncoding = Encoding.ASCII;
			Console.OutputEncoding = Encoding.ASCII;

			var s = Stopwatch.StartNew();

			Console.In.ReadTestCases(i => new TestCase(i))
				.Select(t => t.GetResult())
				.WriteResultsSameLine(Console.Out, (o, r) => o.WriteLine("{0}", r));

			Console.Error.WriteLine("Time: {0}", s.Elapsed);
		}

		public static void ForEach<T>(this IEnumerable<T> collection, Action<T> action)
		{
			foreach (var item in collection)
				action(item);
		}

		public static void ForEach<T>(this IEnumerable<T> collection, Action<T, int> action)
		{
			int i = 0;
			foreach (var item in collection)
				action(item, i++);
		}

		public static int Compare(params Func<int>[] comparisons)
		{
			return comparisons.Select(c => c()).FirstOrDefault(c => c != 0);
		}

		/// <summary>
		/// Call the given selector on pairs of elements from the source: (0, 1), (2, 3), (4, 5) and so on.
		/// </summary>
		public static IEnumerable<TResult> SelectPairs<TSource, TResult>(this IEnumerable<TSource> s, Func<TSource, TSource, TResult> selector)
		{
			using (var enumerator = s.GetEnumerator())
				while (enumerator.MoveNext())
				{
					TSource item1 = enumerator.Current;
					if (enumerator.MoveNext())
						yield return selector(item1, enumerator.Current);
					else
						throw new Exception("UnmatchedItem");
				}
		}

		/// <summary>
		/// Call the given selector with each adjacent pair from the source: (0, 1), (1, 2), (2, 3) and so on.
		/// </summary>
		public static IEnumerable<TResult> SelectAdjacent<TSource, TResult>(this IEnumerable<TSource> s, Func<TSource, TSource, TResult> selector)
		{
			TSource prev = s.FirstOrDefault();
			return s.Skip(1).Select(curr => { TResult r = selector(prev, curr); prev = curr; return r; });
		}

		/// <summary>
		/// Call the given selector with each adjacent pair from the source with wrap-around: (0, 1), (1, 2), (2, 3), ... (n-2, n-1), (n-1, 0).
		/// </summary>
		public static IEnumerable<TResult> SelectAdjacentWrap<TSource, TResult>(this IEnumerable<TSource> s, Func<TSource, TSource, TResult> selector)
		{
			return s.Concat(new[] { s.FirstOrDefault() }).SelectAdjacent(selector);
		}

		/// <summary>
		/// Return the value for the given key if it exists, and the default value if not.
		/// </summary>
		public static TValue GetValueOrDefault<TKey, TValue>(this Dictionary<TKey, TValue> d, TKey key)
		{
			TValue value;
			d.TryGetValue(key, out value);
			return value;
		}

		public static IEnumerable<T> GetRow<T>(this T[,] m, int i)
		{
			return Enumerable.Range(0, m.GetLength(1)).Select(j => m[i, j]);
		}

		public static IEnumerable<IEnumerable<T>> GetRows<T>(this T[,] m)
		{
			return Enumerable.Range(0, m.GetLength(0)).Select(i => m.GetRow(i));
		}

		public static IEnumerable<T> GetColumn<T>(this T[,] m, int j)
		{
			return Enumerable.Range(0, m.GetLength(0)).Select(i => m[i, j]);
		}

		public static IEnumerable<IEnumerable<T>> GetColumns<T>(this T[,] m)
		{
			return Enumerable.Range(0, m.GetLength(1)).Select(j => m.GetColumn(j));
		}

		public static IEnumerable<T> GetDiagonal1<T>(this T[,] m)
		{
			return Enumerable.Range(0, Math.Min(m.GetLength(0), m.GetLength(1))).Select(i => m[i, i]);
		}

		public static IEnumerable<T> GetDiagonal2<T>(this T[,] m)
		{
			return Enumerable.Range(0, Math.Min(m.GetLength(0), m.GetLength(1))).Select(i => m[i, m.GetLength(1) - i - 1]);
		}

		public static IEnumerable<IEnumerable<T>> GetDiagonals<T>(this T[,] m)
		{
			return new[] { m.GetDiagonal1(), m.GetDiagonal2() };
		}

		public static IEnumerable<T> GetElements<T>(this T[,] m)
		{
			return Enumerable.Range(0, m.GetLength(0))
				.SelectMany(i => Enumerable.Range(0, m.GetLength(1)).Select(j => m[i, j]));
		}

		public static IEnumerable<LinkedListNode<T>> GetNodes<T>(this LinkedList<T> ll)
		{
			for (var n = ll.First; n != null; n = n.Next)
				yield return n;
		}

		public static int[] GetPrimesLessThan(int n)
		{
			if (n < 2)
				return new int[0];
			bool[] crossed = new bool[n];
			crossed[0] = true;
			crossed[1] = true;
			for (int i = 2; i * i < n; ++i)
				if (!crossed[i])
					for (int j = i + i; j < n; j += i)
						crossed[j] = true;
			return crossed.Select((b, i) => b ? 0 : i).Where(i => i != 0).ToArray();
		}

		/// <summary>
		/// Get the prime factors of n.
		/// n must be >= 2, primes must have all primes >= 2 up to SQRT(n).
		/// </summary>
		public static IEnumerable<long> GetPrimeFactors(long n, int[] primes)
		{
			foreach (var p in primes)
			{
				if (p * p > n)
					break;
				while (n % p == 0)
				{
					yield return p;
					n /= p;
				}
			}
			if (n != 1)
				yield return n;
		}

		/// <summary>
		/// Merge two sequences, assumed to both be in ascending order.
		/// If one list has c1 of something, and the other has c2 of the same thing, max(c1, c2) of that thing will be in the result.
		/// </summary>
		public static IEnumerable<T> MergeWithDuplicates<T>(T[] s1, T[] s2) where T : IComparable<T>
		{
			int i1 = 0, i2 = 0;
			while (i1 != s1.Length && i2 != s2.Length)
			{
				int c = s1[i1].CompareTo(s2[i2]);
				if (c < 0)
					yield return s1[i1++];
				else if (c > 0)
					yield return s2[i2++];
				else
				{
					yield return s1[i1++];
					i2++;
				}
			}
			while (i1 != s1.Length)
				yield return s1[i1++];
			while (i2 != s2.Length)
				yield return s2[i2++];
		}

		public static int CountBits(int i)
		{
			 i = i - ((i >> 1) & 0x55555555);
			 i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
			 return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
		}

		public static int CombineHashCodes(int h1, int h2)
		{
			return (h1 << 5) + h1 ^ h2;
		}

		public static string FormatSeparated(this IEnumerable<string> values, string separator)
		{
			int length = values.Sum(s => s.Length + separator.Length) - separator.Length;
			return values.Aggregate(new StringBuilder(length), (sb, s) => (sb.Length == 0 ? sb : sb.Append(separator)).Append(s)).ToString();
		}

		public static IEnumerable<T> ReadTestCases<T>(this TextReader input, Func<TextReader, T> readTestCase)
		{
			return Enumerable.Range(0, int.Parse(input.ReadLine().Trim())).Select(i => readTestCase(input));
		}

		/// <summary>
		/// Read space separated strings.
		/// </summary>
		public static string[] ReadStrings(this TextReader input)
		{
			return input.ReadLine().Split(' ');
		}

		public static int[] ReadInts(this TextReader input)
		{
			return input.ReadStrings().Select(s => int.Parse(s)).ToArray();
		}

		public static long[] ReadLongs(this TextReader input)
		{
			return input.ReadStrings().Select(s => long.Parse(s)).ToArray();
		}

		public static BigInteger[] ReadBigIntegers(this TextReader input)
		{
			return input.ReadStrings().Select(s => BigInteger.Parse(s)).ToArray();
		}

		public static double[] ReadDoubles(this TextReader input)
		{
			return input.ReadStrings().Select(s => double.Parse(s)).ToArray();
		}

		static void WriteResults<T>(this IEnumerable<T> results, TextWriter output, Action<TextWriter> endCaseLine, Action<TextWriter, T> writeResult)
		{
			results.ForEach((result, i) =>
			{
				output.Write("Case #{0}:", i + 1);
				endCaseLine(output);
				writeResult(output, result);
			});
		}

		public static void WriteResultsSameLine<T>(this IEnumerable<T> results, TextWriter output, Action<TextWriter, T> writeResult)
		{
			WriteResults(results, output, o => o.Write(" "), writeResult);
		}

		public static void WriteResultsNewLine<T>(this IEnumerable<T> results, TextWriter output, Action<TextWriter, T> writeResult)
		{
			WriteResults(results, output, o => o.WriteLine(), writeResult);
		}

		public static ulong GCD(ulong a, ulong b)
		{
			while (b != 0)
			{
				var t = b;
				b = a % b;
				a = t;
			}
			return a;
		}

		public static long GCD(long a, long b)
		{
			while (b != 0)
			{
				var t = b;
				b = a % b;
				a = t;
			}
			return a;
		}

		public static BigInteger GCD(BigInteger a, BigInteger b)
		{
			while (b != 0)
			{
				var t = b;
				b = a % b;
				a = t;
			}
			return a;
		}

		// Get the lowest-common-multiple for two numbers.  Return null on overflow.
		public static long? LCM(long a, long b)
		{
			try
			{
				return checked(a / Utility.GCD(a, b) * b);
			}
			catch (OverflowException)
			{
				return null;
			}
		}

		// Get all divisors of n, including 1 and n, in ascending order.
		public static long[] GetDivisors(long n)
		{
			List<long> forward = new List<long>();
			Stack<long> reverse = new Stack<long>();
			for (long i = 1; i * i <= n; ++i)
				if (n % i == 0)
				{
					forward.Add(i);
					reverse.Push(n / i);
				}
			return forward.Concat(reverse).ToArray();
		}
	}
}