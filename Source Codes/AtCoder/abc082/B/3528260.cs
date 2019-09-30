using System;
using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var s = ReadLine();
		var t = ReadLine();

		var sa = MakeCharA(s);
		var ta = MakeCharA(t);
		Array.Reverse(ta);
		WriteLine(Judge(sa, ta) ? "Yes" : "No");
	}

	static char[] MakeCharA(string s) {
		var sa = new char[s.Length];
		for (var i = 0; i < s.Length; i++) {
			sa[i] = s[i];
		}
		Array.Sort(sa);
		return sa;
	}

	static bool Judge(char[] s, char[] t) {
		for (var i = 0; i < Math.Max(s.Length, t.Length); i++) {
			if (i >= s.Length) {
				return true;
			}
			if (i >= t.Length) {
				return false;
			}
			if (s[i] < t[i]) {
				return true;
			}
			if (t[i] < s[i]) {
				return false;
			}
		}
		return false;
	}
}