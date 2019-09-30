using System;
using System.Collections.Generic;
using System.Text;

namespace AtCoder
{
	public class Program
	{
		// ABC105-C
		static void Main(string[] args)
		{
			int N = int.Parse(Console.ReadLine());
			long posi = 0, nega = 0, diff = N;

			long[] pattern = new long[64];
			long m = 1;
			for (long i = 0; i < pattern.Length; i++) {
				pattern[i] = m;
				m = (m << 1) | i % 2;
			}

			while (true) {
				if (diff == 0) {
					// ??
					Console.WriteLine(Convert.ToString(posi + nega, 2));
					return;
				} else if (diff > 0) {
					// ?
					int i = 0;
					while (pattern[i] < diff) {
						i += 2;
					}
					posi += 1L << i;
				} else {
					// ?
					int i = 1;
					while (-1 * pattern[i] > diff) {
						i += 2;
					}
					nega += 1L << i;
				}
				diff = N - (posi + (-1 * nega));
			}
		}
	}
}