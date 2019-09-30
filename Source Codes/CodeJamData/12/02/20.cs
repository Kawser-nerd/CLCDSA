using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace RAVE
{
	public static class Utility
	{
		static void Main()
		{
			Console.InputEncoding = Encoding.ASCII;
			Console.OutputEncoding = Encoding.ASCII;

			Console.In.ReadTestCases(i => new TestCase(i))
				.Select(t => t.GetResult())
				.WriteResultsSameLine(Console.Out, (o, r) => o.WriteLine("{0}", r));
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

		public static string FormatSeparated(this IEnumerable<string> values, string separator)
		{
			int length = values.Sum(s => s.Length + separator.Length) - separator.Length;
			return values.Aggregate(new StringBuilder(length), (sb, s) => (sb.Length == 0 ? sb : sb.Append(separator)).Append(s)).ToString();
		}

		public static IEnumerable<T> ReadTestCases<T>(this TextReader input, Func<TextReader, T> readTestCase)
		{
			return Enumerable.Range(0, int.Parse(input.ReadLine().Trim())).Select(i => readTestCase(input));
		}

		public static string[] ReadStrings(this TextReader input)
		{
			return input.ReadLine().Split(' ');
		}

		public static int[] ReadInts(this TextReader input)
		{
			return input.ReadStrings().Select(s => int.Parse(s)).ToArray();
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
	}
}