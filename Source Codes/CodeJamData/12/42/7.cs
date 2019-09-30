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

namespace GoogleCodeJam.GCJ2012.Round2 {
	public class ProblemB {
		private class Student {
			public int R { get; set; }
			public int Index { get; set; }
		}

		private class Answer {
			public double X { get; set; }
			public double Y { get; set; }
			public int Index { get; set; }
		}

		public static void Main(string[] args) {
			new ProblemB().Solve(Console.In);
		}

		private void Solve(TextReader reader) {
			var nTestCases = int.Parse(reader.ReadLine().Trim());
			for (int iTestCases = 0; iTestCases < nTestCases; iTestCases++) {
				var values = reader.ReadLine().Split(' ').Select(int.Parse).ToList();
				var nStudents = values[0];
				var width = values[1];
				var height = values[2];
				var students = reader.ReadLine().Split(' ')
						.Select(
								(r, i) => new Student { R = int.Parse(r), Index = i })
						.ToList();
				students.Sort((s1, s2) => s2.R.CompareTo(s1.R));
				var answers = new List<Answer>();
				answers.Add(new Answer { Index = students[0].Index, X = 0, Y = 0 });
				var y = 0.0;
				var lastIndex = 0;
				for (int i = 1; i < students.Count; i++) {
					if (answers[i - 1].X + students[i - 1].R + students[i].R <= width) {
						answers.Add(
								new Answer {
										X = answers[i - 1].X + students[i - 1].R + students[i].R,
										Y = y,
										Index = students[i].Index,
								});
					} else {
						y = answers[lastIndex].Y + students[lastIndex].R + students[i].R;
						answers.Add(
								new Answer {
										X = 0,
										Y = y,
										Index = students[i].Index,
								});
						lastIndex = i;
					}
				}
				if (y > height) {
					throw new Exception();
				}
				answers.Sort((a1, a2) => a1.Index.CompareTo(a2.Index));
				Console.Write("Case #" + (iTestCases + 1) + ":");
				for (int i = 0; i < answers.Count; i++) {
					Console.Write(" " + answers[i].X + ".0");
					Console.Write(" " + answers[i].Y + ".0");
				}
				Console.WriteLine();
			}
		}
	}
}