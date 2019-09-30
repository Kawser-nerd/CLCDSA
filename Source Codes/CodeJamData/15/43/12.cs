using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Reflection;
using System.Text;
using System.Text.RegularExpressions;
using System.Windows;

namespace ConsoleApplicationCSharp {
	class Program {
		static bool[] ck;
		static string[] input;
		static int n;
		static int answer;
		static List<string>[] list;

		static HashSet<string> t1;
		static HashSet<string> t2;
		static HashSet<string> t3;

		static void recall(int lev) {
			if (lev > n) {
				HashSet<string> r1 = new HashSet<string>();
				HashSet<string> r2 = new HashSet<string>();
				HashSet<string> r3 = new HashSet<string>();

				// false == eng
				// true == frn

				for (int i = 3; i <= n; i++) {
					foreach (string s in list[i]) {
						if (!ck[i]) {
							if (t3.Contains(s)) { continue; }
							if (t2.Contains(s)) {
								if (!r3.Contains(s)) {
									r3.Add(s);
								}
							}
							else {
								if (!r1.Contains(s)) {
									r1.Add(s);
								}
							}
						}
					}
				}
				for (int i = 3; i <= n; i++) {
					foreach (string s in list[i]) {
						if (ck[i]) {
							if (t3.Contains(s)) { continue; }
							if (t1.Contains(s) || r1.Contains(s)) {
								if (!r3.Contains(s)) {
									r3.Add(s);
								}
							}
							else {
								if (!r2.Contains(s)) {
									r2.Add(s);
								}
							}
						}
					}
				}

				if (answer > t3.Count + r3.Count) {
					answer = t3.Count + r3.Count;

					//Console.WriteLine("{0}: {1} {2}", answer, ck[3], ck[4]);
				}
			}
			else {
				ck[lev] = false;
				recall(lev + 1);
				ck[lev] = true;
				recall(lev + 1);
			}
		}

		static void Main(string[] args) {
			int test;
			using (StreamWriter sw = new StreamWriter("output.txt")) {
				using (StreamReader sr = new StreamReader("input.txt")) {
					test = Convert.ToInt32(sr.ReadLine());

					for (int t = 1; t <= test; t++) {
						Console.WriteLine(t);
						n = Convert.ToInt32(sr.ReadLine());
						answer = 999999999;

						input = new string[n + 1];
						list = new List<string>[n + 1];
						ck = new bool[n + 1];

						for (int i = 1; i <= n; i++) {
							input[i] = sr.ReadLine();
							string[] split = input[i].Split(new string[] { " " }, StringSplitOptions.RemoveEmptyEntries);

							list[i] = new List<string>();
							foreach (string s in split) {
								list[i].Add(s);
							}
						}

						t1 = new HashSet<string>();
						t2 = new HashSet<string>();
						t3 = new HashSet<string>();

						foreach (string s in list[1]) {
							if (!t1.Contains(s)) {
								t1.Add(s);
							}
						}

						foreach (string s in list[2]) {
							if (!t2.Contains(s)) {
								t2.Add(s);
							}

							if (t1.Contains(s) && t2.Contains(s)) {
								t1.Remove(s);
								t2.Remove(s);

								if (!t3.Contains(s)) {
									t3.Add(s);
								}
							}
						}

						recall(3);

						//Console.WriteLine(answer);
						sw.WriteLine("Case #{0}: {1}", t, answer);
					}
				}
			}
		}
	}
}
