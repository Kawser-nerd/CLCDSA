using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.IO;

namespace CodeJam
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			int t = int.Parse (Console.ReadLine ());
			for (int testcase = 1; testcase <= t; testcase++) {
				Console.Write ("Case #" + testcase + ": ");
				int[] nums = Console.ReadLine ().Split (' ').Select (int.Parse).ToArray ();
				int r = nums [1];
				int p = nums [2];
				int s = nums [3];
				List<State> states = new List<State> ();
				if (p > 0)
					states.Add (new State ('P'));
				if (r > 0)
					states.Add (new State ('R'));
				if (s > 0)
					states.Add (new State ('S'));
				for (int i = 0; i < nums[0]; i++) {
					List<State> newStates = new List<State> ();
					for (int i1 = 0; i1 < states.Count; i1++) {
						for (int i2 = i1; i2 < states.Count; i2++) {
							if (states [i1].Winner != states [i2].Winner) {
								State newState = new State (states [i1], states [i2]);
								if (newState.R > r || newState.P > p || newState.S > s)
									continue;
								newStates.Add (newState);
							}
						}
					}
					states = newStates;
				}
				if (states.Count == 0)
					Console.WriteLine ("IMPOSSIBLE");
				else
					Console.WriteLine (states[0].Align);
			}
		}
	}

	class State {
		public string Align;
		public char Winner;
		public int R;
		public int P;
		public int S;

		public State (char c)
		{
			Align = c.ToString ();
			Winner = c;
			R = c == 'R' ? 1 : 0;
			P = c == 'P' ? 1 : 0;
			S = c == 'S' ? 1 : 0;
		}

		public State(State s1, State s2) {
			Align = s1.Align + s2.Align;
			if (s1.Winner == 'R' && s2.Winner == 'P')
				Winner = 'P';
			if (s1.Winner == 'R' && s2.Winner == 'S')
				Winner = 'R';
			if (s1.Winner == 'P' && s2.Winner == 'S')
				Winner = 'S';
			if (s2.Winner == 'R' && s1.Winner == 'P')
				Winner = 'P';
			if (s2.Winner == 'R' && s1.Winner == 'S')
				Winner = 'R';
			if (s2.Winner == 'P' && s1.Winner == 'S')
				Winner = 'S';
			R = s1.R + s2.R;
			P = s1.P + s2.P;
			S = s1.S + s2.S;
		}
	}
}
