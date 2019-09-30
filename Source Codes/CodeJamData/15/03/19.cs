using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ProblemC
{
	class Program
	{
		static void Main(string[] args)
		{
			Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

			var t = int.Parse(Console.ReadLine());
			for (var caseNumber = 1; caseNumber <= t; caseNumber++)
			{
				var numberStrings = Console.ReadLine().Split(' ');
				var chunkLength = int.Parse(numberStrings[0]);
				var repeatCount = long.Parse(numberStrings[1]);
				var chunk = Console.ReadLine();
				var chunkQuaternions = chunk.Select(character => new Quaternion(character)).ToList();
				var chunkEquivalent = chunkQuaternions.Aggregate(
					new Quaternion(false, QuaternionDigit.One),
					(accumulator, item) => accumulator * item);
				var possibleTwoSplits = GetPossibleTwoSplits(chunkQuaternions, chunkEquivalent);
				var possibleThreeSplits = GetPossibleThreeSplits3(chunkQuaternions, chunkEquivalent);

				var result = CanBeIJKViaThreeSplit(possibleThreeSplits, chunkEquivalent, repeatCount) ||
					CanBeIJKViaTwoSplit(possibleTwoSplits, chunkEquivalent, repeatCount);
				Console.WriteLine("Case #{0}: {1}", caseNumber, result ? "YES" : "NO");
			}
		}

		static HashSet<Tuple<Quaternion, Quaternion>> GetPossibleTwoSplits(List<Quaternion> chunk, Quaternion chunkEquivalent)
		{
			var result = new HashSet<Tuple<Quaternion, Quaternion>>();
			var startEquivalent = new Quaternion(false, QuaternionDigit.One);
			var endEquivalent = chunkEquivalent;
			result.Add(Tuple.Create(startEquivalent, endEquivalent));
			for (var splitIndex = 1; splitIndex <= chunk.Count; splitIndex++)
			{
				var itemBeforeSplit = chunk[splitIndex - 1];
				startEquivalent = startEquivalent * itemBeforeSplit;
				endEquivalent = Quaternion.GetSecondMultiplier(endEquivalent, itemBeforeSplit);
				result.Add(Tuple.Create(startEquivalent, endEquivalent));
			}
			return result;
		}

		static HashSet<Tuple<Quaternion, Quaternion>> GetPossibleThreeSplits(List<Quaternion> chunk, Quaternion chunkEquivalent)
		{
			var result = new HashSet<Tuple<Quaternion, Quaternion>>();
			var startEquivalent = new Quaternion(false, QuaternionDigit.One);
			var afterStartEquivalent = chunkEquivalent;
			for (var split1Index = 1; split1Index <= chunk.Count; split1Index++)
			{
				var itemBeforeSplit1 = chunk[split1Index - 1];
				startEquivalent = startEquivalent * itemBeforeSplit1;
				afterStartEquivalent = Quaternion.GetSecondMultiplier(afterStartEquivalent, itemBeforeSplit1);

				var midEquivalent = new Quaternion(false, QuaternionDigit.One);
				var endEquivalent = afterStartEquivalent;
				for (var split2Index = split1Index + 1; split2Index <= chunk.Count; split2Index++)
				{
					var itemBeforeSplit2 = chunk[split2Index - 1];
					midEquivalent = midEquivalent * itemBeforeSplit2;
					endEquivalent = Quaternion.GetSecondMultiplier(endEquivalent, itemBeforeSplit2);

					if (midEquivalent == new Quaternion(false, QuaternionDigit.J))
						result.Add(Tuple.Create(startEquivalent, endEquivalent));
				}
			}
			return result;
		}

		static HashSet<Tuple<Quaternion, Quaternion>> GetPossibleThreeSplits2(List<Quaternion> chunk, Quaternion chunkEquivalent)
		{
			var result = new HashSet<Tuple<Quaternion, Quaternion>>();

			var starts = new List<Quaternion>(chunk.Count + 1);
			var startEquivalent = new Quaternion('1');
			starts.Add(startEquivalent);
			for (var splitIndex = 1; splitIndex <= chunk.Count; splitIndex++)
			{
				startEquivalent = startEquivalent * chunk[splitIndex - 1];
				starts.Add(startEquivalent);
			}

			var ends = new List<Quaternion>(chunk.Count + 1);
			var endEquivalent = new Quaternion('1');
			ends.Add(endEquivalent);
			for (var splitIndex = chunk.Count - 1; splitIndex >= 0; splitIndex--)
			{
				endEquivalent = chunk[splitIndex] * endEquivalent;
				ends.Add(endEquivalent);
			}

			for (var startIndex = 0; startIndex <= chunk.Count; startIndex++)
				for (var endIndex = 0; endIndex <= chunk.Count - startIndex; endIndex++)
					if (Quaternion.GetSecondMultiplier(
						Quaternion.GetFirstMultiplier(chunkEquivalent, ends[endIndex]), 
						starts[startIndex]) == new Quaternion('j'))
						result.Add(Tuple.Create(starts[startIndex], ends[endIndex]));

			return result;
		}

		static HashSet<Tuple<Quaternion, Quaternion>> GetPossibleThreeSplits3(List<Quaternion> chunk, Quaternion chunkEquivalent)
		{
			var result = new HashSet<Tuple<Quaternion, Quaternion>>();

			var starts = new Dictionary<Quaternion, int>();
			var startEquivalent = new Quaternion('1');
			starts.Add(startEquivalent, 0);
			for (var splitIndex = 1; splitIndex <= chunk.Count; splitIndex++)
			{
				startEquivalent = startEquivalent * chunk[splitIndex - 1];
				if (!starts.ContainsKey(startEquivalent))
					starts.Add(startEquivalent, splitIndex);
			}

			var ends = new Dictionary<Quaternion, int>();
			var endEquivalent = new Quaternion('1');
			ends.Add(endEquivalent, 0);
			for (var splitIndex = chunk.Count - 1; splitIndex >= 0; splitIndex--)
			{
				endEquivalent = chunk[splitIndex] * endEquivalent;
				if (!ends.ContainsKey(endEquivalent))
					ends.Add(endEquivalent, chunk.Count - splitIndex);
			}

			foreach (var start in starts.Keys)
				foreach (var end in ends.Keys)
					if ((starts[start] + ends[end] < chunk.Count) &&
						(Quaternion.GetSecondMultiplier(
							Quaternion.GetFirstMultiplier(chunkEquivalent, end),
							start) == new Quaternion('j')))
						result.Add(Tuple.Create(start, end));

			return result;
		}

		static bool CanBeIJKViaThreeSplit(
			HashSet<Tuple<Quaternion, Quaternion>> possibleThreeSplits, 
			Quaternion chunkEquivalent,
			long repeatCount)
		{
			foreach (var threeSplit in possibleThreeSplits)
			{
				var startOffsets = new List<int>();
				var startMultiplier = new Quaternion('1');
				for (var startOffset = 0; startOffset < 32; startOffset++)
				{
					if (startMultiplier * threeSplit.Item1 == new Quaternion('i'))
						startOffsets.Add(startOffset);
					startMultiplier = startMultiplier * chunkEquivalent;
				}

				var endOffsets = new List<int>();
				var endMultilier = new Quaternion('1');
				for (var endOffset = 0; endOffset < 32; endOffset++)
				{
					if (threeSplit.Item2 * endMultilier == new Quaternion('k'))
						endOffsets.Add(endOffset);
					endMultilier = chunkEquivalent * endMultilier;
				}

				foreach (var startOffset in startOffsets)
					foreach (var endOffset in endOffsets)
						if ((startOffset + endOffset + 1 <= repeatCount) &&
							(((startOffset + endOffset + 1) % 32) == (repeatCount % 32)))
							return true;
			}

			return false;
		}

		static bool CanBeIJKViaTwoSplit(
			HashSet<Tuple<Quaternion, Quaternion>> possibleTwoSplits,
			Quaternion chunkEquivalent,
			long repeatCount)
		{
			foreach (var twoSplit1 in possibleTwoSplits)
			{
				foreach (var twoSplit2 in possibleTwoSplits)
				{
					var startOffsets = new List<int>();
					var startMultiplier = new Quaternion('1');
					for (var startOffset = 0; startOffset < 32; startOffset++)
					{
						if (startMultiplier * twoSplit1.Item1 == new Quaternion('i'))
							startOffsets.Add(startOffset);
						startMultiplier = startMultiplier * chunkEquivalent;
					}

					var middleOffsets = new List<int>();
					var middleMultiplier = twoSplit1.Item2;
					for (var middleOffset = 0; middleOffset < 32; middleOffset++)
					{
						if (middleMultiplier * twoSplit2.Item1 == new Quaternion('j'))
							middleOffsets.Add(middleOffset);
						middleMultiplier = middleMultiplier * chunkEquivalent;
					}

					var endOffsets = new List<int>();
					var endMultilier = new Quaternion('1');
					for (var endOffset = 0; endOffset < 32; endOffset++)
					{
						if (twoSplit2.Item2 * endMultilier == new Quaternion('k'))
							endOffsets.Add(endOffset);
						endMultilier = chunkEquivalent * endMultilier;
					}

					foreach (var startOffset in startOffsets)
						foreach (var middleOffset in middleOffsets)
							foreach (var endOffset in endOffsets)
								if ((startOffset + middleOffset + endOffset + 2 <= repeatCount) &&
									(((startOffset + middleOffset + endOffset + 2) % 32) == (repeatCount % 32)))
									return true;
				}
			}

			return false;
		}
	}

	enum QuaternionDigit
	{
		One,
		I,
		J,
		K
	}

	struct Quaternion : IEquatable<Quaternion>
	{
		public static bool operator ==(Quaternion x, Quaternion y)
		{
			return x.Equals(y);
		}

		public static bool operator !=(Quaternion x, Quaternion y)
		{
			return !x.Equals(y);
		}

		public static Quaternion operator *(Quaternion x, Quaternion y)
		{
			Quaternion resultForPositive;
			switch (x.Digit)
			{
				case QuaternionDigit.One:
					switch (y.Digit)
					{
						case QuaternionDigit.One:
							resultForPositive = new Quaternion(false, QuaternionDigit.One);
							break;

						case QuaternionDigit.I:
							resultForPositive = new Quaternion(false, QuaternionDigit.I);
							break;

						case QuaternionDigit.J:
							resultForPositive = new Quaternion(false, QuaternionDigit.J);
							break;

						case QuaternionDigit.K:
							resultForPositive = new Quaternion(false, QuaternionDigit.K);
							break;

						default:
							throw new InvalidOperationException();
					}
					break;

				case QuaternionDigit.I:
					switch (y.Digit)
					{
						case QuaternionDigit.One:
							resultForPositive = new Quaternion(false, QuaternionDigit.I);
							break;

						case QuaternionDigit.I:
							resultForPositive = new Quaternion(true, QuaternionDigit.One);
							break;

						case QuaternionDigit.J:
							resultForPositive = new Quaternion(false, QuaternionDigit.K);
							break;

						case QuaternionDigit.K:
							resultForPositive = new Quaternion(true, QuaternionDigit.J);
							break;

						default:
							throw new InvalidOperationException();
					}
					break;

				case QuaternionDigit.J:
					switch (y.Digit)
					{
						case QuaternionDigit.One:
							resultForPositive = new Quaternion(false, QuaternionDigit.J);
							break;

						case QuaternionDigit.I:
							resultForPositive = new Quaternion(true, QuaternionDigit.K);
							break;

						case QuaternionDigit.J:
							resultForPositive = new Quaternion(true, QuaternionDigit.One);
							break;

						case QuaternionDigit.K:
							resultForPositive = new Quaternion(false, QuaternionDigit.I);
							break;

						default:
							throw new InvalidOperationException();
					}
					break;

				case QuaternionDigit.K:
					switch (y.Digit)
					{
						case QuaternionDigit.One:
							resultForPositive = new Quaternion(false, QuaternionDigit.K);
							break;

						case QuaternionDigit.I:
							resultForPositive = new Quaternion(false, QuaternionDigit.J);
							break;

						case QuaternionDigit.J:
							resultForPositive = new Quaternion(true, QuaternionDigit.I);
							break;

						case QuaternionDigit.K:
							resultForPositive = new Quaternion(true, QuaternionDigit.One);
							break;

						default:
							throw new InvalidOperationException();
					}
					break;

				default:
					throw new InvalidOperationException();
			}
			return x.IsNegative == y.IsNegative ? resultForPositive : -resultForPositive;
		}

		public static Quaternion operator -(Quaternion x)
		{
			return new Quaternion(!x.IsNegative, x.Digit);
		}

		public static Quaternion GetSecondMultiplier(Quaternion result, Quaternion firstMultiplier)
		{
			foreach (var digit in new[]
			{
				QuaternionDigit.One, 
				QuaternionDigit.I, 
				QuaternionDigit.J, 
				QuaternionDigit.K
			})
			{
				var positiveSecondMultiplier = new Quaternion(false, digit);
				if (firstMultiplier * positiveSecondMultiplier == result)
					return positiveSecondMultiplier;
				if (firstMultiplier * -positiveSecondMultiplier == result)
					return -positiveSecondMultiplier;
			}

			throw new InvalidOperationException();
		}

		public static Quaternion GetFirstMultiplier(Quaternion result, Quaternion secondMultiplier)
		{
			foreach (var digit in new[]
			{
				QuaternionDigit.One, 
				QuaternionDigit.I, 
				QuaternionDigit.J, 
				QuaternionDigit.K
			})
			{
				var positiveFirstMultiplier = new Quaternion(false, digit);
				if (positiveFirstMultiplier * secondMultiplier == result)
					return positiveFirstMultiplier;
				if (-positiveFirstMultiplier * secondMultiplier == result)
					return -positiveFirstMultiplier;
			}

			throw new InvalidOperationException();
		}


		public Quaternion(bool isNegative, QuaternionDigit digit)
			: this()
		{
			IsNegative = isNegative;
			Digit = digit;
		}

		public Quaternion(char character)
			: this()
		{
			IsNegative = false;
			switch (character)
			{
				case '1':
					Digit = QuaternionDigit.One;
					break;

				case 'i':
					Digit = QuaternionDigit.I;
					break;

				case 'j':
					Digit = QuaternionDigit.J;
					break;

				case 'k':
					Digit = QuaternionDigit.K;
					break;

				default:
					throw new ArgumentException();
			}
		}


		public bool IsNegative { get; private set; }
		public QuaternionDigit Digit { get; private set; }


		public bool Equals(Quaternion other)
		{
			return (IsNegative == other.IsNegative) && (Digit == other.Digit);
		}

		public override bool Equals(object obj)
		{
			return (obj is Quaternion) && Equals((Quaternion)obj);
		}

		public override int GetHashCode()
		{
			return IsNegative.GetHashCode() ^ Digit.GetHashCode();
		}

		public override string ToString()
		{
			switch (Digit)
			{
				case QuaternionDigit.One:
					return IsNegative ? "-1" : "1";

				case QuaternionDigit.I:
					return IsNegative ? "-i" : "i";

				case QuaternionDigit.J:
					return IsNegative ? "-j" : "j";

				case QuaternionDigit.K:
					return IsNegative ? "-k" : "k";

				default:
					throw new InvalidOperationException();
			}
		}
	}
}
