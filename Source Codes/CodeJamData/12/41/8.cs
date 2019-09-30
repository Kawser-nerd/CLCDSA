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
using System.IO;
using System.Linq;

// Using my library: https://github.com/exKAZUu/Paraiba

namespace GoogleCodeJam.GCJ2012.Round2 {
	public class ProblemA {
		public static void Main(string[] args) {
			new ProblemA().Solve(Console.In);
		}

		public class Vine {
			public int Pos { get; set; }

			public int Length { get; set; }

			public int Height { get; set; }

			public Vine(int pos, int length, int height) {
				Pos = pos;
				Length = length;
				Height = height;
			}
		}

		private void Solve(TextReader reader) {
			var nTestCases = int.Parse(reader.ReadLine().Trim());
			for (int iTestCases = 0; iTestCases < nTestCases; iTestCases++) {
				var nVines = int.Parse(reader.ReadLine().Trim());
				var vines = Enumerable.Repeat(0, nVines)
						.Select(
								_ => {
									var values = reader.ReadLine().Split(' ').Select(int.Parse).ToList();
									return new Vine(values[0], values[1], 0);
								})
						.ToList();
				var distance = int.Parse(reader.ReadLine().Trim());
				vines[0].Height = Math.Min(vines[0].Length, vines[0].Pos);

				var maxDistance = 0;
				for (int iVines = 0; iVines < nVines; iVines++) {
					if (vines[iVines].Height <= 0) {
						continue;
					}
					var d = vines[iVines].Pos + vines[iVines].Height;
					maxDistance = Math.Max(maxDistance, d);
					for (int i = iVines + 1; i < nVines && vines[i].Pos <= d; i++) {
						vines[i].Height = Math.Max(
								vines[i].Height,
								Math.Min(vines[i].Length, vines[i].Pos - vines[iVines].Pos));
					}
				}

				var answer = maxDistance >= distance;
				Console.WriteLine(
						"Case #" + (iTestCases + 1) + ": " + (answer ? "YES" : "NO"));
			}
		}
	}
}