using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
	class Program
	{

		static void Main(string[] args)
		{
			var input = @"4
2 2 2
2 1 3
4 4 1
3 2 3";
			//input = GetBigData();

			input = File.ReadAllText("input.txt");

			var outputStr = Solve(Parse(input));

			Console.WriteLine(outputStr);
			File.WriteAllText(GetFileName(), outputStr);

			//Console.ReadLine();
		}

		static string GetBigData()
		{
			var data = GenerateBigData().ToList();
			return data.Count.ToString() + Environment.NewLine + string.Join(Environment.NewLine, data.Select(d => string.Join(" ", d)));
		}
		static IEnumerable<long[]> GenerateBigData()
		{
			for (var i = 1; i <= 6; i++)
			{
				for (var j = 1; j <= 20; j++)
				{
					for (var k = 1; k <= 20; k++)
					{
						yield return new long[] { i, j, k };
					}
				}
			}
		}

		static List<long[]> Parse(string input)
		{
			var parts = input.Split(new char[] { '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries);
			var testCasesStr = long.Parse(parts[0]);
			List<long[]> testCases = new List<long[]>();
			for (var i = 0; i < testCasesStr; i++)
			{
				var testCaseStr = parts[i + 1];
				testCases.Add(testCaseStr.Split(' ').Select(c => long.Parse(c)).ToArray());
			}
			return testCases;
		}

		static string Solve(List<long[]> testCases)
		{
			Init();

			List<string> output = new List<string>();
			for (var i = 0; i < testCases.Count; i++)
			{
				output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(testCases[i])));
			}
			return string.Join(Environment.NewLine, output);
		}

		static List<List<NOmino>> NOminos;
		static void Init()
		{
			NOminos = new List<List<NOmino>>();
			for (var i = 0; i <= 6; i++)
			{
				NOminos.Add(GenerateNOmino(i));
			}
		}

		static Dictionary<string, string> resultCache = new Dictionary<string, string>();
		static string Solve(long[] arr)
		{
			long X = arr[0];
			long R = arr[1];
			long C = arr[2];

			if (X >= 7)
				return "RICHARD";
			//if (X == 1)
			//    return "GABRIEL";

			//if (C < R)
			//{
			//    var t = R;
			//    R = C;
			//    C = t;
			//}

			//string key = string.Join(";", arr);
			//if (resultCache.ContainsKey(key))
			//    return resultCache[key];

			//if (X >= (Math.Min(R, C) * 2 + 1))
			//    return "RICHARD";

			if (((R * C) % X) != 0)
				return "RICHARD";
			if(R > X && C > X)
				return "GABRIEL";

			//if(C < R) {
			//    var t = R;
			//    R = C;
			//    C = t;
			//}

			//if(X == 6 && ((R == 3 && C == 6) || (R == 3 && C == 4)))
			//    return "RICHARD";
			//if(X == 5 && R == 3 && C == 5)
			//    return "RICHARD";
			//if(X == 4 && R == 2 && C == 4)
			//    return "RICHARD";

			var result = SolveInternal(X, R, C);
			//resultCache.Add(key, result);
			return result;
		}
		static string SolveInternal(long x, long r, long c)
		{
			var nos = NOminos[(int)x];
			foreach (var no in nos)
			{
				var results = no.Rotations.Select(nor => TestNor(nor, r, c, x));
				if (results.All(res => res == 0))
					return "RICHARD";
			}
			return "GABRIEL";
		}
		static int TestNor(List<P> nor, long r, long c, long X)
		{
			int maxX = nor.Select(p => p.X).Max();
			int maxY = nor.Select(p => p.Y).Max();

			List<P> allPoints = new List<P>();
			for (var x = 0; x < r; x++)
			{
				for (var y = 0; y < c; y++)
					allPoints.Add(new P(x, y));
			}

			for (var x = 0; x < r - maxX; x++)
			{
				for (var y = 0; y < c - maxY; y++)
				{
					var newNor = nor.Select(p => new P(p.X + x, p.Y + y)).ToList();
					if (TestNorInternal(allPoints, newNor, r, c, X) > 0)
						return 1;
				}
			}

			return 0;
		}
		static int TestNorInternal(List<P> allPoints, List<P> nor, long r, long c, long x)
		{
			var freePoints = allPoints.Except(nor).ToList();
			List<List<P>> groups = new List<List<P>>();
			while (freePoints.Any())
			{
				var first = freePoints.First();
				freePoints.RemoveAt(0);
				var group = new List<P>() { first };
				groups.Add(group);

				var next = first.GetSiblings().Distinct().Intersect(freePoints);
				while (next.Any())
				{
					group.AddRange(next);
					freePoints = freePoints.Except(next).ToList();
					next = next.SelectMany(n => n.GetSiblings()).Distinct().Intersect(freePoints);
				}

				if ((group.Count % x) != 0)
					return 0;
			}
			return 1;
		}

		static List<Tuple<int, int>> GenerateFields(int x)
		{
			List<Tuple<int, int>> result = new List<Tuple<int, int>>();
			for (var r = 1; r <= 20; r++)
			{
				for (var c = r; c <= 20; c++)
				{
					if (x >= (Math.Min(r, c) * 2 + 1))
						continue;
					if (((r * c) % x) != 0)
						continue;

					if (r > (x + 1) || c > (x + 1))
						continue;

					if (r == x && c == x + 1 || c == x && r == x + 1)
						continue;

					var field = new Tuple<int, int>(r, c);
					if (!result.Contains(field))
						result.Add(field);
				}
			}
			return result;
		}

		struct P : IComparable<P>
		{
			public P(int x, int y)
			{
				X = x;
				Y = y;
			}
			public int X;
			public int Y;

			public List<P> GetSiblings()
			{
				return new List<P>()
				{
					new P(X, Y - 1),
					new P(X, Y + 1),
					new P(X - 1, Y),
					new P(X + 1, Y)
				};
			}

			public int CompareTo(P other)
			{
				if (X != other.X)
					return X.CompareTo(other.X);
				return Y.CompareTo(other.Y);
			}
		}
		class NOmino : IEquatable<NOmino>, IEqualityComparer<NOmino>
		{
			public NOmino(List<P> points)
			{
				var l1 = MoveToPositive(points);
				var l2 = MoveToPositive(InverseX(l1));
				var l3 = MoveToPositive(InverseY(l1));
				var l4 = MoveToPositive(InverseXY(l1));
				var l5 = MoveToPositive(SwapXY(l1));
				var l6 = MoveToPositive(InverseX(l5));
				var l7 = MoveToPositive(InverseY(l5));
				var l8 = MoveToPositive(InverseXY(l5));

				Points = l1;
				Rotations = GetRotations(l1, l2, l3, l4, l5, l6, l7, l8);
				Signature = GetSignature(Rotations);
			}

			public List<P> Points { get; set; }
			public List<P>[] Rotations { get; set; }
			public string Signature { get; set; }

			static IEnumerable<P> InverseX(IEnumerable<P> points)
			{
				return points.Select(p => new P(-p.X, p.Y));
			}
			static IEnumerable<P> InverseY(IEnumerable<P> points)
			{
				return points.Select(p => new P(p.X, -p.Y));
			}
			static IEnumerable<P> InverseXY(IEnumerable<P> points)
			{
				return points.Select(p => new P(-p.X, -p.Y));
			}
			static IEnumerable<P> SwapXY(IEnumerable<P> points)
			{
				return points.Select(p => new P(p.Y, p.X));
			}
			static List<P> MoveToPositive(IEnumerable<P> points)
			{
				var minX = points.Select(p => p.X).Min();
				var minY = points.Select(p => p.Y).Min();

				var res = points.Select(p => new P(p.X - minX, p.Y - minY)).ToList();
				res.Sort();
				return res;
			}
			static List<P>[] GetRotations(params List<P>[] allPoints)
			{
				var sigs = allPoints.Select(points => string.Join(";", points.Select(p => p.X + "," + p.Y))).Distinct().ToList();
				return sigs.Select(s => s.Split(';').Select(p => new P(int.Parse(p.Split(',')[0]), int.Parse(p.Split(',')[1]))).ToList()).ToArray();
			}
			static string GetSignature(params List<P>[] allPoints)
			{
				var sigs = allPoints.Select(points => string.Join(";", points.Select(p => p.X + "," + p.Y))).Distinct().ToList();
				sigs.Sort();
				return string.Join("||", sigs);
			}

			public override bool Equals(object obj)
			{
				return Equals((NOmino)obj);
			}
			public bool Equals(NOmino other)
			{
				return Signature == other.Signature;
			}
			public bool Equals(NOmino x, NOmino y)
			{
				return x.Equals(y);
			}
			public override int GetHashCode()
			{
				return Signature.GetHashCode();
			}
			public int GetHashCode(NOmino obj)
			{
				return obj.GetHashCode();
			}
		}

		static List<NOmino> GenerateNOmino(int x)
		{
			if (x <= 0)
				return new List<NOmino>();
			var p = new P(0, 0);
			var eq = new NOmino(new List<P>() { p });
			return GenerateNOmino(x, new P[] { p }, p.GetSiblings()).Select(pl => new NOmino(pl)).Distinct(eq).ToList();
		}
		static IEnumerable<List<P>> GenerateNOmino(int x, IEnumerable<P> points, IEnumerable<P> siblings)
		{
			if (points.Count() == x)
			{
				yield return points.ToList();
			}
			else
			{
				foreach (var s in siblings)
				{
					if (!points.Contains(s))
					{
						foreach (var r in GenerateNOmino(x, points.Union(new P[] { s }), siblings.Union(s.GetSiblings())))
							yield return r;
					}
				}
			}
		}

		static T[] CloneArray<T>(T[] arr)
		{
			T[] result = new T[arr.Length];
			Array.Copy(arr, result, arr.Length);
			return result;
		}
		static string GetFileName()
		{
			return DateTime.Now.Ticks.ToString() + ".txt";
		}
	}
}
