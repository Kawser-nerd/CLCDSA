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
using Paraiba.Collections.Generic.Compare;

// Using my library: https://github.com/exKAZUu/Paraiba

namespace GoogleCodeJam.GCJ2012.Round3 {
	public class ProblemA {
		class Stage {
			public int Index { get; set; }
			public int Time { get; set; }
			public int Die { get; set; }
		}

		public static void Main(string[] args) {
		    new ProblemA().Solve(Console.In);
		}

		class Comaprer : IComparer<Stage> {
			public int Compare(Stage x, Stage y) {
				if (x.Die == 0 && y.Die == 0) {
					return 0;
				}
				if (x.Die == y.Die) {
					return y.Time.CompareTo(x.Time);
				}
				return y.Die.CompareTo(x.Die);
			}
		}

		private void Solve(TextReader reader) {
			var nTestCases = int.Parse(reader.ReadLine().Trim());
			for (int iTestCases = 0; iTestCases < nTestCases; iTestCases++) {
				var nLevels = int.Parse(reader.ReadLine().Trim());
				var times = reader.ReadLine().Split(' ').Select(int.Parse).ToList();
				var dies = reader.ReadLine().Split(' ').Select(int.Parse).ToList();
				var stages = times.Zip(dies, Tuple.Create)
						.Select(
								(t, i) => new Stage {
										Time = t.Item1,
										Die = t.Item2,
										Index = i,
								})
						.ToList();
				stages = stages
						.OrderBy(s => s, new Comaprer())
						.ToList();
				var ans = String.Join(" ", stages.Select(s => s.Index.ToString()));
				Console.WriteLine( "Case #" + (iTestCases + 1) + ": " + ans);
			}
		}
	}
}