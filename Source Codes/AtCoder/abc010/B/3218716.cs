using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program {
	static void Main(string[] args) {
		int n = int.Parse(Console.ReadLine());
		string[] input = Console.ReadLine().Split(' ');

		int count = 0;

		for (int i = 0; i < n; i++) {
			int num = int.Parse(input[i]);
			while (num % 2 == 0 || num % 3 == 2) {
				count++;
				num--;
			}
		}
		Console.WriteLine(count);
	}
}