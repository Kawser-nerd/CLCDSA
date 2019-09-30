using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace CodeJam
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			string[] input = File.ReadAllLines (args [0]);
			int cases = int.Parse (input [0]);
			for (int c = 1; c <= cases; c++) {
				Console.Write ("Case #" + c + ": ");
				string s1 = input [c].Split (' ') [0];
				string s2 = input [c].Split (' ') [1];
				n1 = long.Parse (s1.Replace ('?', '0'));
				n2 = long.Parse (s2.Replace ('?', '0'));
				Solve (s1, s2, 0, 0, 0);
				Console.WriteLine (n1.ToString ().PadLeft (s1.Length, '0') + " " + n2.ToString ().PadLeft (s2.Length, '0'));
			}
		}

		static long n1 = 0;
		static long n2 = 0;
		static void Solve(string s1, string s2, long i1, long i2, int index) {
			if (index == s1.Length) {
				if (Math.Abs (i1 - i2) < Math.Abs (n1 - n2) || 
				    Math.Abs (i1 - i2) == Math.Abs (n1 - n2) && i1 < n1 || 
				    Math.Abs (i1 - i2) == Math.Abs (n1 - n2) && i1 == n1 && i2 < n2) {
					n1 = i1;
					n2 = i2;
				}
				return;
			}
			if (s1 [index] == '?' && s2 [index] == '?') {
				if (i1 == i2) {
					Solve (s1, s2, 10 * i1, 10 * i2, index + 1);
					Solve (s1, s2, 10 * i1 + 1, 10 * i2, index + 1);
					Solve (s1, s2, 10 * i1, 10 * i2 + 1, index + 1);
				}
				if (i1 < i2) {
					Solve (s1, s2, 10 * i1 + 9, 10 * i2, index + 1);
				}
				if (i1 > i2) {
					Solve (s1, s2, 10 * i1, 10 * i2 + 9, index + 1);
				}
				return;
			}
			if (s1 [index] == '?') {
				int tmp = s2 [index] - '0';
				if (i1 == i2) {
					if (tmp > 0) Solve (s1, s2, 10 * i1 + tmp - 1, 10 * i2 + tmp, index + 1);
					if (tmp < 9) Solve (s1, s2, 10 * i1 + tmp + 1, 10 * i2 + tmp, index + 1);
					Solve (s1, s2, 10 * i1 + tmp, 10 * i2 + tmp, index + 1);
				}
				if (i1 < i2) {
					Solve (s1, s2, 10 * i1 + 9, 10 * i2 + tmp, index + 1);
				}
				if (i1 > i2) {
					Solve (s1, s2, 10 * i1, 10 * i2 + tmp, index + 1);
				}
				return;
			}
			if (s2 [index] == '?') {
				int tmp = s1 [index] - '0';
				if (i1 == i2) {
					if (tmp > 0) Solve (s1, s2, 10 * i1 + tmp, 10 * i2 + tmp - 1, index + 1);
					if (tmp < 9) Solve (s1, s2, 10 * i1 + tmp, 10 * i2 + tmp + 1, index + 1);
					Solve (s1, s2, 10 * i1 + tmp, 10 * i2 + tmp, index + 1);
				}
				if (i1 > i2) {
					Solve (s1, s2, 10 * i1 + tmp, 10 * i2 + 9, index + 1);
				}
				if (i1 < i2) {
					Solve (s1, s2, 10 * i1 + tmp, 10 * i2, index + 1);
				}
				return;
			}
			Solve (s1, s2, i1 * 10 + s1 [index] - '0', i2 * 10 + s2 [index] - '0', index + 1);
		}
	}
}
