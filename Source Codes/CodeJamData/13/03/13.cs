using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;

namespace RAVE
{
	class TestCase
	{
		// Little John likes palindromes, and thinks them to be fair (which is a fancy word for nice).
		// A palindrome is just a number that reads the same backwards and forwards - so 6, 11 and 121 are all palindromes,
		// while 10, 12, 223 and 2244 are not (even though 010=10, we don't consider leading zeroes when determining whether
		// a number is a palindrome).

		// He recently became interested in squares as well, and formed the definition of a fair and square number
		// - it is a number that is a palindrome and the square of a palindrome at the same time.
		// For instance, 1, 9 and 121 are fair and square (being palindromes and squares, respectively, of 1, 3 and 11),
		// while 16, 22 and 676 are not fair and square: 16 is not a palindrome, 22 is not a square, and while 676 is a
		// palindrome and a square number, it is the square of 26, which is not a palindrome.

		// Now he wants to search for bigger fair and square numbers.
		// Your task is, given an interval Little John is searching through, to tell him how many fair and square numbers
		// are there in the interval, so he knows when he has found them all.

		// Usually, Google Code Jam problems have 1 Small input and 1 Large input.
		// This problem has 1 Small input and 2 Large inputs.
		// Once you have solved the Small input, you will be able to download any of the two Large inputs.
		// As usual, you will be able to retry the Small input (with a time penalty), while you will get only one chance
		// at each of the Large inputs.

		// Each test case contains two numbers, A and B - the endpoints of the interval Little John is looking at.

		// 100|10000|1000 test cases.
		BigInteger A, B; // 1 ≤ A ≤ B ≤ 1000|10^14|10^100

//		static BigInteger[] FairAndSquare = GetPalindromes().Select(p => p * p).Where(p => IsPalindrome(p)).ToArray();
		static BigInteger[] FairAndSquare = GetFairAndSquareRoots().Select(BigInteger.Parse).Select(p => p * p).ToArray();

//		static long[] Roots = GetPalindromes().Where(p => IsPalindrome(p * p)).ToArray();

		//private static IEnumerable<BigInteger> GetPalindromes()
		//{
		//   return Enumerable.Range(1, 4).SelectMany(i => GetPalindromes(i, i - 1).Concat(GetPalindromes(i, i)));
		//}

		//private static IEnumerable<BigInteger> GetPalindromes(int digits, int mirrored)
		//{
		//   Console.Error.WriteLine("{0} digits, {1} mirrored", digits, mirrored);
		//   BigInteger begin = BigInteger.Pow(10, digits - 1);
		//   BigInteger end = begin * 10;
		//   for (BigInteger i = begin; i != end; ++i)
		//      yield return Mirror(i, mirrored);
		//}

		//private static BigInteger Mirror(BigInteger i, int mirrored)
		//{
		//   var s = i.ToString();
		//   return BigInteger.Parse(new string(Enumerable.Concat(s, s.Take(mirrored).Reverse()).ToArray()));
		//}

		//private static bool IsPalindrome(BigInteger p)
		//{
		//   var s = p.ToString();
		//   int h = (s.Length) / 2;
		//   return s.Take(h).SequenceEqual(s.Reverse().Take(h));
		//}

		public TestCase(TextReader input)
		{
			var x = input.ReadBigIntegers();
			A = x[0]; B = x[1];
		}

		public BigInteger GetResult()
		{
			//foreach (var s in GetFairAndSquareRoots())
			//   Console.Error.WriteLine(s);
			//foreach (var p in Enumerable.Range(1, 25).SelectMany(i => GetPalindromes(i, i - 1).Concat(GetPalindromes(i, i))))
			//   if (IsPalindrome(p * p))
			//   {
			//      var s = p.ToString();
			//      Console.Error.WriteLine("{0}\t{1}\t{2}", s.Substring(0, (s.Length + 1) / 2), s, p * p);

			//   }

			// Return the number of fair and square numbers greater or equal to A and smaller or equal than B.
			return FairAndSquare.Count(f => A <= f && f <= B);
		}

		static IEnumerable<string> GetFairAndSquareRoots()
		{
			// oddSequences[D in 1..25, M in 0..9] are the D-digit sequences d[1] d[2] ... d[D] such that
			//   2 * (d[1]^2 + d[2]^2 + ... + d[D-1]^2) + d[D]^2 <= M
			string[,][] oddSequences = new string[26, 10][];
			for (int d = 1; d != 26; ++d)
				for (int m = 0; m != 10; ++m)
					oddSequences[d, m] = d == 1
						? Enumerable.Range(0, 4).Where(digit => digit * digit <= m).Select(digit => digit.ToString()).ToArray()
						: Enumerable.Range(0, 3).Where(digit => 2 * digit * digit <= m).SelectMany(digit => oddSequences[d - 1, m - 2 * digit * digit].Select(s => digit.ToString() + s)).ToArray();

			// evenSequences[D in 1..25, M in 0..9] are the D-digit sequences d[1], d[2], ... d[D] such that 
			//   2 * (d[1]^2 + d[2]^2 + ... + d[D]^2) <= M
			string[,][] evenSequences = new string[26, 10][];
			for (int d = 1; d != 26; ++d)
				for (int m = 0; m != 10; ++m)
					evenSequences[d, m] = d == 1
						? Enumerable.Range(0, 3).Where(digit => 2 * digit * digit <= m).Select(digit => digit.ToString()).ToArray()
						: Enumerable.Range(0, 3).Where(digit => 2 * digit * digit <= m).SelectMany(digit => evenSequences[d - 1, m - 2 * digit * digit].Select(s => digit.ToString() + s)).ToArray();

			return Enumerable.Range(1, 25).SelectMany(d => oddSequences[d, 9].Where(s => s[0] != '0').Select(s => s + new string(s.Reverse().Skip(1).ToArray()))
				.Concat(evenSequences[d, 9].Where(s => s[0] != '0').Select(s => s + new string(s.Reverse().ToArray()))));
		}
	}
}