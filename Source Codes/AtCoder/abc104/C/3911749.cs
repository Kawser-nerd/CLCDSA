using System;
using System.Linq;
using System.Collections.Generic;

namespace AtCoder
{
	class Programs
	{
		static void Main ()
		{
			var dg = Array.ConvertAll (Console.ReadLine ().Split (), int.Parse);
			var list = new List<Tuple<int,int>> ();
			for (int i = 0; i < dg [0]; i++) {
				var temp = Array.ConvertAll (Console.ReadLine ().Split (), int.Parse);
				list.Add (new Tuple<int,int> (temp [0], temp [1]));
			}
			int minSolve = int.MaxValue;
			for (int i = 0; i < Math.Pow (2, dg [0]); i++) {
				int score = 0;
				int solve = 0;
				var AllGreen = new int[dg [0]];
				for (int j = 0; j < dg [0]; j++) AllGreen [j] = 1;
				for (int slide = 0; slide < dg [0]; slide++) {
					if (((i >> slide) & 1) == 1) {
						score += (slide + 1) * 100 * list[slide].Item1 + list [slide].Item2;
						solve += list [slide].Item1;
						AllGreen [slide] = 0;
					}
				}
				if (score < dg [1]) {
					for (int j = dg [0] - 1; j >= 0; j--) {
						if (AllGreen [j] == 1) {
							int remain = list [j].Item1;
							while (remain >= 0) {
								score += (j + 1) * 100;
								solve++;
								remain--;
								if (score >= dg [1])
									break;
							}
							break;
						}
					}
				}
				if(score >= dg[1]) minSolve = Math.Min (minSolve, solve);
			}
			Console.WriteLine (minSolve);
		}
	}
}