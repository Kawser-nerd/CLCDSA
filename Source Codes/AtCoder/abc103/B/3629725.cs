using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtCoder
{
	public class Program
	{
		// ABC103-B
		static void Main(string[] args)
		{
			string S = Console.ReadLine();
			string T = Console.ReadLine();
			if (S.Length != T.Length) {
				Console.WriteLine("No");
				return;
			}
			int len = S.Length;
			for (int i = 0; i < len; i++) {

				bool f = true;
				for (int j = 0; j < len; j++) {
					int k = (i + j) % len;
					if (S[j] != T[k]) {
						f = false;
						break;
					}
				}
				if (f) {
					Console.WriteLine("Yes");
					return;
				}

			}
			Console.WriteLine("No");
			return;
		}
	}

}