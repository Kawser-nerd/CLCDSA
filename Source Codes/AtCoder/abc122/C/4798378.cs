using System;
using System.Collections.Generic;
using System.Linq;

namespace C
{
	class Program
	{
		static void Main()
		{
			var line = Console.ReadLine();
			var lineSplited = line.Split(new char[] {' '}, StringSplitOptions.RemoveEmptyEntries);

			var N = int.Parse(lineSplited[0]);
			var Q = int.Parse(lineSplited[1]);

			var S = Console.ReadLine().ToList();

			var L = new List<int>();
			var R = new List<int>();
			for (int i = 0; i < Q; i++) {
				var line2 = Console.ReadLine();
				var lineSplited2 = line2.Split(new char[] {' '}, StringSplitOptions.RemoveEmptyEntries);

				L.Add(int.Parse(lineSplited2[0]) - 1);
				R.Add(int.Parse(lineSplited2[1]) - 1);
			}

			var acTable = new List<int>();
			acTable.Add(0);
			
			var count = 0;
			for (int i = 1; i < N; i++) {
				if (S[i - 1] == 'A' && S[i] == 'C') {
					count++;
				}
				acTable.Add(count);
			}

			for (int i = 0; i < Q; i++) {
				Console.WriteLine(acTable[R[i]] - acTable[L[i]]);
			}
		}
	}
}