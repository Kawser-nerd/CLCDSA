using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam {

	class Program {

		static int hex(char c) {
			if (c >= '0' && c <= '9') {
				return c - '0';
			} else {
				return c - 'A' + 10;
			}
		}

		static int calculate(int[,] checkableCumu, int r, int c, int R, int C, int size) {
			int sizeMinus = size - 1;
			int answer = checkableCumu[r, c] - checkableCumu[r - sizeMinus, c] - checkableCumu[r, c - sizeMinus] + checkableCumu[r - sizeMinus, c - sizeMinus];
			return answer;
		}

		static void Main(string[] args) {
			StreamReader sr = File.OpenText(args[0]);
			StreamWriter sw = File.CreateText(args[1]);
			string[] tokens = sr.ReadLine().Split();
			int[,] map = new int[520, 520];
			int count = int.Parse(tokens[0]);
			for (int i = 0; i < count; i++) {
				tokens = sr.ReadLine().Split();
				int R = int.Parse(tokens[0]);
				int C = int.Parse(tokens[1]);
				bool[,] raw = new bool[R, C];
				for (int r = 0; r < R; r++) {
					tokens = sr.ReadLine().Split();
					string s = tokens[0];
					for (int c = 0; c < C; c += 4) {
						int number = hex(s[c / 4]);
						raw[r, c + 0] = (number & 0x08) != 0;
						raw[r, c + 1] = (number & 0x04) != 0;
						raw[r, c + 2] = (number & 0x02) != 0;
						raw[r, c + 3] = (number & 0x01) != 0;
					}
				}
				bool[,] checkable = new bool[R, C];
				for (int r = 0; r < R; r++) {
					for (int c = 0; c < C; c++) {
						if (r == 0 || c == 0) {
							checkable[r, c] = false;
						} else {
							checkable[r, c] = raw[r, c] == raw[r - 1, c - 1] && raw[r, c - 1] == raw[r - 1, c] && raw[r, c] != raw[r, c - 1];
						}
					}
				}
				int[,] checkableCumu = new int[R, C];
				for (int r = 0; r < R; r++) {
					for (int c = 0; c < C; c++) {
						if (r == 0 || c == 0) {
							checkableCumu[r, c] = 0;
						} else {
							checkableCumu[r, c] = (checkable[r, c] ? 1 : 0) +
								checkableCumu[r - 1, c] + checkableCumu[r, c - 1] - checkableCumu[r - 1, c - 1];
						}
					}
				}
				int[,] maxsize = new int[R, C];
				for (int r = 0; r < R; r++) {
					for (int c = 0; c < C; c++) {
						maxsize[r, c] = 1 + Math.Min(r, c);
					}
				}

				int uniqueSize = 0;
				int[] sizeScore = new int[Math.Min(R, C) + 1];
				for (int size = Math.Min(R, C); size >= 1; size--) {
					int sizeMinusSquare = (size - 1) * (size - 1);
					for (int r = 0; r < R; r++) {
						for (int c = 0; c < C; c++) {
							if (maxsize[r, c] < size) continue;  // not eligible;
							if (calculate(checkableCumu, r, c, R, C, size) == sizeMinusSquare) {
								if (sizeScore[size] == 0) uniqueSize++;  // first time;
								sizeScore[size]++;  // found a hit!
								for (int rr = r - size + 1; rr <= r + size; rr++) {
									if (rr >= R) continue;
									for (int cc = c - size + 1; cc <= c + size; cc++) {
										if (cc >= C) continue;
										if (rr <= r && cc <= c) {
											maxsize[rr, cc] = 0;
										} else if (rr > r && cc > c) {
											int rrdelta = rr - r;
											int ccdelta = cc - c;
											if (rrdelta < 0) rrdelta = int.MaxValue;
											if (ccdelta < 0) ccdelta = int.MaxValue;
											int maxdelta = Math.Max(rrdelta, ccdelta);
											maxsize[rr, cc] = Math.Min(maxsize[rr, cc], maxdelta);
										} else if (rr <= r) {  // use distance from c;
											int ccdelta = cc - c;
											maxsize[rr, cc] = Math.Min(maxsize[rr, cc], ccdelta);
										} else if (cc <= c) {  // use distance from r;
											int rrdelta = rr - r;
											maxsize[rr, cc] = Math.Min(maxsize[rr, cc], rrdelta);
										}
									}
								}
							}
						}
					}
				}

				sw.WriteLine("Case #" + (1 + i).ToString() + ": " + uniqueSize.ToString());
				for (int size = Math.Min(R, C); size >= 1; size--) {
					if (sizeScore[size] > 0)
						sw.WriteLine(size.ToString() + " " + sizeScore[size].ToString());
				}
			}
			sr.Close();
			sw.Close();
		}
	}
}
