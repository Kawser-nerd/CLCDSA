using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program {
	static void Main(string[] args) {
		string input = Console.ReadLine();
		string res = string.Empty;

		for (int i = 0; i < input.Length; i++) {
			if (i == 0) {
				res += char.ToUpper(input[i]);
			} else {
				res += char.ToLower(input[i]);
			}
		}
		Console.WriteLine(res);
	}
}