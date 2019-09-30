using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

public class D {
	public string solve() {
		Console.ReadLine();
		string inp = Console.ReadLine ();
		
		Dictionary<char, char> conv = new Dictionary<char, char>();
		conv['o'] = '0';
		conv['i'] = '1';
		conv['e'] = '3';
		conv['a'] = '4';
		conv['s'] = '5';
		conv['t'] = '7';
		conv['b'] = '8';
		conv['g'] = '9';
		
		HashSet<string> unique = new HashSet<string>();
		for (int i = 0; i < inp.Length - 1; ++i) {
			char a = inp[i];
			char b = inp[i + 1];
			
			unique.Add("" + a + b);
			if (conv.ContainsKey(a)) unique.Add("" + conv[a] + b);
			if (conv.ContainsKey(b)) unique.Add("" + a + conv[b]);
			if (conv.ContainsKey(a) && conv.ContainsKey(b)) unique.Add("" + conv[a] + conv[b]);
		}
		
		int[] sa = new int[256];
		int[] sb = new int[256];
		
		foreach (string s in unique) {
			sa[(int)s[0]]++;
			sb[(int)s[1]]++;
		}
		
		int cnt = unique.Count * 2;
		for (int i = 0; i < 256; ++i) {
			cnt -= Math.Min(sa[i], sb[i]);
		}
		
		if (cnt == unique.Count)
			++cnt;
		
		return cnt.ToString();
	}
	
	public static void Main() {
		var instance = new D();
		int n = int.Parse(Console.ReadLine ());
		
		for (int i = 1; i <= n; ++i) {
			Console.WriteLine("Case #{0}: {1}", i, instance.solve());
		}
	}
}
