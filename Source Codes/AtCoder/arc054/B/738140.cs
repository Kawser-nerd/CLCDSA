using System;
class A {
	static void Main() {
		var P = double.Parse(Console.ReadLine()); 
		var t?=?1.5*Math.Log(P*Math.Log(2)/1.5,2);
		Console.WriteLine((t > 0) ? P*Math.Pow(2,-t/1.5)+t : P);
	}
}