using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string str = Console.ReadLine();
		string ans = "consonant";
		if(str == "a" || str == "i" || str == "u" || str == "e" || str == "o"){
			ans = "vowel";
		}
		Console.WriteLine(ans);
	}
}