using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC042_B {
	class Program {
		static void Main() {
			int[] args = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
			int N = args[0];
			int L = args[1];
			List<string> Str = new List<string>();
			for (int i = 0; i < N; i++) {
				Str.Add(Console.ReadLine());
			}
			Str.Sort();
			Console.WriteLine(string.Join("", Str));
		}
	}
}