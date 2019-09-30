using System;
using System.Collections.Generic;

namespace C
{
	class Program
	{
		static void Main(string[] args)
		{
			var N = int.Parse(Console.ReadLine());
			var A = new List<int>();
			
			var line = Console.ReadLine();
			var lineSplited = line.Split(new char[] {' '}, StringSplitOptions.RemoveEmptyEntries);
			foreach (var token in lineSplited) {
				A.Add(int.Parse(token));
			}

			var cost = new Cost(N, A);
			Console.WriteLine(cost.getCost(N - 1));
		}

		class Cost
		{
			private List<int> _costs;
			private List<int> _lens;

			public Cost(int N, List<int> lens)
			{
				_costs = new List<int>();
				for (int i = 0; i < N; i++) _costs.Add(int.MaxValue);

				_lens = lens;
			}

			public int getCost(int i)
			{
				if (_costs[i] < int.MaxValue) return _costs[i];

				if (i == 0) return _costs[0] = 0;
				else if (i == 1)
					return _costs[i] = getCost(i - 1) + Math.Abs(_lens[i] - _lens[i - 1]);
				else {
					int cost1 = getCost(i - 1) + Math.Abs(_lens[i] - _lens[i - 1]);
					int cost2 = getCost(i - 2) + Math.Abs(_lens[i] - _lens[i - 2]);
					return _costs[i] = cost1 < cost2 ? cost1 : cost2;
				}
			}
		}
	}
}