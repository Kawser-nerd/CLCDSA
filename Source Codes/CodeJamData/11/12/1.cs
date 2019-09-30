using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace codejam
{
	class Solution
	{
		Solution(string fileName)
		{
			cin = File.OpenText(fileName);
			cout = new StreamWriter(@"D:\codejam\" + "output.txt");
		}

		void Close()
		{
			cin.Close();
			cout.Close();
		}

		static public void Run(string fileName)
		{
			Solution solution = new Solution(@"D:\codejam\" + fileName);
			solution.Solve();
			solution.Close();
		}

		void CreateSet()
		{
			char c = 'a';
			for (int i = 0; i < 26; i++)
			{
				for (int j = 0; j < words.Count; j++)
				{
					set[i, j] = j;
					for (int k = 0; k < j; k++)
						if (set[i, k] == k)
						{
							bool same = words[j].Length == words[k].Length;
							if (!same)
								continue;
							for (int l = 0; l < words[j].Length && l < words[k].Length; l++)
								if (words[j][l] != words[k][l] && (words[j][l] == c || words[k][l] == c))
								{
									same = false;
									break;
								}
							if (same)
								set[i, j] = k;
						}
				}
				c++;
			}
		}

		void Solve()
		{
			int T = Convert.ToInt32(cin.ReadLine());
			for (int testCase = 1; testCase <= T; testCase++)
			{
				string[] s = cin.ReadLine().Split(' ');
				int N = Convert.ToInt32(s[0]);
				int M = Convert.ToInt32(s[1]);
				words = new List<string>();
				for (int i = 0; i < N; i++)
					words.Add(cin.ReadLine());
				cout.Write("Case #{0}:", testCase);
				CreateSet();
				int[] st = new int[10005];

				int[] points = new int[10005];
				int[] count = new int[10005];
				for (int i = 0; i < M; i++)
				{
					string strategy = cin.ReadLine();
					Array.Clear(points, 0, points.Length);

					for (int q = 0; q < words.Count; q++)
						st[q] = words[q].Length; 
					for (int j = 0; j < 26; j++)
					{
						Array.Clear(count, 0, count.Length);
						int k = strategy[j] - 'a';
						for (int q = 0; q < words.Count; q++)
						{
							if (words[q].Contains(strategy[j]))
								count[st[q]]++;
						}
						for (int q = 0; q < words.Count; q++)
							if (!words[q].Contains(strategy[j]) && count[st[q]] != 0)
								points[q]++;
						for (int q = 0; q < words.Count; q++)
							st[q] = st[q] * 10001 + set[k, q];
						Dictionary<int, int> sets = new Dictionary<int, int>();
						int setNumber = 0;
						for (int q = 0; q < words.Count; q++)
							if (!sets.ContainsKey(st[q]))
								sets[st[q]] = setNumber++;
						for (int q = 0; q < words.Count; q++)
							st[q] = sets[st[q]];
					}
					int p = 0;
					int ans = 0;
					for (int j = 0; j < words.Count; j++)
						if (p < points[j])
						{
							p = points[j];
							ans = j;
						}
					cout.Write(" {0}", words[ans]);
				}
			
				cout.WriteLine();
			}
		}

		List<string> words;
		int[,] set = new int[26, 10005];

		TextReader cin;
		TextWriter cout;
	}
	class Program
	{
		static void Main(string[] args)
		{
			Solution.Run("B-large.in");
		}
	}
}
