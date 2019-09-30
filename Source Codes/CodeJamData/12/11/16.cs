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
using System.Text;

namespace GoogleCodeJam.GJC2012.Round1A {
	public class ProblemA {
		private static void Main(string[] args) {
			new ProblemA().Solve(Console.In);
		}

		private void Solve(TextReader input) {
			var nCases = int.Parse(input.ReadLine());

			for (int iCases = 0; iCases < nCases; iCases++) {
				var AB = input.ReadLine().Split(' ').Select(int.Parse).ToList();
				var current = AB[0];
				var total = AB[1];
				var probs = input.ReadLine().Split(' ').Select(double.Parse).ToList();

				var ans = (double)total + 2;
				var p1 = 1.0;
				for (int nBackspace = current - 1; nBackspace >= 0; nBackspace--) {
					p1 *= probs[current - 1 - nBackspace];
					var p2 = 1.0 - p1;
					ans = Math.Min(
							ans, ((total - current + 1 + nBackspace) + nBackspace) * p1
							     + ((total - current + 1 + nBackspace) + nBackspace + total + 1) * p2);
				}

				Console.WriteLine("Case #" + (iCases + 1) + ": " + ans);
			}
		}
	}
}