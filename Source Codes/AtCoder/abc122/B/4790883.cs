using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
        // ??????
        List<char> acgt = new List<char>(){ 'A', 'C', 'G', 'T' };

		// ??????
        string s = Console.ReadLine();

		// ??
		string temp = "";
		string max = "";
		int index = 0;
		// char???
		foreach(char c in s)
		{
			index++;
			if (acgt.Contains(c))
			{
				temp += c;

				// ??
				if (index == s.Length &&
					temp.Length > max.Length)
				{
					max = temp;
				}
			}
			else
			{
				if (temp.Length > max.Length)
				{
					max = temp;
				}

				temp = "";			
			}
		}
		//??
		Console.WriteLine(max.Length);
	}
}