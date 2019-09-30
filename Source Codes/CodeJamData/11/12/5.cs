using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace codejam
{
	class word : IComparable<word>
	{
		public string w;
		public char c;
		public int index;

		public int CompareTo(word other)
		{
			if (w.Length != other.w.Length) return w.Length - other.w.Length;
			for (int i = 0; i < w.Length; i++)
			{
				if (w[i] == c && other.w[i] != c) return -1;
				if (other.w[i] == c && w[i] != c) return 1;
			}
			return 0;
		}
	}
	class Program
	{
		static void Main(string[] args)
		{
			string[] lines = File.ReadAllLines("B-small-attempt1.in");
			//string[] lines = File.ReadAllLines("in.txt");
			int cases = int.Parse(lines[0]);
			int lineAt = 1;
			string output = "";
			for (int c = 0; c < cases; c++)
			{
				int N, M;
				string[] input = lines[lineAt++].Split(' ');
				N = int.Parse(input[0]);
				M = int.Parse(input[1]);
				List<string> dict = new List<string>();
				List<word> words = new List<word>();
				for (int i = 0; i < N; i++)
				{
					string ww = lines[lineAt++];
					dict.Add(ww);
				}

				for (int i = 0; i < N; i++)
				{
					words.Add(new word { w = dict[i], index = i });
				}
				int[,] match = new int[N, 26];
				int[] limit = new int[26];

				for (int i = 0; i < 26; i++)
				{
					for (int j = 0; j < N; j++)
					{
						words[j].c = (char)('a' + i);
					}
					words.Sort();
					int counter = 1;
					for (int j = 0; j < N; j++)
					{
						if (j > 0)
						{
							if (words[j - 1].CompareTo(words[j]) != 0)
							{
								counter++;
							}
						}
						match[words[j].index, i] = counter;
					}
					counter++;
					limit[i] = counter;
				}
				string ans = "";
				for (int i = 0; i < M; i++)
				{
					string guess = lines[lineAt++];
					int best = 0;
					string bestWord = dict[0];
					for (int j = 0; j < N; j++)
					{
						List<int> possible = new List<int>();
						for (int k = 0; k < N; k++) if(dict[k].Length == dict[j].Length) possible.Add(k);
						int skipped = 0;
						for (int k = 0; k < 26; k++)
						{
							if (possible.Count <= 1)
							{
								int score = 0;
								for (int p = 0; p < k; p++)
								{
									if (!dict[j].Contains(guess[p]))
										score++;
								}
								score -= skipped;
								if (best < score)
								{
									best = score;
									bestWord = dict[j];
								}
								break;
							}
							else
							{
								bool found = false;
								// only guess if one of answers has this letter
								for (int ii = 0; ii < possible.Count; ii++)
								{
									if(dict[possible[ii]].Contains(guess[k]))
									{
										found = true;
										break;
									}
								}
								if (found)
								{
									for (int ii = 0; ii < possible.Count; ii++)
									{
										if (match[j, guess[k] - 'a'] != match[possible[ii], guess[k] - 'a'])
										{
											possible.RemoveAt(ii);
											ii--;
										}
									}
								}
								else
								{
									skipped++;
								}
							}
						}
					}
					

					if (i != 0) ans += " ";
					ans += bestWord;
				}
				
				output += "Case #" + (c + 1) + ": " + ans + Environment.NewLine;
				
			}
			Console.WriteLine(output);
			File.WriteAllText("out.txt", output);
		}
		
	}
}
