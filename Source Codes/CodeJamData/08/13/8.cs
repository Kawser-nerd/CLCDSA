using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication1 {
	class Program {
		static void Main(string[] args) {
			string res = MyNumbers.ProcessFile(args[0]);
			File.WriteAllLines(args[1], new string[] { res });
			Console.Write(res);
		}
	}

	class MyNumbers {
		public static string ProcessFile(string filePath) {
			List<string> fileContent = FileUtils.GetFileContent(filePath);
			StringBuilder output = new StringBuilder();

			if (fileContent.Count > 0) {
				int total = int.Parse(fileContent[0]);
				int testCase = 1;
				decimal b = 5.2360679774997896964091736687313m;
				Console.WriteLine("B:{0}", b);
				for (int current = 1; current < fileContent.Count; ) {
					long n = long.Parse(fileContent[current++]);
					decimal res = 0;
					if (n == 0) {
						res = 1;
					} else {
						res = b;
						for (long i = 1; i < n; i++) {
							res *= b;
						}
					}
					decimal res2 = Math.Truncate(res);
					string str = string.Format("{0:F0}", res2);// res2.ToString("000");
					if (str.Length < 3) {
						str = string.Format("{0:000}", int.Parse(str));
					}
					string str2 = str.Substring(str.Length - 3);
					Console.WriteLine("{0} -- {1} -- {2} -- {3} -- {4}", n, res, res2, str, str2);
					output.AppendFormat("Case #{0}: {1}\n", testCase++, str2);
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
