using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;

namespace GCJ1B_1
{

	struct Tree
	{

		public Tree(long x, long y)
			: this()
		{
			X = x;
			Y = y;
		}


		public long X { get; private set; }

		public long Y { get; private set; }

	}

	class Problem
	{

		public Problem()
		{
		}


		public int TreeCount { get; set; }

		public int A { get; set; }

		public int B { get; set; }

		public int C { get; set; }

		public int D { get; set; }

		public int X0 { get; set; }

		public int Y0 { get; set; }

		public int M { get; set; }


		public long Solve()
		{
			long[,] treesByModCount = new long[3, 3];

			foreach (var tree in GenerateTrees())
				treesByModCount[tree.X % 3, tree.Y % 3]++;

			long result = 0;

			for (int xMod1 = 0; xMod1 < 3; xMod1++)
				for (int yMod1 = 0; yMod1 < 3; yMod1++)
					for (int xMod2 = 0; xMod2 < 3; xMod2++)
						for (int yMod2 = 0; yMod2 < 3; yMod2++)
							for (int xMod3 = 0; xMod3 < 3; xMod3++)
								for (int yMod3 = 0; yMod3 < 3; yMod3++)
									if (((xMod1 + xMod2 + xMod3) % 3 == 0) && ((yMod1 + yMod2 + yMod3) % 3 == 0))
									{
										long variants1 = treesByModCount[xMod1, yMod1];
										long variants2 = treesByModCount[xMod2, yMod2];
										long variants3 = treesByModCount[xMod3, yMod3];

										if ((xMod2 == xMod1) && (yMod2 == yMod1))
											variants2--;
										if ((xMod3 == xMod1) && (yMod3 == yMod1))
											variants3--;
										if ((xMod3 == xMod2) && (yMod3 == yMod2))
											variants3--;
										
										if ((variants1 > 0) && (variants2 > 0) && (variants3 > 0))
											result += variants1 * variants2 * variants3;
									}

			return result / 6;
		}


		private IEnumerable<Tree> GenerateTrees()
		{
			long x = X0;
			long y = Y0;

			yield return new Tree(x, y);

			for (int i = 1; i < TreeCount; i++)
			{
				x = (A * x + B) % M;
				y = (C * y + D) % M;
				yield return new Tree(x, y);
			}
		}

	}

	class Program
	{
		static void Main(string[] args)
		{
			int testCaseCount = ReadInt32();
			for (int testCaseNumber = 1; testCaseNumber <= testCaseCount; testCaseNumber++)
			{
				var formattedResult = ProcessTestCase();
				Console.WriteLine(string.Format(CultureInfo.InvariantCulture, "Case #{0}: {1}",
					testCaseNumber, formattedResult));
			}
		}

		static string ProcessTestCase()
		{
			var parameters = ReadInt32List();
			var problem = new Problem();
			problem.TreeCount = parameters[0];
			problem.A = parameters[1];
			problem.B = parameters[2];
			problem.C = parameters[3];
			problem.D = parameters[4];
			problem.X0 = parameters[5];
			problem.Y0 = parameters[6];
			problem.M = parameters[7];

			var result = problem.Solve();

			return result.ToString(CultureInfo.InvariantCulture);
		}

		static int ParseInt32(string value)
		{
			return int.Parse(value, CultureInfo.InvariantCulture);
		}

		static int ReadInt32()
		{
			return ParseInt32(Console.ReadLine());
		}

		static int[] ReadInt32List()
		{
			var items = Console.ReadLine().Split(' ');
			return items.Select(item => ParseInt32(item)).ToArray();
		}

	}

}
