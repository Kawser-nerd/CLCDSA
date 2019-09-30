using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string str1 = Console.ReadLine();
		string str2 = Console.ReadLine();
		string s = "";
		if(str1.Substring(0,1) == str2.Substring(2,1) && str1.Substring(1,1) == str2.Substring(1,1) && str1.Substring(2,1) == str2.Substring(0,1)){
			s = "YES";
		} else {
			s = "NO";
		}
		Console.WriteLine(s);
	}
}