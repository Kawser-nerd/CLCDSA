using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam {

	class Program {

		static void Main(string[] args) {
			StreamReader sr = File.OpenText(args[0]);
			StreamWriter sw = File.CreateText(args[1]);
			string[] tokens = sr.ReadLine().Split();
			int count = int.Parse(tokens[0]);
			for (int i = 0; i < count; i++) {
				tokens = sr.ReadLine().Split();
				Int64 L = (Int64) int.Parse(tokens[0]);
				Int64 P = (Int64) int.Parse(tokens[1]);
				Int64 C = (Int64) int.Parse(tokens[2]);
				int iter = 0;
				while (P > C * L) {
					double v = Math.Sqrt(L * P);
					Int64 vLB = (Int64) Math.Floor(v);
					Int64 vUB = (Int64) Math.Ceiling(v);
					if (((double) P) / ((double) vLB) < ((double) vUB) / ((double) L)) {
						;  // go with vLB -> P;
						L = vLB;
						iter++;
					} else {
						;  // go with L -> vUB;
						P = vUB;
						iter++;
					}
				}

				sw.WriteLine("Case #" + (1 + i).ToString() + ": " + iter.ToString());
			}
			sr.Close();
			sw.Close();
		}
	}
}
