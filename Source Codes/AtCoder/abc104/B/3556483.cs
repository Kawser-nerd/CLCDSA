using System;
using System.Collections.Generic;
using System.Text;

namespace AtCoder
{
	public class Program
	{
		// ABC104-B
		static void Main(string[] args)
		{
			string S = Console.ReadLine();
			bool result = true;
			int c = 0;
			for (int i = 0; i < S.Length; i++) {
				if (i == 0) {
					if (S[i] != 'A') {
						result = false;
						break;
					}
				} else if ((2 <= i && i <= S.Length - 2) && S[i] == 'C') {
					c++;
				} else if (S[i] < 'a' || 'z' < S[i]) {
					result = false;
					break;
				}
			}
			if (c != 1) {
				result = false;
			}
			if (result) {
				Console.WriteLine("AC");
			} else {
				Console.WriteLine("WA");
			}
		}
	}
}