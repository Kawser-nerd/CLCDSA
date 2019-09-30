using System;
using System.Collections.Generic;
using System.Linq;

class Program {
	static void Main(string[] args) {
		string s = Console.ReadLine();
		Dictionary<char, int> cCount = s.Distinct().ToDictionary(n => n, n => s.Count(a => a == n) % 2);
		int single = cCount.Values.Count(x => x == 1);
		int ans;
		if(single == 0) {
			ans = s.Length;
		}else {
			ans = (s.Length - single) / 2 / single * 2 + 1;
		}
		Console.WriteLine(ans);
	}
}