using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace task3
{
	class Program
	{
		static void Main(string[] args)
		{
			var splitters = new char[] { ' ', '\t' };
			TextReader reader = null;
			TextWriter writer = null;
			try
			{
				reader = new StreamReader(args[0], Encoding.ASCII);
				writer = new StreamWriter(args[0] + ".out", false, Encoding.ASCII);
				var cases = int.Parse(reader.ReadLine());
				Console.WriteLine("Number of cases {0}", cases);
				for (var k = 1; k <= cases; ++k)
				{
					solved = new Dictionary<SolutionInfo, int>();
					var vars = reader.ReadLine().Split(splitters);
					var p = int.Parse(vars[0]);
					var q = int.Parse(vars[1]);
					var prisoners = new int[q];
					vars = reader.ReadLine().Split(splitters);
					for (var i = 0; i < q; ++i)
					{
						prisoners[i] = int.Parse(vars[i]) - 1;
					}
					var res = Solve(prisoners, 0, q - 1, 0, p - 1);
					var result = String.Format(CultureInfo.InvariantCulture,"Case #{0}: {1}", k, res);
					Console.WriteLine(result);
					writer.WriteLine(result);
				}
			}
			finally
			{
				if (writer != null)
					writer.Close();
				if (reader != null)
					reader.Close();
			}
		}

		private static int Solve(int[] prisoners, int prisonersFrom, int prisonersTo, int cellsFrom, int cellsTo)
		{
			var key = new SolutionInfo();
			key.prisoners = new int[prisonersTo - prisonersFrom + 1];
			Array.Copy(prisoners, prisonersFrom, key.prisoners, 0, prisonersTo - prisonersFrom + 1);
			key.cellsFrom = cellsFrom;
			key.cellsTo = cellsTo;
			var result = 0;
			if (solved.TryGetValue(key, out result))
				return result;
			result = int.MaxValue;
			for (var i = prisonersFrom; i <= prisonersTo; ++i)
			{
				var temp = 0;
				var freeNum = prisoners[i];
				if (i > prisonersFrom)
				{
					temp += Solve(prisoners, prisonersFrom, i - 1, cellsFrom, freeNum - 1);
				}
				if (i < prisonersTo)
				{
					temp += Solve(prisoners, i + 1, prisonersTo, freeNum + 1, cellsTo);
				}
				if (temp < result)
					result = temp;
			}
			result += cellsTo - cellsFrom;
			solved.Add(key, result);
			return result;
		}

		private static Dictionary<SolutionInfo, int> solved;
	}

	class SolutionInfo : IEqualityComparer<SolutionInfo>
	{
		public int[] prisoners;
		public int cellsFrom;
		public int cellsTo;

		public override bool Equals(object obj)
		{
			var other = obj as SolutionInfo;
			if (ReferenceEquals(other, null))
				return false;
			return Equals(other);
		}

		public bool Equals(SolutionInfo other)
		{
			if (other.cellsFrom != cellsFrom || other.cellsTo != cellsTo
				|| other.prisoners.Length != prisoners.Length)
				return false;
			for (var i = 0; i < prisoners.Length; ++i)
			{
				if (other.prisoners[i] != prisoners[i])
					return false;
			}
			return true;
		}

		public int GetHashCode(SolutionInfo info)
		{
			return info.GetHashCode();
		}

		public bool Equals(SolutionInfo lhs, SolutionInfo rhs)
		{
			if (ReferenceEquals(lhs, null))
				return ReferenceEquals(rhs, null);
			return lhs.Equals(rhs);
		}

		public override int GetHashCode()
		{
			var hash = (cellsTo << 24) ^ (cellsFrom << 16) ^ prisoners.Length;
			foreach (var val in prisoners)
			{
				hash <<= 2;
				hash ^= val;
			}
			return hash;
		}
	}
}
