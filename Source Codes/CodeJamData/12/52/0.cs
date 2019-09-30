#region License

// Copyright (C) 2011-2012 Kazunori Sakamoto
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#endregion

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

// Using my library: https://github.com/exKAZUu/Paraiba

namespace GoogleCodeJam.GCJ2012.Round3 {
	internal class Point {
		public int X { get; set; }
		public int Y { get; set; }

		public Point(int x, int y) {
			X = x;
			Y = y;
		}
	}

	public class ProblemB {
		public static void Main(string[] args) {
			new ProblemB().Solve(Console.In);
		}

		private readonly Point[] dps = new[] {
				new Point(-1, -1), new Point(-1, 0), new Point(0, -1), new Point(+1, +1),
				new Point(+1, 0), new Point(0, +1)
		};

		private int size, diff;
		private int[,] table;
		private readonly HashSet<int> edges = new HashSet<int>();
		private readonly HashSet<int> corners = new HashSet<int>();

		private void Solve(TextReader reader) {
			var nTestCases = int.Parse(reader.ReadLine().Trim());
			for (int iTestCases = 0; iTestCases < nTestCases; iTestCases++) {
				var sizeAndMove = reader.ReadLine().Split(' ').Select(int.Parse).ToList();
				size = sizeAndMove[0] * 2 - 1;
				diff = size / 2;
				var nMoves = sizeAndMove[1];
				var moves = Enumerable.Repeat(0, nMoves)
						.Select(
								_ => {
									var xy = reader.ReadLine().Split(' ').Select(int.Parse).ToList();
									return new Point(xy[0], xy[1]);
								})
						.ToList();

				table = new int[size + 1,size + 1];
				var count = 0;
				var count2 = 1;
				bool ring;
				var ans = "none";
				foreach (var p in moves) {
					count++;
					edges.Clear();
					corners.Clear();
					ring = false;
					CheckBridgeAndFork(p, count);
					var firstCount = count2;
					foreach (var dp in dps) {
						var p2 = new Point(p.X + dp.X, p.Y + dp.Y);
						// マップ外
						if (!(1 <= p2.X && p2.X <= size && 1 <= p2.Y && p2.Y <= size)) {
							continue;
						}
						// 失敗塗り潰しかどうか
						if (table[p2.X, p2.Y] <= -firstCount) {
							continue;
						}
						// 壁かどうか
						if (table[p2.X, p2.Y] > 0) {
							continue;
						}
						ring |= CheckRing(p2, count2++, firstCount);
					}
					if (edges.Count >= 3) {
						if (corners.Count >= 2) {
							if (ring) {
								ans = "bridge-fork-ring in move " + count;
							} else {
								ans = "bridge-fork in move " + count;
							}
						} else {
							if (ring) {
								ans = "fork-ring in move " + count;
							} else {
								ans = "fork in move " + count;
							}
						}
						break;
					}
					if (corners.Count >= 2) {
						if (ring) {
							ans = "bridge-ring in move " + count;
						} else {
							ans = "bridge in move " + count;
						}
						break;
					}
					if (ring) {
						ans = "ring in move " + count;
						break;
					}
				}
				Console.WriteLine("Case #" + (iTestCases + 1) + ": " + ans);
			}
		}

		private bool CheckRing(Point p, int count, int firstCount) {
			table[p.X, p.Y] = -count;
			foreach (var dp in dps) {
				var p2 = new Point(p.X + dp.X, p.Y + dp.Y);
				// マップ外
				if (!(1 <= p2.X && p2.X <= size && 1 <= p2.Y && p2.Y <= size)) {
					return false;
				}
				// 既に塗りつぶしたかどうか
				if (table[p2.X, p2.Y] == -count) {
					continue;
				}
				// 失敗塗り潰しかどうか
				if (table[p2.X, p2.Y] <= -firstCount) {
					return false;
				}
				// 壁かどうか
				if (table[p2.X, p2.Y] > 0) {
					continue;
				}
				if (!CheckRing(p2, count, firstCount)) {
					return false;
				}
			}
			return true;
		}

		private void CheckBridgeAndFork(Point p, int count) {
			table[p.X, p.Y] = count;
			if (p.X == size && p.Y == size) {
				corners.Add(0);
			} else if (p.X == 1 && p.Y == 1) {
				corners.Add(1);
			} else if (p.X == size && p.Y == diff + 1) {
				corners.Add(2);
			} else if (p.X == diff + 1 && p.Y == size) {
				corners.Add(3);
			} else if (p.X == diff + 1 && p.Y == 1) {
				corners.Add(4);
			} else if (p.X == 1 && p.Y == diff + 1) {
				corners.Add(5);
			} else if (p.X == size) {
				edges.Add(0);
			} else if (p.Y == size) {
				edges.Add(1);
			} else if (p.X - p.Y == diff) {
				edges.Add(2);
			} else if (p.Y - p.X == diff) {
				edges.Add(3);
			} else if (p.X == 1) {
				edges.Add(4);
			} else if (p.Y == 1) {
				edges.Add(5);
			}
			foreach (var dp in dps) {
				var p2 = new Point(p.X + dp.X, p.Y + dp.Y);
				if (!(1 <= p2.X && p2.X <= size && 1 <= p2.Y && p2.Y <= size)) {
					continue;
				}
				if (!(0 < table[p2.X, p2.Y] && table[p2.X, p2.Y] < count)) {
					continue;
				}
				CheckBridgeAndFork(p2, count);
			}
		}
	}
}