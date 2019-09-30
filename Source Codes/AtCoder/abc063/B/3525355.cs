using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var S = ReadLine();
		var dic = new HashSet<char> { };

		foreach (var c in S) {
			if (dic.Contains(c)) {
				WriteLine("no");
				return;
			}
			dic.Add(c);
		}
		WriteLine("yes");
	}
}