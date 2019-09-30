using System;

class E { static void Main() => new J(); }
class J
{
	int F() => int.Parse(Console.ReadLine());
	public J()
	{
		var X = F();
		var t = Math.Max(0, (int)((Math.Sqrt(8.0 * X + 1) - 1) / 2) - 3);
		var s = t * (t + 1L) / 2;
		while (s < X) { t++; s += t; }
		Console.WriteLine(t);
	}
}