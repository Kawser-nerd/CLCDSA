using System;
using System.Collections;
using System.Collections.Generic;

public class A {
	public string solve() {
		int n = int.Parse(Console.ReadLine ());
		int[] a = new int[n];
		int[] b = new int[n];
		int[] s = new int[n];
		int st = 0;
		int res = 0;
		
		for (int i = 0; i < n; ++i) {
			string[] ss = Console.ReadLine ().Split (' ');
			a[i] = int.Parse (ss[0]);
			b[i] = int.Parse (ss[1]);
		}
		
		while (st < 2 * n) {
			bool ok = false;
			for (int i = 0; i < n; ++i) {
				if (st >= b[i] && s[i] < 2) {
					ok = true;
					st += 2 - s[i];
					s[i] = 2;
					++res;
				}
			}
			
			if (ok) {
				continue;
			}
			
			int best = -1;
			for (int i = 0; i < n; ++i) {
				if (st >= a[i] && s[i] == 0) {
					if (best == -1 || b[best] < b[i]) {
						best = i;
					}
				}
			}
			
			if (best == -1)
				return "Too Bad";
			
			s[best] = 1;
			++st;
			++res;
		}
		
		return res.ToString();
	}
	
	public static void Main() {
		var instance = new A();
		int n = int.Parse(Console.ReadLine ());
		
		for (int i = 1; i <= n; ++i) {
			Console.WriteLine("Case #{0}: {1}", i, instance.solve());
		}
	}
}
