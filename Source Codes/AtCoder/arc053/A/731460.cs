using System;
using System.Linq;

class Program {
	static void Main(string[] args) {
		var s = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
		int H = s[0];
		int W = s[1];
		Console.WriteLine((H - 1) * W + H * (W - 1));
	}
}