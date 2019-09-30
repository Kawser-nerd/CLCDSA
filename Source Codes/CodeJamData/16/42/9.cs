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
				int[] nums = Console.ReadLine ().Split (' ').Select (int.Parse).ToArray ();
				int k = nums [1];
				double[] prob = Console.ReadLine ().Split (' ').Select (x => double.Parse (x, CultureInfo.InvariantCulture)).ToArray ();
				//Console.WriteLine ("  possible group: " + string.Join (" ", prob));
				List<double[]> choose = new List<double[]> ();
				Choose (prob, 0, new double[k], 0, choose);
				double best = 0;
				foreach (double[] p in choose) {
					//Console.WriteLine ("  take group: " + string.Join (" ", p));
					double currProb = 0;
					List<double[]> yes = new List<double[]> ();
					Choose (p, 0, new double[k/2], 0, yes);
					foreach (double[] y in yes) {
						double probYes = 1;
						double probNo = 1;
						int indexY = 0;
						int indexP = 0;
						while (indexP < p.Length) {
							if (indexY < y.Length && y [indexY] == p [indexP]) {
								probYes *= y [indexY];
								indexY++;
								indexP++;
							} else {
								probNo *= 1 - p [indexP];
								indexP++;
							}
						}
						currProb += probYes * probNo;
					}
					//currProb /= 2;
					if (currProb > best)
						best = currProb;
					//Console.WriteLine ("  probability: " + currProb);
						}
				Console.WriteLine (best.ToString (CultureInfo.InvariantCulture));
			}
		}

		static void Choose(double[] prob, int index, double[] taken, int write, List<double[]> chosen) {
			if (index == prob.Length) {
				if (write == taken.Length)
					chosen.Add ((double[])taken.Clone ());
				return;
			}
			Choose (prob, index + 1, taken, write, chosen);
			if (write == taken.Length)
				return;
			taken [write++] = prob [index];
			Choose (prob, index + 1, taken, write, chosen);
		}
	}
}
