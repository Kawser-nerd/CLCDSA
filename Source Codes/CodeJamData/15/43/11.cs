using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace gcj
{
	class ProblemX
	{
		private List<List<string>> sentences;
		private List<List<int>> sentInt;
		private List<string> allWords; 
		private int n;
		private int ans;

		int[] status;

		public void Solution(TextReader Input, TextWriter Output)
		{
			int T = int.Parse(Input.ReadLine());
			var sw = Stopwatch.StartNew();

			for (int i = 0; i < T; i++)
			{
				Console.WriteLine(i);
				Console.WriteLine(sw.Elapsed);

				ans = 1000000000;
				n = int.Parse(Input.ReadLine());
				sentences = new List<List<string>>();
				sentInt = new List<List<int>>();
				allWords = new List<string>();

				for (int j = 0; j < n; j++)
				{
					sentences.Add(Input.ReadLine().Split(' ').ToList());
					foreach (var line in sentences[j])
						allWords.Add(line);
				}
				allWords = allWords.Distinct().ToList();

				int ptr = 0;
				Dictionary<string, int> words = allWords.ToDictionary(word => word, word => ptr++);

				for (int j = 0; j < n; j++)
				{
					sentInt.Add(sentences[j].Select(x => words[x]).ToList());
				}

				Solve();
				Output.WriteLine("Case #" + (i + 1) + ": " + ans);

			}
		}

		private void Solve()
		{
			status = new int[allWords.Count];

			for (int i = 0; i < (1 << (n - 2)); i++)
			{
				var ts = new int[n];
				ts[0] = 1;
				ts[1] = 2;
				var x = i;


				for (int j = 2; j < n; j++)
				{
					ts[j] = x%2 + 1;
					x /= 2;
				}

				for (int j = 0; j < allWords.Count(); j++)
					status[j] = 0;
				
				for (int j = 0; j < n; j++)
				{
					foreach (var word in sentInt[j])
					{
						status[word] |= ts[j];
					}
				}

				int cur = 0;
				for (int j = 0; j < allWords.Count(); j++)
					if (status[j] == 3)
						cur++;

				ans = Math.Min(ans, cur);
			}
		}
	}


	class Program
	{
		public static void Main()
		{
#if Local
			var inputStream = new StreamReader(@"..\..\input.txt");
			var outputStream = new StreamWriter(@"..\..\output.txt");

			new ProblemX().Solution(inputStream, outputStream);

			inputStream.Close();
			outputStream.Close();
#else
			new ProblemX().Solution(Console.In, Console.Out);
#endif
		}
	}
}