using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Round1B2013 {
	class TaskC {
		class LeafInfo {
			public Branch Branch = new Branch();
			public bool IsTerminal = false;
		}

		class Branch {
			public Dictionary<char, LeafInfo> Leaves = new Dictionary<char, LeafInfo>();

			public void AddWord(string word, int offset) {
				if(!Leaves.ContainsKey(word[offset])) {
					Leaves[word[offset]] = new LeafInfo();
				}

				if(offset+1 < word.Length) {
					Leaves[word[offset]].Branch.AddWord(word, offset+1);
				} else {
					Leaves[word[offset]].IsTerminal = true;
				}
			}
		}

		private static string[] words;

		private static readonly Branch Tree = new Branch();

		private static readonly LeafInfo RootLeaf = new LeafInfo { Branch = Tree, IsTerminal = true };

		private static IEnumerable<int> Candidates(string s, int offset, int failAllowed, LeafInfo processingLeaf) {
			char ch = s[offset];

			var processingBranch = processingLeaf.Branch;
			
			if(processingBranch.Leaves.ContainsKey(ch)) {
				var resultA = SolveSmall(s, offset+1, failAllowed, processingBranch.Leaves[ch]);
				if(resultA >= 0) {
					yield return resultA;
				}
			}

			if(processingLeaf.IsTerminal) {
				if(Tree.Leaves.ContainsKey(ch)) {
					var resultB = SolveSmall(s, offset+1, failAllowed, Tree.Leaves[ch]);
					if(resultB >= 0) {
						yield return resultB;
					}
				}
			}

			if(failAllowed <= offset) {
				var newFailAllowed = offset+5;

				var branches = processingBranch.Leaves.AsEnumerable();
				if(processingLeaf.IsTerminal) {
					branches = branches.Concat(Tree.Leaves);
				}

				foreach(var kvp in branches) {
					if(kvp.Key == ch) {
						continue;
					}

					var resultC = SolveSmall(s, offset+1, newFailAllowed, kvp.Value);
					if(resultC >= 0) {
						yield return 1+resultC;
					}
				}
			}
		}

		private static int DoSolveSmall(string s, int offset, int failAllowed, LeafInfo processingLeaf) {
			if(s.Length == offset) {
				if(processingLeaf.IsTerminal) {
					return 0;
				} else {
					return -1;
				}
			}

			//Console.WriteLine("SolveSmall({0}, {1}, {2})", s, offset, failAllowed);

			int result = -1;

			foreach(var candidate in Candidates(s, offset, failAllowed, processingLeaf)) {
				if(candidate < 0) {
					continue;
				}
				if(result < 0 || candidate < result) {
					result = candidate;
				}
				if(result == 0) {
					return result;
				}
			}

			return result;

			/*if(processingBranch.Leaves.ContainsKey(ch)) {
				foreach(var subBranch in processingBranch.Branches[ch]) {
					var candidate = SolveSmall(s, offset+1, failAllowed, subBranch);
					if (candidate == null) {
						continue;
					}
					if(result == null || candidate.Item1 < result.Item1) {
						result = Tuple.Create(candidate.Item1, ch + candidate.Item2);
					}
				}
			}

			if(failAllowed <= offset) {
				foreach(var kvp in processingBranch.Branches) {
					if(kvp.Key == ch) {
						continue;
					}

					foreach(var subBranch in kvp.Value) {
						var candidate = SolveSmall(s, offset+1, offset+5, subBranch);
						if (candidate == null) {
							continue;
						}
						if(result == null || candidate.Item1+1 < result.Item1) {
							result = Tuple.Create(candidate.Item1+1, kvp.Key + candidate.Item2);
						}
					}
				}
			}

			return result;*/

			/*foreach(var word in words) {
				if(word.Length+offset > s.Length) {
					continue;
				}

				int actualFailAllowed = failAllowed;
				bool fit = true;
				int mistypes = 0;
				for(int i=0; i<word.Length; i++) {
					if(word[i] != s[offset+i]) {
						if(offset+i < actualFailAllowed) {
							fit = false;
						} else {
							actualFailAllowed = offset+i+5;
							mistypes++;
						}
					}
				}

				if(fit) {
					var branch = SolveSmall(s, offset + word.Length, actualFailAllowed);
					if(branch != null) {
						if(result == null || result.Item1 > branch.Item1) {
							result = Tuple.Create(mistypes+branch.Item1, word + " " + branch.Item2);
						}
					}
				}
			}
			
			return result;*/
		}

		private static readonly Dictionary<Tuple<string, int, int, LeafInfo>, int> Cache = new Dictionary<Tuple<string,int,int,LeafInfo>,int>();

		private static int SolveSmall(string s, int offset, int failAllowed, LeafInfo processingLeaf) {
			var key = Tuple.Create(s, offset, failAllowed, processingLeaf);
			if(!Cache.ContainsKey(key)) {
				Cache[key] = DoSolveSmall(s, offset, failAllowed, processingLeaf);
			}
			return Cache[key];
		}

		public static void RunSmall() {
			{
				var inputWords  = new List<string>();
				using(var file = new StreamReader("garbled_email_dictionary.txt")) {
					while(!file.EndOfStream) {
						inputWords.Add(file.ReadLine());
					}
				}
				words = inputWords.Where(s => !string.IsNullOrWhiteSpace(s)).Select(s => s.Trim()).ToArray();

				foreach(var word in words) {
					Tree.AddWord(word, 0);
				}
			}

			{
				int T = int.Parse(Console.ReadLine());
				for(int i=1; i<=T; i++) {
					var S = Console.ReadLine().Trim();
					var result = SolveSmall(S, 0, 0, RootLeaf);
					Console.WriteLine("Case #{0}: {1}", i, result);
				}
			}
		}
	}
}
