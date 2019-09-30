using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;

namespace TheKillerWord {
	class TheKillerWord {
		//2011 Round 1A Problem A

		static void Main(string[] args) {
			using (StreamWriter writer = new StreamWriter("output.txt")) {
				using (StreamReader reader = new StreamReader("B-small-attempt4.in")) {
					int numproblems = int.Parse(reader.ReadLine());
					for (int p = 1; p <= numproblems; p++) {
						var tokens = reader.ReadLine().Split(' ');
						int N = int.Parse(tokens[0]);
						int M = int.Parse(tokens[1]);

						List<String> dictionary = new List<string>();

						for (int i = 0; i < N; i++) {
							dictionary.Add(reader.ReadLine());
						}

						Console.WriteLine("Case #{0}:", p);
						writer.Write("Case #{0}:", p);
						for (int i = 0; i < M; i++) {
							string letterorder = reader.ReadLine();

							int bestword = 0;
							int bestscore = 0;

							for (int w = 0; w < dictionary.Count; w++) {
								int score = 0;
								int guessix = 0;
								string word = dictionary[w];
								List<String> remdict = new List<string>(dictionary);
								List<Char> Tries = new List<char>();

								string pattern = new String('.', word.Length);

								FilterSubDict(remdict, pattern, Tries);

								while (remdict.Count > 1) {
									char guess;
									while (true) {
										guess = letterorder[guessix++];
										if (ContainsLetter(remdict, guess)) {
											//it's valid, break out
											break;
										}
									}

									if (!Guess(word, ref pattern, guess)) {
										score++;
									}
									Tries.Add(guess);

									FilterSubDict(remdict, pattern, Tries);								
								}

								if (score > bestscore) {
									bestscore = score;
									bestword = w;
								}
							}

							writer.Write(" {0}", dictionary[bestword]);
						}
						writer.WriteLine();
					}
				}
			}
		}

		private static void FilterSubDict(List<String> dict, string pattern, List<Char> absent) {
			for (int i = 0; i < dict.Count; i++) {
				if (!CheckWord(dict[i], pattern, absent)) {
					dict.RemoveAt(i);
					i--;
				}
			}
		}

		private static bool CheckWord(string word, string pattern, List<char> absent) {
			if (word.Length != pattern.Length) return false;
			for (int i = 0; i < word.Length; i++) {
				if (pattern[i] != '.') {
					if (word[i] != pattern[i]) {
						return false;
					}
				} else if (absent.Contains(word[i])) {
					return false;
				}
			}
			return true;
		}

		private static bool ContainsLetter(List<String> dict, char character) {
			foreach (String word in dict) {
				foreach (char c in word) {
					if (c == character) return true;
				}
			}
			return false;
		}

		private static bool Guess(String word, ref string mask, char newchar) {
			bool goodguess = false;
			StringBuilder newmask = new StringBuilder(mask);
			for (int i = 0; i < word.Length; i++) {
				if (word[i] == newchar) {
					newmask[i] = newchar;
					goodguess = true;
				}
			}
			mask = newmask.ToString();
			return goodguess;
		}
	}
}
