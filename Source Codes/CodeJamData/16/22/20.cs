using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using NUnit.Framework;

namespace task2
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
					var parameters = reader.ReadLine().Split(' ');
					var c = parameters[0];
					var j = parameters[1];
					Solve(ref c,  ref j);
					writer.WriteLine(string.Format(CultureInfo.InvariantCulture, "Case #{0}: {1} {2}", i, c, j));
				}
			}
		}

		private static void Solve(ref string c, ref string j)
		{
			var c1 = c.ToCharArray();
			var j1 = j.ToCharArray();
			Solve(c1, j1, 0, 0);
			c = new string(c1);
			j = new string(j1);
		}

		private static BigInteger Solve(char[] c, char[] j, int offset, BigInteger diff)
		{
			while (offset < c.Length)
			{
				diff *= 10;
				if (diff == 0)
				{
					var cc = c[offset];
					var jc = j[offset];
					if (cc == '?')
					{
						if (jc != '?')
						{
							var v = new[] { (char)(jc - 1), jc, (char)(jc + 1) }.Select(_ => TryVariant(c, j, offset, diff, _, jc))
								.Where(_ => _.Item2 != null).OrderBy(_ => BigInteger.Abs(_.Item1)).First();
							Array.Copy(v.Item2, c, c.Length);
							Array.Copy(v.Item3, j, j.Length);
							return v.Item1;
						}
						else // ? ?
						{
							var v = new List<Tuple<BigInteger, char[], char[]>>
							{
								TryVariant(c, j, offset, diff, '0', '0'),
								TryVariant(c, j, offset, diff, '0', '1'),
								TryVariant(c, j, offset, diff, '1', '0')
							}.Where(_ => _.Item2 != null).OrderBy(_ => BigInteger.Abs(_.Item1)).First();
							Array.Copy(v.Item2, c, c.Length);
							Array.Copy(v.Item3, j, j.Length);
							return v.Item1;
						}
					}
					if (jc == '?')
					{
						var v = new[] { (char)(cc - 1), cc, (char)(cc + 1) }.Select(_ => TryVariant(c, j, offset, diff, cc, _))
							.Where(_ => _.Item2 != null).OrderBy(_ => BigInteger.Abs(_.Item1)).First();
						Array.Copy(v.Item2, c, c.Length);
						Array.Copy(v.Item3, j, j.Length);
						return v.Item1;
					}
					// both normal digits
				}
				else if (diff > 0)
				{
					if (c[offset] == '?')
					{
						c[offset] = '0';
					}
					if (j[offset] == '?')
					{
						j[offset] = '9';
					}
				}
				else // diff < 0
				{
					if (c[offset] == '?')
					{
						c[offset] = '9';
					}
					if (j[offset] == '?')
					{
						j[offset] = '0';
					}
				}
				diff += c[offset] - j[offset];
				++offset;
			}
			return diff;
		}

		private static Tuple<BigInteger, char[], char[]> TryVariant(char[] c, char[] j, int offset, BigInteger diff, char ct, char jt)
		{
			if (ct < '0' || ct > '9' || jt < '0' || jt > '9')
			{
				return Tuple.Create(BigInteger.Zero, (char[])null, (char[])null);
			}
			var c1 = (char[])c.Clone();
			var j1 = (char[])j.Clone();
			c1[offset] = ct;
			j1[offset] = jt;
			return Tuple.Create(Solve(c1, j1, offset + 1, diff + ct - jt), c1, j1);
		}

		[Test]
		[TestCase("1?", "2?", "19", "20")]
		[TestCase("?2?", "??3", "023", "023")]
		[TestCase("?", "?", "0", "0")]
		[TestCase("?5", "?0", "05", "00")]
		public void Test(string c, string j, string ec, string ej)
		{
			Solve(ref c, ref j);
			Assert.That(c, Is.EqualTo(ec));
			Assert.That(j, Is.EqualTo(ej));
		}
	}
}
