using System;
using System.Collections;
using System.Collections.Generic;

public class A {
	public double solve() {
		string[] ss = Console.ReadLine().Split(' ');
		int a = int.Parse (ss[0]);
		int b = int.Parse (ss[1]);
		
		ss = Console.ReadLine ().Split(' ');
		double[] p = new double[a];
		for (int i = 0; i < a; ++i)
			p[i] = double.Parse(ss[i]);
		
		double min = b + 2;
		double ok = 1;
		
		for (int i = 0; i <= a; ++i)
		{
			double exp = (a - i) + (b - i) + 1;
			exp += (1 - ok) * (b + 1);
			min = Math.Min(min, exp);
			
			if (i != a) {
				ok *= p[i];
			}
		}
		
		return min;
	}
	
	public static void Main() {
		var instance = new A();
		int n = int.Parse(Console.ReadLine ());
		
		for (int i = 1; i <= n; ++i) {
			Console.WriteLine("Case #{0}: {1}", i, instance.solve());
		}
	}
}
