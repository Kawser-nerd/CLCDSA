using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Mousetrap
{
	class Program
	{
		static void Main(string[] args)
		{
			StreamReader sr = new StreamReader(@"c:\temp\c-small-attempt0.in");
			StreamWriter sw = new StreamWriter(@"c:\temp\c.out");
//			TextWriter sw = Console.Out;

			int noCases = int.Parse(sr.ReadLine());
			for (int caseNo = 1; caseNo <= noCases; caseNo++)
			{
				int K = int.Parse(sr.ReadLine());
				string[] split = sr.ReadLine().Split(' ');
				int n = int.Parse(split[0]);
				int[] d = new int[n];
				for (int i = 0; i < n; i++)
					d[i] = int.Parse(split[i + 1]) - 1;

				List<int> deck = new List<int>(K);
				for (int i = 0; i < K; i++)
					deck.Add(i);
				int[] card = new int[K];
				
				for (int i = 0; i < K; i++)
				{
					int left = K - i;
					int pos = i%left;
					card[deck[pos]] = i + 1;
					List<int> newDeck = new List<int>(K - 1);
					for (int j = pos + 1; j < left; j++)
						newDeck.Add(deck[j]);
					for (int j = 0; j < pos; j++)
						newDeck.Add(deck[j]);
					deck = newDeck;
				}

				sw.Write("Case #" + caseNo + ":");
				foreach (var ix in d)
					sw.Write(" " + card[ix]);
				sw.WriteLine();
			}
			sw.Close();
		}
	}
}
