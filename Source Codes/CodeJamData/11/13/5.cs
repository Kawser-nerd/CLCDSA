using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace codejam
{
	class recurse
	{
		List<int> c, t, s;
		List<int> hand = new List<int>();
		public recurse(List<int> cc, List<int> ss, List<int> tt)
		{
			c = cc;
			t = tt;
			s = ss;
		}
		public int go(int n)
		{
			for (int i = 0; i < n; i++)
			{
				hand.Add(i);
			}
			return Play(1, 0, n);
		}
		int Play(int turns, int score, int deckAt)
		{			
			if (turns == 0)
			{
				return score;
			}
			if (hand.Count == 0)
			{
				return score;
			}
			List<int> oldHand = new List<int>(hand);
			for (int i = 0; i < hand.Count; i++)
			{
				if (t[hand[i]] > 0)
				{
					PlayCard(hand[i], ref turns, ref score, ref deckAt);

					hand.RemoveAt(i);
					
					i--;
				}
			}
			if (hand.Count == 0)
			{
				return score;
			}
			// need to choose if we don't have to play card drawing
			if (hand.Count > turns)
			{
				hand.Sort(new Comparison<int>(delegate(int a, int b)
				{
					if (s[a] > s[b]) return -1;
					if (s[b] > s[a]) return 1;
					if (c[a] > c[b]) return -1;
					if (c[b] > c[a]) return 1;

					return 0;
				}));
				if (c[hand[turns - 1]] == 0)
				{
					List<int> tempHand = new List<int>(hand);
					int tturns = turns;
					int tscore = score;
					int td = deckAt;

					// we must choose to draw or score					
					PlayCard(hand[0], ref turns, ref score, ref deckAt);
					hand.RemoveAt(0);
					int scoring = Play(turns, score, deckAt);

					hand = tempHand;
					hand.Sort(new Comparison<int>(delegate(int a, int b)
					{
						if (c[a] > c[b]) return -1;
						if (c[b] > c[a]) return 1;
						if (s[a] > s[b]) return -1;
						if (s[b] > s[a]) return 1;

						return 0;
					}));

					turns = tturns;
					score = tscore;
					deckAt = td;
					PlayCard(hand[0], ref turns, ref score, ref deckAt);
					hand.RemoveAt(0);
					int drawing = Play(turns, score, deckAt);

					hand = oldHand;
					return Math.Max(scoring, drawing);
				}
			}			
			
			// forced to play this eventually
			hand.Sort(new Comparison<int>(delegate(int a, int b)
			{
				if (c[a] > c[b]) return -1;
				if (c[b] > c[a]) return 1;
				if (s[a] > s[b]) return -1;
				if (s[b] > s[a]) return 1;
					
				return 0;
			}));
			PlayCard(hand[0], ref turns, ref score, ref deckAt);
				
			hand.RemoveAt(0);
			int res = Play(turns, score, deckAt);
			hand = oldHand;
			return res;				
					
		}
		void PlayCard(int card, ref int turns, ref int score, ref int deckAt)
		{
			score += s[card];
			turns += t[card];
			for (int cc = 0; cc < c[card] && deckAt < s.Count; cc++)
			{
				hand.Add(deckAt++);
			}
			turns--;
		}
	}
	class Program
	{
		static void Main(string[] args)
		{
			string[] lines = File.ReadAllLines("C-small-attempt3.in");
			//string[] lines = File.ReadAllLines("input.txt");
			int cases = int.Parse(lines[0]);
			int lineAt = 1;
			string output = "";
			for (int C = 0; C < cases; C++)
			{
				List<int> c = new List<int>(), s = new List<int>(), t = new List<int>();
				int N = int.Parse(lines[lineAt++]);
				for (int i = 0; i < N; i++)
				{
					string[] input = lines[lineAt++].Split(' ');
					int c1 = int.Parse(input[0]);
					int s1 = int.Parse(input[1]);
					int t1 = int.Parse(input[2]);
					c.Add(c1);
					s.Add(s1);
					t.Add(t1);
				}

				int M = int.Parse(lines[lineAt++]);
				for (int i = 0; i < M; i++)
				{
					string[] input = lines[lineAt++].Split(' ');
					int c2 = int.Parse(input[0]);
					int s2 = int.Parse(input[1]);
					int t2 = int.Parse(input[2]);
					c.Add(c2);
					s.Add(s2);
					t.Add(t2);
				}

				recurse r = new recurse(c, s, t);
				int ans = r.go(N);
				
				output += "Case #" + (C + 1) + ": " + ans + Environment.NewLine;
				
			}
			Console.WriteLine(output);
			File.WriteAllText("out.txt", output);
		}
		
	}
}
