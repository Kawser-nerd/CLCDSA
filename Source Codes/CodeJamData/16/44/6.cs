using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.IO;
using System.Globalization;

namespace CodeJam
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			int t = int.Parse (Console.ReadLine ());
			for (int testcase = 1; testcase <= t; testcase++) {
				Console.Write ("Case #" + testcase + ": ");
				int n = int.Parse (Console.ReadLine ());
				bool[,] grid = new bool[n, n];
				for (int i = 0; i < n; i++) {
					string line = Console.ReadLine ();
					for (int j = 0; j < n; j++) {
						grid [j, i] = line [j] == '1';
					}
				}
				bool success = false;
				for (int change = 0; !success; change++) {
					foreach (bool[,] g in Change(grid,n, change,0,0)) {
						if (Valid (g, n)) {
							Console.WriteLine (change);
							success = true;
							break;
						}
					}
				}
			}
		}

		static IEnumerable<bool[,]> Change(bool[,] grid, int n, int change, int x, int y) {
			if (y == n) {
				if (change == 0)
					yield return grid;
				yield break;
			}
			foreach (bool[,] result in Change (grid, n, change, (x + 1) % n, y + (x + 1 == n ? 1 : 0)))
				yield return result;
			if (grid [x, y] == false && change > 0) {
				bool[,] gridNew = (bool[,])grid.Clone ();
				gridNew [x, y] = true;
				foreach (bool[,] result in Change (gridNew, n, change - 1, (x + 1) % n, y + (x + 1 == n ? 1 : 0)))
					yield return result;
			}
		}

		static bool Valid(bool[,] grid, int n) {
			return Valid (grid, n, new bool[n], new bool[n]);
		}

		static bool Valid(bool[,] grid, int n, bool[] workers, bool[] machines) {
			for (int worker = 0; worker < n; worker++) {
				if (workers [worker])
					continue;
				bool canWork = false;
				for (int machine = 0; machine < n; machine++) {
					if (grid [worker, machine] && !machines [machine]) {
						canWork = true;
						workers [worker] = true;
						machines [machine] = true;
						bool canGoOn = Valid (grid, n, workers, machines);
						machines [machine] = false;
						workers [worker] = false;
						if (!canGoOn)
							return false;
					}
				}
				if (!canWork)
					return false;
			}

			return true;
		}
	}
}
