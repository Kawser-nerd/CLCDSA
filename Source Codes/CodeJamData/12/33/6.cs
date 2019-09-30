using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _1CC
{
	internal class Program
	{
		private struct Range
		{
			public long Count;
			public long Type;
		}

		private static List<Range> As, Bs;

		private struct Position
		{
			public int aI, bI;
			public long aPartial, bPartial;
		}

		private static long PositionPrice(Position position)
		{
			var result = 0L;
			if (position.aI >= As.Count || position.bI >= Bs.Count)
				return result;

			if (As[position.aI].Type == Bs[position.bI].Type)
			{
				var aDelta = As[position.aI].Count - position.aPartial;
				var bDelta = Bs[position.bI].Count - position.bPartial;
				if (aDelta < bDelta)
					return aDelta + PositionPrice(new Position { aI = position.aI + 1, bI = position.bI, aPartial = 0L, bPartial = position.bPartial + aDelta });
				else
					return bDelta + PositionPrice(new Position { aI = position.aI, bI = position.bI + 1, aPartial = position.aPartial + bDelta, bPartial = 0L });
			}

			var useA = false;
			for (var i = position.bI + 1; i < Bs.Count; i++)
			{
				if (Bs[i].Type == As[position.aI].Type)
				{
					useA = true;
					break;
				}
			}
			if (!useA)
				return PositionPrice(new Position { aI = position.aI + 1, bI = position.bI, aPartial = 0L, bPartial = position.bPartial });

			var useB = false;
			for (var i = position.aI + 1; i < As.Count; i++)
			{
				if (As[i].Type == Bs[position.bI].Type)
				{
					useB = true;
					break;
				}
			}
			if (!useB)
				return PositionPrice(new Position { aI = position.aI, bI = position.bI + 1, aPartial = position.aPartial, bPartial = 0L });

			result = Math.Max(result, PositionPrice(new Position { aI = position.aI, bI = position.bI + 1, aPartial = position.aPartial, bPartial = 0L }));
			result = Math.Max(result, PositionPrice(new Position { aI = position.aI + 1, bI = position.bI, aPartial = 0L, bPartial = position.bPartial }));
			return result;
		}

		private static void Main(string[] args)
		{
			var line = Console.ReadLine();
			var testCount = int.Parse(line);
			for (var testNumber = 1; testNumber <= testCount; testNumber++)
			{
				var elements = Console.ReadLine().Split();
				var N = int.Parse(elements[0]);
				var M = int.Parse(elements[1]);

				As = new List<Range>(N);
				elements = Console.ReadLine().Split();
				for (var i = 0; i < N; i++)
					As.Add(new Range {Count = long.Parse(elements[i*2]), Type = long.Parse(elements[i*2 + 1])});

				Bs = new List<Range>(M);
				elements = Console.ReadLine().Split();
				for (var i = 0; i < M; i++)
					Bs.Add(new Range {Count = long.Parse(elements[i*2]), Type = long.Parse(elements[i*2 + 1])});

				Console.WriteLine("Case #{0}: {1}", testNumber, PositionPrice(new Position()));
			}
		}
	}
}
