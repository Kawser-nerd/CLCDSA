using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

public class C {
	public string solve() {
		string[] ss = Console.ReadLine ().Split (' ');
		long m = long.Parse (ss[0]);
		long f = long.Parse (ss[1]);
		int n = int.Parse (ss[2]);
		long[] p = new long[n];
		long[] s = new long[n];
		
		for (int i = 0; i < n; ++i) {
			ss = Console.ReadLine ().Split (' ');
			p[i] = long.Parse (ss[0]);
			s[i] = long.Parse (ss[1]) + 1;
		}
		
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i != j && p[i] >= p[j] && s[i] <= s[j]) {
					p[i] = long.MaxValue;
				}
			}
		}
		
		Array.Sort (p, s);
		
		long max = 0;
		
		for (int i = 0; i < n; ++i) {
			if (p[i] == long.MaxValue)
				break;
			
			try {
				long singlep = f;
				long singles = 0;
				for (int j = 0; j < i; ++j) {
					long days = s[j] - singles;
					singlep = checked(singlep + days * p[j]);
					singles = s[j];
				}
				
				if (singlep > m) {
					break;
				}
				
				long maxnext = s[i] - singles;
				
				long price = 0;
				long ddays = 0;
				long times = 0;
				
				while (true) {
					price += singlep;
					ddays += singles;
					++times;
					
					if (price > m) {
						break;
					}
					
					long extra = Math.Min ((m - price) / p[i], maxnext * times);
					
					max = Math.Max (max, ddays + extra);
				}
			} catch (Exception ex) {
				Console.WriteLine (ex.Message);
				// TODO
			}
		}
		
		return max.ToString();
	}
	
	public static void Main() {
		var instance = new C();
		int n = int.Parse(Console.ReadLine ());
		
		for (int i = 1; i <= n; ++i) {
			Console.WriteLine("Case #{0}: {1}", i, instance.solve());
		}
	}
}
