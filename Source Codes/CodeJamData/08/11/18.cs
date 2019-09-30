using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication1 {
	class Program {
		static void Main(string[] args) {
			string res = Vectors.ProcessFile(args[0]);
			File.WriteAllLines(args[1], new string[] { res });
			Console.Write(res);
		}
	}

	class Vectors {
		public static string ProcessFile(string filePath) {
			List<string> fileContent = FileUtils.GetFileContent(filePath);
			List<long> v1 = new List<long>();
			List<long> v2 = new List<long>();
			StringBuilder output = new StringBuilder();

			if (fileContent.Count > 0) {
				int total = int.Parse(fileContent[0]);
				int testCase = 1;
				for (int current = 1; current < fileContent.Count; ) {
					int n = int.Parse(fileContent[current++]);
					v1.Clear();
					v2.Clear();
					string[] s_v1 = fileContent[current++].Split(' ');
					string[] s_v2 = fileContent[current++].Split(' ');
					foreach (string s in s_v1) {
						v1.Add(long.Parse(s.Trim()));
					}
					foreach (string s in s_v2) {
						v2.Add(long.Parse(s.Trim()));
					}
					v1.Sort();
					v2.Sort();

					long value1 = 0;
					long value2 = 0;
					long value3 = 0;
					for (int i = 0; i < n; i++) {
						value1 += (v1[i] * v2[i]);
						value2 += (v1[i] * v2[v2.Count - 1 - i]);
						value3 += (v1[v1.Count - 1 - i] * v2[i]);
					}

					long min = Math.Min(value1, value2);
					min = Math.Min(min, value3);

					output.AppendFormat("Case #{0}: {1}\n", testCase++, min);
				}
			}

			return output.ToString();

		}
	}

	class FileUtils {
		public static List<string> GetFileContent(string filePath) {
			return new List<string>(System.IO.File.ReadAllLines(filePath));
		}
	}
}
