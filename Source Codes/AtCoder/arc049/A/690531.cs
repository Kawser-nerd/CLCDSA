using System;
using System.Linq;

class A {
	public static void Main(string[] args) {
		var str = Console.ReadLine().ToList();
		var xs = Console.ReadLine()
			.Split(' ')
			.Select(int.Parse)
			.ToArray();
		str.Insert(xs[0], '"');
		str.Insert(xs[1] + 1, '"');
		str.Insert(xs[2] + 2, '"');
		str.Insert(xs[3] + 3, '"');
		Console.WriteLine(string.Concat(str));
	}
}