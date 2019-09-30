using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

public class B {
	public string solve() {
		string[] ss = Console.ReadLine ().Split ();
		int n = int.Parse (ss[0]);
		int w = int.Parse (ss[1]);
		int l = int.Parse (ss[2]);
		int[] r = new int[n];
		int[] ri = new int[n];
		int[] ww = new int[n];
		int[] ll = new int[n];
		
		ss = Console.ReadLine ().Split ();
		for (int i = 0; i < n; ++i) {
			r[i] = int.Parse (ss[i]);
			ri[i] = i;
		}
		
		Array.Sort(r, ri);
		bool flip = w > l;
		if (flip) {
			w ^= l;
			l ^= w;
			w ^= l;
		}
		
		int cw = w + 1;
		int cl = 0;
		int cln = - r[n - 1];
		
		for (int i = n - 1; i >= 0; --i) {
			cw += r[i];
			if (cw > w) {
				cw = 0;
				cl = cln + r[i];
				cln = cl + r[i];
			}
			
			ww[i] = cw;
			ll[i] = cl;
			cw += r[i];
		}
		
		if (flip) {
			int[] q = ww;
			ww = ll;
			ll = q;
		}
		
		string[] res = new string[2 * n];
		
		for (int i = 0; i < n; ++i) {
			int j = Array.IndexOf(ri, i);
			res[2 * i] = ww[j].ToString();
			res[2 * i + 1] = ll[j].ToString();
		}
		
		return string.Join(" ", res);
	}
	
	public static void Main() {
		var instance = new B();
		int n = int.Parse(Console.ReadLine ());
		
		for (int i = 1; i <= n; ++i) {
			Console.WriteLine("Case #{0}: {1}", i, instance.solve());
		}
	}
}
