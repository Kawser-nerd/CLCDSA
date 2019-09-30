using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ProblemA
{
	class Program
	{
		private const string InputFile = "Input.txt";
		private const string OutputFile = "Output.txt";

		static void Main(string[] args)
		{
			string[] lines = File.ReadAllLines(InputFile);
			File.WriteAllText(OutputFile, String.Empty);
			for (int i = 1; i < lines.Count(); ++i)
			{
				ulong answer = FindAnswer(lines[i]);
				File.AppendAllText(OutputFile, String.Format("Case #{0}: {1}\n", i, answer));
			}
		}

		private static ulong FindAnswer(string numberRepr)
		{
			HashSet<char> digits = new HashSet<char>(numberRepr);
			uint numberBase = Math.Max((uint) digits.Count, 2);
			Dictionary<char, uint> digitToNumber = new Dictionary<char, uint>();
			ulong answer = 0;
			uint nextPossibleNumber = 1;
			foreach (char c in numberRepr)
			{
				uint current;
				if (digitToNumber.ContainsKey(c))
					current = digitToNumber[c];
				else
				{
					current = nextPossibleNumber;
					digitToNumber[c] = current;
					if (nextPossibleNumber == 1)
						nextPossibleNumber = 0;
					else if (nextPossibleNumber == 0)
						nextPossibleNumber = 2;
					else
						nextPossibleNumber += 1;
				}

				answer = answer * numberBase + current;
			}

			return answer;
		}
	}
}