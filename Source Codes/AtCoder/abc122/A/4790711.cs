using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
        // ??????
        List<string> e1 = new List<string>(){ "A", "T" };
        List<string> e2 = new List<string>(){ "C", "G" };

		// ??????
        string b = Console.ReadLine();

		// ??
		string outPut = "";

		// ??????
		if (e1.Contains(b))
		{
			foreach(string s in e1)
			{
				if (s != b)
				{
					outPut = s;
				}
			}	
		}
		else if (e2.Contains(b))
		{
			foreach(string s in e2)
			{
				if (s != b)
				{
					outPut = s;
				}
			}	
		}

		//??
		Console.WriteLine(outPut);
	}
}