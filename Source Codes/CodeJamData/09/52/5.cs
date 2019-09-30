using System;
using System.Collections.Generic;
using System.IO;

namespace Alphabetomials
{
	internal static class Program
	{
		private static void Main()
		{
			StreamReader r = new StreamReader(@"D:\Downloads\B-small-attempt1.in");
			StreamWriter wr = new StreamWriter(@"C:\output.txt");

			var testCases = new List<Tuple<string[], int, List<int[]>>>();

			string line = r.ReadLine();
			string[] parts;
			int testCaseCount = int.Parse(line);
			Console.WriteLine("Cases: " + testCaseCount);

			for (int i = 0; i < testCaseCount; i++)
			{
				line = r.ReadLine();
				parts = line.Split(' ');
				string[] terms = parts[0].Split('+');
				int K = int.Parse(parts[1]);

				List<int[]> dictionary = new List<int[]>();

				line = r.ReadLine();
				int wordCount = int.Parse(line);

				for (int j = 0; j < wordCount; j++)
				{
					dictionary.Add(CountLetters(r.ReadLine()));
				}

				wr.WriteLine("Case #{0}: {1}", i + 1, string.Join(" ", DoCase(terms, K, dictionary)));
				Console.WriteLine("Completed case " + (i + 1));
			}
			wr.Close();
		}

		private static int[] CountLetters(string word)
		{
			int[] letters = new int[26];
			for (int i = 0; i < 26; i++)
			{
				char c = (char)('a' + i);

				foreach (char x in word)
				{
					if (x == c)
					{
						letters[i]++;
					}
				}
			}

			return letters;
		}

		private static int EvaluatePoly(string[] terms, int[] letters)
		{
			int accum = 0;
			checked
			{

				foreach (string term in terms)
				{
					int mul = 1;
					foreach (char letter in term)
					{
						mul *= letters[letter - 'a'];
					}
					accum += mul;
				}
			}
			return accum % 10009;
		}


		private static int Step(string[] terms, int Kleft, List<int[]> dictionary, int[] letters)
		{
			if (Kleft == 0)
			{
				return EvaluatePoly(terms, letters);
			}

			int accum = 0;

			foreach (var x in dictionary)
			{
				for (int i = 0; i < 26; i++)
				{
					letters[i] += x[i];
				}

				accum += Step(terms, Kleft - 1, dictionary, letters);

				for (int i = 0; i < 26; i++)
				{
					letters[i] -= x[i];
				}
			}

			return accum%10009;
		}

		private static string[] DoCase(string[] terms, int K, List<int[]> dictionary)
		{
			string[] results = new string[K];
			for (int x = 0; x < K; x++)
			{
				results[x] = Step(terms, x + 1, dictionary, new int[26]).ToString();
			}

			return results;
		}
	}

	internal struct Tuple<A,B,C>
	{
		public A a;
		public B b;
		public C c;

		public Tuple(A a, B b, C c)
		{
			this.a = a;
			this.b = b;
			this.c = c;
		}
	}
}