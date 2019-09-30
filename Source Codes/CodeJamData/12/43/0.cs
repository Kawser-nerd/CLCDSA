using System;
using System.Collections;
using System.Collections.Generic;

public class C {
	public string solve() {
		int n = int.Parse (Console.ReadLine ());
		int[] next = new int[n - 1];
		
		string[] ss = Console.ReadLine ().Split (' ');
		for (int i = 0; i < n - 1; ++i) {
			next[i] = int.Parse (ss[i]) - 1;
		}
		
		for (int i = 0; i < n - 1; ++i) {
			for (int j = i + 1; j < n - 1; ++j) {
				if (next[i] > j && next[i] < next[j]) {
					return "Impossible";
				}
			}
		}
		
		int[] h = new int[n];
		int[] dh = new int[n];
		
		h[n - 1] = 1000000000;
		dh[n - 1] = 0;
		
		for (int i = n - 1; i >= 0; --i) {
			int d = dh[i] + 1;
			for (int j = 0; j < i; ++j) {
				if (next[j] == i) {
					h[j] = h[i] - d * (i - j);
					dh[j] = d;
					++d;
				}
			}
		}
		
		string[] res = new string[n];
		for (int i = 0; i < n; ++i)
			res[i] = h[i].ToString();
		
		return string.Join(" ", res);
	}
	
	public static void Main() {
		var instance = new C();
		int n = int.Parse(Console.ReadLine ());
		
		for (int i = 1; i <= n; ++i) {
			Console.WriteLine("Case #{0}: {1}", i, instance.solve());
		}
	}
}
