using System;
using System.Collections.Generic;

namespace ABC103_B_String_Rotation
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string s = Console.ReadLine();
			string t = Console.ReadLine();
			List<string> rollS = new List<string>();
			
			bool matchStr = false;
			
			for (int i = 0; i < s.Length; i++) {
				rollS.Add(s.Substring(i, 1));
			}

			string endStr = "";
			for (int i = 0; i < s.Length; i++)
			{
				for (int j = s.Length - 1; j > 0; j--) {
					if (j == s.Length - 1)
					{
						endStr = rollS[j];
					}
					rollS[j] = rollS[j - 1];
					if (j == 1)
					{
						rollS[0] = endStr;
					}
				}
				
				string rollEndS = "";
				foreach (var str in rollS)
				{
					rollEndS += str;
				}
				if (rollEndS == t)
				{
					matchStr = true;
					break;
				}
			}

			if (matchStr)
			{
				Console.WriteLine("Yes");
			}
			else
			{
				Console.WriteLine("No");
			}
		}
	}
}