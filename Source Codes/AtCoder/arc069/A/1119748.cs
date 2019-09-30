using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder20170211 {
	class Program {
		static void Main(string[] args) {
			var input = Console.ReadLine().Split(' ');

			var s = Convert.ToDecimal(input[0]);
			var c = Convert.ToDecimal(input[1]);

			var scc = 0m;

			if(s * 2 <= c) {
				scc = s;

				scc += Math.Floor((c - s * 2) / 4);
			}
			else {
				scc = Math.Floor(c / 2);
				//s -= scc;

				//scc += Math.Floor(s / 2);
			}
			Console.WriteLine(scc);
			//Console.ReadLine();
		}
	}
}