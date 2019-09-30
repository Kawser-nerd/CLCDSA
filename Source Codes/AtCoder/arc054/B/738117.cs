using System;
using System.Linq;

class A {
	static void Main() {
		var n = 	double.Parse(Console.ReadLine()); 
		double low = 0.0, high = 1000.0;

		Func<double,double> f = (x) => {
			return x + n / Math.Pow(2.0,x / 1.5);
		};

		for(int i = 0 ; i < 86 ; i++){
			var l = (low * 2.0 + high) / 3.0;
			var r = (low + high * 2.0) / 3.0;
			if(f(l) < f(r)) high = r; else low = l;
		}

		Console.WriteLine(f(low));
	}
}