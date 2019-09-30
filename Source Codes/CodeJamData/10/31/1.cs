using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam {

	public struct XY {
		public int from, to;
	}

	class Program {

		
		static void Main(string[] args) {
			StreamReader sr = File.OpenText(args[0]);
			StreamWriter sw = File.CreateText(args[1]);
			string[] tokens = sr.ReadLine().Split();
			int count = int.Parse(tokens[0]);
			for (int i = 0; i < count; i++) {
				tokens = sr.ReadLine().Split();
				int N = int.Parse(tokens[0]);
				XY[] XY = new XY[N];
				for (int j = 0; j < N; j++) {
					tokens = sr.ReadLine().Split();
					int from = int.Parse(tokens[0]);
					int to = int.Parse(tokens[1]);
					XY[j] = new XY() { from = from, to = to };
				}

				int answer = 0;
				for (int j = 0; j < N; j++) {
					int f0 = XY[j].from, t0 = XY[j].to;
					int m0 = t0 - f0;
					int c0 = f0;
					for (int jj = j + 1; jj < N; jj++) {
						int f1 = XY[jj].from, t1 = XY[jj].to;
						int m1 = t1 - f1;
						if (m0 == m1) continue;
						int c1 = f1;
						int MM = m0 - m1;
						int CC = c0 - c1;
						if (CC > 0 && MM > 0) continue;
						if (CC < 0 && MM < 0) continue;
						if (Math.Abs(CC) > Math.Abs(MM)) continue;
						answer++;
					}
				}
				sw.WriteLine("Case #" + (1 + i).ToString() + ": " + answer.ToString());
			}
			sr.Close();
			sw.Close();
		}
	}
}
