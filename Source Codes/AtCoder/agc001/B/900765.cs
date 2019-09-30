using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

namespace CF317
{
	internal class Program
	{
		private static void Main(string[] args)
		{
			var sr = new InputReader(Console.In);
			//var sr = new InputReader(new StreamReader("input.txt"));
			var task = new Task();
			using (var sw = Console.Out)
				//using (var sw = new StreamWriter("output.txt"))
			{
				task.Solve(sr, sw);
				//Console.ReadKey();
			}
		}
	}

	internal class Task
	{
		public void Solve(InputReader sr, TextWriter sw)
		{
			var input = sr.ReadArray(Int64.Parse);
			var n = input[0];
			var x = input[1];
			sw.WriteLine(Count(x, n - x, true, x));
		}

		private long Count(long curr, long step, bool isEven, long currCount)
		{
			if (isEven) {
				if (curr % step == 0)
					return currCount + (2 * (curr / step)) * step;
				currCount += (2L * (curr / step) + 1L) * step;

				return Count(step, curr - (curr / step) * step, false, currCount);
			}
			if (curr % step == 0)
				return currCount + (2 * (curr / step) - 1L) * step;

			currCount += (2L * (curr / step)) * step;
			return Count(step, curr - (curr / step) * step, false, currCount);
		}
	}
}

internal class InputReader : IDisposable
{
	private bool isDispose;
	private readonly TextReader sr;

	public InputReader(TextReader stream)
	{
		sr = stream;
	}

	public void Dispose()
	{
		Dispose(true);
		GC.SuppressFinalize(this);
	}

	public string NextString()
	{
		var result = sr.ReadLine();
		return result;
	}

	public int NextInt32()
	{
		return Int32.Parse(NextString());
	}

	public long NextInt64()
	{
		return Int64.Parse(NextString());
	}

	public string[] NextSplitStrings()
	{
		return NextString()
			.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
	}

	public T[] ReadArray<T>(Func<string, CultureInfo, T> func)
	{
		return NextSplitStrings()
			.Select(s => func(s, CultureInfo.InvariantCulture))
			.ToArray();
	}

	public T[] ReadArrayFromString<T>(Func<string, CultureInfo, T> func, string str)
	{
		return
			str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)
				.Select(s => func(s, CultureInfo.InvariantCulture))
				.ToArray();
	}

	protected void Dispose(bool dispose)
	{
		if (!isDispose) {
			if (dispose)
				sr.Close();
			isDispose = true;
		}
	}

	~InputReader()
	{
		Dispose(false);
	}
}