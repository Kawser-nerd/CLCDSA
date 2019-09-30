using System;
using System.Collections;
using System.Collections.Generic;

public class A {
	public string solve() {
		int n = int.Parse(Console.ReadLine ());
		long[] d = new long[n];
		long[] l = new long[n];
		long[] m = new long[n];
		
		for (int i = 0; i < n; ++i) {
			string[] s = Console.ReadLine ().Split (' ');
			d[i] = long.Parse (s[0]);
			l[i] = long.Parse (s[1]);
		}
		
		m[0] = d[0];
		
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				long dist = d[i] - d[j];
				if (m[j] >= dist) {
					m[i] = Math.Max (m[i], Math.Min (l[i], dist));
				}
			}
		}
		
		long end = long.Parse (Console.ReadLine ());
		for (int i = 0; i < n; ++i) {
			if (d[i] + m[i] >= end) {
				return "YES";
			}
		}
		return "NO";
	}
	
	public static void Main() {
		var instance = new A();
		int n = int.Parse(Console.ReadLine ());
		
		for (int i = 1; i <= n; ++i) {
			Console.WriteLine("Case #{0}: {1}", i, instance.solve());
		}
	}
}
