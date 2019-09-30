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
				int N = int.Parse(tokens[0]);
				int K = int.Parse(tokens[1]);
				bool allOn = true;
				for (int n = 0; n < N; n++)
					if ((K & (1 << n)) == 0) allOn = false;
				sw.WriteLine("Case #" + (1 + i).ToString() + ": " + (allOn ? "ON" : "OFF"));
			}
			sr.Close();
			sw.Close();
		}
	}
}
