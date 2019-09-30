using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace CodeJam
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			string[] input = File.ReadAllLines (args [0]);
			int cases = int.Parse (input [0]);
			for (int c = 1; c <= cases; c++) {
				Console.Write ("Case #" + c + ": ");
				string number = GetNumber (input [c]);
				Console.WriteLine (number);
			}
		}

		static string GetNumber(string s) {
			Dictionary<char, int> letters = new Dictionary<char, int> ();
			for (char add = 'A'; add <='Z'; add++)
				letters.Add (add, 0);
			foreach (char c in s) {
				letters [c]++;
			}
			int[] digits = new int[10];
			digits [0] = letters ['Z'];
			letters ['Z'] -= digits [0];
			letters ['E'] -= digits [0];
			letters ['R'] -= digits [0];
			letters ['O'] -= digits [0];
			digits [2] = letters ['W'];
			letters ['T'] -= digits [2];
			letters ['W'] -= digits [2];
			letters ['O'] -= digits [2];
			digits [4] = letters ['U'];
			letters ['F'] -= digits [4];
			letters ['O'] -= digits [4];
			letters ['U'] -= digits [4];
			letters ['R'] -= digits [4];
			digits [5] = letters ['F'];
			letters ['F'] -= digits [5];
			letters ['I'] -= digits [5];
			letters ['V'] -= digits [5];
			letters ['E'] -= digits [5];
			digits [6] = letters ['X'];
			letters ['S'] -= digits [6];
			letters ['I'] -= digits [6];
			letters ['X'] -= digits [6];
			digits [7] = letters ['V'];
			letters ['S'] -= digits [7];
			letters ['E'] -= digits [7];
			letters ['V'] -= digits [7];
			letters ['E'] -= digits [7];
			letters ['N'] -= digits [7];
			digits [8] = letters ['G'];
			letters ['E'] -= digits [8];
			letters ['I'] -= digits [8];
			letters ['G'] -= digits [8];
			letters ['H'] -= digits [8];
			letters ['T'] -= digits [8];
			digits [1] = letters ['O'];
			letters ['O'] -= digits [1];
			letters ['N'] -= digits [1];
			letters ['E'] -= digits [1];
			digits [3] = letters ['T'];
			digits [9] = letters ['I'];

			string result = "";
			for (int i = 0; i < 10; i++)
				result += new string ((char)('0' + i), digits [i]);
			return result;
		}
	}
}
