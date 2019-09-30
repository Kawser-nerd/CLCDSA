using System;
using System.Collections.Generic;

public class A
{
	private class Range : IComparable<Range>
	{
		public int Min { get; private set; }
		public int Max { get; private set; }

		private Range(int min, int max)
		{
			Min = min;
			Max = max;
		}
		
		public override string ToString()
		{
			return string.Format("[{0}, {1}]", Min, Max);
		}

		public static Range For(int target, int value)
		{
			int max = (value * 10) / (target * 9);
			int min = (value * 10) / (target * 11);

			if (value * 10 != min * (target * 11))
			{
				min++;
			}

			if (max < min)
			{
				return null;
			}
			else
			{
				return new Range(min, max);
			}
		}

		public int CompareTo(Range other)
		{
			if (Min < other.Min || Min == other.Min && Max < other.Max)
			{
				return -1;
			}
			else if (Min == other.Min && Max == other.Max)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
	}

	private static void PrintRanges(Queue<Range>[] ranges)
	{
		Console.Write('\n');

		for (var i = 0; i < ranges.Length; i++)
		{
			foreach (var range in ranges[i])
			{
				Console.Write("{0} ", range);
			}

			Console.Write('\n');
		}

		Console.Write('\n');
	}

	private static int Solve(Queue<Range>[] ranges)
	{
//		PrintRanges(ranges);

		var kits = 0;

		// on every loop we should see if we can use the packet at
		// the start of each queue; otherwise, pop the smallest

		while (true)
		{
			var greatestMin = 0;
			var leastMax = int.MaxValue;

			foreach (var queue in ranges)
			{
				if (queue.Count == 0)
				{
					return kits;
				}

				var range = queue.Peek();

				if (range.Min > greatestMin)
				{
					greatestMin = range.Min;
				}

				if (range.Max < leastMax)
				{
					leastMax = range.Max;
				}
			}

			if (greatestMin <= leastMax)
			{
				// we can use all these in a kit

				kits++;

				foreach (var queue in ranges)
				{
					queue.Dequeue();
				}
			}
			else
			{
				// toss all kits whose max is smaller than the
				// greatest min

				foreach (var queue in ranges)
				{
					var range = queue.Peek();

					if (range.Max < greatestMin)
					{
						queue.Dequeue();
					}
				}
			}
		}
	}

	public static void Main(string[] args)
	{		
		var T = int.Parse(Console.ReadLine());

		for (var Q = 1; Q <= T; Q++)
		{
			var words = Console.ReadLine().Split(' ');

			var N = int.Parse(words[0]);
			var P = int.Parse(words[1]);

			var ranges = new Queue<Range>[N];

			var targetStrs = Console.ReadLine().Split(' ');

			for (var i = 0; i < N; i++)
			{
				var target = int.Parse(targetStrs[i]);
				var rangeList = new List<Range>();

				var packValueStrs = Console.ReadLine().Split(' ');

				for (var j = 0; j < P; j++)
				{
					var packValue = int.Parse(packValueStrs[j]);

					var range = Range.For(target, packValue);

					if (range != null)
					{
						rangeList.Add(range);
					}
				}

				rangeList.Sort();
				ranges[i] = new Queue<Range>(rangeList);
			}

			Console.Write("Case #{0}: {1}\n", Q, Solve(ranges));
		}
	}
}