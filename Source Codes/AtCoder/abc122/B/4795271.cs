using System;
using System.Collections.Generic;
using System.Linq;

namespace B
{
	class Program
	{
		static void Main()
		{
			var S = Console.ReadLine().ToList();
			
			int maxLen = 0;
			for (int winSize = 1; winSize <= S.Count; winSize++) {
				// winSize?????????(?????)
				
				for (int i = 0; i + winSize <= S.Count; i++) {
					// Console.WriteLine(i + " ~ " + (i + winSize));
					var subS = S.GetRange(i, winSize);

					int count = 0;
					foreach (var c in subS) {
						// Console.Write(c);
						if (c != 'A' && c != 'C' && c != 'G' && c != 'T')
							break;
						count++;
					}
					// Console.WriteLine();

					if (count == subS.Count) maxLen = count;
				}
			}
			
			Console.WriteLine(maxLen);
		}
	}
}