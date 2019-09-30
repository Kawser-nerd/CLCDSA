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

namespace GoogleCodeJam.GJC2012.Round1A {
	// Using https://github.com/exKAZUu/Paraiba
	internal class ProblemB {
		private class Level {
			public int FirstStar { get; private set; }
			public int SecondStar { get; private set; }
			public bool DoneFirst { get; set; }
			public bool DoneSecond { get; set; }

			public Level(int firstStar, int secondStar) {
				FirstStar = firstStar;
				SecondStar = secondStar;
			}
		}

		private class FirstLevelComparer : IComparer<Level> {
			public int Compare(Level l1, Level l2) {
				return l2.SecondStar - l1.SecondStar;
			}
		}

		private class SecondLevelComparer : IComparer<Level> {
			public int Compare(Level l1, Level l2) {
				return l1.SecondStar - l2.SecondStar;
			}
		}

		private static void Main(string[] args) {
			new ProblemB().Solve(Console.In);
		}

		private void Solve(TextReader input) {
			var nCases = int.Parse(input.ReadLine());

			for (int iCases = 0; iCases < nCases; iCases++) {
				var nLevel = int.Parse(input.ReadLine());
				var levels = Enumerable.Repeat(0, nLevel)
						.Select(
								_ => {
									var vs = input.ReadLine().Split(' ').Select(int.Parse).ToList();
									return new Level(vs[0], vs[1]);
								})
						.ToList();
				levels.Sort((l1, l2) => l2.SecondStar - l1.SecondStar);

				var ans = 0;
				var nStarts = 0;
				var last = levels.Count - 1;
				while (last >= 0) {
					if (nStarts >= levels[last].SecondStar) {
						nStarts += levels[last].DoneFirst ? 1 : 2;
						last--;
					} else {
						var firstLevel =
								levels.Take(last + 1).FirstOrDefault(
										l => nStarts >= l.FirstStar && !l.DoneFirst);
						if (firstLevel == null) {
							ans = -1;
							break;
						}
						firstLevel.DoneFirst = true;
						nStarts++;
					}
					ans++;
				}

				Console.WriteLine(
						"Case #" + (iCases + 1) + ": " + (ans != -1 ? ans.ToString() : "Too Bad"));
			}
		}
	}
}