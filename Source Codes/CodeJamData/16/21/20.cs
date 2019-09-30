using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using NUnit.Framework;

namespace task1
{
	[TestFixture]
	public class Program
	{
		static void Main(string[] args)
		{
			using (var reader = new StreamReader(args[0], Encoding.ASCII))
			using (var writer = new StreamWriter(args[0] + ".out", false, Encoding.ASCII))
			{
				var cases = int.Parse(reader.ReadLine());
				Console.WriteLine("Cases {0}", cases);
				for (var i = 1; i <= cases; ++i)
				{
					var s = reader.ReadLine();
					writer.WriteLine(string.Format(CultureInfo.InvariantCulture, "Case #{0}: {1}", i
						, Solve(s)));
				}
			}
		}

		private static string Solve(string s)
		{
			var d = s.ToCharArray().GroupBy(_ => _).ToDictionary(_ => _.Key, _ => _.Count());
			var result = new List<int>();
			while (d.ContainsKey('Z')) //ZERO
			{
				result.Add(0);
				Remove(d, "ZERO");
			}
			while (d.ContainsKey('W')) //TWO
			{
				result.Add(2);
				Remove(d, "TWO");
			}
			while (d.ContainsKey('U')) //FOUR
			{
				result.Add(4);
				Remove(d, "FOUR");
			}
			while (d.ContainsKey('X')) //SIX
			{
				result.Add(6);
				Remove(d, "SIX");
			}
			while (d.ContainsKey('R')) //THREE
			{
				result.Add(3);
				Remove(d, "THREE");
			}
			while (d.ContainsKey('S')) //SEVEN
			{
				result.Add(7);
				Remove(d, "SEVEN");
			}
			while (d.ContainsKey('V')) //FIVE
			{
				result.Add(5);
				Remove(d, "FIVE");
			}
			while (d.ContainsKey('H')) //EIGHT
			{
				result.Add(8);
				Remove(d, "EIGHT");
			}
			while (d.ContainsKey('I')) //NINE
			{
				result.Add(9);
				Remove(d, "NINE");
			}
			while (d.ContainsKey('N')) //ONE
			{
				result.Add(1);
				Remove(d, "ONE");
			}
			result.Sort();
			return string.Join("", result);
		}

		private static void Remove(IDictionary<char, int> d, string digit)
		{
			foreach (var c in digit)
			{
				var v = d[c] - 1;
				if (v > 0)
				{
					d[c] = v;
				}
				else
				{
					Debug.Assert(v == 0);
					d.Remove(c);
				}
			}
		}

		[Test]
		[TestCase("OZONETOWER", ExpectedResult = "012")]
		[TestCase("WEIGHFOXTOURIST", ExpectedResult = "2468")]
		[TestCase("OURNEONFOE", ExpectedResult = "114")]
		[TestCase("ETHER", ExpectedResult = "3")]
		public string Test(string s)
		{
			return Solve(s);
		}
	}
}
